# 🚀 Instalación de Apache Airflow con Docker

[Video Youtube](https://youtu.be/IA3NkkHvfBk?si=HJbLjJa1EXWbhYSW)
 Para una instalación óptima y actualizada, lo ideal es seguir la documentación oficial de Airflow en la sección: **Home > How-to Guides > Running Airflow in Docker**.

---

## 📄 1. Descargar el archivo `docker-compose.yaml`

Buscamos la sección **"Fetching docker-compose.yaml"** para obtener el archivo de configuración. Podemos descargarlo directamente o utilizar el comando `curl`.

⚠️ **Nota para Windows (PowerShell/CMD):** `curl` no funciona igual de forma nativa en Windows. Para que corra correctamente debes usar `curl.exe` o ejecutar el comando desde la terminal de **Git Bash**.

### 🛠️ Modificación Recomendada
Antes de levantar el entorno, abre el archivo `.yaml` y cambia la siguiente línea para evitar que el sistema tarde demasiado cargando datos de prueba:

```yaml
AIRFLOW__CORE__LOAD_EXAMPLES: 'false'
```

*(Por defecto viene en `'true'`. Cambiarlo a `'false'` ahorra mucho tiempo y mantiene limpia tu interfaz).*

---

## 🔑 2. Inicialización del Entorno

### Configurar Directorios y Variables de Entorno

Ejecuta los siguientes comandos para crear la estructura de carpetas necesaria y configurar el usuario de Airflow:

```bash
# Crear las carpetas locales que se sincronizarán con el contenedor
mkdir -p ./dags ./logs ./plugins ./config

# Crear el archivo .env con el UID del usuario actual
echo -e "AIRFLOW_UID=$(id -u)" > .env
```

📌 *Nota: El comando `id -u` requiere un entorno basado en Linux/POSIX, por lo que debes ejecutarlo obligatoriamente desde **Git Bash** o **WSL** si estás en Windows.*

### Inicializar la Base de Datos

Antes de levantar la aplicación por primera vez, debes crear y migrar la base de datos de los servicios:

```bash
docker compose up airflow-init
```

---

## ⚡ 3. Ejecutar Airflow

Una vez inicializada la base de datos, ya puedes encender todos los servicios en segundo plano:

```bash
docker compose up -d
```

📌 **Tip Pro:** Se recomienda usar el flag `-d` (detached mode). De lo contrario, la terminal se inundará con los logs en tiempo real de los 5 contenedores en simultáneo, volviéndose ilegible.

Para verificar que todo se levantó correctamente, ejecuta:

```bash
docker ps
```


### 📦 Estructura de Contenedores Creados

Al levantar el servicio, notarás que la arquitectura de Airflow se divide en varios contenedores especializados:

| CONTAINER ID | IMAGE | COMMAND | PORTS | NAMES |
| :--- | :--- | :--- | :--- | :--- |
| `247ebe6cf87a` | `apache/airflow:3.2.1` | `"/usr/bin/dumb-init …"` | 8080/tcp | `compose_airflow-worker_1` |
| `ed9b09fc84b1` | `apache/airflow:3.2.1` | `"/usr/bin/dumb-init …"` | 8080/tcp | `compose_airflow-scheduler_1` |
| `7cb1fb603a98` | `apache/airflow:3.2.1` | `"/usr/bin/dumb-init …"` | 0.0.0.0:8080->8080/tcp | `compose_airflow-api_server_1` |
| `74f3bbe506eb` | `postgres:16` | `"docker-entrypoint.s…"` | 5432/tcp | `compose_postgres_1` |
| `0bd6576d23cb` | `redis:latest` | `"docker-entrypoint.s…"` | 0.0.0.0:6379->6379/tcp | `compose_redis_1` |


📌 Notar que tenemos 3 containers del tipo ``airflow``: WORKER - SCHEDULER - API_SERVER 

Una vez que todos figuren como activos, ingresa desde tu navegador a:
- 🌐 **URL:** `http://localhost:8080`
- 👤 **Usuario y Contraseña por defecto:** `airflow` / `airflow`


Dejamos de ejecutar la terminal con ``Ctrl + C``

⚠️ Nota importante sobre la base de datos

Si después de reiniciar siguen apareciendo los ejemplos, es porque ya se cargaron en la base de datos de Postgres la primera vez que levantaste el servicio. En ese caso, la forma más rápida de limpiar todo (si estás empezando y no tienes datos importantes aún) es:  

```Bash
# Esto borrará los volúmenes y limpiará la base de datos por completo
docker-compose down --volumes
docker-compose up -d
```

📌 recomiendo usar el comando con el flag de deteach (-d) asi no tenemos 500 LOGS y vemos cual aun esta pendiente de terminar y cual no.

Solo falta crear un DAG de prueba y ver que aparezca en la pantalla de Airflow


Para probar que tu instalación de Airflow está funcionando correctamente (y que ahora está limpia de ejemplos), vamos a crear un **DAG (Directed Acyclic Graph)** muy sencillo[cite: 1].

### 1. Instrucciones de preparación
1.  Ve a la carpeta que creaste anteriormente llamada `./dags`[cite: 1].
2.  Crea un nuevo archivo dentro de esa carpeta llamado `dag_prueba.py`[cite: 1].
3.  Copia y pega el siguiente código:



### 2. Cómo probarlo en la interfaz de Airflow
Una vez que guardes el archivo, Airflow tardará entre **30 y 60 segundos** en detectarlo automáticamente en la interfaz web[cite: 1].

1.  Abre tu navegador en `http://localhost:8080` (el puerto que vimos en tu tabla de contenedores)[cite: 1].
2.  Busca el DAG con el nombre `mi_primer_dag_de_prueba`[cite: 1].
3.  **Activa el DAG:** Haz clic en el interruptor (Toggle) para ponerlo en "On" (azul)[cite: 1].
4.  **Ejecutar:** Haz clic en el icono de "Play" (Trigger DAG) en la esquina superior derecha[cite: 1].
5.  **Ver resultados:** Haz clic en el nombre del DAG, ve a la pestaña **Graph** o **Grid**, selecciona el cuadradito verde de la tarea ejecutada y busca la opción **Logs**[cite: 1]. Deberías ver el mensaje: *"¡Hola! Tu instalación de Airflow está funcionando correctamente 🚀"*[cite: 1].



### 💡 Tip para tu README
Puedes agregar esta pequeña sección de "Comandos de Mantenimiento" a tus apuntes:

| Tarea | Comando (en Git Bash) |
| :--- | :--- |
| **Levantar Airflow** | `docker-compose up -d`[cite: 1] |
| **Bajar Airflow** | `docker-compose down`[cite: 1] |
| **Limpiar Volúmenes** | `docker-compose down --volumes`[cite: 1] |
| **Ver Logs** | `docker-compose logs -f`[cite: 1] |
