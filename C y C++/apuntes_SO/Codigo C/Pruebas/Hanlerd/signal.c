#include <stdlib.h> // [atoi] esta incluido
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void rutina (int n) {
	switch (n) {
		case SIGINT:
			printf("Sacame si te la bancas!!\n"); // Ctrl + C
		break;
		case SIGUSR1:
			printf("LLEGO SIGUSR1\n"); // Le tire un KILL PID , desde consola
		break;
	}
}

void main () {
    // Ya sea reciba señales de cualquiera de los dos el programa no termina,(se atiende la funcion definida y luego regresas a la ejecucion normal)
	signal(SIGINT, rutina);
	signal(SIGUSR1, rutina);
	while(1) { 
		printf("Hola Mundo\n");
		sleep(3);
	}
}


/*  raise(SIGINT) ESTE CORTA LA EJECUCION A LA ESPERA DE LA SEÑAL CONTRARIO AL OTRO
    en este caso espera una señal del tipo SIGINT -> signal_catch -> continua

    int main () {
	signal(SIGINT, signal_catch);

   printf("Se termina la charla??\n");
   raise(SIGINT);

   printf("Y… se nos termino la charla\n");
   return(0);
}

void signal_catch(int signal) {
   printf("No se termina maaaaas\n");
}
 */