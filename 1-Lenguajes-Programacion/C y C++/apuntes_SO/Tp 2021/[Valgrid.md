# VALGRID

Valgrind es un conjunto de herramientas libres que ayudan en la depuración de problemas de memoria y rendimiento de nuestras aplicaciones.

````javascript
valgrind <parámetros> <miPrograma> <argumentos>
````

Ejemplo

````c
valgrind ./ej1
````



**Ejemplo 1: “Invalid write of size…”**

````c
char * arr = malloc(5);
arr[5]='J';
````

**Ejemplo 2: Free**

Debemos tener igual cantidad de **allocs** y **frees**

````
==6789== HEAP SUMMARY:
==6789== in use at exit: 5 bytes in 1 blocks
==6789== total heap usage: 1 allocs, 0 frees, 5 bytes allocated
==5263== 
==5263== 5 bytes in 1 blocks are definitely lost in loss record 1 of 1
````

Tipeamos en consola `valgrind --leak-check=yes ./ej1` para detectar los memory leaks. 

*Heap* es un área grande de memoria libre sin usar. En otra palabra, a donde recurrimos al momento de reservar memoria dinámica.

En la quinta línea nos dice que *perdimos* **definitivamente** *5 bytes en un bloque de memoria*. Claramente tenemos que arreglarlo.

USAR EL FULL ES MUY BUENO





#### Final luego de corregir

Si volvemos a correr valgrind, veremos que nos dirá *“All heap blocks were freed -- no leaks are possible”.* En otras palabras, no tenemos más leaks.



**Ejemplo 3: “Conditional jump or move depends on uninitialised values”**

````c
#include <stdio.h>
int main(void){
	int a;
	printf("a = %d \n", a);
	return 0;
}
````

*El kernel de Linux se encarga de llenar la memoria con ceros* *(por lo que nuestras variables no inicializadas siempre tendrian 0) pero POSIX en sí no garantiza nada.*

````
==7079== Conditional jump or move depends on uninitialised value(s)
==7079==    at 0x4E7C4F1: vfprintf (vfprintf.c:1629)
==7079==    by 0x4E858D8: printf (printf.c:35)
==7079==    by 0x400537: main (ej3.c:5)
````

“*Conditional jump or move depends on uninitialised value(s)*”, es decir, se evalúa un salto condicional con un valor no inicializado. 

Si leemos de abajo hacia arriba: Error en main -> Error en el printf -> error en la fun vfprinf

Memcheck nos deja utilizar las variables no inicializadas hasta cierto punto. De hecho, si quitamos la línea del printf y volvemos a correr Valgrind, nos va a decir que está todo bien. ¿Por qué?. Porque **Memcheck sólo va a putear cuando los datos no inicializados afecten el comportamiento externo/visible** **de nuestro programa.** En éste caso particular, Memcheck putea en el vfprintf porque internamente tiene que examinar el valor contenido en la variable *a* para convertirlo en la cadena que corresponda en ASCII (sí, es acá donde ocurre el salto condicional).

“*Use of uninitialised value of size 8*”. Más claro imposible, Valgrind nos está diciendo que estamos haciendo uso de un valor de tamaño de 8 bytes que no inicializamos.



**Ejemplo 4: “Conditional jump or move depends on uninitialised values” (Ejemplo 3 en Memoria Dinámica)**

Análogo al anterior

````c
#include <stdio.h>
#include <stdlib.h>
int main(void){
	int *a = malloc(sizeof(int));
	// (*a) = 1;
	printf("a = %d \n", (*a));
	free(a);
	return 0;
}
````

**Ejemplo 5: “Syscall param contains uninitialised bytes”**

Pasar por parámetro variables no inicializadas

#### PLUS

Otra herramienta muy útil que provee Valgrind, es [Helgrind](http://valgrind.org/docs/manual/hg-manual.html), para solucionar y detectar problemas de sincronización. También te va a resultar muy útil, pero eso ya es otra historia...

