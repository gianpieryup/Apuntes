/*
 * main.c
 *	En vs Lo unico que hay que hacer es corregir este archivo y hacer make y luego el ejecutable
 *  Primero abrir el servidor
 *  Luego ejecutar el cliente que es este    
 */

#include "tp0.h"

int main(void)
{
	/*---------------------------------------------------PARTE 2-------------------------------------------------------------*/
	int conexion;
	char* ip;
	char* puerto;
	char* valor;

	t_log* logger;
	t_config* config;

	logger = iniciar_logger();

	//Loggear "soy un log"
	log_info(logger,"soy un log");

	config = leer_config();

	//asignar valor de config a la variable valor
	valor = config_get_string_value(config, "CLAVE");

	//Loggear valor de config
	log_info(logger,valor);

	leer_consola(logger);// HASTA QUE NO TERMINE ESTE READLINE NO SE EJECUTARA EL SIGUIENTE
	// ME REFIERO AL DE ABAJO OSEA EL DE paquete(conexion)


	/*---------------------------------------------------PARTE 3-------------------------------------------------------------*/

	//antes de continuar, tenemos que asegurarnos que el servidor esté corriendo porque lo necesitaremos para lo que sigue.

	//crear conexion
	ip = config_get_string_value(config, "IP");
	puerto = config_get_string_value(config, "PUERTO");
	conexion = crear_conexion(ip,puerto);

	//enviar CLAVE al servirdor
	enviar_mensaje(valor,conexion);
	paquete(conexion);

	terminar_programa(conexion, logger, config);
}

t_log* iniciar_logger(void)
{
	return log_create("tp0.log", "TP0", 1, LOG_LEVEL_INFO);
}

t_config* leer_config(void)
{
	return config_create("tp0.config");
}

void leer_consola(t_log* logger)
{
	char* leido = readline(">");

	while(strncmp(leido, "", 1) != 0) {
			log_info(logger, leido);
			free(leido);
			leido = readline(">");
	}
	free(leido);
	printf("Fin del leer consola para logs\n******************\nEmpieza consola para enviar por SOKETCS\n");
}

void paquete(int conexion)
{
	//Ahora toca lo divertido!

	char* leido = readline(">");
	t_paquete* paquete= crear_paquete();

	while(strncmp(leido, "", 1) != 0) {
		agregar_a_paquete(paquete, leido, strlen(leido) + 1); // El +1 es por el '/0'
		free(leido);
		leido = readline(">");
	}

	free(leido);
	enviar_paquete(paquete,conexion);
	eliminar_paquete(paquete);

}

void terminar_programa(int conexion, t_log* logger, t_config* config)
{
	//Y por ultimo, para cerrar, hay que liberar lo que utilizamos (conexion, log y config) con las funciones de las commons y del TP mencionadas en el enunciado
	liberar_conexion(conexion);
	log_destroy(logger);
	config_destroy(config);
	printf("FIN\n");
}
