#ifndef TDAPISTA_H
#define TDAPISTA_H
#include "Estructuras.h"
#include <iostream>
#include <windows.h>
#include <fstream>
#include "GestionVehículos.h"

using namespace std;

tPista *crearPista();
void mostrarPista(tPista pista);

void vehiculoEnPista(tPista *pista, tVehiculo vehiculo);
void cargarPista(tPista *pista, ifstream& archivo);
void guardarPista(tPista *pista, ofstream& archivo);
void cargarPista(tPista *pista, ifstream& archivo);
void destruirPista(tPista *pista);


#include "TDAPista.cpp"
#endif // TDAPISTA_H