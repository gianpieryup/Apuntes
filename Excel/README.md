# EXCEL

Dado que recuerdo SQL mas que Excel, y como hay una relación entre ellos. 

## INDICE
<!-- TOC -->

- [Funciones](#funciones)
    - [BUSCARV](#buscarv)
    - [BUSCARX o XLOOKUP](#buscarx-o-xlookup)
	- [SI](#si)

<!-- /TOC -->




## Funciones

Para buscar,filtrar por condición, SUM, AVG


### BUSCARV

Busca un valor en una tabla

```shell
BUSCARV(valor_buscado; matriz_tabla; indicador_columnas; [rango])
```

![BUSCARV](img/BUSCARV.png)

Recordar que :

````visual basic
BUSCARV("Torrez", ..)
			|->	Si  pones el cuadro, tomara su contenido
BUSCARV(B3,B2:E7, ..)
			|->	La Tabla
BUSCARV(B3,  B2:E7, 2 , ..)
					|->	La columna del return de la Tabla
````

Si hay mas de un resultado en la búsqueda devuelve el primero


### BUSCARX o XLOOKUP

Algo que no se menciono es que el primer valor cuando es un cuadro, a medida que cambio el valor de ese cuadro se cambia el resultado

Ademas, la diferencia con **BUSCARV** es que puedo devolver mas de un dato de la fila encontrada.

En este caso devolvi "Nombre de empleado" y "Departamento"

![BUSCAR X](img/BUSCAR%20X.jpg)


### SI

Como el IF de programación : La comparacion es con `'='` no con `'=='`

![IF BUSCARV](img/IF%20BUSCARV.png)





### FECHAS

![FECHAS](img/FECHAS.png)