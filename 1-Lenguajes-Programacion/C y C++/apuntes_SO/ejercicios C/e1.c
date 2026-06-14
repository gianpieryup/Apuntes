#include <stdlib.h>
#include <stdio.h>
#include <string.h>


char* string_concat(const char* a, const char* b){
    char * p = malloc(10);  // Reservo nueva memoria
    strcpy(p, a);  // copio el contenido de 'a' en 'p'// [Puedo por que el puntero 'p' aun no tiene direccion de memoria asociada(esta en nil)]
    strcat(p, b);  // concateno el contenido de 'b' en 'p'
    return p;
}   

void string_concat_dinamyc(const char* a, const char* b, char** nuevo){
    // El char** nuevo | es para pasar la referencia y que pueda ser modificado
    *nuevo = string_concat(a,b);
}

void mail_split(const char* mail, char** user, char** dominio){
   
    char* p =strchr(mail,'@');
    printf("DM de '@'= %p\n",p);
    int dicr = p - mail;
    printf("Caracter= %c , ubicado en %d\n\n",mail[dicr],dicr);
    
    char*f_user=malloc(15);//Si no pongo esto se rompe [Segmentation fault](para poder definir valores)
    char*f_dominio=malloc(15);

    for(int i=0;i<dicr;i++){
        f_user[i]= mail[i];
    }
    for(int j=dicr+1; j<strlen(mail) ;j++){
        f_dominio[j-dicr-1]= mail[j]; // OJO CON LOS INDICES [ME DEMORE 1 DIA]
    }

    *user = f_user;   //strcpy(*user, "gggg"); NO SIRVE SI YA TENGO LA D.M.
    *dominio = f_dominio;  
    /* (LO QUE SE EXPLICA ES DE QUE LA D.M del dominio apunte a f_dominio no que lo copie)    
        Entonces al cambiar el apunte, apunta a los datos que hallan en f_dominio
        No estoy copiando porque no se puede cambiar el contenido de un char* cuando es definido
        Entonces lo que se hace es crear un nuevo char* con datos y hacer que la referencia
        apunte a este nueva construccion
    */
}

int main ( void ){
    
    /*  ---    string_concat     ---------------
    char* nombre = "Ritchie";
    char* saludo = string_concat("Hola ", nombre);
    printf("saludo = %s\n",saludo);     */
    
    /*  ---    string_concat_dinamyc     --------
    char* nombre = "Ritchie";
    char* saludo;
    string_concat_dinamyc("Hola ", nombre, &saludo);
    printf("saludo = %s\n",saludo);      */
    

    char* mail = "ritchie@ansic.com.ar";
    char* user;// [IDEMA ABAJO]
    char* dominio;//estan en null aun pueden ser modificados
    mail_split(mail, &user, &dominio);
    printf("user=%s\n",user);
    printf("dominio=%s\n",dominio);
    
    return 0;
}