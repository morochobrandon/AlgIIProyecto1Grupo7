#ifndef MENUS_H
#define MENUS_H

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "TDAPista.h"

using namespace std;
int opcion;

void menuPrincipal(tPista *pista, tListaVehiculos *listaCompetidores);
void opcionesPista(tPista *pista, tListaVehiculos *listaCompetidores);
void opcionesGestionDeVehiculos(tPista *pista, tListaVehiculos *listaCompetidores);

void menuVelocidadVehiculo();
void menuTipoDeMonsterTruck();
void menuComoSeVeElVehiculo();
void menuTipoDeCaucho();
void menuTamanoDeCaucho();
void menuNuevoVehiculo();

#include "menus.cpp"
#endif /* MENU_H */
