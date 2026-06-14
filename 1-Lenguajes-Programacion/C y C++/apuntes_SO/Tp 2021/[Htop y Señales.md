## HTOP y Señales

HTOP: Es un comando para ver todos los procesos (su PID/USER/USO de CPU/)

La ultima linea son comandos que podemos usar puedes acceder con el teclado o directamente con el mouse dánosle clic

En este caso se muestra el uso de filter con el nombre del ejecutable que queremos visualizar

<img src="0_INFO_de_procesos.png" alt="0 INFO de procesos" style="zoom:50%;" />

Tendríamos la siguiente vista

<img src="1_htop_filtrar.png" alt="1 Htop filtrar" style="zoom:80%;" />

Para **mandar señales** con `KILL`

![2_elegir_señal](2_elegir_señal.png)

Vemos una columna a la izquierda elegimos la señal que queremos mandar al proceso

````c
2 SIGINT  'Equivale a un Ctrl+c'
9 SIGKILL 'Equivale a un Kill PID o matar terminal'
10 SIGUSR1 'Algun tipo especifico de señal no se'    
````

