<img src="node-logo.png" alt="node-logo" style="zoom:50%;" />



- NodeJS es un entorno de ejecución de JavaScript . Compila código JavaScript
- Tu maquina no reconoce el lenguaje JavaScript solo ejecuta programas
- Resolvió la problemática de las conexiones concurrentes, antes (con JAVA, PHP,.. ) si se conectaban 10000 usuarios a tu pagina era mucho. Se creaba un hilo por cada conexión de usuario y se caía la pagina.
- Crear conexiones de manera asíncrona



##### Instalación 

Mira un video de YouTube

````javascript
> node --version       // Puedes comprobar si lo tienes, en la consola
````



##### Ejecutar un script 

````javascript
> node miejemplo.js
````



Las buenas practicas dicen tener un `archivo principal`  (el que se ejecuta) y las demás funciones se importan a este archivo

````javascript
Tengo un archivo `mate.js` | que tiene funciones y propiedades
function sumar(a ,b){return a + b ;}
// Para exportar las funciones de este archivo
// export.(un nombre que yo quiera) = "el nombre de la funcion definida"
exports.add = sumar;

// por lo general se escriben igual para no perder la simplicidad
exports.restar = restar;    // si nesecita mas funciones

// Podemos exportar todo el modulo ó (objeto, funciones,etc)
module.exports = nombreDelModulo  // Yo uso esto con [func1,func2,..] una linea.



--------------------------------------------------    
En el archivo `index.js` // el (./) me dice que estoy parado en la ubicacion del archivo index.js

// Para importar las funciones del archivo mate.js
const math = require('./mate.js');

// Es como si 'math' fuera un objeto y las funciones sus metodos
console.log(math.add(1,2))
````



##### NodeJS ya viene con módulos instalados, como los llamamos?

````javascript
// Podemos leer la documentacion de nodeJS en |DOCS|v10.6.0 API Ejemplos
const os = require('os')  // Tiene informacion del S.O.
consol.log(os.cpus()) // Informacion de mis CPUs
fdsgole.log(os.release()) // Info del S.O.
````

````javascript
// Escribir un arhcivo
//fs.writeFile("ruta y nombre del archivo",CONTENIDO, CALLBACK)
fs.writeFile('./newtexto.txt',"linea uno",function(err){
    if(err){ console.log(err)}
    console.log("Archivo creado")
})
// importante: se ejecuta el CALLBACK cuando se termino lo anterior, que como es trabajo del SO lo delega y sigue ejecutando las demas filas.


// Leer un archivo
fs.readFile('./texto.txt',function(err, data){
    if(err){ console.log(err)}
    console.log(data); // pero esta en un formato raro
    console.log(data.toString()); // Apa la papa
})

// Eliminar un archivo
fs.unlink('data.txt',(err)=>{});


//NO OLVIDES QUE TODO ESTA EN LA DOCUMENTACION y tener en cuenta que estos metodos son asincronos si quiero que sean sincronos existen funciones similares para esto por ejemplo
let data = fs.readFileSync('data.txt','utf-8')
````



##### El Asincronismo, para tareas que nodeJS no hace

````javascript
// En este caso 'consulatar la base de datos' no lo hace nodeJS 
query('SELECT * FROM users', function(err,users){
    if(err){
        console.log(err)
    }
    if(users){
        // Hacer algo con ellos
    }
})
````



###### La tarea principal nodeJS es crear servidores, :smiley: SI, hay un modulo para eso

````javascript
const http = require('http')

http.createServer(function(req,res){  // creando un servidor
   res.writeHead(200,{})  // Informacion de la cabecera
   res.write('<h1>Hola mundo desde NodeJS</h1>') 
   res.end()
}).listen(3000);  // en que puerto escucha

//Para verlo ir a localhost:3000
````

````javascript
http.createServer(function(req,res){
   // Informacion de la cabecera
   res.writeHead(200,{ 'Conten-type': 'text/html'});  
   res.write('<h1>Hola mundo desde NodeJS</h1>') 
   res.end()
}).listen(3000);

//Para verlo, ir a 'Network' y recargar la pagina
````



###### Existe un modulo que me sirve y se usa mucho para proyectos en nodeJS (npm)

````javascript
// Podemos usar modulos de otras personas con 'npm' , la documentacion esta en la pagina de npm, ejemplo este es para colorear.
$ npm install color

// Que sucede? 
// Se crea una carpeta [node_modules] : Se encuentran los modulos instalados
// Un archivo [package-lock.json] : Una lista de todos los modulos instalados y y algunas especificaciones de estos. 

// Estas dos cosas no se tocan OJoncio, en nuestro index.js
var colors = require('colors'); // por que existe en nuestro proyecto
console.log('hello'.green); // outputs green text
//Apa la papa en verdecito en la cmd
````



Obviamente se usan muchos módulos y se debe poder usar por cualquiera en cualquier maquina, entonces necesitamos una lista de dependencias

````javascript
// Esto crea un archivo json (package.json) con informacion del proyecto y las dependencias
> npm init
Enter a lo que quieras por defecto si no modificar a tu gusto
Fijate en las dependencias
````

Me olvidaba no subes `node-modules `pesa mucho , con `package.json` tenemos la lista de dependencias y se descarga en cada computador

Como recuperamos la carpeta  `node-modules` a partir del  `package.json` fácil con el comando `npm install`, lo que hace es leer el `package.json` e instalar las dependencias que aparecen acá.

![package](package.png)

Vemos en la imagen (package.json ) que   "scripts" :{ "start" : "node index.js"} esto es muy importante si en la consola escribo `npm start` se ejecuta `node index.js`  que es la forma que usábamos para ejecutar un archivo en JavaScript

También podemos tener nuestro propios comandos como `npm desarrollo` que ejecuta `node index.js` 

> Observación: cuando no es "start" se debe poner `npm run desarrollo`



#### Express

Nosotros no necesitamos escribirlo todo desde cero, existe **framework** como **Express**

````javascript
> npm i express --save   
//El modificador (--save) agrega la dependencia en el package.json
//En las ultimas versiones no es nesesario, ya q lo hace automaticamente

//Como venimos haciendo
const express = require('express');
//El color no olvidar XD
const server = express(); // se crea un servidor
server.get('/', function (req,res)=>{
	res.send('<h1>Hola Express y Node</h1>')
	res.end();
});

server.listen(3000, function () => {
    console.log('Server on port 3000'.red);
});
````

