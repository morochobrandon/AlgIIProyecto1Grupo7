#ifndef esNumero_H
#define esNumero_H
#include <iostream>
#include <string>

using namespace std;
//función para saber si es un número entero
bool esEntero(string linea);
//función para saber si son solo espacios
bool noSoloEspacios(string str);
//función para saber si es un número flotante
bool esFloatValido(string str);
//función para saber si es un número
bool esNumerico(string str);
//función para saber si el string es válido
bool cadenaValida(string str);
//transformar string a entero
int pedirDatoInt(string mensajeDePedirDatos);

#include "esNumero.cpp"
#endif // esNumero_H