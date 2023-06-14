#ifndef MENUS_H
#define MENUS_H

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "GestionVehiculos.h"


using namespace std;
int opcion;

void menuVelocidadVehiculo();
void menuTipoDeMonsterTruck();
void menuComoSeVeElVehiculo();
void menuTipoDeCaucho();
void menuTamanoDeCaucho();
void menuNuevoVehiculo();
void menuPrincipal(tPista *pista, tListaVehiculos *listaCompetidores);
void opcionesPista(tPista *pista, tListaVehiculos *listaCompetidores);
void opcionesGestionDeVehiculos(tPista *pista, tListaVehiculos *listaCompetidores);

#include "TDAPista.h"

#include "menus.cpp"
#endif /* MENU_H */
