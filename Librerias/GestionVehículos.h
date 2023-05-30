#ifndef GestionVehiculos_H
#define GestionVehiculos_H
#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>
#include <ctime>
#include "Estructuras.h"

using namespace std;

struct lista{
string nombre_es;
string nombre_en;
string conductor;
//string tipo_caucho;
//string tamano_caucho;
//string velocidad;
int resistencia_bomba;
int resistencia_piedra;
int resistencia_liquido;
lista* prox;
};



void llenarDatosVehiculo(tVehiculo &p, string nombreEsp , string nombregringo , string piloto ,int tipoDeCaucho , int tamanoDeCaucho, int velocidadDelCarro , double bombas , double piedras , double liquidos , int comoSeVeElVehiculo );

void muestraVehiculoEspecifico(tVehiculo &p);
//crear nodo tKILOMETRO y llenarlo con la funci'on llenar datos vehiculo
void crearKilometro();
void muestra(lista *p);
void mostrarOpciones();
void consultarVehiculo(lista *p);
void eliminarVehiculo(lista **p);
void modificarVehiculo(lista **p);
void eliminarLista(lista **p);

#include "GestionVehículos.cpp"
#endif // GestionVehiculos_H