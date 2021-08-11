<p align="center"><img src="http://navent.com/es/wp-content/uploads/Navent-isologo.svg" width=200px></p>

# Desafio-Navent-FrontEnd

### 1)
 Realizar el maquetado del siguiente diseño utilizando HTML, CSS y Javascript. Se pueden utilizar librerias como jQuery o sliders.
El bloque en horizontal deberá ser adaptable hasta su ancho mínimo y luego convertise a modo vertical utilizando los mismos elementos
html logrando la completa transformación con css.
El slider de fotos deberá ser adaptable en la versión vertical.
Aplicar galería de íconos FontAwesome y de tipografía Roboto (webfont de google).
### Respuesta
Cumpli con todos los requisitos del enunciado. Use bootstrap y Jquery , use la estrategia Mobile First .

### 2)
Al hacer click en el ícono del corazón, este tiene que cambiar de color y guardar su estado de forma local de modo que al recargar la
página este elemento siga teniendo el color del relleno.
### Respuesta
El corazon lo saque de FontAwesome , la estado del corazon se guarda el localStorage con la clave `color` .

### 3)
 El precio del aviso tiene que hacerse editable al hacer click sobre el número. Al guardarse un nuevo precio, el valor por metro cuadrado
($/m2) debe modificarse de forma automática en base a la medida indicada. Los datos deben mantenerse al recargar la página.
### Respuesta
Al presionar el precio del aviso se despliega un `modal de boostrap` para editar el precio, con validacion de que el campo no este vacio.

### 4)
Haciendo clic en el botón “contactar” se abrirá un formulario (adaptable) para incluir el e-mail. Este podría tener un label animado y
ser validado mediante Javascript mostrando un mensaje de error o éxito según sea necesario
### Respuesta
Al presionar el botom `contactar` se  despliega un `modal de boostrap` para rellenar un mail, con validacion de que no este vacio y que tenga formato email por `Javascript`.
