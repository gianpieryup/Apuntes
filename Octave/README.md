<p align="center"><img src="gnu-octave-logo-cutout-svg.png" alt="gnu-octave-logo-cutout-svg" width="200px" /></p>


El instalador es el ejecutable  `octave-5.1.0-w64-installer.exe` en la pagina de Octave.

Se creara 2 iconos uno (CLI) y el otro (GUI) son lo mismo pero uno es por `consola` y el otro tiene `interfaz de usuario`

Obviamente usaremos el "GUI"
- Funciona como una calculadora normal

### Introducción

#### Definir variables

 ````octave
var = 7
 ````

- Las variables expiran cuando cierras el programa.
- Como se el valor de una variable 

#### Operador punto y coma `;`

````octave
4 +5 ; 
%Esto le dice a Octave que ejecute la sentencia, pero que no nos devuelve nada por pantalla
````

#### Exponentes 

````octave
2^5 %Tambien se usa  2**5
ans = 32
````

#### Booleanos

Por `convencion` : true (1) o false (0)

#### Comentarios

````octave
#...comentario...
%...comentario...
````

#### Cadenas de caracteres

````octave
# Imprime por consola
disp(c)
disp("HELLO WORLD")
````

#### Borrar

````octave
% Borra todas las variables guardadas
clear

% Borra la consola
clc
````

### Editor de Programas

Veamos el `Editor` podemos guardar nuestros algoritmos en un script `extension .m`
Tenemos que seleccionar el directorio en donde esta el archivo `.m`

````octave
%Si nuestro archivo se llama suma.m:
var1 = 3;
var2 = 5;
var1 + var2
````

Para invocarlo en la consola solo necesitas su nombre

````octave
suma
ans=8
````

También podemos ejecutar nuestros scripts en la ventana `Editor` que se encuentra abajo, <span style="background:yellow;">no olvidar</span> la dirección del script debe estar a la izquierda

### Vectores

O matrices de dimensión 1 x n

````octave
u = [-2 3 1] % con espacios como separacion
u = [-2, 3, 1] % con comas como separacion

%Posición y valor del elemento del vector
u(1)
ans = -2

u(2)
ans = 3

a = zeros(1,7)
a = [0,0,0,0,0,0,0]  % Matriz de 1x7 echa de `ceros`

b = ones(1,4) % Matriz de 1x4 echa de `unos`
length(b) % Cantidad de columnas de una `matriz`
ans = 4
````

#### Concatenar

````octave
x = [3 4 7 11]
y = [1 5 6]
[x y] = [3 4 7 11 1 5 6]
````

#### Operaciones con Vectores

````octave
u + v % Deben tener la misma dimension
u - v 
u * w % Producto escalar
% Aclaracion:El producto escalar de dos vectores se tiene que dar con un vector fila y otro columna.
````

#### Transpuesta

