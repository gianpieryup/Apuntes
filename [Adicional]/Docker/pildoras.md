# Pildoras de Docket

Curso de Youtube del chabon de **Pildoras de Programacion** (un crack)

## Ejemplo Basico

Ejemplo de creacion e un servidor enginex, para ejecuta un contenedor:

```sh
$ docker run --name test -d -p 8080:80 nginx:lastest
```

- `run` : corre o crea si no existe el container
- `--name` : el alias del container
- `-d` : (modo deteach) para que no nos bloquee la consola
- `-p p1:p2` : para que todo el trafico de mi *puerto de mi compu* `p1`, hacia el *puerto del contenedor* `p2`
- `nginx:lastest` nombre de la **imagen**:[version], si no la encuentra en la maquina la descarga de **Docker Hub**

