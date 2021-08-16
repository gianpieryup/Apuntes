********************************************************
**			ＢＵＧＳ － ＰＥＲＦＯＲＭＡＮＣＥ			 **
********************************************************


［ＣＯＲＲＥＧＩＲ］


［ＭＥＪＯＲＡＳ ＤＥ ＰＥＲＦＯＲＭＡＮＣＥ］




4.  De hecho, un consejo para el TP: les recomiendo ir jugando con los distintos niveles de log según la necesidad que tengan. 
    Por ejemplo, pueden para el día a día codear en nivel LOG_LEVEL_DEBUG usando log_debug()s. 
    Una vez que vean que lo que loguean es lo esperado ir pasando esos log_debug() a log_trace(), 
    ya que si más adelante hacen un cambio que rompe algo anterior pueden elegir cambiar el nivel a LOG_LEVEL_TRACE y ver en detalle qué está pasando. 
    Otra ventaja que tiene esto es que en la entrega pueden decidir subir el nivel a LOG_LEVEL_INFO y ocultar todos esos mensajes en una sola línea de código y sin tener que quitarlos.




*********************************
*	𝗕𝗨𝗚𝗦 𝗣𝗔𝗦𝗔𝗗𝗢𝗦            *
*********************************
// Si este es un trip que termino 1  tarea y es justo el elegido para el sabotaje/ cuando termine no le puedo asignar esta tarea con 0/ muya aparte de ser ilogico rompe por que primero resta 0-1=-1 y luego comprueba si es ==0 entonces  se va hasta el -1,-2,-3....
// Errores de condicion de carrera
// se pausea todo cuando se crea 3 patotas


********************************************************************************