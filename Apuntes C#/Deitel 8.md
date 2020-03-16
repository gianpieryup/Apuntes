## 8. Arreglos

Declaraciones

````c#
int[] arreglo;	//declarar un arreglo de enteros
arreglo = new int[10]; // 10 elementos int
// queda arreglo = [0,0,0,0,0,0,0,0,0,0];

//Forma Alternativa
int[] v = {10,20,30,40};

¿Para recorrer un vector sin saber la longitud?
1. Foreach
2. for(int i = 0; i < arreglo.Length;i++)
````

> TIP : Tratar de declarar una constante con nombre sin inicializarla es un error de compilacion

### ArrayList

Para que o que y cual es la diferencia con un `array` , bueno básicamente es un array que admite cualquier tipo de dato. Esta descontinuado pero es bueno saberlo para entender código viejo. Vemos mas adelante sobre lo que se usa hoy en día

````c#
//Para usarlo debemos tener la referencia 
using System.Collections;//Esta si no no lo reconoce
ArrayList lista = new ArrayList();
````

### List 

Usado hoy en día para definir arreglos. Eso si con un solo tipo de dato

````c#
List<int> lista2 = new Lista<int>();
````

#### Paso de arreglos y elementos de arreglos a los métodos

1. *Cuando se pasa como argumentos un arreglo hacia un método, recibe una copia de la referencia*
2. Cuando se pasa un elemento individual de un arreglo se pasa por valor

````c#
double[] temperaturas = new double[24];

void modificarArreglo(double[] b)   
````

#### Paso de arreglos por valor y por referencia

En C# como en la mayoría de lenguajes, una variable que "almacena" un objeto, en realidad no almacena el objeto en si , si no una <span style=" background:yellow;">referencia al objeto(es decir ,la ubicación en memoria de la computadora)</span> . Como una dirección del lugar donde esta :smile:

Como se sabe, cuando una aplicación pasa un argumento a un método, <span style=" background:#81F7F3;"> el método recibe una copia del valor de ese argumento</span>. Las modificaciones no afectan al original.(recordar lo del rendimiento)

````c#
* => [original]
---------		//Se crea una copia de []
(**) => [copia]
//Con lo que trabajo es (**)
````



Si es llamado por **referencia** , <span style=" background:#81F7F3;"> el método recibe una copia de la referencia</span>,no del objeto . Con esta <span style=" background:yellow;">copia de referencia</span> las modificaciones afectan al objeto original.(recordar lo de la seguridad)

> En C# LOS OBJETOS(INCLUYENDO LOS ARRAYS) se pasan por referencia, no confundir objetos con variables

````c#
* => [original]
	//	
(**) 
Se crea una copia de * cuyo valor es (**)
//Con lo que trabajo es (**), puedo modificar [original] pero no (*)

    

Existe la palabra clave "ref"  que me permite modificar la variable original y no recibir una copia de la referencia
* => [original]
//Recibo (*) para usar,no una copia el original   
    
public static void funcion(ref int[] arr){}
````

##### SUPEREJEMPLO

````c#
A = [1,2,3]
copiA = A
//A y copiA apuntan a la misma porcion de memoria donde hay datos (un array)
metodo(int[] b){
    //b seria una copia de la referencia de a
  duplicar cada elemento de b
    //Tiene acceso a los elementos
  b = new int[] {11,12,13};
    //esta ultima sentencia se da a la copia de la referencia, por lo que nuestra referencia original y su copia siguen apuntando a la original
}
metodo(A)
//Quedaria lo siguiente
A = [2,4,6]
copiaA = [2,4,6] = A
// A y copiaA siguen apuntando a la misma porcion de memoria


----------------
A = [1,2,3]
copiA = A
metodo(ref int[] b){
    //b seria una exactamente la referencia de A
  duplicar cada elemento de b
    //Tiene acceso a los elementos
   b = new int[] {11,12,13};
     //esta ultima sentencia se da a la referencia de A
}
metodo(A)
//Quedaria lo siguiente
A = [11,12,13]
copiaA = [2,4,6] != A
// A y copiaA ya no apuntan a la misma porcion de memoria
````



## Arreglos multidimensionales

#### Arreglos rectangulares

Cada fila tiene el mismo numero de columnas

````c#
int [ , ] b = { {1,2}, {3,4}}

//Para acceder a cada elemento
b[0,0] = 1      b[1,0] = 3
b[0,1] = 2		b[1,1] = 4
````

#### Arreglos dentados

Cada elemento se mantiene como un arreglo unidimensional. Las longitudes de las filas en el arreglo no necesitan ser las mismas

````c#
int [] [] dentado = { new int[] {1 ,2},
                      new int[] {3},
                      new int[] {4,5,6}
                    };
dentado[0,0] = 1      dentado[1,0] = 3		dentado[2,0] = 4
dentado[0,1] = 2							dentado[2,1] = 5
    										dentado[2,2] = 6
````

Declaraciones

````c#
//rectangular
int [,] b;
b = new int [3,4];

//dentado
int [][] c = new int[2][5];//error
int [][] c;
c = new int[2][];// crear dos filas
c[0] = new int[5];// crea 5 columnas para la fila 0
c[1] = new int[3];// crea 3 columnas para la fila 1

BONUS
matriz.GetLength(0); //devuelve el numero de filas
matriz.GetLength(1); //devuelve el numero de columnas
````

#### Lista de argumentos de longitud variable

Permite crear métodos que reciben un **numero arbitrario de argumentos**, para esto se antepone la palabra clave `params` .**Solo se puede usar** en la ultima entrada de la lista de parámetros

Si bien se podría hacer con **sobrecarga**, tendríamos que definir cada sobrecarga y esa no es la idea :kissing_smiling_eyes:

````c#
//Es muy usado para el tratamiento de arreglos
public static double Promedio(params double[] numeros){
	double total = 0.0;
    foreach(double d in numeros){
        total+=d;
    }
    return total;
}

//El param me abilita lo siguiente, muchos elementos
Console.WriteLine("EL promedio es {0}",Promedio(1.0,2.0));
Console.WriteLine("EL promedio es {0}",Promedio(1.0,2.0,3.0,4.0));

//Sin el 'params' tengo que pasarle un solo elemento (un array)
Console.WriteLine("EL promedio es {0}", Promedio(new double[]{1.1,1.2}) );
````

