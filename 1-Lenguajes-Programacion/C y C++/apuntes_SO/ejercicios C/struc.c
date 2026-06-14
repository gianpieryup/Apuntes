#include <stdlib.h> // [atoi] esta incluido
#include <stdio.h>
#include <commons/string.h>
#include <commons/collections/list.h>

typedef struct{
    char *region;
    char *nombre_apellido;
    int edad;
    int num_telefono;
    int dni;
    int saldo;
} t_alumno;

bool filtrar_edad(t_alumno*aux){
    return (aux -> edad) < 18;
}


int main ( void ){

    char caracteres[100];
    FILE *archivo; 	
 	t_list * lista_personas = list_create();

 	archivo = fopen("prueba.txt","r");
    while (feof(archivo) == 0){
 		fgets(caracteres,100,archivo);
        char** str_spl = string_split(caracteres, ";");

        t_alumno*al = malloc(50);
        al->region = str_spl[0];
        al->nombre_apellido=str_spl[1];
        al->edad=atoi(str_spl[2]);
        al->num_telefono=atoi(str_spl[3]);
        al->dni=atoi(str_spl[4]);
        al->saldo=atoi(str_spl[5]);

        list_add(lista_personas, al);
 	}
    //t_alumno*al_new =list_get(lista_personas,1);
    //printf("%s\n",al_new->nombre_apellido);

    t_list* l_filtrada = list_filter(lista_personas, filtrar_edad);
    t_alumno*al_new =list_get(l_filtrada,1);
    printf("%s\n",al_new->nombre_apellido);
}