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
    string tipoCaucho[3]={"Normales","Anti coleo","Todo terreno"};
    string tamanoCaucho[3]={"Pegado al piso","Normales","Monster truck"};
    string velocidad[4]= {"Lento","Normal","Rapido","Ultra rapido"};
   // string tiempoDisminucion;
    tResistencia resistencia;
    clock_t cronometro;
    int PosicionDeLlegada;
    char vehiculoEnPantalla[11] = {'¥','@', '©', '£', 'Ç','$','Ø', 'æ', 'þ', '§', '®'}; // @ = Vehiculo, O = Vehiculo con daño, X = Vehiculo destruido
};
typedef struct tObstaculo
{
    string nombre;
    tResistencia resistencia;
    char display[3] = {'¤', '¶', '#'};
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