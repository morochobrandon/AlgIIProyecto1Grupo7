#ifndef GestionVehiculos_H
#define GestionVehiculos_H
#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>
#include <ctime>
#include "Estructuras.h"

using namespace std;


void muestra(tListaConductores *p);
void mostrarOpciones();
void agregarVehiculo(tListaConductores **p, string nombreEsp , string nombreEn , string piloto , int tipoCaucho , int tamCaucho,  int mT , int velocidad, int comoSeVeElVehiculo );
void llenarDatosVehiculo(tListaConductores **p, string nombreEsp , string nombreEn , string piloto ,int tipoDeCaucho , int tamanoDeCaucho, int tamanoMonster, int velocidadDelCarro , int comoSeVeElVehiculo );
void consultarVehiculo(tListaConductores *p);
void eliminarVehiculo(tListaConductores **p);
void modificarVehiculo(tListaConductores **p);
bool validarVehiculo(int tipoDeCaucho , int tamanoDeCaucho, int tamanoMonster, int velocidadDelCarro);
void modificarDatosDelVehiculoAux(tListaConductores **p);
void pedirDatosVehiculo(tListaConductores **p);
void muestraVehiculoEspecifico(tListaConductores *p);
void modificarDatosDelVehiculoAux(tListaConductores **p);
void eliminartListaConductores(tListaConductores **p);

void cargar_archivo3(tListaConductores **p); 
void cargar_archivo2(tListaConductores **p);
void descargar_archivo3(tListaConductores *primero) ;



#include "GestionVehiculos.cpp"
#endif // GestionVehiculos_H