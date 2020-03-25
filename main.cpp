#include<iostream>
#include"LibreriaPrueba.h"

using namespace std;
/*
para compilar el codigo, abrir la terminal y escribirk

-- g++ -Wall main.cpp Prueba1.cpp -o salida

//lo cual genera un archivo ejecutable llamado salida

--./salida

//lo cual ejecuta el programa

*/
int main(){
	int resultado = suma(1,1);
	cout << "El resultado es: " << resultado << "\n";
	return 0;

}
