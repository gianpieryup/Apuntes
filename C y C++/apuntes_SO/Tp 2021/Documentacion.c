La estructura general de la planificacion 
Un hilo que gestiona cada transicion N -> R / B -> R /..
cada nucleo es un hilo (depende del grado de multitarea) ellos comen de la lista de READY cuando estan disponibles
Todos se controlan atraves de semaforos_contadores y para las listas conmutex
ASEGURAMOS: que no haya espera activa

EL hilo tripulante
| -> se bloq por sem_wait y se tiran sem_post alternadamente 
El nucleo

El nucleo le tira un signal al trip pausado, luego se pausa el nucleo hasta que el trip
termine 1 ciclo de ejecucion y luego tira signal al nucleo y asi sucesivamente hasta que no tengo mas tareas por hacer
Luego el nucleo elige un nuevo trip de la cola de Listo

Para pausar la planificacion
Creamos una funcion atencion_interrupcion() que esta en cada hilo de transicion al final de 1 ciclo de ejecucion

Listar tripulantes
Tenemos una lista global

Expulsar tripulante
le cambiamos un parametro que tiene el trip y lo atendera algun hilo o algun nucleo dentro de la funcion atencion_interrupcion()

Sabotaje
Tambien una especie de pausar_planificacion


// DEBug y corregciones de los demas modulos en conjunto
free mal echos
fclose no echos
variables sin inicializar


Cual es el objetivo del modulos
Como lo hace a grandes rasgos (a tu criterio)