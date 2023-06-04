#ifndef GestionVehiculos_H
#define GestionVehiculos_H
#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>
#include <ctime>
#include "Estructuras.h"

using namespace std;




void agregarVehiculo(lista **p, string nombreEsp , string nombregringo , string piloto , int bomba , int piedra , int liquido);
void muestra(lista *p);
void mostrarOpciones();
void consultarVehiculo(lista *p);
void eliminarVehiculo(lista **p);
void modificarVehiculo(lista **p);
void modificarDatosDelVehiculoAux(lista **p);
void llenarDatosVehiculo(lista **p, string nombreEsp , string nombregringo , string piloto ,int tipoDeCaucho , int tamanoDeCaucho, int velocidadDelCarro , double bombas , double piedras , double liquidos , int comoSeVeElVehiculo );
void pedirDatosVehiculo(lista **p);
void muestraVehiculoEspecifico(lista *p);
void eliminarLista(lista **p);

void cargar_archivo3(lista **p); 
void cargar_archivo2(lista **p);
void descargar_archivo3(lista* primero) ;



#include "GestionVehículos.cpp"
#endif // GestionVehiculos_H