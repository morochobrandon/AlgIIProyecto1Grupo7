#ifndef Estructuras_H
#define Estructuras_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

struct lista{
string nombre_es;
string nombre_en;
string conductor;
string tipo_caucho;
string tamano_caucho;
string velocidad;
string vehiculo_en_pantalla;

int resistencia_bomba;
int resistencia_piedra;
int resistencia_liquido;



lista* prox;
};


struct tObstaculo
{
    string nombre;
    int resistencia_bomba;
    int resistencia_piedra;
    int resistencia_liquido;
    string obstaculo_en_pantalla;
  
     int tipo;
    
     int tiempoDisminucion;
};
struct tKilometro
{
    int numeroDeKilometroQueEsta;
    bool obstaculoEncontrado;
    bool vehiculoPresente;
    tKilometro *prox;
};
struct tCarril
{
    tKilometro *primerKilometro;
    tKilometro *ultimoKilometro;
    tKilometro *ubicacionVehiculo; // para saber donde esta el vehiculo
    string conductor;
    int numeroDeKilometros;
    string velocidad;
    tCarril *prox;
};
struct tPista
{
    tCarril *inicio;
    tCarril *fin;
    int numeroCarriles;
};

lista *primero , *ultimo , *actual , *nuevo;
//  char display[3] = {'¤', '¶', '#'};


#endif // Estructuras_H