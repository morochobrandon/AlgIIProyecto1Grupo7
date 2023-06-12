#ifndef MENUS_H
#define MENUS_H

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "TDAPista.h"

using namespace std;
int opcion;

void OpcionesPista();
void opcionesGestionDeVehiculos(tPista *pista, tListaVehiculos *p);

#include "menus.cpp"
#endif /* MENU_H */
