#ifndef GestionVehiculos_H
#define GestionVehiculos_H
#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>
#include <ctime>
#include "Estructuras.h"

using namespace std;




void agregarVehiculo(tListaConductores *p, string nombreEsp , string nombregringo , string piloto , int bomba , int piedra , int liquido);
void muestra(tListaConductores p);
void mostrarOpciones();
void consultarVehiculo(tListaConductores p);
void eliminarVehiculo(tListaConductores *p);
void modificarVehiculo(tListaConductores *p);
void modificarDatosDelVehiculoAux(tListaConductores *p);
void llenarDatosVehiculo(tListaConductores *p, string nombreEsp , string nombregringo , string piloto ,int tipoDeCaucho , int tamanoDeCaucho, int velocidadDelCarro , double bombas , double piedras , double liquidos , int comoSeVeElVehiculo );
void pedirDatosVehiculo(tListaConductores *p);
void muestraVehiculoEspecifico(tListaConductores p);
void eliminartListaConductores(tListaConductores *p);

void cargar_archivo3(tListaConductores *p); 
void cargar_archivo2(tListaConductores *p);
void descargar_archivo3(tListaConductores *primero) ;



#include "GestionVehículos.cpp"
#endif // GestionVehiculos_H