# JavaScript - Asincronismo

La asincronía es uno de los pilares fundamentales de JavaScript.

Los lenguajes de programación asíncronos se basan en llamadas que pueden ser cumplidas ahora o en un futuro. Es decir, las variables pueden ser llenadas o asignadas en cualquier momento de la ejecución del programa

Muchos de los lenguajes de programación populares se basan en procesos síncronos. Es decir, una orden solo se puede ejecutar luego que se ejecuta la anterior. Esto es muy beneficioso para el programador, debido a que no tiene que preocuparse de cuando los datos estarán listos. El problema de estos tipos de lenguajes es que los procesos ocupan más memoria, y son menos eficientes.



## Callbacks

Supongamos que trabajamos con ` base de datos` 

````javascript
function requestHandler(req, res) {
  User.findById(req.userId, function(err, user){
 
  })
}
//Este codigo se lee de la siguiente forma:
Voy a consultar al usuario por el id, la base de datos me dara una respuesta, `esa respuesta` la manejamos con la function(err,user){/aca/}
````



El asincronismo de JavaScript

````javascript
function requestHandler(req, res) {
  User.findById(req.userId, function(err, user){
  })
  console.log("Yo voy primero")
}
//NodeJS no va a esperar a que termine "la consulta a la bd", si no que pasara a la siguiente linea. si quiero que las siguientes lineas dependan del resultado de la consulta a la DB entonces deben ir adentro

function requestHandler(req, res) {
  User.findById(req.userId, function(err, user){
      console.log("Yo voy primero")
  })
}
````



En el siguiente ejemplo

1. Consultamos el usuario por ID
2. Si lo anterior no tubo errores, con este ID busca sus tareas asociadas
3. Si lo anterior no tubo errores, cambiar el estado de estas tareas y guardar
4. Si lo anterior no tubo errores, mostrar un mensaje  'Task Completed'

````javascript
function requestHandler(req, res) {
  User.findById(req.userId, function(err, user) { //consulta a la BD
    if (err) { // Ubo un error
      res.send(err);
    } else { // Si no hay error
      Tasks.findById(user.tasksId, function (err, tasks) {
        if (err) { // Ubo un error
          return res.send(err);
        } else { // Si no hay error
          tasks.completed = true;//cambiar el estado
          tasks.save(function(err) { //guardar en la base
            if (err) {
              return res.send(err);
            } else {
              res.send('Task Completed');
            }
          });
        }
      });
    }
  });
}
// Este forma de escribir codigo es correcta, pero de mala practica
// La piramide de la muerte, dificil de mantener
````



## Promesas

Solución a las Callbacks, con el mismo ejemplo anterior, con `Promesas`

- `then()` : cuando el proceso valla bien
- `catch()` : si aparece un error

````javascript
function requestHandler(req, res) {
  User.findById(req.userId)
    .then(function (user) {
      res.send(user);
    }).catch(function (err) {
      res.send(err);
    });
}    
````

Cuando tenemos mas operaciones se ve la diferencia

1. Consultamos el usuario por ID
2. Si lo anterior no tubo errores, con este ID busca sus tareas asociadas
3. Pero esto se hace concatenando los `then()` y con un `return`
4. El `catch` capturas los errores de todas las consultas, por eso `errors`

````javascript
function requestHandler(req, res) {
  User.findById(req.userId)
    .then(function (user) {
      return Tasks.findById(user.tasksId)//nueva promesa 2
    })
    .then(function (tasks) { //el then asociado a la promesa 2
      tasks.completed = true;
      return tasks.save();//nueva promesa 3
    })
    .then(function () {//el then asociado a la promesa 3
      res.send('Tasks Completed!');
    })
    .catch(function (errors) {
      res.send(erros);
    });
}

````



## Async-Await

Una mejor forma de hacer `Promesas`

- `await`  :  Dice que el código siguiente va a tomar tiempo de ejecución, que es un método asíncrono 
- `async` : Para usar `await`  ,solo esta disponible para funciones `async`

Como si fuera un lenguaje síncrono convencional

````javascript
async function requestHandler(req, res) {
    try{
        const user = await User.findById(req.userId);
    	const tasks = await Tasks.findById(user.tasksId);
    	tasks.completed = true;
    	await tasks.save();
        res.send('Task Completed')
    }
    catch(e){
        res.send(e);
    }
}
````



## Código sequential

Tengamos dos archivos `task.js` y `index.js`

````javascript
//En task.js
const util = require('util');
const sleep = util.promisify(setTimeout);
module.export = {
    async taskOne(){
        await sleep(4000);//se demora 4 segundos
        return 'One value'
    },
    async taskTwo(){
        await sleep(2000);//se demora 2 segundos
        return 'Two value'
    }
}

-------------
//En index.js
const { taskOne, taskTwo } = require('./tasks');

// Secuentially Processes
async function main() {
  try {
    console.time('Midiendo time');// [time/timeEnd]

    const valueOne = await taskOne(); // task 4 seconds to finish
    const valueTwo = await taskTwo(); // wait the last task to finish

    console.log('Task One returned: ', valueOne);
    console.log('Task Two returned: ', valueTwo);
    
    console.timeEnd('Midiendo time'); // the total is 6 seconds to finish
  }
  catch (e) {
    console.log(e);
  }
}

main();
````



## Código Paralelo

Las dos tareas se ejecutan al mismo tiempo

````javascript
const { taskOne, taskTwo } = require('./tasks');

// EXECUTING TWO TASKS IN PARALLEL
async function main() {

  try {
    console.time('tasks time');

    const data = await Promise.all([taskOne(), taskTwo()]);

    console.log('Task One returned: ', data[0]);
    console.log('Task Two returned: ', data[1]);

    console.timeEnd('tasks time');
  }
  catch (e) {
    console.log(e);
  }

}

main();
````

