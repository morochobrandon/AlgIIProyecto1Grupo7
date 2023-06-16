#ifndef Estructuras_H
#define Estructuras_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <chrono>

using namespace std;

struct tListaVehiculos{
    string nombreEs;
    string nombreEn;
    string conductor;
    int tipoCaucho;
    string aTipoCaucho[4]={"Error", "Todoterreno", "Normal" , "Anticoleo"};
    int tamanoCaucho;
    string aTamanoCaucho[4]={ "Error", "Monstertruck", "Normal" , "Pegado al piso"};
    int monsterTruck;
    int velocidad;
    string aVelocidad[5]={ "Error", "Perezoso", "Crucero", "SuperFerrari","Delorean"};
    int velocidadKm;
    int resBomba;
    int resPiedra;
    int resLiquido;
    double contadorAux{0}; // contador que se le suma a la velocidad
    int velocidadAux; // velocidad que se le suma al carro
    int tiempoAux; // tiempo que se le suma a la velocidad
    string vehiculoEnPantalla;
    std::chrono::milliseconds::rep duracionEnPista;
    tListaVehiculos *prox;
};

struct tObstaculo
{
    string sprite;
    int display=0;
    string aDisplay[4] = {"-","¤", "¶", "#"};
};
struct tKilometro
{
    int ordinalKilometro; // para saber que kilometro es
    bool obstaculoPresente;
    bool vehiculoPresente=0;
    tObstaculo *obstaculo;
    tKilometro *prox;
};
struct tCarril
{
    tKilometro *primerKilometro=NULL;
    tKilometro *ultimoKilometro=NULL;
    tKilometro *ubicacionVehiculo=NULL; // para saber donde esta el vehiculo
    tListaVehiculos *vehiculo;
    bool terminoCarrera=false;
    tCarril *prox;
};
struct tPista
{
    string nombre;
    const int longitud = 160;
    tCarril *primerCarril=NULL;
    tCarril *ultimoCarril=NULL;
    int numeroCarriles;
    std::chrono::system_clock::time_point tiempoInicio;
};

tListaVehiculos *primero , *ultimo , *actual , *nuevo;
//  char display[3] = {'¤', '¶', '#'};


#endif // Estructuras_H



/*
velocidad con respecto al tiempo

metodo 1 , ya nos la da
metodo 2 , sumar el tiempo trascurrido en cada nodo








*/