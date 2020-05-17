# C / C++

### Diferencias entre C y C++

C es un subconjunto de C++ , dado que C++ tiene mas cosas como (herencia,objetos,..) que C no tiene implementado



### Espacio de nombres (namespace)

Los espacios de nombres se utilizan para organizar el código en grupos lógicos y para evitar colisiones de nombres que pueden ocurrir especialmente cuando su base de código incluye varias bibliotecas.

````c++
#include <iostream> //incluye funciones como std
//Se define que std se usara, para acceder directamente a sus funciones
using namespace std; 

//Si no lo pusiera tendria que declararlo cada ves que lo use
//Por ejemplo
using std::string a;      // string a;
std::cout<<"Hola";		  // cout<<"Hola";
````

### E/S de archivos

