## Sección 9 : Módulos

Es un fichero que tiene funciones que luego las importo en mi archivo original.

````python
# Modulo
## modulo.py
def saludar(nombre):
	print("Hola " + nombre)

class Persona:
    def __init__(self,nombre):
        self.nombre = nomre
----------------------------
# Mi fichero
# Importar todas las funciones y clases del fichero 'modulo'
import modulo
modulo.saludar("Jorge")
usuarioP = modulo.Persona("Pedro")

# Importar solo una funcion o clase del fichero 'modulo'
from modulo import saludar
saludar("Jorge")

#opcional renombrar la funcion
from modulo import saludar as quehay
````

### PIP

Gestor de paquetes y módulos para python, `en node era npm`

````shell
Para ver si lo tenemos
$ pip --version

Paquetes y modulos instalados
$ pip list
````

Como importar un modulo nuevo

````shell
$ pip install camelcase
````

````python
import camelcase
came1 = camelcase.CamelCase() #Objeto de la clase, una instancia
texto = "mi nombre es antonio"
print(came1.jump(texto))
````

Podemos desinstalarlo si ya no queremos el modulo

````shell
$ pip uninstall camelcase
````

## Sección 10 : Ficheros de texto