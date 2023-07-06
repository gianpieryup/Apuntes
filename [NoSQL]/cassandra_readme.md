# NOSQL Column Family

Como usa python 2.x y para no matar la version (base) de python de mi compu. Cree un entorno virtual con ayuda de `anaconda` , lo creas con python 2 y levanta correctamente

## Levantar Cassandra

Abro dos entornos que cree anteriormente, uno tendra cassandra y el otro cql

```sql
-- CASSANDRA
-- =============================
cassandra -f 

-- Este log indica que ya esta listo
-- INFO  [main] 2023-07-06 19:33:50,423 Server.java:156 - Starting listening for CQL clients on localhost/127.0.0.1:9042 (unencrypted)...


-- CQL
-- =============================
cqlsh
```

## KEYSPACE

Verification de los **KEYSPACE** que existen en nuestro sistema
```
cqlsh> DESCRIBE keyspaces;
```


Crear el **KEYSPACE**
```
cqlsh.> CREATE KEYSPACE gian
WITH replication = {'class':'SimpleStrategy', 'replication_factor' : 3};
```


Create Tabla
```sql
-- Elegir keyspace
use gian;

-- create
CREATE TABLE alumnos (
  legajo text,
  materia text,
  nora int,
  primary key (legajo, materia)
);

-- insert
INSERT INTO alumnos(legajo,materia,nora) VALUES ('111', 'nosql', 10);
INSERT INTO alumnos(legajo,materia,nora) VALUES ('111', 'GDD', 10);
INSERT INTO alumnos(legajo,materia,nora) VALUES ('111', 'proyecto', 10);

-- fetch 
SELECT count(*) FROM alumnos;
```




