#### Consumir de una api

````javascript
fetch("http://laruta de la api")
 .then(function(res){
    retunr res.json();
 })
 .then(function(data){
    // Toda la magia que quieras con 'data'
 })
 .then(function(error){
    console.log('El error es:' + error);  
 })
````

#### Mandar una petición

````javascript
fetch("http://laruta de la api",{
    method:'POST',
    body: datosFormulario
 })
 .then(function(res){
    retunr res.text();
 })
 .then(function(data){
    // La magia que quieras hacer con la respuesta
 })

// Que va en [datosFormulario]
var campos={nombre:"ada", apellido:"lol"}
var datosFormulario= new FormData();
datosFormulario.append('datos',JSON.stringify(campos));
/ Esto ultimo hace que se guarde en POST[datos] la info de campos /
````

