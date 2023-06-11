#ifndef TDAPISTA_H
#define TDAPISTA_H
#include "Estructuras.h"
#include <iostream>
#include <windows.h>
#include <fstream>
#include "GestionVehiculos.h"

using namespace std;

tPista *crearPista();
void mostrarPista(tPista pista);
void cargarPista(tPista *pista, ifstream& archivo);
void generarObstaculos(tPista *pista, int cantidadObstaculos);
void sacarVehiculosDeListaConductores(tPista *pista, int cantidadVehiculos);
void vehiculoEnPista(tPista *pista, tVehiculo vehiculo);
void destruirPista(tPista *pista);

#include "TDAPista.cpp"
#endif // TDAPISTA_H