#ifndef GestionVehiculos_H
#define GestionVehiculos_H
#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>
#include <ctime>
#include "esNumero.h"
#include <iomanip>
#include "Estructuras.h"
#include "menus.h"

using namespace std;


bool validarResistencias1(int tamanoMonster, int resBomba, int resPiedra, int resLiquido, int velocidadkm);
bool validarResistencias2(int velocidadDelCarro,int tamanoMonster, int resBomba, int resPiedra, int resLiquido, int velocidadkm);
void muestra(tListaVehiculos *listaCompetidores);
void agregarVehiculo(tListaVehiculos **listaCompetidores, string nombreEsp , string nombreEn , string piloto , int tipoCaucho , int tamCaucho,  int mT , int velocidad,int velocidadKm , int comoSeVeElVehiculo, int resistenciaBomba, int resistenciaPiedra, int resistenciaLiquido );
void llenarDatosVehiculo(tListaVehiculos **listaCompetidores, string nombreEsp , string nombreEn , string piloto ,int tipoDeCaucho , int tamanoDeCaucho, int tamanoMonster, int velocidadDelCarro ,int velocidadDelCarroKm  , int comoSeVeElVehiculo, int resistenciaBomba, int resistenciaPiedra, int resistenciaLiquido);
void consultarVehiculo(tListaVehiculos *listaCompetidores);
void eliminarVehiculo(tListaVehiculos **listaCompetidores);
void modificarVehiculo(tListaVehiculos **listaCompetidores);
bool validarVehiculo(int tipoDeCaucho , int tamanoDeCaucho, int tamanoMonster, int velocidadDelCarro);
void modificarDatosDelVehiculoAux(tListaVehiculos **listaCompetidores);
void pedirDatosVehiculo(tListaVehiculos **listaCompetidores);
void muestraVehiculoEspecifico(tListaVehiculos *listaCompetidores);
void modificarDatosDelVehiculoAux(tListaVehiculos **listaCompetidores);
void eliminartListaVehiculos(tListaVehiculos **listaCompetidores);

void cargarArchivoDefault
(tListaVehiculos **listaCompetidores); 
//void cargar_archivo2(tListaVehiculos **listaCompetidores);
void descargar_archivo3(tListaVehiculos *primero) ;

void menuVelocidadVehiculo();
void menuTipoDeMonsterTruck();
void menuComoSeVeElVehiculo();
void menuTipoDeCaucho();
void menuTamanoDeCaucho();
void menuNuevoVehiculo();

#include "GestionVehiculos.cpp"
#endif // GestionVehiculos_H