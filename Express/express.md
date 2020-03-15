<img src="express logo.jpg" alt="express logo" style="zoom:40%;" />

## Introducción

Es un framework de JavaScript que me da una estructura de proyecto para no escribir todo de cero, en comparación a a hacerlo manualmente.

````javascript
//Manualmente es muy tedioso
const http = require('http');
const server = http.createServer((req,res) => {
    res.status = 200; // obligatorio
    res.setHeader('Content-type','text/plain'); // obligatorio
    res.end('Hello World'); // obligatorio
});

server.listen(3000, () => {
    console.log('Server om port 3000')
})
````

Ahora con el modulo **express**

````javascript
//Buenas constumbres de un programador
1. Crear el archivo package.json con el comando `npm init`
2. Intalar el modulo express con el comando `npm install express`
Se creara una carpeta llamada 'node_modules'

const express = require('express');
// Esto es un objeto, que en realidad es mi servidor
const app = express();

app.get('/',(req,res) => {
    res.send('Hello world') // 3 lineas en una
})
app.listen(3000, () => {
    console.log('Server om port 3000')
})
````



## Express Routing

````javascript
//Mas rutas
app.get('/about',(req,res) => {
    res.send('About me')
});
app.get('/contact',(req,res) => {
    res.send('Form Contact')
});
````



### Nodemon

````javascript
Es un modulo que reinicia el servidor cada vez que edite el codigo
$ npm i -g nodemon  //para todo el sistemaa
$ npm i nodemon -D  //solo para el proyecto
//recuerda que siempre puedes ver la documentacion

//Notamos entonces en package.json
"dependencies" :{ //Para el funcionamiento de mi aplicacion
    "express" : "^4.16.4"
}
"devDependencies" :{ //Para el desarrollo de mi aplicacion
    "nodemon": "^1.18.10"
}

Para ejecutar
> npx nodemon index.js
````

###### Metodos HTTP

````javascript
app.get()    //Pedir datos
app.post()	 //Guardar datos
app.put()    //Modificar
app.delete() //Eliminar
````



###### Lo mas usual es devolver información en formato JSON

````javascript
app.get('/user',(req,res) => {
    res.json({
        username : 'juancito',
        lastname : 'Perez'
    })
});

app.post('/user',(req,res) => {
    console.log(req.body)
});
A pero en este ultimo me sale un 'undefined', es por que express no entiende los objetos JSON solucion?
    
//Antes de todas las rutas
app.use(express.json());
````



###### Rutas Dinámicas

````javascript
Parametros de la peticion
app.post('/user/:id',(req,res) => {
    console.log(req.body);
    console.log(req.params);
});

Entonces si la ruta es localhost:3000/user/25
req.params = { id : '25'}
//Ojo es un objeto y los valores son string:
//req.params.id == '25'
````



##### Bonus

````javascript
// all() funcion express. Significa que para todas las rutas ('/user') tendran que pasar primero por aqui.
app.all('/user',(req,res)=>{
    console.log('Por aqui paso');
    //res.send('finish');
    next(); //esto hace que siga su camino a la ruta original
});
//RECORDAR q Despues del (.send) no se ejecuta nada más.
````



##### Resumen

````javascript
app.METHOD(PATH,HANDLER)
````



## Middlewares

Básicamente son funciones que se ejecutan antes de las rutas, conviene ponerlas al principio de todo.

````javascript
//Como el app.all('/user') pero para toda ruta, no solamente que comienze con 'use'

function mifuncion(req,res,next){
    console.log('pasas ´por mi primero');
    next();
}
app.use(mifuncion);

//las rutas....
````

#### Morgan

````javascript
//Un midellwar muy util que me muestra informacion en cada ruta
$ npm i morgan

const morgan = require('morgan')
app.use(morgan('dev'))

//Mirar la documentacion en NPM,el mas usado es 'dev'

Y para que todo esto??
Mira tu consola cuando visitas una ruta valida (GET,POST)
````



### Static Files

````javascript
//Otro midellwar muy interesante,este ya viene en express
//Se encarga de enviar archivos al frontend (html,css,js) estos son archivos staticos

app.use(express.static('public'));
Hace referncia a que debe existir la carpeta `public` donde podemos cargar archivos (html,css,js)
````



### Settigs (Configuraciones)

