<div align="center">
	<code><img width="100" src="https://user-images.githubusercontent.com/25181517/192108372-f71d70ac-7ae6-4c0d-8395-51d8870c2ef0.png" alt="Git" title="Git"/></code>
</div>

## INDICE
<!-- TOC -->

- [Comandos Básicos](#Comandos-Básicos)
    - [Git Stash](#Git-Stash)

<!-- /TOC -->






## Comandos Básicos

#### Clonar un repositorio

````shell
$ git clone url/delrepo
````

#### Actualizar cambios

````shell
$ git pull
````

#### Ver el estado de los archivos

````shell
$ git status
````

#### Agregar archivos

````shell
-- De a uno
$ git add archivo.js

-- Opcional: para subir todos los cambios
$ git add .
````

#### Comitear

````shell
$ git commit -m "Una frase referida a los cambios"
````

#### Configuración de cuenta

````shell
git config --global user.email gyupanquisalvatierra@gmail.com
git config --global user.name gianpieryup
````

#### Subir cambios

````shell
git push
````


#### Git Stash
El comando git stash almacena temporalmente (o guarda en un stash) los cambios que hayas efectuado en el código en el que estás trabajando para que puedas trabajar en otra cosa y, más tarde, regresar y volver a aplicar los cambios más tarde. Guardar los cambios en stashes resulta práctico si tienes que cambiar rápidamente de contexto y ponerte con otra cosa, pero estás en medio de un cambio en el código y no lo tienes todo listo para confirmar los cambios.

[>> Documentacion](https://www.atlassian.com/es/git/tutorials/saving-changes/git-stash)


```python
# Coge los cambios sin confirmar (tanto los que están preparados como los que no), los guarda aparte para usarlos más adelante y, acto seguido, los deshace en el código en el que estás trabajando.
git stash

# Puedes volver a aplicar los cambios de un stash mediante el comando
git stash pop
```



####  Me arrepiento de hacer un `git add`

````shell
git reset
````



#### Orden Tradicional

````shell
git add .
git commit -m ""
git pull (MUY IMPORTANTE)
git push
````

<span style='color:red'>**NO HACER**</span>

````shell
git commit   y luego un git push 
/ puede incluso salir error diciendo falta hacer un git pull
/ es para estar actualizado si nadie comiteo dara lo mismo hacer el pull 
````

<span style='color:blue'>**MERGE**</span>

````shell
git commit -m ""
git pull
/ Si se realizo cambios en el mismo archivo
/ aparece un "conflito", me aparecera en vs

>> Mis cambios
<< Los otros cambios
Decidir "aceptar mis cambios","aceptar los otros cambios","aceptar ambos"
Luego de elegir cual, en VScode

En la terminal
git status -> me sale que realice un cambio
git add .
git commit -m "arregle merge conflic"
git push
````

### Revertir un PUSH

````shell
git add .
git commit -m ""
git push
--- "huy este cambio no lo quise subir" ---
git log  // Eso me muestra los hash(id) de cada commit
# Estam ordena por fecha, identificar el ultimo o con el nombre
# El hash es un alfanumerico enorme
git revert poner_el_hash

# Me saldra la terminal (podemos editar el txt del commit pero yo se lo dejo)
# Ctrl + X
git status
git push
````





### La vendita terminal VIM

Cuando hay conflictos hay que pasar por esta pantalla, veamos como salimos de esta

1. Empiezas en la terminal en `modo insertar`, si no lo estas, presiona <kbd>i</kbd> 
2. Escribe el mensaje, `se nota que abajo dice el modo --INSERTAR--`
3. Al terminar de escribir presiona <kbd>esc</kbd> y aparecerá el cursor en la ultima línea
4. Tipea <kbd>:wq</kbd>   (write & quit) para guardar y salir de esta consola

#### Logs

Para ver todos los commits que hemos creado

````shell
$ git log

commit 2278d9ssdas
Author : gianpieryup
Date : Mon Jan 4 21:02:30
	El primer commit
	
-----
$ git status
On branch master //estas en la rama master
nothing to commit, working tree clean //Nada para comitear
````

#### Checkout

Para revertir los cambios de los archivos, pone le que cambiamos algo pero quiero volver al anterior, especificar el archivo

````shell
$ git checkout -- index.html
````

#### Diferencias

Me muestra que cambios se hicieron en el archivo con respecto a la ultima actualización

````shell
git diff index.html
````

#### Archivos a ignorar

Podemos decidir que archivos y carpetas no quiero subir, sirve para cosas pesadas como dependencias.

Para hacer esto debemos crear un archivo llamado `.gitignore` , dentro escribimos que no se va a subir al repositorio

````javascript
//En el arhivo .gitignore
cosapesada.txt
algo.js

//Para carpetas usar la siguiente notacion
node_modules
/rest/node_modules/
/backend/node_modules/
/backend/.env
````

> TIP : Las carpetas vacías se ignorar por defecto

### Ramas

````shell
Para saber en que rama estoy
$ git branch
* master

Crear una rama, una copia de lo tengas hasta ese momento
$ git branch login

Moverte entre ramas
$ git checkout login
````











