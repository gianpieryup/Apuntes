## Entornos Virtuales

### ANACONDA

Si necesitas desplegar con alguna version de python especifica algun entorno te sugiero usar conda

El entorno virtual se crea en la ruta donde esta anaconda

> Mi Compu: En mi caso uso el entorno (base) de conda como mi python local, entonces cualquier pip install que haga se guardara en como dependencia de la env (base)


Aqui estan todos los comandos

https://www.campusmvp.es/recursos/post/como-gestionar-diferentes-entornos-para-python-con-conda.aspx







### PYTHON

Para trabajar con entornos virtuales debemos descargar la siguiente dependencia
````
pip install virtualenv
````

Veras todas las dependencias que instalaste en tu compu
````
pip freeze
````


##### Crear el entorno virtual

En una carpeta vacia, le doy un nombre al entorno ej:  `mi_vm` , esto me crea el entorno
````
virtualenv mi_vm
````

Se creara la carpeta `mi_vm` con los siguientes archivos

![env](env.png)


##### Activar el entorno virtuale

En la misma ruta donde esta la carpeta `mi_vm` (no dentro de esta) tipear
````
.\mi_vm\Scripts\activate
````

Ej de un entorno llamada `yolotp`

![env2](env2.png)


Ahora estas por el cmd en un entorno nuevo, juega con la consola para verificar que no siges en tu computadora :)

![env3](env3.png)

##### Apagar el entorno virtual

````
deactivate
````


