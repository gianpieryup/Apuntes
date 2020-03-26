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
#Puedo simplificar, si quiero multiples
from modulo import (suma,resta,mul)

--#Puedo importar todos con la misma forma
from modulo import *

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

#### Archivos py

Cuando importamos un modulo en otro archivo se creara una carpeta llamada `__pycahe__`  que seria el modulo compilado a código binario. Esto facilita ya que no estará compilando a código maquina a cada rato, si no leera el archivo ejecutable

Este archivo se crea cuando ha sido importado por primera vez o cuando el modulo a sido modificado.

#### Atributo `__name__`

A diferencia de `C` no tenemos una función principal `main` ,podemos reconocer cual es el archivo que se esta ejecutando

````python
if __name__ == '__main__':
    print("Yo soy el archivo principal")
else:
    print("Esto como modulo")
````

#### Paquetes

Es un folder o carpeta que tiene muchos módulos. Empecemos, debemos crear un archivo llamado `__init.py` junto con todos los módulos(`aves.py` e `felinos.py`) en la misma ubicación. Todos estos archivos los guardo en una carpeta ,ejem `animales`

En el archivo principal importo la carpeta animales

````python
# from elPaquete.elarchivo
from animales.aves import Pinguino
pinguino = Pinguino()
````

Y que pasa con el archivo `__init.py` esta en blanco?? . Lo podemos rellenar

````python
# En __init.py
print("Este es un mensaje de init")
#Osea esto siempre se ejecutara siempre que se importe el `paquete` animales
# Podemos poner todos los imports en este archivo 
# Podemos poner la conexion a la base de datos asi no tengo que hacerlo en cada modulo
# Podemos definir funciones
````

#### Anotaciones

Las anotaciones son **únicamente de carácter informativo**

````python
def saludo(nombre : str )-> None:
	print("Hola" + nombre)
    
#Informamos que es 'str' un string
#Podemos especificar los siguientes: str,int,float y bool
#Informamos el tipo de dato que retorna (->)
#None : como void
def suma(num1 : int,num2 : int = 100)-> int:
    return num1+num2
print(suma(56.8)) #Puede recibir cualquier tipo
````

#### comprehension

````python
lista = []

for x in range(0,101):
    lista.append(x)
print(lista)

#PODEMOS obtener el mismo resultado en menos lineas
# Dependiendo puede ser [],() o {}
# ['valor a almacenar' | 'ciclo']
estructura = [x for x in range(0,101)]
print(estructura)

# Tuplas
# ['valor'|'ciclo' |'condicion']
estructura = tuple((x for x in range(0,101) if x % 2 == 0 ))
print(estructura)

#Utiliza esta forma cuando es simple el algoritmo
# Diccionario
dic = {indice:valor for indice,valor in enumerate(estructura)}
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

### Expresiones Regulares

