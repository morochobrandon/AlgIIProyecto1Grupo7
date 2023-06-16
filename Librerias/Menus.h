#ifndef MENUS_H
#define MENUS_H

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "GestionVehiculos.h"
#include "TDAPista.h"


using namespace std;
int opcion=-1;

void menuVelocidadVehiculo();
void menuTipoDeMonsterTruck();
void menuComoSeVeElVehiculo();
void menuTipoDeCaucho();
void menuTamanoDeCaucho();
void menuNuevoVehiculo();
void menuPrincipal(tPista *pista, tListaVehiculos **listaCompetidores);
void pista1(tPista *pista, tListaVehiculos *listaCompetidores);
void pista2(tPista *pista, tListaVehiculos *listaCompetidores);
void opcionesGestionDeVehiculos(tPista *pista, tListaVehiculos **listaCompetidores);

#include "menus.cpp"

#endif /* MENU_H */
