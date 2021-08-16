#include <stdio.h>

typedef enum{
    READ,
    WRITE,
    APPEND
}forma_open;

FILE * abrir_archivo(char*arc,forma_open fo);
void cerrar_archivo(FILE *arc);
void leer_linea_determinada(FILE *archivo,int linea);