Como en JavaScript con la librería 're', ``ver apunte de E.R. en javascript`

````python
import re
texto = "Hola , mi nombre es antonio"
resultado = re.search("nombre",texto)
# 'resultado' es un objeto con informacion de la busqueda
# resultado.start() / resultado.end()
if (resultado):
    print("cadena encontrada")
else
	print("cadena no encontrada")
    
# ---
re.search("antonio%",texto)
re.search("^Hola",texto)

# el caracter (.) es cualquiera, el (*) es una o mas repeticiones
re.search("mi.*es",texto)

----
# findall : busca todas las ocurrencias que halla, y las muestra en un array
texto = """
El coche de Luis es rojo,
el coche de antonio es blanco,
y el coche de maria es rojo
"""

re.findall("coche.*rojo",texto)

# split: cortar bajo un separador
re.split("\n",texto)

# sub : sustituye todas las coincidencias
re.sub("la palabra que queremos cambiar","el nuevo valor",texto)
````

### JSON

Convertir datos de un diccionario a JSON

````python
# Diccionario
products = { "nombre" : "silla" , "color" : "rojo" , "precio" : 80}

# comvierte un diccionario en formato JSON
import json
estructura_JSON = json.dump(products)
estructura_JSON[0]

# JSON => Diccionario
products2 = json.loads(estructura_json)
products2["nombre"]
````

### fecha y hora

````python
from datetime import datetime
fechaHoy = datetime.now()
print(fechaHoy)

# Los metodos
.year		.hour
.month		.minute
.day		.second			.microsecond
````

## Sección 14: Base de datos

````python
# SQlite : sistema de gestion de base de datos
import sqlite3
# Nombre de la base de datos si existe de lo contrario lo crea
conexion = sqlite3.connect("mydatabase.db")

#Para ejecutar sentencias sql con `execute`: SELECT, INSERT,UPDATE,DELETE
cursor = conexion.cursor()
cursor.execute("CREATE TABLE personas(nombre TEXT,apellido TEXT,edad INTEGER)")

#Para comitear los cambios
conexion.commit()
conexion.close()
````

#### Insertar varias filas a la vez

````python
cursor = conexion.cursor()
lista = [('Pedro','Rodrigez',26),('Maria','Lopez',45)]

cursor.executemany("INSERT INTO PERSONAS VALUES (?,?,?,?)",lista)
conexion.commit()
conexion.close()
````

Algunos ejemplos



## Sección 15: Interfaz gráfica con el módulo tkinter

Vendría a ser como el `Windos form de C#`

````python
import tkinter
raiz = tkinter.Tk()
raiz.title("Mi programa") #Este es el titulo del cuadro,no en el contenido

raiz.mainloop()
````

## Sección 16: Generar documentación automáticamente

#### Docstrings

````python
def saludar(nombre):
    """
    Este texto de ayuda aparecera si ejecuto(**)
    """
    print("Hola", nombre)

(**) help(saludar)

class Saludos:
    """
    Texto sobre la clase
    """
    def m(self,nombre):
        """Sobre la funcion"""
        print(nombre)
        
(**) help(Saludos)        
````

#### pydoc

Generar documentación automática desde la consola o terminal

````shell
Sale en la terminal
$ pydoc ruta_del_fichero

Se genera un archivo .html con la documentacion
$ pydoc -w ruta_del_fichero

Para salir Crtl + z  ó q
````

## Sección 17 - Pruebas Automáticas

#### Doctest

Generar pruebas dentro de la documentación, se ponen en el operador `>>>`

````python
def sumar(num1,num2):
	"""
	Esta es la documentacion de la funcion
	Recibe dos parametros y devuelve la suma
	
	>>> sumar(4,3)
	7
	
	>>> sumar(5,4)
	9
	
	>>> sumar(1,3)
	7
	
	"""
    return num1+num2

resultado = sumar(2,4)
print(resultado)

#Para que se ejecute las pruebas
import doctest
doctest.testmod()

-----------------------------------------
#En la terminal, no olvidar (-v) para ejecutar las pruebas
$ python sumar.py -v
````

#### Unittest

Sirve para crear pruebas dentro del propio código

````python
def multiplicar(num1,num2):
	return num1*num2

import unittest
class pruebas(unittest,TestCase):
    def test(self):
        self.assertEqual(sumar(2,4,8))
        
if __name__ == '__main__':
    unittest.main()
````



## 18 - Funciones Avanzadas

#### Funciones Generadoras

````
range(4) //empieza de 0

range(0,4) //de 0 a 4

ramge(0,9,2) // de 0 a 9 , saltando de a 2s
````

#### Filter

````python
# La 'funcion' retorna un booleano
lista_filtrada = filter(funcion,lista)
resultado = list(lista_filtrada)
````

#### Map

````python
# La 'fucion' debe retornar algo
lista_mapeada = map(funcion,lista)
resultado = list(lista_mapeada)
````

> TIP : Al contrario de crear una `def funcion: ...`  Usamos una función lambda

````python
lista_res = list(map(lambda num : num *2),lista)
````









