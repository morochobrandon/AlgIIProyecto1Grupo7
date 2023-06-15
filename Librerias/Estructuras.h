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
    int velocidadKm;  // velocidad del carro
    //double resistenciaBomba;        agregar castellano a gestion de vehiculo
    //double resistenciaPiedra;   agregar castellano a gestion de vehiculo
    //double resistenciaLiquido;   agregar castellano a gestion de vehiculo
    double contadorAux{0}; // contador que se le suma a la velocidad
    int velocidadAux; // velocidad que se le suma al carro
    int tiempoAux; // tiempo que se le suma a la velocidad
    string vehiculoEnPantalla;
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
    const int longitud = 80;
    tCarril *primerCarril;
    tCarril *ultimoCarril;
    int numeroCarriles;
};

tListaVehiculos *primero , *ultimo , *actual , *nuevo;
//  char display[3] = {'¤', '¶', '#'};


#endif // Estructuras_H



/*
velocidad con respecto al tiempo

metodo 1 , ya nos la da
metodo 2 , sumar el tiempo trascurrido en cada nodo








*/