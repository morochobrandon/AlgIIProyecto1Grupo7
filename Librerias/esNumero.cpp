#include "esNumero.h"

//función para saber si un string es un número entero
bool esEntero(string linea) {
	bool esEntero = true;
	int longitud = linea.size();
	
	if (longitud == 0) {
		esEntero = false;
	} else if (longitud == 1 && !isdigit(linea[0])) {
		esEntero = false;
	} else {
		int indice = 0;
		if (linea[0] == '+' || linea[0] == '-') {
			indice = 1;
		} else {
			indice = 0;
		}
		while (indice < longitud) {
			if (!isdigit(linea[indice])) {
				esEntero = false;
				break;
			}
			indice++;
		}
	}	
	return esEntero;	
}
//función para saber si son solo espacios
bool noSoloEspacios(string str) {
    for (int i = 0; i < str.length(); i++)
        if (str[i] != ' ')
            return true;
    return false;
}
//función para saber si es un número flotante
bool esFloatValido(string str) {
    int cont = 0;
    for (int i = 0; i < str.length(); i++) {
    if ((str[i] == '.') || (str[i] == ',')) {
        cont++;
        if (cont > 1) return false;
    } else if (isdigit(str[i]) == false) return false;
    }
    return true;
}
//función para saber si es un número
bool esNumerico(string str) {
    for (int i = 0; i < str.length(); i++)
        if (isdigit(str[i]) == false)
        return false;
    return true;
}
//función para saber si el string es válido
bool cadenaValida(string str){
    if (str.empty())
        return false;
    else
        if (noSoloEspacios(str))
            return true;
        else 
            return false;   
}
