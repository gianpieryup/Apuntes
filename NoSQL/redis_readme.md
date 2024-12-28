
# NOSQL Clase 2
Principios basicos del modelado de datos en NOSQL
1. De-Normalizacion: Iplica Mas espacio
2. Agregacion: Es la minima unidad de manipulacion


Pero que cuesta mas Costo Computacional o el Costo de Almacenamiento
Es caso la razon por la que las NOSQL siguen ganando terreno por el abaratamiento del espacio
Normalizacion -> Asegura consistencia de los datos, solo aparecen una vez(o bien muy pocas) -> Me genera muchos JOINS -> Muy caro Costo Computacional




## REDIS

#### Arquitectura Servidor - Cliente
```redis
redis-server

redis-cli
```

### CACHE
borrar la cache para empezar de 0
```redis
FLUSHALL
```

#### STRING
```redis
SET student:1595118:name Leandro
SET student:1595118:surname Julian
GET student:1595118:name

-- Contadores
INCR student:1595118:exams

-- Se guarda como 'string' pero se interpreta como 'number'
TYPE student:1595118:exams
DECRBY student:1595118:exams 100

-- Para ver los values de un conjunto de keys | MGET <key1> <key2> <key3> ...
MGET student:1595118:name student:1595118:surname student:1595118:exams
```


#### Objetos Hash MAP
```redis
-- HMSET key      sub-key1 value1 sub-key2 value2
HMSET student:1605118 name Juana surname Perez exams 0
HGET student:1605118 name

-- Incrementar el valor de una sub-key en cierta cantidad
HINCRBY student:1605118 exams 1

-- Cambiar un value de la subkey 'name'
HSET student:1605118 name Natalia

-- Algunos GETTERS
HKEYS student:1605118
HVALS student:1605118
HGETALL student:1605118
```


#### Atomicidad
Crear estudiantes de manera atomica(es decir con una sola operacion)
1. Con el HMET como vimos
2. `SET student:1234567 "{\"name:\"John"\}"`

Entra el concepto de **TRANSACCIONES** en REDIS
Atomicas y Aisladas,pero no cumple con las demas letras ACID
```
MULTI

-- Los comandos se encolan hasta poner el 'EXEC'
SET student:1595064:name Ignacio NX
SET student:1595064:surname Zullo NX
INCR student:1595064:exams
EXEC
```

**No realizan rollback cuando fallan**, las operaciones validas si corren y modifican
El unico motivo de aborto, es un error de sintaxis, cuando le das exec te sale error y no ejecuta ninguna sentencia


### LISTAS
```
RPUSH student:1595118:exams:2C2019 "1P TACS"
RPUSH student:1595118:exams:2C2019 "2P ING SW"
RPUSH student:1595118:exams:2C2019 "1P TACS"

LRANGE student:1595118:exams:2C2019 0 -1

LPUSH student:1595118:exams:2C2019 "1P REDES"
LLEN student:1595118:exams:2C2019

-- Borrar y quedarnos con los primeros 2
LTRIM student:1595118:exams:2C2019 0 2
DEL student:1595118:exams:2C2019

RPUSH student:1595118:exams:2C2019 "1P REDES" "1P TACS" "2P ING SW"
```

### SETS
Caso de uso: no repetidos
```
SET (S) Conjuntos
SADD course:k5571:professors JUan Martin Santiago "Juan Martin" Ignacion Leandro
SADD course:k5571:professors Juan Hernan Juan

SMEMBERS: consultar los elementos de un SET
SCARD: la cardinalidad (número de elementos) del conjunto ordenado, o 0 si la key no existe.
SISMEMBER
SUNION
SDIFF
SINTERSTORE: guardar el resultado en otra clave
```

### SORTED SET
Caso de uso: no repetidos y con un orden
```
ZADD course:k5571:students 8.5 Juana 9 Pedro 7.4 Jorge 10 Carla 3 Jose

-- orden asc por score
ZRANGE course:k5571:students 0 -1 WITHSCORES

-- mejor estudiante
ZREVRANGE course:k5571:students 0 0 WITHSCORES

ZSCORE course:k5571:students Jose

-- El indice
ZRANK course:k5571:students Pedro
```



### HIPERLOGLOG
No almacena datos, es una estructura probabilistica
```
PFADD subject:I-NOSQL 1595118 222222 112345 1239123 124125 449 32 112345 32 222222

PFCOUNT subject:I-NOSQL

-- Para ver el tamañp de la memoria
MEMORY USAGE subject:I-NOSQL

PFADD subject:I-NOSQL 1 2 3 4 5 6 9 7
-- VEmos que aumento la memoria
```

### SESIONES
Caso de Uso: Guardado de Sesiones o info de carritos
```
-- Por el  FLAG(EX): solo existe en 10 seg
SET user:1cc17025:session "{\"cookie\": \"ble\"}" NX EX 10

-- Segundos que el falta para expirar, cuando devuelve -2 es que ya expiro o que no existe
TTL user:1cc17025:session

INCR user:1cc17025:views

-- Define el tiempo de expiracion de alguna clave ya creada
EXPIRE user:1cc17025:views 30
```


### BLOB 
Cualquier cosa binaria, incluido imagenes / entiendo que almacenadas como 1 y 0s
