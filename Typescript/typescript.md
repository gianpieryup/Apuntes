<img src="C:\Users\HP\Desktop\Mis Apuntes\Typescript\ts logo.png" alt="ts logo" style="zoom:80%;" />



Un lenguaje superconjunto de JavaScript

Tiene conceptos como (clases,herencia,interfaces ,..) lo que me permite que sea mas escalable.

Escribimos un archivo `.ts` al ejecutarlo se transpila a código JavaScript, entonces podemos integrarlo a proyectos hechos en JavaScript.

* **Lenguaje**   :  sintaxis 
	* Tipos de datos :  bolean, string, etc
	* ES6 sintaxis
	* Sintaxis orientada a objetos :  clases, herencia, polimorfismo 
* **Compilador**
  * Convierte a código `.js`
  * Esta escrito en typescript
  * Sintaxis orientada a objetos :  clases, herencia, polimorfismo 
* **Servicios del lenguaje**
  * Herramientas de autocompletado, información de la función
* Revisión del tipado estático
  * Si hay errores te lo muestra mientras escribes 

Empecemos

## Instalación

Lo primero hay que verificar si tenemos este modulo instalado, para esto nos fijamos en la **RUTA**

> C:\Users\HP\AppData\Roaming\npm\node_modules

Aquí se encuentran todos los módulos que tenemos disponibles para todo el sistema, si no esta procedemos a instalar el módulo de Typescript

````sh
//Ayudin, podemos verificar si lo tenemos con
$ tsc -v

//Para instalar
$ npm install -g typescript
`Notar que en la ruta, ya esta la carpeta Typescript`
````

Si tengo un archivo `.ts` y lo quiero convertir a `.js`

````shell
$ tsc archivo.js
````



## Tipos de datos

````typescript
var testo = "HEllo world"; // El lenguaje infiere que es un string
testo = 22 //Salta error al quere asignar un numero, ya que antes fue declarado como string, posible solucion
testo = 22 +""; // asi mantengo que sea uns tring
````

Es molesto que por cada cambio tenga que estar reiniciando la consola, solución

````shell
$ tsc archivo.js -w
`Esto actualiza el archivo (.js) cada vez que hago cambios en el arhivo (.ts)`
````

````typescript
//STRING
var nombre : string = "Jose";
nombre.split()

//NUMBER
var num : number = 45;

//BOOLEAN
var boo : boolean = true;

//ANY : cualquier tipo de dato
var obj : any = "Hola";
obj = false;

//NUMBER => STRING
num.toString()  // '45'

//TYPEOF: me dice el tipo de dato que es
typeof(45)  // mum
````



### Arrays

````typescript
var colection = ["a","b","c"]
colection = [1,2,3]; //Error en ts

var colection: any[] = [1,"a",true,"c"] //solucion

//puedo especificar el tipo de dato del array
var colnum : number[] = [1,2,3];
````



### Tuplas

````typescript
var tup : [string,number];
tup = ["Helloday",12]; //OK
tup = [12,"Helloday"]; //Error tipo de dato no valido
tup = ["Helloday",12,...];// Error deben tener solo 2 elementos
````



### void undefinid null

````typescript
const PI = 3.1415;
PI = 12 //error

let myVoid : void = undefined;
let myNull : null = null;
let myUndefined : undefined = undefined;
````



### Funciones

````typescript
function getsum(a: number,b:  number):number{
	return a+b;
}
//retorna un numero y los parametros son tambien un numeros

let mySum = function(
	num1: number | string,
    num2, number | string):number {
        if(typeof(num1) === 'string'){
            num1 = parseInt(num1);
        }
         if(typeof(num2) === 'string'){
            num1 = parseInt(num2);
        }
    return num1 + num2;
}

//El simbolo (?) significa parameto opcional
function getName(
	firstName: string, 
    lastName?: string):string{
        if(lastName == undefined){
            return firstName;
        }
    return `${firstName} ${lastName}`;
}

function myVoid():void{
    return 22; //error no estipo void
} 
````



### Interfaces

````typescript
interface Itodo{
    title: string,
    text : string
}

function showTodo(todo: Itodo){
   // return 22;error no estipo void
    console.log(todo.title + ':' + todo.text)
}

let myTodo: Itodo = {
    title: 'Pex',
    text: 'tex'
}

showTodo({
    title: 'HOla',
    text: 'mundo'
})
````



### Clases

````typescript
class User{
    name:string;
    email:string;
    age:number;
    
    //constructor
    constructor(name){
        this.name = name;
    }
    
    //metodo
    register(){
        console.log(`${this.name} esta resgistrado`);
    }
    pay(){
        console.log(this.name + "bien")
    }
}

var john = new User('John');

//tenemos tambien ya sea para atributos o metodos
- public name: string / Disponible para todo
- private / solo se puede usar en la clase no en una instancia
- protected / solo se puede usar en la clase y en las clases que hereden de el

````



### Herencia

````typescript
class Miembro extends User {
    id: number;
	constructor(id,name,email,age){
        super(name,email,age) //hereda del constructor padre
        this.id = id;
    }
    mipay(){
        super.pay() //hereda del padre
    }
    
}
````

