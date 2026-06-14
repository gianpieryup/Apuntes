## Usando el modulo figlet con npm

1. Visitar documentación
2. Instalar el modulo
3. Ver ejemplos

 Primero empezamos un proyecto de cero: Esto crea un `package.json`

````shell
$ npm init -y
````

> Si te sale un error omite este paso, yo lo tuve que omitir. Directamente instala el modulo y automáticamente se creara el `package.json` y el `node_module`

**Solución 2020** : 

1. Crear el app.js vacio
2. Correr `npm init`
3. Alternativa: después de leerlo detenidamente tienes que escribir el nombre del

#### Instalar el modulo

````shell
npm install figlet
````

Creo un archivo `àpp.js`

````javascript
const figlet = require('figlet')

figlet('Hello World',(err,result)=>{
	console.log(err || result)
})
````

## Primeros pasos: línea de comando

Para usar figlet.js en la línea de comando, instale figlet-cli: Lo instala globalmente para ser usado en cualquier lugar con la consola

```shell
npm install -g figlet-cli
```

Y luego debería poder ejecutar desde la línea de comandos. Ejemplo:

```shell
figlet  "Hello world"
 
ó bien con estilos

figlet -f "Dancing Font" "Hi"
```

#### Otros

Otros módulos parecidos a este `ascii-art` en `npm`

### No podían faltar las imágenes :fire:

El modulo es `images-to-ascii` en `npm`

Mirar documentación si no se instalo correctamente, en el video le mando a instalar `chocolat` y te pide mas dependencias para poder instalarlo

Hasta el culaso como se ve , no lo intentes . Ósea la idea que hace el modulo es transformar una imagen.jpg a código ASCII