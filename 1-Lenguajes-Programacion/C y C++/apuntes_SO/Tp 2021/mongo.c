// SABOTAJE
void handler {
	● mandar msj a Discordiador
	// El disc pausa todo y elige al trip con una TAREA SABOTAJE  llegua a la tarea y manda el msj
	// Atencion de un sabotaje()
	● me llega el anterior msj
	● Comienzo el fsk
		debo determinar los siguientes valores
		// Si sera un sabotaje al superbloque
		○ Cantidad_de_bloques : se calcula esto de disco
			if Cantidad_de_bloques !=  lo_que_esta_enmemoria
				printf("Sedecto un sabotaje al superbloque")
				reparar(lo_que_esta_enmemoria); // esto podria ser con una funcion
				// se puede hacer aui dentro o con una funcion

		○ Bitmap
			calculamos el bit o como sumamos?



		// Si sera un sabotaje a los Files
		○  Size
			Me cambian el SIZE
			Como resolver: recorrer los bloques del archivo
			Hay que tener algun centinela para saber "hasta aca llegue" (no estoy seguro)

		○ Block_count y blocks
			No cocuerda el valor de BLOCK_COUNT y 	  BLOCKS
										1 			[5,12,3,9]
			Como resolver: actualizando : 1 -> 4   (solo eso)
	
		○ Blocks
			BLOCKS (el mas complejo) se altero la lista BLOCKS y los bloques no estan en orden
			EJ:	[20,5,1,68] -> [68,20,1,5]
			Como resolver: con el md5 del archivo 
			calculamos el md5 de [68,20,1,5] y lo comparamos con  el 'md5 del archivo'
			si no concuerda
			(**)restaurar el archivo: escribir caracteres 'O' hasta completar el SIZE
			reescribimos el archivo
			no se reordena nada(ver video por si acaso)
	
	● Si llego aqui significa que encontro y reparo el sabotaje
	debemos esperar el msj de disc el de notificar_fin_sabotaje_imongo
}

(**) El proceso de restauración de archivos consiste en tomar como referencia el size del archivo y el
caracter de llenado e ir llenando los bloques hasta completar el size del archivo, en caso de que
falten bloques, los mismos se deberán agregar al final del mismo.



// VIDEO TEORIA
corromper información crucial almacenada en cualquier componente del File System

1 tenemos que informarte cuando pedirmos tarea
2 cuando comensamos
3 cuando acabamos una tarea


ESTRUCTURAS------
superbloque
blocks
Archivos de recursos
Bitacoras

ＳＵＰＥＲＢＬＯＱＵＥ
archivo binario
[tamaño de los bloques|cant de bloques|bitmap]
El tamaño del bitman depende de la cant de bloques

Si tenemos 8 bloques -> nuestro bitmap va a pesar 1 byte(8 bits)
1 bit que me indica si el bloque esta libre o ocupado
Si tenemos 14 bloques -> nuestro bitmap va a pesar 2 byte(16 bits)


ＢＬＯＱＵＥ
// BLA BLA BLA


// ARCHIVOS DE RECURSOS
CONTIENE:
SIZE
cantidad de bloques=4
los bloques=[20,5,1,68]  / en ese orden
caracter de llenado= O
MD5_ARCHIVO=tomar los 4 bloques unirlos y calcular el md5 (sirve para los sabotajes)

// BITACORAS
SIZE
BLOCKS=[1,2,3]
(Solo tiene esos campos por que las bitacoras no sufren sabotajes, son logs no lo haran)



EL servidor de imongostore es multihilo
-   Lectura y escritura de archivos se maneja las peticiones de forma concurrente
    Mas alla de que defina una sinronizacion
- manejador SIGUSR1 para notificar el sabotaje

// LA copia del blocks.ims
Vamos manejando la copia y cada cierto tiempo(config imognog)
se escribira en el original
mmap y msing

// SABOTAJE
1. notificacion
    con htop (es mas visual osea desde un cmd)
2. como recibo esta señal
    con un handler atraves de un signal
    basicamente es si le tiro un kill por htop se ejecuta el signal
    signal(SIRGUS1,funcion)
    se pausa lo que se este ejecutando -> se ejecuta la 'funcion' -> termina y se regresa a donde fue pausado

// Sabotaje en superbloque
Me setean la cantidad de bloques del campo superbloque
lo verifico con la copia.ims y lo corrigo en caso de que no concuerde



Sabotaje en el bitmap
me cambian algun bit del archivo bitmap del superbloque(bit de valides) // MINUTO TAL DEL VIDEO DE SUS LABIOS
Como resolver: recorrer los File y Files/Bitacoras y constatar/arreglar el bitmap

// Sabotaje sobre los files(nunca sabotaje)
Me cambian el SIZE
Como resolver: recorrer los bloques del archivo
Hay que tener algun centinela para saber "hasta aca llegue"

No cocuerda el valor de BLOCK_COUNT y BLOCKS
1 [5,12,3,9]
Como resolver: actualizando : 1 -> 4   (solo eso)

BLOCKS (el mas complejo)
se altero la lista BLOCKS y los bloques no estan en orden
[20,5,1,68] -> [68,20,1,5]
Como resolver: con el md5 del archivo 
calculamos el md5 de [68,20,1,5] y lo comparamos con  el 'md5 del archivo'
si no concuerda
restaurar el archivo: escribir caracteres 'O' hasta completar el SIZE
reescribimos el archivo
no se reordena nada(ver video por si acaso)

void * superbloque
4 byte | tam_bloque
tam_bloque : sera el tamaño de todos los bloques
la fragmentacion interna la rellena con /0
OOOOOOOOO\0\0\0


---------------------
tarea : hola\n\0

//hola

sabotaje del bitmap
llegue el trip tiro un msj de Comienzo tarea SABOTAJE