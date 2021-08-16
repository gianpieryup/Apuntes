#include <stdlib.h> // [atoi] esta incluido
#include <stdio.h>
#include <commons/string.h>
#include <commons/collections/list.h>
#include <commons/log.h>

// NO HAY MEMORY LEAKS [YEAHHH] + IMPLEMENTACION DE LOGS
// gcc p_commons.c -lcommons -o cm

typedef struct{
    char *region;
    char *nombre_apellido;
    int edad;
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
    printf("%-14s | %-10s | %2d | %3d\n",alu->nombre_apellido,alu->region,alu->edad,alu->saldo);
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
}

int main ( void ){   
    FILE *archivo;
    archivo = fopen("prueba.txt","r");
    char caracteres[100];
    
    // [LOGSS]
    t_log* logger =  log_create("res.log", "res", 1, LOG_LEVEL_INFO);
    // [LISTA]
 	t_list * lista_personas = list_create();

    while (feof(archivo) == 0){
 		fgets(caracteres,100,archivo);
        char** str_spl = string_split(caracteres, ";");

        char* region_dup = string_duplicate(str_spl[0]);
        char* nom_apell_dup = string_duplicate(str_spl[1]);

        t_alumno*al = malloc(sizeof(t_alumno)); //malloc(50); NO PORFAVOR NO
        al->region = region_dup;
        al->nombre_apellido = nom_apell_dup;
        al->edad=atoi(str_spl[2]);
        al->num_telefono=atoi(str_spl[3]);
        al->dni=atoi(str_spl[4]);
        al->saldo=atoi(str_spl[5]);

        list_add(lista_personas, al);
        liberar_lista_string(str_spl);
 	}
    fclose(archivo);

    log_info(logger,"Tenemos toda la lista en memoria");// PARA USAR EL LOG/APARTE QUE ME HACE UN PRINTF
    //printf("Tenemos toda la lista en memoria\n---------------\n");
    list_iterate(lista_personas, (void*)iterator);//QUE GOZU SIN USAR FOR

    //t_list* lista_personas = list_filter(lista_personas, filtrar_edad); 
    // No puedo estoy redefiniendo el puntero :v

    //Filtrar Los menores de 18 años[OJO CON LA NOTACION DEL PASADO DE FUNCION POR PARAMETRO]
    t_list* lista_filtrada = list_filter(lista_personas, (void*)filtrar_edad); 
    
    log_info(logger,"Lista Filtrada: Menores de 18");
    //printf("\nLista Filtrada: Menores de 18\n---------------\n");
    list_iterate(lista_filtrada, (void*)iterator);

    // ORDENAR LISTA
    list_sort(  lista_filtrada, (void*)ordenar_region );
    log_info(logger,"Lista Ordenada por Region y edad");
    //printf("\nLista Ordenada por Region y edad\n---------------\n");
    list_iterate(lista_filtrada, (void*)iterator);
    

    /*Escribir el archivo de salida */
    FILE *arc_salida;
    arc_salida = fopen("salida.txt","w");
    
    log_info(logger,"Logueamos a las personas con menos de $100 de saldo");

    for (int i = 0; i < list_size(lista_filtrada); i++)
    {
        t_alumno*alu =list_get(lista_filtrada,i);// No estoy reservando memoria??????? O solo estoy definiendo un puntero con una direccion de memoria
       
        char *unaPalabra = string_new();
        string_append(&unaPalabra,alu->region);
        string_append(&unaPalabra,"|");

        char* edad_d = string_itoa(alu->edad);
        string_append(&unaPalabra,edad_d);    //string_itoa(alu->edad) | aqui se crea un char y no se libera
        string_append(&unaPalabra,"|");

        char* alu_d = string_itoa(alu->dni);
        string_append(&unaPalabra,alu_d);
        string_append(&unaPalabra,"|");
        string_append(&unaPalabra,alu->nombre_apellido);
        string_append(&unaPalabra,"|");

        char* num_d = string_itoa(alu->num_telefono);
        string_append(&unaPalabra,num_d);

        if (alu->saldo < 100)
        {
           // SI QUIERO DE TODAS LAS PERSONAS LO PONGO EN EL FOR DE ARRIBA 
           log_info(logger,alu->nombre_apellido);
           //Si lo pongo mas abajo me como el '\n'  ():v)
        }

        string_append(&unaPalabra,"\n");

        fputs( unaPalabra, arc_salida ); // Escribimos la oracion en el archivo
        //alu_destroy(alu);  // Si pongo esto estoy borrando las DM de la lista y eso lo hago al final

        

        free(unaPalabra);
        free(edad_d);
        free(alu_d);
        free(num_d);
    }

 	fclose ( arc_salida );
    
    log_destroy(logger);
    list_destroy_and_destroy_elements(lista_personas, (void*) alu_destroy);// Primero borro toda la lista original y sus elemtos(si lo hago de la filtrada me van a quedar sin liberar los elem que filtro)
	// AHORA: en la "lista_filtrada" solo tiene elem que son direcciones a espacios de memoria NULL por que lo limpie. Solo me falta liberar esta "lista_filtrada"
    list_destroy(lista_filtrada);
    return 0;
}