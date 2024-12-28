# NOSQL Column Family

Tenemos dos formas de Levantarlo

## 1. Docker

Ahora que aprendi es muchisimo mas facil de esa forma, sin la necesidad de romper tu computadora.

Solo sigue los pasos de la diapo:

- Recorda que en la seccion de la diapo **Get Inside The Container** : debes poner el id del container que generaste

```sh
$ docker pull cassandra

$ docker run -p 7000:7000 -p 7001:7001 -p 7199:7199 -p 9042:9042 -p 9160:9160 --name cassandra -d cassandra:latest

# Get Inside The Container
$ docker exec -it 98ad90c6d2b8 bash
root@98ad90c6d2b8:/#

$ root@98ad90c6d2b8:/# cqlsh
Connected to Test Cluster at 127.0.0.1:9042
[cqlsh 6.2.0 | Cassandra 5.0.2 | CQL spec 3.4.7 | Native protocol v5]
Use HELP for help.
cqlsh>
```



## 2. Anaconda

Como usa python 2.x y para no matar la version (base) de python de mi compu. Cree un entorno virtual con ayuda de `anaconda` , lo creas con python 2 y levanta correctamente

**Levantar Cassandra**: Abro dos entornos, uno tendra cassandra(Servidor) y el otro cql(Cliente)

```sh
-- CASSANDRA (Servidor)
-- =============================
$ cassandra -f 
-- Este log indica que ya esta listo
-- INFO  [main] 2023-07-06 19:33:50,423 Server.java:156 - Starting listening for CQL clients on localhost/127.0.0.1:9042 (unencrypted)...


-- CQL (Cliente)
-- =============================
$ cqlsh
```





### Keyspace

Primero debemos definifir un nuevo *KEYSPACE*

```sh
# Verification de los KEYSPACE que existen en nuestro sistema
cqlsh> DESCRIBE keyspaces;

# Crear un KEYSPACE nuevo
cqlsh.> CREATE KEYSPACE gian
WITH replication = {'class':'SimpleStrategy', 'replication_factor' : 1};

# Verification de los KEYSPACE que existen en nuestro sistema
cqlsh> DESCRIBE keyspaces;
```



### Tablas

Ahora si podemos crear tablas en cassandra.

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
SELECT * FROM alumnos;
SELECT count(*) FROM alumnos;
```