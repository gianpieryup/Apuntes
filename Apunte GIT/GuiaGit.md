<img src="gitlogo.jpg" alt="gitlogo" style="zoom:40%;" />

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











