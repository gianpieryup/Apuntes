#include <stdlib.h> // [atoi] esta incluido
#include <stdio.h>
#include <commons/string.h>
#include <commons/collections/list.h>

// NO HAY MEMORY LEAKS [YEAHHH]

typedef struct{
    char *region;//
    char *nombre_apellido;//8bits
    int edad;//4bits
    int num_telefono;
    int dni;
    int saldo;
} t_alumno;

bool filtrar_edad(t_alumno*aux){// ASI SE DECLARABA PTMR
    //t_alumno*aux=element; en la implemetacion agregar (*void)
    //sihago lo de arriba estoy duplicando una estructura
    return (aux -> edad) < 18;
}

bool ordenar_region(t_alumno *alu1, t_alumno *alu2){// Ordenar segun su Región y Edad.
    //t_alumno*alu1=elem1; [IDEM que arriba]
    //t_alumno*alu2=elem2;

    if (alu1->region[0] <= alu2->region[0])// Trampita solo compara los dos primeros char [Hay? algo en las commons]
    {
        if (alu1->region[0] == alu2->region[0]) // Para la edad
        {
            return alu1->edad < alu2->edad; 
        }else
            return true;
        
    }else
        return false;
    
    
}

void iterator(t_alumno* alu){// [ITERAR USANDO COMMONS]
    printf("%-14s | %-10s | %2d\n",alu->nombre_apellido,alu->region,alu->edad);
}

void alu_destroy(t_alumno* alu) {
	free(alu->region);
    free(alu->nombre_apellido);
	free(alu);
}

void liberar_lista_string(char**lista){
    int i=0;
    while (lista[i]!= NULL){
        free( lista[i]);
        i++;
    } 
    free(lista); 
    /* 
    for (int i = 0; i < sizeof(lista); i++) {     ERROR NO USAR EL SIZEOF SIEMPRE RETORNA 4 NO MAMES
        free( lista[i]);
    }
    free(lista); 
    */
}

int main ( void ){

    char caracteres[100];
    FILE *archivo; 	
 	t_list * lista_personas = list_create();


 	archivo = fopen("prueba.txt","r");
    while (feof(archivo) == 0){
 		fgets(caracteres,100,archivo);
        char** str_spl = string_split(caracteres, ";");//[Liberar elem y lista]

        char* region_dup = string_duplicate(str_spl[0]);
        char* nom_apell_dup = string_duplicate(str_spl[1]);

        t_alumno*al = malloc(sizeof(t_alumno)); //malloc(50); NO PORFAVOR NO
        al->region = region_dup; // str_spl[0]; si los dejo como antes no puedo liberar el 'str_spl'
        al->nombre_apellido = nom_apell_dup; // str_spl[1];
        al->edad=atoi(str_spl[2]); //los int no tienen problema
        al->num_telefono=atoi(str_spl[3]);
        al->dni=atoi(str_spl[4]);
        al->saldo=atoi(str_spl[5]);

        //Lo que tiene la lista son referencias a los elementos a donde apunta
        list_add(lista_personas, al);

        //Si destuyo el elemento, se pierde la referencia que esta en la lista
        //alu_destroy(al);//Rompe por lo anterior
        
        //free(str_spl); [ESTAS LIBERARNDO EL ARRAY Y NO SUS ELEMENTOS]
        liberar_lista_string(str_spl);// Para que esto no borre la info de los char
        //Es que lo duplico asi si borro esto no se borra en la lista por que lo duplique
 	}

    fclose(archivo);

    /* //[COMO IMPRIMIR UNA LISTA]
    printf("Tenemos toda la lista en memoria\n---------------\n");
    for (int i = 0; i < list_size(lista_personas); i++) 
    {
        t_alumno*alu =list_get(lista_personas,i);
        printf("%s\n",alu->nombre_apellido);
    }*/

    printf("ALTERNATIVA USANDO COMMOS\n");
    list_iterate(lista_personas, (void*)iterator);//QUE GOZU SIN USAR FOR

    list_destroy_and_destroy_elements(lista_personas, (void*) alu_destroy);
    return 0;
}  