#ifndef GestionVehiculos_H
#define GestionVehiculos_H
#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>
#include <ctime>
#include "Estructuras.h"
#include "esNumero.h"

using namespace std;

void muestra(tListaVehiculos *p);
void mostrarOpciones();
void agregarVehiculo(tListaVehiculos **p, string nombreEsp , string nombreEn , string piloto , int tipoCaucho , int tamCaucho,  int mT , int velocidad, int comoSeVeElVehiculo );
void llenarDatosVehiculo(tListaVehiculos **p, string nombreEsp , string nombreEn , string piloto ,int tipoDeCaucho , int tamanoDeCaucho, int tamanoMonster, int velocidadDelCarro , int comoSeVeElVehiculo );
void consultarVehiculo(tListaVehiculos *p);
void eliminarVehiculo(tListaVehiculos **p);
void modificarVehiculo(tListaVehiculos **p);
bool validarVehiculo(int tipoDeCaucho , int tamanoDeCaucho, int tamanoMonster, int velocidadDelCarro);
void modificarDatosDelVehiculoAux(tListaVehiculos **p);
void pedirDatosVehiculo(tListaVehiculos **p);
void muestraVehiculoEspecifico(tListaVehiculos *p);
void modificarDatosDelVehiculoAux(tListaVehiculos **p);
void eliminartListaVehiculos(tListaVehiculos **p);

void cargar_archivo3(tListaVehiculos **p); 
void cargar_archivo2(tListaVehiculos **p);
void descargar_archivo3(tListaVehiculos *primero) ;

#include "GestionVehiculos.cpp"
#endif // GestionVehiculos_H