````octave
% Si nesecito transponer un vector usamos el simbolo ( ' )
v = [-2 3 1]
v'
ans =
  -2
   3
   1
````

#### Matrices

Se definen como vector de vectores con la misma longitud

````octave
u = [2 1 0]
v = [-2 3 1]
w = v'
A = [u ; v; w'] % Donde u v y w' son vectores fila de igual longitud
A = [1,2,3;4,5,6;7,8,9] % Pasa a la siguiente fila con el signo (;)
````

#### Operaciones con Matrices

````octave
A'       # Transpuesta de la matriz A
inv(A)   # Inversa de la matriz A 
A(2,3)   # Valor de la posicion fila = 2 y columna = 3

size(A)  # Tamaño de la matriz A
f c      # filas #columnas

A(:,1)   # Traeme todo las filas (:), de la columna 1
A(1,:)   # De la fila 1 y traeme todas las columnas

eye(4) 	 # Matriz identidad de 4x4
5*eye(3) # Matriz identidad d 3x3

A * B    # Producto de matrices
A .* B   # Producto de elemento con elemento

#Ejemplo: De la operacion con (.)
|1	2| .* |1  2| = |1  4|
|3	4|	  |0  1|   |0  4|

A ./ B   # Division
A .^ B   # Analogo con los exponentes
A .^ 2   # Cada elemento elevado al cuadrado
````

#### BONUS

````octave
% Existe una forma alternativa de definir una Matriz
A(1,2)=7   % Esta asignacion crea una matriz con el valor en la posicion
	0	7  % Rellena las demas posiciones con 0
	0	0
A(2,1)=1
	0	7
	1	0
A(3,2)=5
	0	7
	1	0
	0	5
````

### Rangos 

#### Operador (:)

````octave
# (La base : limite) % intervalo con incremento de (+1)
3:8
ans = 3 4 5 6 7 8

# (La base: el incremento : el límite)
1 : 3 : 5
ans = 1 4

# linspace ( base , límite , n )
% Devuelve un vector de fila con n elementos linealmente espaciados entre la base y el límite .
inspace(0,2,6)
ans =
 0.00000   0.40000   0.80000   1.20000   1.60000   2.00000
````

### Inputs

````octave
# La consola te pedira que ingreses un valor y + `Enter` guardara ese valor en 'b'
b = input('Introduce unn valor: ')

# Tipo de inputs
# Por defecto sin modificadores espera un valor `numerico`
# Si le agregamos el modificador "s" ,ahora solo espera un 'string'
c = input("Nombre del usuario: ","s")
# I genera un error: si intentamos mandarle un numero
````



### Funciones matemáticas elementales

````octave
o sin(x) : seno
o cos(x) : coseno
o tan(x) : tangente
o asin(x) : arco seno
o acos(x) : arco coseno
o log(x) : logaritmo natural
o log10(x) : logaritmo decimal
o exp(x) : función exponencial
o sqrt(x) : raíz cuadrada
o round(x) : redondeo hacia el entero más próximo
o fix(x) : redondea hacia el entero más próximo a 0
o floor(x) : valor entero más próximo hacia -∞
o ceil(x) : valor entero más próximo hacia +∞
o gcd(x) : máximo común divisor
o lcm(x) : mínimo común múltiplo
o real(x) : partes reales
o imag(x) : partes imaginarias
o abs(x) : valores absolutos
o angle(x) : ángulos de fase
````

### Condicionales y Bucles

#### Sentencia IF

````octave
# Una sola sentencia
if (condition)
	then-body
endif
----
if (condition)
	then-body
else
	else-body
endif
----
# E probado y tambien funciona el `endif`->`end`
````

### Definición de Funciones

Por convención son archivos externos `.m` con nombre de la función

La primera línea de un fichero llamado `name.m `que define una función tiene la forma:

````octave
function [lista de valores de retorno] = name(lista de argumentos)
````

donde name es el nombre de la función. Entre corchetes y separados por comas
van los valores de retorno (siempre que haya más de uno), y entre paréntesis también
separados por comas los argumentos. Puede haber funciones sin valor de retorno y
también sin argumentos. Recuérdese que los argumentos son los datos de la función y
los valores de retorno sus resultados. Si no hay valores de retorno se omiten los
corchetes y el signo igual (=); si sólo hay un valor de retorno no hace falta poner
corchetes. Tampoco hace falta poner paréntesis si no hay argumentos.

### Funciones con varias salidas

```octave
function [x, y] = ceroyuno ()
 x = 0;
 y = 1;
endfunction

% Para invocar es de la siguiente forma
[cero,uno] = ceroyuno ()
```

#### TIP

A mi me paso que <span style="background:yellow;">cuando copie las funciones de la guia directamente en la terminal se me quedo el cursor al final</span> y no importaba cuantos <kbd>Enter</kbd> presionase no salía de la definición de la función por lo que use <kbd>Ctrl + C</kbd> para salir.

La RESPUESTA era que le faltaban 1 `end` en todas las funciones, por tanto una forma de arreglarlo es escribiendo `end` + <kbd>Enter</kbd> . 

### Graficas de funciones

Para graficar funciones en 2D usamos la función `plot()`

````octave
% plot(eje X, eje Y) crea un gráfico a partir de vectores. Ósea:
vect1 = [1,2,3,5]
vect2 = [3,5,7,11]
plot(vect1,vect2)
````

#### Grafica del coseno

````octave
x = linspace(0,2*pi,100); # Dominio de valores
y = cos(x); # Definicion de funcion
plot(x,y);  # Mostrar grafica
````