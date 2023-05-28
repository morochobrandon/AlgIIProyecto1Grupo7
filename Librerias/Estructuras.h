#ifndef Estructuras_H
#define Estructuras_H

#include <iostream>
#include <string>
#include <ctime>

using namespace std;

typedef struct tResistencia{
    int resistenciaBombas;
    int resistenciaPiedras;
    int resistenciaLiquidos;
};
typedef struct tVehiculo
{
    string nombreEspanol;
    string nombreIngles;
    string conductores;
    int tipoCaucho;
    int tamanoCaucho;
    int velocidad;
   // string tiempoDisminucion;
    tResistencia resistencia;
    clock_t cronometro;
    int PosicionDeLlegada;
};
typedef struct tObstaculo
{
    string nombre;
    tResistencia resistencia;
    // int tipo;
    // int velocidad;
    // int tiempoDisminucion;
};
typedef struct tKilometro
{
    int numeroDeKilometro;
    tObstaculo obstaculo;
    bool obstaculoEncontrado;
    bool vehiculoPresente;
    tKilometro *prox;
};
typedef struct tCarril
{
    tKilometro *inicio;
    tKilometro *fin;
    tVehiculo vehiculo;
    tCarril *prox;
    tKilometro *ubicacionVehiculo;
    int numeroKilometros;
};
typedef struct tPista
{
    tCarril *inicio;
    tCarril *fin;
    int numeroCarriles;
};
#endif // Estructuras_H