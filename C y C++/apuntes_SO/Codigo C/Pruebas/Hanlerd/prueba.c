#include <stdlib.h> // [atoi] esta incluido
#include <stdio.h>
#include <commons/string.h>

void liberar_lista_string(char **lista)
{
    int i = 0;
    while (lista[i] != NULL)
    {
        free(lista[i]);
        i++;
    }
    free(lista);
}


void main () {

    char *p = "[1|1,3|3,4|5]";
    char**  magio = string_get_string_as_array(p);

    // PROCESO PARA RECORRER- INCLUYE LIBERACION DE MEMORIA
    int i = 0;
    while (magio[i] != NULL)
    {
        // ******
        char **posiciones = string_split(magio[i], "|");
        int x = atoi(posiciones[0]);
        int y = atoi(posiciones[1]);
        printf("(%d,%d) \n",x,y);
        liberar_lista_string(posiciones);

        //free(magio[i]);
        i++;
    }
    liberar_lista_string(magio);
    //free(magio);
}