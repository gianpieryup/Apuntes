/*Algunas consideraciones
Si quiero un campo vacio ponerle ('' o "") al valor
Aveces se rompe la sintaxis por las 'tabs' o los espacios 
Fijate con el icono "mostrar todos caracteres"

*/
use usuarios
show collections
db.usuarios.find()
db.usuarios.remove({})

db.usuarios.insert([
	{
	  "name" : "jose",
	  "edad" : 23,
	  "foto" : "",
	  "estado" : 1,
	  "fechaRegistro" : new Date()
    },
    {
      "name" : "pedro",
      "edad" : 19,
	  "estado" : 0,
	  "fechaRegistro" : new Date(2019,11,11)
    },
	{
      "name" : "juan",
      "edad" : 18,
	  "foto" : "juancito.jpg",
	  "fechaRegistro" : new Date(2020,2,3)
    },
	{
      "name" : "pablo",
      "edad" : 17,
	  "estado" : 1,
	  "fechaRegistro" : new Date(2020,1,13)
    },
	{
      "name" : "pablo",
      "edad" : 27,
	  "estado" : 0,
	  "fechaRegistro" : new Date(2020,2,1)
    },
	{
      "name" : "estebanquito",
      "edad" : 21,
	  "estado" : 1,
	  "fechaRegistro" : new Date(2019,12,31)
    },
	{
      "name" : "maria",
      "edad" : 32,
	  "foto" : 0,
	  "estado" : 0,
	  "fechaRegistro" : new Date(2020,1,15)
    }
]) 


//Ejercicios Resueltos
a. Imprimir todos los usuarios de la plataforma
db.usuarios.find().pretty()

b. Recuperar los primeros 5 usuarios que tengan mas de 18 años.
db.usuarios.find(
	{
		"edad" : { $gt : 18}
	}
).limit(5)

c. Mostrar los usuarios de nombre : 'pablo' y con estado : 1
db.usuarios.find({"name" : "pablo", "estado" : 1})

d. Mostrar usuarios con edad mayor a 20 y que no tenga foto asociada
db.usuarios.find(
	{
		"edad" : { $gt : 20},
		"foto" : { $exists: false}
	}
)
//Los usuarios que no tienen el 'atributo' foto directamente

e. Mostrar los usuarios ordenados por edad desc que cumplan nombre : 'pablo' y edad entre 20 y 30
db.usuarios.find(
	{
		"edad" : { $gt : 20 , $lt : 30},
		"foto" : { $exists: false}
	}
).sort({name :-1})

f. Actualizar los usuarios que tengan estado 0 a 1, que cumplan las condiciones :  mayores a 20 años y tengan foto asociada
db.usuarios.update(
	{
		"edad" : { $gt : 20},
		"foto" : { $exists: true},
		"estado" : 0
	},
	{
		$set: { "estado" : 1 }
	}
)

g. Borrar todos los usuarios cuyo estado sea 0 y la fecha de registro sea dos meses menor a la actual.
//En mongo se guarda las fechas en milisegundos
var miCursor = db.usuarios.find();
    
while (miCursor.hasNext()){
	let dias = (new Date() -  miCursor.fechaRegistro)/(1000 * 3600 * 24)
	if( dias < 2*30 ){
		printjson(miCursor);
	}
	miCursor.next()
};

  


h. Eliminar un usuario por mail

i. Actualizar todos los datos de un usuario filtrando por ID


