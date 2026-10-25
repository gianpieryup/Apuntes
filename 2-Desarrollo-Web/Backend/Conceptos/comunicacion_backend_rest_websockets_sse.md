# Resumen: Lo que necesitas saber del Backend incluso si usas IA
**Canal:** Fazt Code
**Tema Principal:** REST API vs WebSockets vs SSE (Cómo se comunican el Frontend y el Backend).

## 📌 Conceptos Clave de Comunicación

### 1. REST API (El método clásico)
*   **Cómo funciona:** Basado en el modelo de **petición y respuesta** (Request/Response) a través del protocolo HTTP.
*   **Uso práctico:** Operaciones estándar (CRUD) utilizando métodos como `GET`, `POST`, `PATCH` y `DELETE`.
*   **Limitación:** El cliente debe solicitar la información activamente; no es eficiente para el tiempo real.

### 2. Long Polling (La solución tradicional/parche)
*   **Cómo funciona:** El cliente hace una petición y el servidor mantiene la conexión abierta hasta que hay nuevos datos. Luego el ciclo se repite.
*   **Problema:** Tiene limitaciones de rendimiento y no es la forma más óptima de manejar el tiempo real en aplicaciones modernas.

### 3. WebSockets (Tiempo real bidireccional)
*   **Cómo funciona:** Establece una conexión persistente y **bidireccional** entre el cliente y el servidor.
*   **Cuándo usarlo:** Cuando ambos necesitan enviarse datos constantemente y sin demoras.
*   **Casos de uso:** Chats, sincronización en tiempo real entre múltiples usuarios, juegos multijugador.

### 4. Server-Sent Events o SSE (Notificaciones unidireccionales)
*   **Cómo funciona:** El servidor envía flujos de datos al cliente de forma continua a través de una conexión HTTP (es de una sola vía: del Servidor -> al Cliente).
*   **Cuándo usarlo:** Cuando solo necesitas recibir actualizaciones del servidor pero no enviar nada de vuelta por ese mismo canal.
*   **Casos de uso:** Feed de actividades en vivo, notificaciones, tickers de bolsa.

### 5. GraphQL (El extra para optimizar datos)
*   **El Problema que resuelve:** El *over-fetching* (descargar más datos de los necesarios en un archivo JSON usando REST).
*   **Cómo funciona:** Permite al frontend solicitar *exactamente* los campos específicos que necesita, optimizando la carga.

## 💡 Conclusión: ¿Cuándo usar cada uno?
*   Usa **REST API / GraphQL** para la carga de datos tradicional y acciones de usuario estándar.
*   Usa **WebSockets** si la aplicación requiere interacción en vivo de ida y vuelta (ej. un documento colaborativo).
*   Usa **SSE** si solo necesitas "escuchar" lo que pasa en el servidor (ej. un muro de notificaciones de un red social).