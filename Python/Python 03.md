## 20 - Módulo pandas

Un modulo con funciones para el tratamiento de `Series`

#### Series

¿Que es esto? . Un objeto **"Series"** es un vector con datos indexados. Como una lista o array solo que puedes definir los **"índices"**

````python
import pandas as pd

#Si no se especifican indices, se asigna una secuencia de indices por defecto.
serie1 = pd.Series((3,5,7))
serie1
	0  ->  3
	1  ->  5
	2  ->  7
	dtype: int64
    
#Ahora asignando indices.
asignaturas = ["mate","historia","fisica","literatura"]
notas = [8,7,6,9]
# Una serie de notas, indexado por asignaturas
serie_notas_daniel = pd.Series(notas,index=asignaturas)  
    
serie_notas_daniel
    mate          8
	historia      7
	fisica        6
	literatura    9
	dtype: int64

#Ejemplo
serie_notas_daniel["fisica"]
6

# Acceder a los Datos(values) de una "Serie"
serie_notas_daniel.values
array([8, 7, 6, 9], dtype=int64)

# Acceder a los indices de una "Serie"
serie_notas_daniel.index
Index(['mate', 'historia', 'fisica', 'literatura'], dtype='object', name='Asignatura')
-----------------------


# Los elementos cuyo valor sea >= 8
serie_notas_daniel[serie_notas_daniel >= 8]
    mate          8
	literatura    9
	dtype: int64
    
# Dandole un nombre a la serie    
serie_notas_daniel.name = "Notas de Daniel"
serie_notas_daniel
    mate          8
	historia      7
	fisica        6
	literatura    9
	Name: Notas de Daniel, dtype: int64
        
# Ponerle nombre al campo de los index
serie_notas_daniel.index.name = "Asignatura"

serie_notas_daniel
	Asignatura
	mate          8
	historia      7
	fisica        6
	literatura    9
	Name: Notas de Daniel, dtype: int64
        
# Serie a diccionario
diccionario = serie_notas_daniel.to_dict()
diccionario
{'mate': 8, 'historia': 7, 'fisica': 6, 'literatura': 9}

# Diccionario a serie
# Pierde los nombres, porque en el diccionario no se guarda
serie = pd.Series(diccionario)
serie
	mate          8
	historia      7
	fisica        6
	literatura    9
	dtype: int64
    
#Promediar series
asignaturas = ["mate","historia","fisica","literatura"]
notas_ana = [7,8,5,9]
serie_notas_ana = pd.Series(notas_ana,index=asignaturas)
serie_notas_ana
	mate          7
	historia      8
	fisica        5
	literatura    9
	dtype: int64
        
serie_notas_clase = ( serie_notas_daniel + serie_notas_ana) / 2
serie_notas_clase
    Asignatura
	mate          7.5
	historia      7.5
	fisica        5.5
	literatura    9.0
	dtype: float64
````

#### DataFrames

Es como un tabla de **Excel** , con filas y columnas. La primera fila que tiene el nombre de las columnas, no se cuenta como fila del DataFrame

````python
import pandas as pd
import webbrowser #Funcionalidades con internet

website = "https://es.wikipedia.org/wiki/Anexo:Campeones_de_la_NBA"
webbrowser.open(website) #Al ejecutarse, habre la pagina web

#Vamos a buscar una tabla y la vamos a seleccionar,IMPORTANTE:
#La copiamos, ponele las primeras 10 filas. Ahora estan copiadas en el portapapeles

# CREAR UN DATAFRAME del portapeles
dataframe_nba = pd.read_clipboard()
dataframe_nba

#Los nombres de las columnas
dataframe_nba.columns

#Datos de la columna
dataframe_nba['Campeón del Oeste']

#Devolver la fila 5
dataframe_nba.loc[5]

#Las primeras 3 filas
dataframe_nba.head(3)

#Las ultimas 2 filas
dataframe_nba.tail(2)


# CREAR UN DATAFRAME a partir de un diccionario
lista_asignaturas = ["mate","historia","fisica"]
lista_notas = [7,8,9]
dicc = {'Asignaturas':lista_asignaturas,'Notas':lista_notas}

dataframe_notas = pd.DataFrame(dicc)
dataframe_notas
````

#### Índices

