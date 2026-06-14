## README: Configuración de Docker para Aplicación FastAPI

📌 *No olvidar que el simbolo puntito (.) hace referencia a todo el directorio donde estas parado.*

### Descripción General
Este archivo `Dockerfile` define el entorno de ejecución para una aplicación Python (específicamente diseñada para **FastAPI** con **Uvicorn**). Utiliza una imagen base ligera y configura el entorno de trabajo, las dependencias y el comando de ejecución necesario para el despliegue de contenedores.

### Detalles de las Instrucciones

*   **Imagen Base:** `python:3.11-slim`.
    *   Utiliza Python 3.11 en su versión "slim" para reducir el tamaño de la imagen final y mejorar la seguridad al eliminar paquetes innecesarios.
*   **Directorio de Trabajo:** `/code`.
    *   Define la ruta dentro del contenedor donde se realizarán todas las operaciones posteriores.
*   **Gestión de Dependencias:**
    1.  `COPY requirements.txt .`: Copia el archivo de requisitos al directorio de trabajo.
    2.  `RUN pip install --no-cache-dir -r requirements.txt`: Instala las librerías necesarias sin guardar la caché de pip para optimizar el espacio del contenedor.
*   **Copia de Código:** `COPY . .`.
    *   Transfiere el resto del código fuente del proyecto al contenedor.
*   **Red y Puertos:** `EXPOSE 8000`.
    *   Informa que el contenedor escuchará en el puerto **8000** en tiempo de ejecución.
*   **Comando de Inicio (CMD):**
    *   Ejecuta el servidor **Uvicorn**.
    *   Apunta al objeto `app` dentro del archivo `main.py`.
    *   Configura el host en `0.0.0.0` para permitir conexiones externas y activa `--reload` para facilitar el desarrollo (reinicio automático al detectar cambios).



### Notas de Uso
Para construir y ejecutar este contenedor, puedes utilizar los siguientes comandos en tu terminal:

1.  **Prende el docker:**
    La app de escritorio Docker Desktop
2.  **Construir la imagen:**
    `docker build -t mi-app-fastapi .`

    Esto busca el archivo Dockerfile en el directorio y lo ejecuta.

    📌 `docker images` : Para ver todas las imagenes creadas.
3.  **Ejecutar el contenedor:**
    `docker run -p 8000:8000 mi-app-fastapi`

    Crea un contenedor a partir de la imagen (`mi-app-fastapi`)

⚠️ Para asignar un nombre específico a tu contenedor al momento de ejecutarlo, debes utilizar el parámetro `--name`.

Si no incluyes esta opción, Docker asignará automáticamente un nombre aleatorio


# Volumnes

Si queremos actualizar mi codigo, eso no se actualiza automaticamente en docker.

Tengo que borrar el container y volverlo a crear 😔 -> Para no hacer esto existe el concepto de Volumenes

DEF: Un tipo de ENLACE entre DOCKER y mi LOCAL. para que cuando exista algun cambio en mi codigo local, se actualizen esos cambios con los que estan en el contenedor.

Ejecutando el siguiente comando (fijarse que solo se agrego el flag ``-v``)

### Comando

```sh
docker run -d -p 8000:8000 -v ${pwd}:/code mi-app-fastapi
```

📌 `${pwd}` : Es un comando de powershell que devuelve la ruta donde estas parado

📌 La notacion (:) linkea una ruta con otra ``(ruta_local:ruta_docker)``


## 🔌 Integración con VS Code

Si programas desde local, VS Code te marcará errores de autocompletado y librerías inexistentes porque las dependencias están instaladas *dentro* del contenedor, no en tu máquina. Para solucionar esto, podemos conectar VS Code directamente a Docker.

### Extensiones Necesarias
* **Docker** (*Microsoft*)
* **Dev Containers** (*Microsoft*)

### Método 1: Conectarse a un contenedor que ya está corriendo (Attach)
1. Haz clic en el botón verde de la **esquina inferior izquierda** de VS Code (o abre la paleta de comandos con `Ctrl + Shift + P` y busca `Dev Containers: Attach to Running Container...`).
2. Selecciona el contenedor de la lista.
3. Se abrirá una nueva ventana de VS Code conectada al entorno interno de Docker (lo verás indicado abajo a la izquierda).
4. Al principio verás todo vacío: recuerda abrir la carpeta interna de Docker en la ruta `/code`.

---

### Método 2: Entornos de desarrollo aislados (Dev Containers interactivos)

Esta es la forma más rápida de inicializar un entorno de desarrollo limpio y preconfigurado dentro de un contenedor, sin renegar con configuraciones manuales.

#### Configuración Paso a Paso:
1. Haz clic en el botón de la esquina inferior izquierda y selecciona **Reopen in Container** (o *Add Dev Container Configuration Files...*).
2. Selecciona **From a predefined container configuration template** (Plantilla predefinida).
3. Elige el entorno base: **Python 3**.
4. Selecciona la versión específica (por ejemplo, **3.12-bookworm** o la que necesites).
5. Si te pregunta por características (Features) adicionales a instalar, dale a **Ok / Aceptar** sin marcar ninguna.

#### ¿Qué pasa ahora?
VS Code creará la carpeta `.devcontainer/` con la configuración y se recargará **dentro del contenedor**. 
* **Tu espacio de trabajo:** La terminal que uses ahora será de **Linux** (la del contenedor). Puedes ejecutar `pip install` o comandos del sistema con total libertad.
* **¿Dónde se guardan los archivos?:** Todo lo que programes se guarda en tiempo real en tu carpeta local gracias a un volumen automático que crea VS Code. 

#### Salir del contenedor:
Cuando termines de trabajar, vuelve a hacer clic en el botón verde inferior izquierdo y selecciona **Reopen Folder Locally**. El VS Code volverá a tu entorno de Windows nativo.

#### Tip Pro: Reconstruir el entorno
Si modificas el archivo `Dockerfile` o la configuración del contenedor y necesitas que Docker aplique los cambios, abre la paleta de comandos (`Ctrl + Shift + P`) y ejecuta:

`Dev Containers: Rebuild and Reopen in Container`

Esto reconstruirá el entorno desde cero con las nuevas instrucciones.