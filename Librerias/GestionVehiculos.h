#ifndef GestionVehiculos_H
#define GestionVehiculos_H
#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>
#include <ctime>
#include "Estructuras.h"
#include "esNumero.h"
#include <iomanip>

using namespace std;

void muestra(tListaVehiculos *listaCompetidores);
void agregarVehiculo(tListaVehiculos **listaCompetidores, string nombreEsp , string nombreEn , string piloto , int tipoCaucho , int tamCaucho,  int mT , int velocidad, int comoSeVeElVehiculo );
void llenarDatosVehiculo(tListaVehiculos **listaCompetidores, string nombreEsp , string nombreEn , string piloto ,int tipoDeCaucho , int tamanoDeCaucho, int tamanoMonster, int velocidadDelCarro , int comoSeVeElVehiculo );
void consultarVehiculo(tListaVehiculos *listaCompetidores);
void eliminarVehiculo(tListaVehiculos **listaCompetidores);
void modificarVehiculo(tListaVehiculos **listaCompetidores);
bool validarVehiculo(int tipoDeCaucho , int tamanoDeCaucho, int tamanoMonster, int velocidadDelCarro);
void modificarDatosDelVehiculoAux(tListaVehiculos **listaCompetidores);
void pedirDatosVehiculo(tListaVehiculos **listaCompetidores);
void muestraVehiculoEspecifico(tListaVehiculos *listaCompetidores);
void modificarDatosDelVehiculoAux(tListaVehiculos **listaCompetidores);
void eliminartListaVehiculos(tListaVehiculos **listaCompetidores);

void cargar_archivo3(tListaVehiculos **listaCompetidores); 
//void cargar_archivo2(tListaVehiculos **listaCompetidores);
void descargar_archivo3(tListaVehiculos *primero) ;

#include "GestionVehiculos.cpp"
#endif // GestionVehiculos_H