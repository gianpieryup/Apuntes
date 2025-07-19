# JavaScript ES6 ++

Este documento se mantendrá actualizado, dado que ya existen ES7, 8, 9

Ultima versión <span style='color:blue'>*8/03/2020*</span>

Para funciones anónimas, "callbacks"



## Funciones Flecha (ES6)

Para funciones anónimas, "callbacks"

````javascript
function(){
    console.log('Hola coder');
}

---------
`(ÈS6)`
() => {
    console.log('Hola coder');
}
````

No olvidar

````javascript
//Cuando es una sola linea el *return*
(a,b) => {            	|	
    return a+b;			|	(a,b) => a+b
}						|
    
//Si hay un solo parametro
(a) => a + 10    		|	a => a + 10

//Podemos usarlo en 'setTimeout(callback.delay)'
setTimeout(()=> {
    console.log("Termine")
},2000);
//Se lee, en dos segundos ejecuta el los 'Termine'
````



## Tilde Invertida (``) (ES6)

Podemos juntar lo **dinámico**: `las variables,const,...` con Strings dentro de este operador con la siguiente sintaxis.

````javascript
let namae = "Eduardo";
console.log(`El usuario se llama ${namae}`);
````

