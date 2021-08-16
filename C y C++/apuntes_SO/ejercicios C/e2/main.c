#include "tad_archivo.h" // #include <stdio.h> ya lo contiene

int main()
{
    char *filename = "new.txt";
    FILE *archivo = abrir_archivo(filename,READ);
    leer_linea_determinada(archivo,1);
    cerrar_archivo(archivo);
    return 0;
}