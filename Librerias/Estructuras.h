#ifndef Estructuras_H
#define Estructuras_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

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
    string vehiculoEnPantalla;
    tListaVehiculos* prox;
};

struct tObstaculo
{
    string sprite;
    int display;
    string aDisplay[4] = {"-","¤", "¶", "#"};
};
struct tKilometro
{
    int ordinalKilometro; // para saber que kilometro es
    bool obstaculoPresente;
    bool vehiculoPresente;
    tObstaculo *obstaculo;
    tKilometro *prox;
};
struct tCarril
{
    tKilometro *primerKilometro;
    tKilometro *ultimoKilometro;
    tKilometro *ubicacionVehiculo; // para saber donde esta el vehiculo
    tListaVehiculos *vehiculo;
    tCarril *prox;
};
struct tPista
{
    string nombre;
    const int longitud = 10;
    tCarril *primerCarril;
    tCarril *ultimoCarril;
    int numeroCarriles;
};

tListaVehiculos *primero , *ultimo , *actual , *nuevo;
//  char display[3] = {'¤', '¶', '#'};


#endif // Estructuras_H