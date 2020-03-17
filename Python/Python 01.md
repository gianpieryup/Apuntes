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

#
is is not
````









