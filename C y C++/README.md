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

````c++
//Para leer arhicvos no olvidar el include 
#include <fstream>

int main(){
    std:ofstream fout;
    fout.open("mi_archivo.txt");//Si existe lo sobreescibe
    //fout.open("mi_archivo.txt",ios_base::app);//Abrir en modo 'append' osea se escribe al final
    fout << 89 << std:endl; //Operacion de insercion
    fout << 6 << " "; // Para escibir sin salto de linea
    fout << 'S' << " ";
    fout.close();
    return 0;// si estubiera en un void (no va esta linea)
}

//Para leer la informacion, si sabemos la estructura
int main(){
    int a;
    float b;
    std:ifstream fin;//leer datos , no escirbir
    fin.open("mi_archivo.txt");
	fin >> a;
    fin >> b;// Toma el siguiente dato despues de (espacio blanco)
    fin.close();
}

//end-of.file
while(!fin.eof()){ // mientras haya datos que leer 
    int a;
    fin >> a; 
}

//fail : me da true si fue bien leido
if(fin.fail()){
    std::cout<<"Error"<<std::endl;
}else{
    std::cout<<"Abierto"<<std::endl;
}
//No olvidar el clouse
````

### Vectores

````c++
#include <vector>
#include <iostream>

using namespace std;

int main(){
	vector<int> v0(100);// <0,0,0,...,0>
	vector<int> v1(100,37);// <37,37,...,37>
	
	cout << v0[140] << endl;
}


//Que pasa, en este caso devuelve 37
//?? RES: Porque en memoria se guardo al costado del otro vector
// [...|0|0|37|37|...]


//Cuando es muy grande el vector y lo quiero pasar a una funcion, por defecto se hace una copia del vector
//Yo no quiero esto por que consume mucho tiempo de procesamiento
//SOL: Podemos pasarlo por referencia asi no se copia(cuidando no modificar el vector)
//existe la palabra reservada 'const' que nos ayuda usar al vector como 'solo-lectura' 
float promedio(const vector<float>& v){
	
	//Error
	v[0] =37
}
//esto me asegura que no se modificarar y me ayuda para detectar errores
````

