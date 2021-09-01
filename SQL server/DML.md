## COMANDOS

````sql
SELECT * | listade columnas
FROM nom_tabla| lista de tablas
WHERE condiciones ó filtros
GROUP BY columnas clave de agrupamiento
HAVING condiciones sobre lo agrupado
ORDER BY columnas clave de ordenamiento
````

#### SELECT

````sql
SELECT stock_num, unit_price*1.15

# ALias de Columna o Etiqueta
SELECT stock_num, unit_price*1.15 NewPrice

# Concatenar columnas en una sola nueva columna de salida.
SELECT lname+', ' +fname apellidoYNombre

# Utilización de funciones especiales: ARITMETICAS, TRIGONOMETRICAS, FINANCIERAS, DE FECHA, DE STRINGS, Entre otras..
SELECT YEAR(order_date), MONTH(order_date), DAY(order_date), USER_NAME()
````

##### DISTINCT

````sql
SELECT customer_num
FROM orders
ORDER BY 1

# Listar valores únicos para una columna, ante una repetición de valores de esa columna.
SELECT DISTINCT customer_num
FROM orders
ORDER BY 1
````

#### Funciones Agregadas

````sql
SUM(columna)
COUNT(*) 		# cuenta todas las filas de la tabla

COUNT(columna)  # cuenta filas con dicha columna (NO NULA)
# Muestra la cantidad de Ordenes de Compra con fecha de pago No Nula
SELECT COUNT(paid_date) FROM orders

COUNT(DISTINCT columna)	 # Cuenta solo una vez cada valor.
MIN(columna)
MAX(columna)
SUM(columna)
AVG(columna)
````

Mucho ojo cuando se cuenta los valores **NO NULOS**

Son funciones que dado un conjunto de datos realizan operaciones agregadas <span style=" background:yellow;">devolviendo un único valor cómo resultado.</span>

````sql
SELECT MIN(orde_date) primeraCompra,
	   MAX(orde_date) ultCompra,
	   COUNT(*) cantOrdenes
FROM orders
# notar que todas las columnas deberan quedar agrupadas de alguna u otra forma
````



#### WHERE

````sql
WHERE condiciones | [AND, OR, NOT]
[NOT] LIKE			validar substrings
lname LIKE 'A%'			apellidos que comiencencon 'A'.
lname LIKE '%th%' 		apellidos que contenga'th' en cualquier parte.
lname LIKE 'A_ _ _' 	apellidos que comiencen con 'A' y tengan 4 letras
lname LIKE '[AE]%'		apellidos que comiencen con 'A'ó 'E'.
lname LIKE '[A-E]%' 	apellidos que comiencen entre la 'A' y la 'E'.


[NOT] BETWEEN		entre rango # WHERE order_num BETWEEN 1004 AND 1020
[NOT] IN			en lista de valores # WHERE customer_num IN (104,110,127)
IS [NOT] NULL 		es o no es nulo
````

#### ORDER BY

**Aclaracion**: En los numeros asendente es tan simple como 7, 8, 9

En el alfabero, ordenados asendentemente seria "a","b","d" 

````sql
# Ordenados asendentemento por 'city' y a igual 'ciudad', se ordena por customer_num también ascendente.
ORDER BY city, customer_num

# ASCENDENTE (default) -> Ordenados asendentemento por 'city' y en a igual DESC por 'customer_num'
ORDER BY city, customer_num DESC

# Se pueden poner números que indican la posición de la columna en la consulta, en lugar del nombre.
ORDER BY 4, 1 DESC
````

#### GROUP BY y HAVING

Esta clausula de agrupamiento es muy ponderosa en conjunto con la utilización de **funciones Agregadas.**

````sql
GROUP BY columnas clave de agrupamiento
HAVING condiciones sobre lo agrupado # OJO sobre los grupos
````

Veamos algunos ejemplos

````sql
SELECT customer_num, COUNT(order_num) cantOrdenes,
	MIN(order_date) primeraCompra, MAX(order_date) ultCompra
FROM orders
GROUP BY customer_num
````

Observamos los 17 clientes que compraron, de cada uno tenemos la cantidad de Ordenes de compra, la fecha de la primer y ultima compra.



````sql
GROUP BY YEAR(order_date), MONTH(order_date)
````

Observamos que rápidamente obtenemos la cant. De ordenes, la primer y ultima compra pero ahora agrupado por año y mes.



#### HAVING 

La Clausula HAVING actúa sobre los datos de las filas ya agrupadas y en general se le ponen condiciones con funciones agregadas

````sql
GROUP BY YEAR(order_date), MONTH(order_date)
HAVING count(*) >= 8
````

Basicamente: Es un **WHERE** en cada **Grupo**, en este caso se lee que Filtrare los grupos cuya cantidad de elementos sea mayor o igual a 8. <span style=" background:yellow;">Ahora que tengo solo los grupos que cumplen la condicion</span> , con las **funciones Agregadas** me devuelven un unico valor por **grupo**

Si en la columna tenemos un `count()` 
