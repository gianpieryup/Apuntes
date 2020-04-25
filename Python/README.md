<p align="center"><img src="Python-logo.png" alt="Python-logo" width="200px"/></p>

## Configuraciones

Para tu computadora, abre la terminal

````shell
`Instalar numpy`
$ pip install numpy

`Instalar pandas`
$ pip install pandas
````



### Formato de Salida

````python
#Si {0:3} Se justifica hacia la derecha empezando 3 espacios

1|2|3|
------
    1
    2
   12
  231


#Si {0} Se justifica hacia la izquierda desde el lugar inicial

1
123
12
123
66666
````



### Switch en Python

No existe la palabra clave `switch`  

````python
def switch_demo(argument):
    switcher = {
        1: "January",
        2: "February",
        3: "March",
        4: "April",
        5: "May",
        6: "June",
        7: "July",
        8: "August",
        9: "September",
        10: "October",
        11: "November",
        12: "December"
    }
    print switcher.get(argument, "Invalid month")   
````

