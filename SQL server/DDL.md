## Motor SQL Server

#### CREATE

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

##### ALTER





**DELETE**: Borra registros

**DROP**: Borra la tabla(incluida la estructura), no queda nada

**TRUNCATE**:  Vacía la tabla(borra todos los registros) y Resetea la tabla (resetea el auto-increment)

````sql
DROP TABLE name_table -- La tabla desaperece
TRUNCATE TABLE name_tabla -- Aun existira la tabla
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



#### <u>VIEW</u>

Nombre (o alias) que se le da a una query, esta query se **visualiza como una tabla** y cada vez que se consulta se (ejecuta la query)

<span style=" background:yellow;">No contiene datos almacenados (No aloca espacio de almacenamiento.)</span>

Las vistas se pueden utilizar para:
Suministrar un nivel adicional de **seguridad** restringiendo el acceso a un conjunto predeterminado de filas o columnas de una tabla.
Ocultar la complejidad de los datos. Simplificar sentencias al usuario.

Una **view** depende de las tablas a las que se haga referencia en ella, si se elimina una tabla todas las **views** que dependen de ella se borraran o se pasará a estado **INVALIDO**, dependiendo del motor. Lo mismo para el caso de borrar una **view** de la cual depende otra **view**. (depende del motor de BD)

Tener en cuenta ciertas **restricciones** para el caso de Actualizaciones:

- Si en la tabla existieran <span style=" background:yellow;">campos que no permiten nulos </span>y en **la view no aparecen**, los **inserts** fallarían.

- Si en la **view** no aparece la **primary key** los **inserts** podrían fallar.


Con la opción **WITH CHECK OPTION**, se puede actualizar siempre y cuando el <span style=" background:yellow;">checkeo de la opción en el **where** sea verdadero</span>

````sql
CREATE VIEW V_clientes_california
(codigo, apellido, nombre) -- Notar que se renombran los names de las columnas
AS
SELECT customer_num, lname, fname
FROM customer
WHERE state='CA'

-- Podriamos INSERTAR (En la VISTA)
INSERT INTO V_clientes_california
VALUES (999,'Martin','Mihura','FL') -- Y LO INSERTARA SI NO hay problemas de integridad(NULL aceptable en los otros campos de la tabla customer)

-- Si hacemos el SELECT count(*) de la V_clientes_california
Notaremos que no aparece este nuevo regitro, RECORDEMOS que la vista es la query(en tiempo de ejecucion) esa que tiene un WHERE state='CA' y la que insertamos es de (state='FL')

-- Hademos un Updatesobre el cliente 101 de California cambiando su estado a NewYork.
Y te deja, obviamente no podemos verlo en la query porque tiene el WHERE

-- Pero PARA
Esto no es SEGURO, puedo Manipular(INSERT,DELETE,UPDATE) registros mediante la VIEW. que actualmente no pueden ser accedidos a traves de la vista.


-- Aqui entra
WITH CHECK OPTION : realiza un chequeo de integridad de los datos a insertar o modificar, los cuales deben cumplir con las condiciones del WHERE de la vista.

CREATE VIEW V_clientes_california_WCK
(codigo, apellido, nombre,estado)
AS
SELECT customer_num, lname, fname,state
FROM customer
WHERE state='CA'
WITH CHECK OPTION

-- Ahora cuando se quiera operar algo que no cumpla con el WHERE te saldra un mensaje de error: The attempted insert or update failed because the target view either specifies WITH CHECK OPTION
````



<img src="carpetaViews.png" alt="carpetaViews" style="zoom:48%;" />



#### <u>SNAPSHOTS</u>

Una FOTO de una TABLA en un determinado momento. Deben ser recalculadas o refrescadas cuando los datos de las tablas master cambian. <span style=" background:yellow;">Pueden ser refrescadas en forma manual, o a intervalos de tiempo definidos dependiendo el motor de BD.</span>

Por lo general son tablas sumarizadas(con funciones agregadas) → para toma de decisión

Se utilizan sobre todo en **Data Warehouse**, sistemas para soporte de toma de decisión

