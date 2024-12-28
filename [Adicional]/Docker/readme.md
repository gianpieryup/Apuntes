# Desktop

Que es docket Desktop ?

- Una Virtual machine → Corre Linux (Ejecutar containers)
- Permite acceder al sistema de archivos, también a la red
- También incluye, Docker Compose, CLI … otras herramientas más.
- Corre nativo en windows WSL2(Windows Subsystem for Linux)

## Instalacion

Ahora es tan simple como buscar Docker Desktop y descargarte el intalador.

Los prerequisitos en Windows es tener WSL , que ya la mayoria de los Windows lo tiene.

Con este comando puedes visualizar la version.

```sh
> wsl -l -v
  NAME              STATE           VERSION
* docker-desktop    Stopped         2
```

Recuerde que para usar Docker debe abrir Docker Desktop y dejarlo abierto.
Asegurese de que no este pausado, abajo debe decir **Engine Running**. Ahora si abra si CMD y podra usar los comandos del CLI.


## Imagenes

Todas se descargan de la pagina web ``Docker Hub``, especificamente el comando de la imagen a descargar.

```sh
$ docker images

# Instale una imagen de cassandra, como no especifique la version sera la lasted
$ docker pull cassandra

# Vemos info detallada de la imagen que descargue
$ docker images
REPOSITORY   TAG       IMAGE ID       CREATED        SIZE
cassandra    latest    5d4795c41491   2 months ago   577MB

# Borrar Imagen
$ docker image rm cassandra
```



## Containers

Usaremos como base la de mongo, porque no necesitas realizar muchas configuraciones para levantarlo

```sh
$ docker pull mongo

# Esto nos devolvera el ID del container
$ docker create mongo
40e7b0564966cdd401194d795decaa7da3cc1e81301910cad884945aa0473d94

# Arrancar nuestro container
$ docker start 40e7b0564966cdd401194d795decaa7da3cc1e81301910cad884945aa0473d94

# Verificar status de los container que estan corriendo
# IMAGE: La 'imagen' base con la que fue creada
# NAME: Nombre de nuestro contenedor
$ docker ps
CONTAINER ID   IMAGE     COMMAND                  CREATED              STATUS          PORTS       NAMES
40e7b0564966   mongo     "docker-entrypoint.s…"   About a minute ago   Up 32 seconds   27017/tcp   peaceful_sinoussi

# Parar container
$ docker stop 40e7b0564966

# Esta vacio? Pues claro, este solo muestra los que estam en RUN
$ docker ps

# Ahora si
$ docker ps -a

# Borramos
$ docker rm peaceful_sinoussi
```

### Alias

Si, ponemos ponerle alias a los containers (asi es mas facil)

```sh
$ docker create --name monguito mongo
$ docker start monguito
$ docker ps
```

Bueno, pero por mas de que este prendido y tenga un puerto aun no podemos usar el container. Para este debemos solucionar un tema de Puertos.

### Puertos

Entonces como quedaria, borremos nuevamente el container `monguito` y ahora lo crearemos con el parametro especifico del puerto. Si no le ponemos medio que lo hace docker y no tenemos control (siempre es preferible ponerlo nosotros)

```sh
$ docker create -p27017:27017 --name monguito mongo
7af9a8dff314ddce61a5651d36e6d25ac08f853eda41817dc3107227559ce095

# Vamos a ver en la colummna PORTS como es la asignacion(el mapeo)
$ docker start monguito
CONTAINER ID   IMAGE     COMMAND                  CREATED              STATUS          PORTS                      NAMES
7af9a8dff314   mongo     "docker-entrypoint.s…"   About a minute ago   Up 43 seconds   0.0.0.0:27017->27017/tcp   monguito
```

Bueno y como verifico que el servidor de mongo esta andando ?

```sh
# Podemos ver los logs que hay asta el momento.
$ docker logs monguito

# Si quiero quede en modo escucha(para dejar la ventana y ver si aparecen nuevos logs)
$ docker logs --follow monguito
```

Ahora borremos todo :)

Desde el vacio, se puede usar el comando RUN y con una simple linea se puede crear todo un contenedor y que salga corriendo
1. Si no encuentra una imagen la descarga
2. Crea un container en base a la imagen
3. Inicia el container en modo --follow

```sh
# Lo carga con todos parametros por defecto
$ docker run mongo

# Para no estar en la verdion --follow
$ docker run -d mongo

# Pero tambien tengo la opcion de especificarlo
$ docker run --name monguito -p27017:27017 -d mongo
```

Ojo que cada vez que ejecutamos el comando RUN se creara un container nuevo.


## Ejemplos

Comensando con el de mongo, borremos de nuevo el container.

Aclaracion: No lo pude hacer correr porque, me olvide de Node y bueno, pero es algo asi.

```sh
$ docker rm monguito

# En este caso segun la documentacion oficial debo pasarle unas variables de entorno
# -e : nombre de variable de entotno
$ docker create -p27017:27017 --name monguito  -e MONGO_INITDB_ROOT_USERNAME=nico -e  MONGO_INITDB_ROOT_PASSWORD=password mongo

$ docker start monguito
```

En Node
```js
import express from 'express'
import mongoose from 'mongoose'

const Animal = mongoose.model('Animal', new mongoose.Schema({
  tipo: String,
  estado: String,
}))

const app = express()

// Tal cual como fue creado [nico][password]
mongoose.connect('mongodb://nico:password@monguito:27017/miapp?authSource=admin')

```