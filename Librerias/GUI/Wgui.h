#ifndef wgui_H
#define wgui_H

#include <iostream>
#include <string>
#include <windows.h>
#include <commctrl.h>
#include <conio.h>
#include <algorithm>

using namespace std;

// Constantes

#define MAX 100
#define MAX2 1000
#define MAX3 10000

// Estructuras

struct Nodo
{
    int dato;
    Nodo *sig;
};

struct Nodo2
{
    string dato;
    Nodo2 *sig;
};

struct Nodo3
{
    char dato;
    Nodo3 *sig;
};


// Funciones

void gotoxy(int x, int y);
void color1(int x);
void color2(int x, int y);
void color3(int x, int y, int z);
void color4(int x, int y, int z, int w);

void cuadro(int x, int y, int ancho, int alto);
void cuadroC(int x, int y, int ancho, int alto, int color);

void linea(int x, int y, int x2, int y2);
void lineaC(int x, int y, int x2, int y2, int color);

void rectangulo(int x, int y, int ancho, int alto);
void rectanguloC(int x, int y, int ancho, int alto, int color);

void circulo(int x, int y, int radio);
void circuloC(int x, int y, int radio, int color);

void texto(int x, int y, string texto);
void textoC(int x, int y, string texto, int color);
void texto2(int x, int y, int ancho, int alto, string texto);
void texto2C(int x, int y, int ancho, int alto, string texto, int color);

#include "Wgui.cpp"

#endif // wgui.h