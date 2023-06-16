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
void generarPista(tPista *pista, tListaVehiculos *vehiculos, bool random);
void generarObstaculos(tPista *pista);
void destruirPista(tPista *pista);
bool validarSiPuedeMover(tCarril *carrilAux, tPista *pista);
void selectionSort(struct tListaVehiculos **p);
tListaVehiculos *tablaDePosiciones(tPista *pista);
bool llego(tCarril *carril);
bool llegaronTodos(tPista *pista, bool *lleg);
void modificarUnVehiculo(tCarril *carrilAux, tPista *pista);
void modificarPociciones(tPista *pistaAux);
void simularCarrera(tPista *p);

#include "TDAPista.cpp"
#endif // TDAPISTA_H