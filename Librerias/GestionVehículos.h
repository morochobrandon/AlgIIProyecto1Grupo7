#ifndef GestionVehiculos_H
#define GestionVehiculos_H
#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>
#include <ctime>

using namespace std;

#include <iostream>

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

/*
struct Carril{
int numerosDeCarriles;
Vehiculos vehiculos;
};
*/

/*
struct Carrera{
lista* inicio;
int dimension;
};
/
/
typedef struct {
char* tipo; // tipo de obstaculo
int tiempo; // tiempo que afecta al vehiculo
} Obstaculo;

typedef struct {
lista* carriles;
lista* obstaculos;
lista* vehiculos;
} Juego;
*/

void agregarVehiculo(lista **p, string nombreEsp , string nombregringo , string piloto , int bomba , int piedra , int liquido);
void muestra(lista *p);
void mostrarOpciones();
void consultarVehiculo(lista *p);
void eliminarVehiculo(lista **p);
void modificarVehiculo(lista **p);
void eliminarLista(lista **p);

#include "GestionVehículos.cpp"
#endif // GestionVehiculos_H