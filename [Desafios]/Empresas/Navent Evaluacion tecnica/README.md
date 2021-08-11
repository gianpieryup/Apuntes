# Desafio-Navent
## Pasos De Instalacion
1. Descargar el repositorio
2. Usamos XAMP asi que mueva la carpeta a htdocs
3. Prenda el apache y busque el proyecto por el navegador (index.html)

## 1)
Se desean modelar los Pedidos realizados por un cliente. Las operaciones que se necesitan son: crear pedidos, modificar pedidos, buscar pedidos por id, y borrar pedidos. Se pide modelar un servicio que implemente estas operaciones (en lenguaje Java) sabiendo que se utiliza una estructura de caches para no acceder a la base de datos en cada operación solicitada a este servicio backend. El servicio es utilizado en un sitio web, con usuarios concurrentes. Tomar como ya implementadas las clases BumexMemcached y PedidosDAO, descritas más adelante."
### Respuesta
No tengo mucha practica en Java en este momento, por eso use PHP en la menor cantidad que pude. Estoy dispuesto a aprender y por la base de programacion que tengo (OOP,C++,PHP) creo poder aprender rapidamente las sintaxis de este lenguaje.
- Use fetch para guardar pedidos sin recargar la pagina
- Cree una vista para modificar el pedido seleccionado (Presione el botom modificar)
- Cree un botom borrar, que borra un pedido

## 2)
Suponiendo que la tabla Pedidos tiene muchos registros y columnas (algunas de ellas nullable, algunas BLOB / "binary-large-object"), que consideraciones se deberían tener en cuenta para realizar desde un sitio web consultas a la base de datos de manera eficiente? Discuta performance a nivel motor de base de datos, networking, capa aplicativa desde donde se realizan las solicitudes, entre otros aspectos que considere relevantes.

### Respuesta
Como La Base de Datos tiene una sola tabla, la de Pedidos escogi una Base de Datos No Relacional (JSON) y como seguiriamos teniendo una sola tabla seguiria con un BD no relacional, la ventaja de esta ultima es su performance cuando hay una cantidad de datos masivos y la ineficacia de usar una BD relacional (mySQL) para una sola tabla sin relacion alguna. Podiamos usar otras BD no relacional como Mongo DB.  

## 3)

Implemente en una página HTML con el código javascript correspondiente el formulario para guardar un Pedido a través de una invocación AJAX a la URI /pedidos/guardar. Aplicar las siguientes validaciones a los campos:
- nombre es un campo obligatorio y no puede superar los 100 caracteres
- monto es un campo obligatorio del tipo integer
- descuento es un campo del tipo integer

### Respuesta
Las validaciones se hicieron a traves de javascript y las invocaiones AJAX a traves de fetch.
