## TRANSACCIONES

Hasta ahora hablamos de **Integridad** → (Constrain PK, FK,...) , pero no hablamos de **<u>Consistencia</u>**

Datos correctos → *para determinado caso de negocio*

EJ: Compre 10 frutas → Stock frutas (- 10)



#### Funcionalidad de la <u>Consistencia</u>

- <span style=" background:yellow;">**TRANSACCIONES**</span>
  - Es un conjunto de sentencias SQL que se ejecutan atómicamente (**MUTEX**)
- <span style=" background:yellow;">**LOGS TRANSACCIONALES**</span>: Es un registro donde el motor almacena la información de cada operación llevada a cabo con los datos
- <span style=" background:yellow;">**RECOVERY**</span>: Método de recuperación ante caídas.

Para definir una transacción debemos definir un conjunto de instrucciones precedidas por la sentencia **BEGIN TRANSACTION**, de esta manera las sentencias a continuación se ejecutarán de forma atómica

````sql
BEGIN TRANSACTION
-- sentencia
-- ...
A secas si ejecutas y cierras el Managment te consulta si quieres ROOLBAKEAR o COMITEAR

-- COMO en GIT
COMMIT TRANSACTION -- Persiste en el Disco los cambios

ROLLBACK TRANSACTION -- Deshace los cambios de la transaccion
Como??
-- Con los 'LOGS TRANSACCIONALES' realiza las operaciones contrarias
````

SI ocurre un error en la **TRANSACTION** el motor hace un **ROLLBACK**, además nosotros podemos definir de <u>forma manual</u> el **ROLLBACK** mediante `if(vender > stock) ROLLBACK` dentro de la transacción

Algunos Ejemplos: <span style=" background:yellow;">OJO la ubicación y lo que este anidado</span>

````sql
CREATE TABLE #numeros (num int)

BEGIN TRAN T1
	INSERT INTO #numeros VALUES (1)
	BEGIN TRAN T2
		INSERT INTO #numeros VALUES (2)
	COMMIT TRAN -- COnfirma T2
	
ROLLBACK TRAN -- Deshace T1 que contiene a T2; entonces tambien la deshace
````

Algunos motores de base de datos permiten establecer **puntos intermedios de guardad**o de información.

````sql
CREATE TABLE #numeros (num int)

BEGIN TRAN T1
INSERT INTO #numeros VALUES (2)
SAVE TRAN N2 -- Guardo estado actual a N2

	BEGIN TRAN T2
		INSERT INTO #numeros VALUES (2)
	ROLLBACK TRAN N2 -- Deshago la transaccion actual hasta N2
	
INSERT INTO #numeros VALUES (4)
COMMIT TRAN
````

Es posible realizar más de un *Save Tran* en cada transacción y se puede elegir a cual se desea volver en cual momento. El resultado de todo esto será la inserción de [2,4]

 

##### Mecanismos de recuperación (RECOVERY)

Es un mecanismo provisto por los motores de Base de Datos que se ejecuta en cada inicio del motor de forma automática como dispositivo de tolerancia a fallas

Retornar al Motor de Base de datos al punto **consistente** más reciente. (**checkpoint** = punto en el que el motor sincronizó memoria y disco)
Utilizar los **logs transaccionales** para retornar el motor de base de datos a un estado lógico consistente



Foco en la ejecución de **Transacciones**

- **A**tomicidad: **BLOQUE TRY** (Serie de pasos donde se ejecuta completa o ninguna se ejecuta)
- **C**onsistencia: <span style=" background:yellow;">La BD parte y va hacia un estado consistente por cada transacción</span>  (\*)
- **I**solation(Aislamiento): Esto asegura que la realización de dos transacciones sobre la misma información sean independientes y no generen ningún tipo de error. 
- **D**urabilidad: **COMMIT** → el dato dura eternamente, hasta que le tire un DELETE u algo parecido



#### EJEMPLO ACID

Transacción para transferir $1000 de la cuenta X a la cuenta Y:

1. leer (X)
2. X = X –1000
3. escribir (X)
4. Listo)
5. Y = Y + 1000
6. escribir (Y)

- **Requisito de atomicidad**: si la transacción falla después del paso 3 y antes del paso 6, el sistema debe asegurarse de que sus actualizaciones no se reflejen en la base de datos, de lo contrario, se producirá una incoherencia.
- **Requisito de coherencia**: la suma de X e Y no cambia con la ejecución de la transacción.
- **Requisito de Aislamiento**: si entre los pasos 3 y 6, se permite que otra transacción acceda a la base de datos parcialmente actualizada, verá una base de datos inconsistente (la suma X + Y será menor de lo que debería ser).
  1. El aislamiento se puede garantizar de manera trivial ejecutando transacciones en serie, es decir, una tras otra.
  2. Sin embargo, la ejecución de múltiples transacciones al mismo tiempo tiene beneficios significativos, como veremos más adelante.
- **Requisito de durabilidad**: una vez que se notifica al usuario que la transacción se ha completado (es decir, se ha realizado la transferencia de $1000), las actualizaciones de la base de datos por parte de la transacción deben persistir a pesar de las fallas.

