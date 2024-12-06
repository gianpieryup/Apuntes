## Información a tener en consideración

``````sql
-- El SuperUsuario con la contraseña que se puso al momento de instalar la base de datos oracle no olvidar estos datos.
Usuario : sys
Contraseña : root
``````

### Privilegios de usuario

Se pueden editar a los usuarios creados a partir del usuario SYS , es recomendable tener una instancia con el usuario `SYS` llamada `System` que no la utilicemos pero nos servirá para poder modificar los usuarios y administrar las conexiones. **No borrar**