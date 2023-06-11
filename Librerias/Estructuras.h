#ifndef Estructuras_H
#define Estructuras_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

struct tVehiculo{
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
};

struct tListaConductores{
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
    tListaConductores* prox;
};

struct tObstaculo
{
    string sprite;
    bool bomba;
    bool piedra;
    bool liquido;
};
struct tKilometro
{
    int ordinalKilometro; // para saber que kilometro es
    bool obstaculoEncontrado;
    bool vehiculoPresente;
    tObstaculo obstaculo;
    tKilometro *prox;
    tObstaculo *presentes;
};
struct tCarril
{
    tKilometro *primerKilometro;
    tKilometro *ultimoKilometro;
    tKilometro *ubicacionVehiculo; // para saber donde esta el vehiculo
    int numeroDeKilometros;
    tVehiculo *vehiculo;
    tCarril *prox;
    tObstaculo presentes;

};
struct tPista
{
    tCarril *primerCarril;
    tCarril *ultimoCarril;
    int numeroCarriles;
};

tListaConductores *primero , *ultimo , *actual , *nuevo;
//  char display[3] = {'¤', '¶', '#'};


#endif // Estructuras_H