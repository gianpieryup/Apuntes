<img src="Python-logo.png" alt="Python-logo" style="zoom:25%;"/>

# Introducción a Python

### Ejecutar un programa en Python

1. Si tienes Python instalado, como lo se ? . En la terminal poner   `python --version`
   Por consola: Escribir  `python`  +  <kbd> Enter </kbd> . Te quedara un símbolo.

   > *>>>*  'Aquí puedes escribir código python'

   Para salir de la consola.

   > *>>>* exit()

2. Si quiero ejecutar un archivo.py , primero estar parado por consola en la ubicación del archivo.

   > *>* python archivo.py

3. Usando **Anaconda** / Júpiter Notebook



## Variables y Números

Sensible a mayúsculas para declarar variables.

````python
var1 = "Hola "
var2 = "Mundo"
conca = var1 + var2
> conca
"Hola Mundo"
````

```python
a = 3
> type(a)  # hallar el tipo de dato de la variable
int

b = 3.7
> type(b)
float

> a + b  # Como en C# convierte implicitamente (a) de (int -> float)
float
```



## Conversión de Tipo de dato

````python
num = 5
cadena = str(num) # Coversion a cadena
> cadena
'5'
> "Hola" + num //error => str(num) ok

cadena = '25'
num = int(cadena) # Conversion a entero
> num
25

cadena = '25.7'  # Ojo aca la variable no es int, recordar
num = float(cadena) # Conversion a decimal
> num
25.7
````


## Cadena de Texto

````python
cadena = "Hola Mundo"
> cadena[0] # 0 -> H / 1 -> o / ...
'H'
> cadena[-1] # -1 -> o / -2 -> d /... (Es un recorrido inverso)
'o'
> cadena[2:7] # Desde la pos 2 (inclusive) hasta la 7 (no se incluye la 7)
'la Mu'
> cadena[2:] # Todo a partir de la posicion 2
'la Mundo'
````

### Funciones de cadenas

````python
cadena = "Hola Mundo"
longitud: len(cadena)
    
mayusculas: cadena.upper() # solo muestra
cadena = cadena.upper() # si quiero modificar

minusculas : cadena.lower()
    
cadena.split()
["Hola","Mundo"]

cadena2 = "hola,mundo"
cadena2.split(',')
````

### Imprimir variables de cadena de texto

````python
nombre = 'Julio'
print("hola"+nombre)

print("Hola {}, feliz {}",format(nombre,"cumple"))

res = 10/3
print("acotado : {r}",format(r=res))

#Un entero y 3 numeros decimales
print("acotado : {r:1.3f}",format(r=res)) 

#python 3.6 + como en js con (``)
print(f"Hola {nombre} como esta la familia")
````

### Entrada texto por teclado

````python
print("Introduce tu nombre")
entrada = input()
print(entrada)
````

### Operadores

````python
resto(%), potencia(**) , cociente (//)

#a = a + b   // a += b
(*=,/=,**=,//=)

(==,!=,<,>,>=,<=)

(and, or, not)

#para comparar objetos: 'is'
var1 = [1,3]
var2 = [1,3]
var1 is var2
true

#'is not' la negacion de 'is'

# operadores de Pertenecia
lista is elemento
lista is not elemento
````



### Colección de datos

#### Listas

````python
x = ["hola",2020]
x[0] = "hola"
numberlist = list((1,2,3,4)) #list() solo recibe un argumento

x.append("naranja")
> ["hola",2020,"naranja"]

x.remove("hola")
> [2020,"naranja"]

x = list(range(1,10)) => x = [1,2,3,4,5,6,7,8,9]

#Recorrer una lista con (for in)
for color in colores
	print(color)
    
#Borrar todos los elementos
x.clear()

#existen mas funciones
````

#### Tuplas

Una colección de elementos que no se pueden alterar.

````python
x = (1,2,3)
x[0] = 1
````

#### Conjuntos

Una colección de elementos desordenados(sin índices)

````python
conj_color = {"rojo","verde","azul"}
conj_color[0] #Error
conj_color.add("negro")
````

#### Diccionario

````python
#como un json (clave:valor)
dic = {'color':'rojo', 'tipo':'toyotas'}
dic['color'] = 'rojo'
dic['black'] = 'negro' #Agregar elementos
dic.pop['tipo'] #Borra este elemento y devuelve su valor 'toyotas'
del(dic['tipo']) #alternatica de borrar

for clave in dic
	print(clave)
    
for clave,valor in dic.items()
	print(clave,valor)
````

### Bucles y Condiciones

#### if-else

````python
if(3 > 4):
    print("3 es mayor que 4")

if (a > b) and (b < d):
    print("hola")
    
if 'condicion' :
    |#codigo
else
	print("en el else")
    
if 'condicion' :			|	if (){
    #codigo					|	#cofigo
elif (a == b)				|	}else{
	print("son iguales")	|		if(a == b){
else						|		print("son iguales") 
	print("ninguna")		|		}else{
    						|		print("ninguna")
							|		}
							|	}		
````

#### Bucles

````python
# FOR
for elemento in lista:
    print(elemento)

# Funcionan el break y el continue  

# WHILE
while (condicion):
    print("aun estoy en el while")
````

#### BONUS

````python
# La funcion 'range'
range(valorinicial,valorfinal,intervalo?opcional)
range(3,8,2)
3
5
7
````

### Clases objetos y Funciones

#### Clases

````python
class Clasesilla:
	color = 'blanco'
	precio = 100
    
obj = Clasesilla() #instanciar un objeto
obj.color #funciona como 'get' y 'set'

class Persona:
    #Constructor
    def __init__(self,nombre,edad):
        self.nombre = nombre
        self.edad = edad
    #Metodo
    def saludar(self):	#NO OLVIDAR el 'self'
        print("Hola me llamo",self.nombre)
        
persona1 = Persona('Juan',37)  
persona1.saludar()     
````

#### Funciones

````python
def saludar():
	print('BUenas dias')
    
def saludar(nombre):
	print('BUenas dias' + nombre)   
#No admiten Sobrecarga admitida, se toma la ultima definicion

#USO del Return
def sumar(num1, num2):
    suma = num1 + num2
    return suma
print("Operacion 4 + 5 = ",sumar(4,5))

------------------------------------
#Paso por valor , Paso por referencia
colores = ["rojo", "verde", "azul"]
def incluir_color(colores,color):
    colores.append(color)
    
color = "negro"
incluir_color(colores,color)
colores
#Se modifico la lista
````

> TIP : Como en la guía de C# los objetos y los Arrays siempre se pasan por referencia OJO

##### Función Lambda

````python
resultado = lambda numero : numero + 30
resultado(10)

resultado2 = lambda nume1, num2 : num1 + num2
resultado2(10,20)
````