````javascript
// Declarar variables (nombre,valor)
app.set('appName','fast express tutorial');

// Ver el valor
console.log(app.get('appName'));
````



### Motor de Plantillas

````javascript
Muy usado para poder mostrar emvés de json un html con colores
$ npm install ejs

**existen muchos,(pug) yo use uno que creo era `hbs`(handelbars)
    
//configuracion
app.set('view engine','ejs');

Esto lo que me dice es que en la carpeta `view` (q si no existe la creo), habran archivos(por ejemplo `index.ejs`) que nos sirven de plantilla

app.get('/',(req,res)=> {
    res.render('index.ejs')
})


Donde los archivos (.ejs) son html comunes que tienen acceso a datos que les pasamos por aca. Por ejemplo
app.get('/',(req,res)=> {
    const data = [{name : 'john'},{name: 'jose'}]
    res.render('index.ejs',{personas:data});
})
Osea al archivo `index.ejs` le paso la info de `personas`

---
En `index.ejs`
<ul> 
	<% personas.forEach(function(per) {%>
    	<li><%= per.name %></li>
    <%  }) %>                                  
</ul>
````



## Frameworks de Database

Si  quiero usar base de datos como la integro?? Con módulos de `npm  `  no es obvio ya a esta altura :slightly_smiling_face:

Como depende con cual trabaje debemos ir a *express database integration* en **Google**



## ORM

**sequelize** para base de datos sql

**mongose** para base de datos nosql

Ambos sirven para evitar escribir código sql y codigo nosql respectivamente, y para que? para **abstraerte** de la **base de datos**



### Otros frameworks (Por que no solo existe Express)

- ADONIS
- SAILS js
- koa js
- hapi js
- kraken js



## Generador de aplicaciones Express

Un modulo que me permite crear un esqueleto de trabajo, una estructura de directorios lista para usar.

````javascript
npm install express-generator -g
````



Tip: toda instalación con el modificador (-g) significa que el modulo estará disponible en cualquier lugar de tu computadora. **Notar la ruta** donde se instala, aparece en los logs si es tu primera vez. No pasa nada si se quiere instalar de nuevo no se crea ningún conflicto :slightly_smiling_face: ni hay redundancia , detecta que ya esta y no pasa nada.

**RUTA**

> C:\Users\HP\AppData\Roaming\npm\node_modules

Todos los **módulos** que están en esta *ruta* ya están instalados y disponibles para usar en cualquier carpeta.

```sh
Para crear el proyecto
$ express --view=hbs nombreDelProyecto

Existen distintos motores de vista
--ejs           add ejs engine support
--hbs           add handlebars engine support
--pug           add pug engine support
--hogan         add hogan.js engine support
--no-view       generate without view engine
```

Se creara una carpeta con el nombre del proyecto con las siguientes carpetas

- :file_folder: `bin`  :    Tenemos el archivo  `www` con todas las configuraciones generales: "nro puerto", "protocolo", etc.
- :file_folder: `public`  :    (CSS, JAVASCRIPT, imágenes)
- :file_folder: `routes`  :    Rutas de la aplicación
- :file_folder: `view`  :    Vistas de la aplicación
- El `archivo app.js`  :  Módulos y rutas.
- El `archivo package.json`  :  Información del proyecto y sus dependencias

Luego instale dependencias:

```sh
$ cd nombreDelProyecto
$ npm install

// Lo corremos con
$ npm start
```

> Tip : No te olvides de nodemon sirve mucho para no tener que estar reiniciando el servidor cada vez que edite el código.

````sh
$ nodemon npm start
````



En la :file_folder: `routes`  : el archivo index.js tenemos lo siguiente

````javascript
var express = require('express');
var router = express.Router();

/* GET home page. */
router.get('/', function(req, res, next) {
  res.render('index', { title: 'Express' });
});

Esto se lee renderiza la vista `index.hbs`, con un objeto al cual tendremos acceso en la vista `el objeto {title : 'Express'}`

module.exports = router;


------
Para acceder al valor de las variables usamos `{{}}`
Por ejemplo en la vista 'index.hbs'
<p>Estamos en {{title}}</p>
````



#### ¿Que onda con los parámetros?

- **req** : Request (información que llega al controller)
- **res** : Response (La información que sale del controller)
- **next()** : Break; (Pasa a la siguiente funcion)