````python
#Indices
import pandas as pd
lista_valores = [1,2,3]
lista_indices = ['a','b','c']
serie = pd.Series(lista_valores,lista_indices)

# Acceder a los indices de una "Serie"
serie.index
Index(['a', 'b', 'c'], dtype='object')

serie.index[1]
'b'

# Los indices son inmutables/ los valores no
# serie.index[0] = 'z' /ERROR!!
# serie['a'] = 9 /OK!!

#Crear indices en un Dataframe
lista_valores = [[6,7,8],[8,9,5],[6,9,7]]
lista_indices = ["Matematica","Historia","Fisica"]
lista_nombres = ["Antonio","Maria", "Pedro"]#Las columnas

dataframe = pd.DataFrame(lista_valores, index=lista_indices,columns=lista_nombres)

#dataframe
			Antonio	  Maria	  Pedro
Matematica		6		7		8
Historia		8		9		5
Fisica			6		9		7


dataframe.index
Index(['Matematica', 'Historia', 'Fisica'], dtype='object')

dataframe.index[0]
'Matematica'
````

#### Eliminar elementos

````python
# Eliminar elementos en series y Dataframes
import pandas as pd
import numpy as np

#Tiene que haber (=) cantidad de elementos que indices
serie = pd.Series(np.arange(4),index=['a','b','c','d'])

#eliminar un elemento,es mediante su indice
serie.drop('c')

#Ojo no presiste. guardar el nuevo resultado en una variable

np.arange(9).reshape(3,3).
array([[0, 1, 2],
       [3, 4, 5],
       [6, 7, 8]])

lista_valores = np.arange(9).reshape(3,3)
lista_indices = ['a','b','c']
lista_columnas = ['c1','c2','c3']
dataFrame = pd.DataFrame(lista_valores, index=lista_indices, columns=lista_columnas)

# borrar fila
dataFrame.drop('b')

# borrar columna
# axis :1 el eje
dataFrame.drop('c2',axis=1)

#no olvidar que, los cambios no persisten
#una solucion: dataFrame = dataFrame.drop('c2',axis=1)
````

#### Seleccionar datos en series

````python
import pandas as pd
import numpy as np

lista_valores = np.arange(3)
lista_indices = ['i1','i2','i3']
serie = pd.Series(lista_valores, index=lista_indices)

#Podemos multiplicar a todo por 2
serie = serie*2

#Buscar valor por indice
serie['i2']
#Alternativamente se puede buscar por indice numerico convencional
serie[1]

#SubSeries
#desde 0 hasta 1
serie[0:2]

#desde el indice 'i1' hasta el 'i2'
serie['i1':'i2']

# Condicionales : Toma los datos para comparar
serie[serie > 3]

# En una Serie : Los indices son inmutables/ los valores no
serie[serie > 3] = 6
````

#### Seleccionar datos en dataframes

````python
import pandas as pd
import numpy as np
lista_valores = np.arange(25).reshape(5,5)
lista_valores

# Tenemos 5 filas .Por tanto nesecitamos 5 INDICES
lista_indices = ['i1','i2','i3',"i4","i5"]

#Entonces, nesecitamos 5 nombres de columnas
lista_columnas = ['c1','c2','c3','c4','c5']
dataframe = pd.DataFrame(lista_valores,index=lista_indices,columns=lista_columnas)

#Tomar datos de una columna
dataframe['c2']
    i1     1
    i2     6
    i3    11
    i4    16
    i5    21

#Cuando tomas un columna, tienes una SERIE
dataframe['c2']['i2']
6
#TIP no funciona alreves

#Podemos elegir las columnas
dataframe[['c3','c1']]

#Selecionar por valor
#Del dataFrame los valores(filas) que cumplan una condicion, en este caso que el valor de cuya pocicion en la columna 'c2' sea mayor a 15
dataframe[dataframe['c2'] > 15]

#Para condicionales: Devuelve una tabla de 'true'/ 'false'
dataframe > 20

#Seleccionar por indice(OJO el loc no olvidar)
dataframe.loc['i3']
    c1    10
    c2    11
    c3    12
    c4    13
    c5    14
dataframe.loc['i3']['c4']
````

#### Operaciones

````python
# Operaciones sobre series y dataframes
import pandas as pd
import numpy as np

