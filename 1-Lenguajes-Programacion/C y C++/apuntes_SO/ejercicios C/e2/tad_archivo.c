#include "tad_archivo.h"

FILE * abrir_archivo(char*arc,forma_open fo){

    char* c;
    switch(fo){
	      case 0: c="r"; printf("ABRIR ARCHIVO MODO: READ\n"); break; // OJO que es "" no '' en c="w"
	      case 1: c="w"; printf("ABRIR ARCHIVO MODO: WRITE\n"); break;
	      case 2: c="a"; printf("ABRIR ARCHIVO MODO: APPEND\n"); break;
	}

	return fopen(arc, c);
}
void cerrar_archivo(FILE *arc){
    fclose (arc);
}
void leer_linea_determinada(FILE *archivo,int linea){
    char caracteres[100];
    for(int i=1;i<=linea;i++){
        fgets(caracteres,100,archivo);
    }
    printf("Linea %d : %s",linea,caracteres);
}
