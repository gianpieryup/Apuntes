Lenguaje Imperativo: Se lee lineá por lineá

#### TIPS

````javascript
// PROBLEMAS
// Poner el <script> en el head y no al final del body/ esto se arregla con
window.onload = function(){
    "Todo el codigo"
}
// ONLOAD: espera que carge primero el html para ejecutar el .js
````

#### Eventos mas comunes

````javascript
.onclick
.ondbclick
.onmouseover  y  .onmouseout  // salir y entrar, el cursor
.onmousemove
.onscroll
.onload
.onfocus

//EJEMPLO
elDIv.onmouse = function(evento){
    console.log(evento.clientX); //El eje X donde esta el cursor
}
````

#### THIS: Podemos hacer referencia al objeto

````javascript
elDiv.onclick = sayHello;

function sayHello(){
  this."lo que quieres bebe"; // hago referencia a lo de arriba
}
````

#### Si quiero evitar que se dispare un evento por defecto

````javascript
<a href="">Click on me</a>
var btn = document.querySelector('a');
btn.onclick = function(e){
    alert('Hi here');
    e.preventDefault();//ACA PRIMO
}
````

#### Contador y/o Timer

````javascript
// Solo se ejecuta una vez
var mi = setTimeout(are,3000); // Los parametros son [funcion,tiempor en milisegundos]
function are(){
    alert('Areee');
}

// Se ejecuta MUCHAS VECEZ
var mi = setIterval(fn,del); // [funcion,tiempor de espera para ejecutar el callback]


//COMO PARAR LOS TIMERS: Para cada caso
clearTimeout(elvar);
clearInterval(elvar);
````

