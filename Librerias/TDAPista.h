#ifndef TDAPISTA_H
#define TDAPISTA_H
#include <iostream>
#include <windows.h>
#include <fstream>
#include <unistd.h>
#include "GestionVehiculos.h"

using namespace std;

tPista *inicializarPista();
void mostrarPista(tPista *pista);
void cargarPista(tPista *pista, ifstream& archivo);
void pedirDatosPista(tPista *pista, tListaVehiculos *vehiculos);
void generarObstaculos(tPista *pista);
void destruirPista(tPista *pista);
bool llego(tCarril *carril);
bool llegaronTodos(tPista *pista, bool *lleg);
void modificarUnaPosicion(tCarril *carrilAux, tPista *pista);
void modificarPociciones(tPista *pistaAux);
void simularCarrera(tPista *p);

#include "TDAPista.cpp"
#endif // TDAPISTA_H