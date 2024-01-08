<div align="center">
	<img width="150" src="https://user-images.githubusercontent.com/25181517/117208740-bfb78400-adf5-11eb-97bb-09072b6bedfc.png" alt="PostgreSQL" title="PostgreSQL"/>
	<img width="150" src="https://user-images.githubusercontent.com/25181517/183896128-ec99105a-ec1a-4d85-b08b-1aa1620b2046.png" alt="MySQL" title="MySQL"/>
	<img width="150" src="https://github.com/marwin1991/profile-technology-icons/assets/136815194/82df4543-236b-4e45-9604-5434e3faab17" alt="SQLite" title="SQLite"/>
	<img width="150" src="https://github.com/marwin1991/profile-technology-icons/assets/19180175/3b371807-db7c-45b4-8720-c0cfc901680a" alt="MSSQL" title="MSSQL"/>
</div>

## Enlaces interesantes

- [SQl windows functions](https://www.sqlshack.com/es/como-usar-las-funciones-de-windows-en-sql-server/)
- [Databricks sql/language-manual](https://docs.databricks.com/en/sql/language-manual/index.html)
- [WITH](https://modern-sql.com/feature/with)
- [window-functions con animaciones](https://dataschool.com/how-to-teach-people-sql/how-window-functions-work/)


## ¿Qué son las funciones de ventana?

Las funciones de ventana **crean una nueva columna** basada en cálculos realizados en un subconjunto o "ventana" de los datos. Esta **ventana** comienza en la primera fila de una columna particular y **aumenta de tamaño** a menos que restrinja el tamaño de la ventana.

> [!IMPORTANT]
> Si no quedo claro, la VENTANA es ese cuadro en color amarillo y borde en negrita

```sql
SELECT 'Day', 'Mile Driving',
SUM('Miles Driving') OVER(ORDER BY 'Day') AS 'Running Total'
FROM 'Running total mileage visual';
```
![wf1](img/wf1.gif)

Aquí podemos verlo realizar una agregación de lo que hay al lado de la ventana.
La ventana crece en cada fila y, por lo tanto, agrega más y más datos, lo que le brinda una **agregación acumulada, en este caso un total acumulado**.

Si **restringimos** la ventana a 3 filas de alto, podemos obtener un promedio móvil de 3 días.

```sql
SELECT 'Day', 'Daily Revenue',
AVG('Daily Revenue') OVER(ORDER BY 'Day' ROWS 2 PRECEDING)
AS '3 Day Average' FROM 'Running Average Example';
```
![wf2](img/wf2.gif)