#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
 	int pid;
	pid = fork();
	if (pid < 0) {
		fprintf(stderr, "Falló");
		exit(-1);
	} else if (pid == 0) {
		/* Inicio de código de Proceso Hijo */
        sleep(10);
		printf("Soy el hijo\n");
        //execlp("/bin/ls“,"ls”,NULL);
	
		/* Fin de código de Proceso */
    }	else {
		/* Inicio de código de Proceso Padre */
	
		/* Esperar término del Hijo */
		
        //wait(NULL); // Es bloqueante espera a que termine el hijo y recien ejecuta el padre
        //sleep(5);
		printf("Child Complete\n");
		exit(0);
	
		/* Fin de código de Proceso Padre */
	}
}
