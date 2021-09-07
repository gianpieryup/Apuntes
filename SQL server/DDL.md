## Motor SQL Server

#### CREAR TABLA

````sql
CREATE TABLE ordenes (
	N_orden INT NULL ,
	N_cliente INT NULL ,
	F_orden DATETIME NULL ,
	C_estado SMALLINT NULL ,
	F_alta_audit TIMESTAMP NULL ,
	D_usuario VARCHAR(20) NULL 
);
````



#### Secuencias

Los generadores de **secuencias** proveen una serie de <u>números secuenciales</u>, especialmente usados en <span style=" background:yellow;">entornos multiusuarios para generar una números secuenciales y únicos</span>

Los motores de base de datos proveen diferentes formas de implementar secuencias a través de:

- Propiedades de una columna (SqlServer, Mysql, DB2)
- Tipo de Dato de una columna (Informix, PostgreSQL)
- Objeto Sequence(Oracle, Informix, PostgreSQL, DB2, SqlServer)

Mirar el PDF, en este caso hablaremos específicamente de `SqlServer` 

Al insertar una fila en dicha tabla, el motor va a buscar el próximo nro. del más alto existente en la tabla. Seria el **AUTO_INCREMENTAL** (En SQLserver **IDENTITY**)

````sql
CREATE TABLE ordenes(
    N_orden int IDENTITY (1, 1), -- Primer valor 1, se incrementa de a 1
    N_clienteintNULL ,
    F_ordendatetimeNULL
);

INSERT INTO ordenes(n_cliente, f_orden) VALUES (114,'2020-03-03')
-- Si el N_orden maximo era 25. El nuevo registro insertado tendra PK=26
````

<span style='color:red'>Cuidado con las secuencias, cuando requerimos números consecutivos sin huecos.</span>



#### DEFINIR PK

````sql
CREATE TABLE ordenes (
	N_orden INT PRIMARY KEY,
	N_cliente INT,);

# Clave compuesta, fijate que al final la define
CREATE TABLE items_ordenes (
	N_orden INT,
	N_item SMALLINT,
	C_producto INT,
	Q_cantidad INT,
	PRIMARY KEY (n_orden, n_item) 
);
````

#### DEFINIR FK

````sql
CREATE TABLE items_ordenes (
	N_orden INT REFERENCES ordenes,
    N_item SMALLINT,
    PRIMARY KEY (n_orden, n_item) );
    
# FK Compuesta, fijate que al final la define
CREATE TABLE mov_stock (
    N_stock INT,
    C_movimientoSMALLINT,
    N_orden INT,
    N_itemSMALLINT,
    C_productoINT,
    Q_cantidadINT, # REFERENCES name_tabla [(atributos,..)]
    FOREIGN KEY (n_orden, n_item) REFERENCES items_ordenes
);

# SELF REFERENCING CONSTRAINT
CREATE TABLE empleados (
    N_empleado INTEGER PRIMARY KEY,
    D_Apellido VARCHAR(60),
    D_nombresVARCHAR(60),
    N_cuilNUMERIC(11,0),
    N_jefeINTEGER,
    FOREIGN KEY (n_jefe) REFERENCES empleados (n_empleado)
);
/*El motor no permitirá ingresar un empleado cuyo nro. de jefe no exista como número de empleado.
Lo que si permitirá es ingresar un nro. de jefe NULO.*/
````