serie1=pd.Series([0,1,2],index=['a','b','c'])
serie2=pd.Series([3,4,5,6],index=['a','b','c','d'])

#Suma y tiene criterios de no coincidencia, los rellena con NaN
serie1 +serie2


lista_valores = np.arange(4).reshape(2,2)
lista_indices = list('ab') #Forma de construir una lista
lista_columnas = list('12')
dataframe = pd.DataFrame(lista_valores,index=lista_indices, columns=lista_columnas)

lista_valores_2 = np.arange(9).reshape(3,3)
lista_indices_2 = list('abc') #Forma de construir una lista

lista_columnas_2 = list('123')
dataframe_2 = pd.DataFrame(lista_valores_2,index=lista_indices_2, columns=lista_columnas_2)

#Los lugares donde hay datos faltantes , se asigna NaN
dataframe_3 = dataframe + dataframe_2

#Mi dataframe_3 tiene valores NaN , al sumar puedo reemplazarlos por 0 asi no hay perdida de datos
dataframe_3.add(dataframe_2,fill_value=0)
````

#### Ordenación y clasificación

````python
import pandas as pd
import numpy as np

lista_valores = range(4)
lista_indices = list('CABD')

serie = pd.Series(lista_valores,index=lista_indices)

#Ordenar por indices
serie.sort_index()

#Ordenar por valores
serie.sort_values()

# Cambia el valor por: Su Lugar, si estubiera ordenado por valor(No cambia la posicion)
serie.rank()
````

#### Estadísticas

````python
# Estadisticas en dataframes
import pandas as pd
import numpy as np

array = np.array([[1,8,3],[5,6,7]])
dataframe = pd.DataFrame(array, index=['a','b'], columns=list('123'))
dataframe
	1	2	3
a	1	8	3
b	5	6	7

#Suma por columnas
dataframe.sum()
#Suma por filas
dataframe.sum(axis=1)#Osea por el otro eje

#El minimo valor, de cada columna
dataframe.min()

#El maximo valor, de cada columna
dataframe.max()
#El otro sentido es 'axis=1' como argumento

dataframe.idxmin()
#Primero haya el valor minimo de la columna y lo cambia por su indice

#Breve Descripcion de toda la tabla, por columnas
dataframe.describe()
````

#### Valores nulos

````python
# Valores nulos - NaN
import pandas as pd
import numpy as np

lista_valores = ['1','2',np.nan,'4']
serie = pd.Series(lista_valores, index=list('abcd'))

# Me sale 'True' si el elemento es nulo
serie.isnull()

#Borrar valores nulos, no persiste en el original
serie.dropna() #Para que persista: serie = serie.dropna()

#-----------------
#Ahora con DataFrame
lista_valores = [[1,2,3],[4,np.nan,5],[6,7,np.nan]]
lista_indices = list('123')
lista_columnas = list('abc')
dataframe = pd.DataFrame(lista_valores, index=lista_indices, columns=lista_columnas)

#Hay nulos en el DataFrame?
dataframe.isnull()

#borrar nulos, vasta que aparesca un nulo en la fila y se borra tola la fila
dataframe.dropna()

#reemplazar NaN por otro valor
dataframe.fillna(0)
````

#### Jerarquía de índices

````python
import pandas as pd
import numpy as np

lista_valores = np.random.rand(6)
lista_indices = [[1,1,1,2,2,2],['a','b','c','a','b','c']]
series = pd.Series(lista_valores, index=lista_indices)

# Tenemos doble indice
# El indice de primer nivel es:  1 y 2
# El indice de segundo nivel es:  a , b yc
series
    1  a    0.742062
       b    0.419324
       c    0.544580
    2  a    0.049094
       b    0.802933
       c    0.486000
    
series[1]
    a    0.742062
    b    0.419324
    c    0.544580
    
series[1]['b']    
0.41932362004918

#Podemos aprovechar el 'doble indice' para crear un DataFrame
# El indice principal o de primer nivel => El indice del DataFrame
# El indice de segundo nivel => Los nombre de las columnas del DataFrame
dataframe = series.unstack()

#DataFrame => serie con doble indice
dataframe.stack()
````

**BONUS**

````python
#Numeros random enteros
# randint(num_minimo,num_max,cantidad_numeros)
np.random.randint(1,10,3)
array([6, 3, 7])
````
