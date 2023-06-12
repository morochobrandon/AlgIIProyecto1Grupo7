#ifndef TDAPISTA_H
#define TDAPISTA_H
#include <iostream>
#include <windows.h>
#include <fstream>
#include "GestionVehiculos.h"

using namespace std;

tPista *inicializarPista();
void mostrarPista(tPista *pista);
void cargarPista(tPista *pista, ifstream& archivo);
void pedirDatosPista(tPista *pista);
void generarObstaculos(tPista *pista, int cantidadObstaculos);
void sacarVehiculosDeListaVehiculos(tPista *pista, int cantidadVehiculos);
void destruirPista(tPista *pista);

#include "TDAPista.cpp"
#endif // TDAPISTA_H