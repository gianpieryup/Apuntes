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

````python
# (rt : r lectura, t : texto)
fichero = open("nobreDelArchivo.txt","rt")
datos_fichero = fichero.read()
print(datos_fichero)

# crear y/o guardar informacion en un archivo
# (wt : w escritura, t : texto)
fichero = open("fichero_para_grabar.txt","wt")
cadena_texto = "Hay que bonito soy"
fichero.write(cadena_texto)
fichero.close() #cerramos el fichero, para que mas adelante se pueda abrir

# Agregar info al archivo
# (at : a append, t : texto)
fichero = open("fichero_para_grabar.txt","at")
cadena_texto = "\n nueva linea"
fichero.write(cadena_texto) # lo agrega al final
fichero.close()

# Borrar un fichero de texto
import os
os.remove("fichero.txt")
````

## Sección 11 : Ficheros binarios

````python
import pickle	#Modulo para manejar ficheros binarios
lista = ["rojo", "axul"]
fichero = open("archivo.pckl","wb")
pickle.dump(lista,fichero)
fichero.close()

# Leer datos de un fichero binario
fichero = open("archivo.pckl","rb")
lista_leida = pickle.load(fichero)
print(lista_leida)

#Que onda con este guardado, Fijate que se guarda como un diccionario osea que cuando lo vuelva a leer sera un array y no una cadena de texto '[1,2,3]' 
````

## Sección 12 : Gestión de errores

````python
# try ... except ... else .... finally

# Si se produce algun error en el bloque 'try' se ejecuta el bloque 'except'
try:
	n1 = 5
    n2 = 0
    div = 5 /0
    print(div)
except:
	print("Ha habido un error")

    
#Podemos especificar que 'except' puede ser
try:
	n1 = 5
    n2 = 0
    div = 5 /0
    print(div)
except ZeroDivisionError:	#Si coincide con este tipo de error
    print("Error, division entre cero")
except:    #Si es otro error distinto al de arriba
	print("Ha habido un error")
   

#En case de que no haya error en el bloque 'try' se ejecuta 'else'
try:
    #...
except:
    #...
else:
    print("la division funciono correctamente")
    

# finally  : Permite ejecutar un codigo independiente del 'try' y del 'except' 
try:
    #...
except:
    #...
else:
    #...
finally:
    print("Esta prueba try se ha acabado")
````

## Sección 13: Expr Reg, JSON, fecha y hora