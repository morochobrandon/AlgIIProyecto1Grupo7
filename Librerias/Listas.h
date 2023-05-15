#ifndef Listas
#define Listas

#include <stdio.h>
#include <stdlib.h>

using namespace std;
/* Estructura principal = lista */
struct lista{
	int valor;
	lista *prx;};
/* Rutinas base */
void burbuja(lista **p);
// metodo de ordenamiento

void insercion(lista **p);
// metodo de ordenamiento

void borrartodo(lista **p);
// borra por completo una lista

void voltear(lista **p);
// voltea la lista (con lista auxiliar)

void voltear2(lista **p);
// voltea la lista 2da forma (sin auxiliares)

void pospar (lista **p);
// elimina los elementos en posicion par

void separadig (lista *p);
// separa cada numero mayor a 9 en digitos separados

int cuenta (lista *p);
// cuenta los elementos

void elimina (lista **p, int x);
// elimina la primera ocurrencia de un elemento

void primos(lista **p);

void elimrep (lista *p);
// elimina los elementos repetidos

int busca (lista *p, int x);
// busca un elemento X en la lista

int cuentarep (lista *p, int x);
// cuenta cuantas veces se encuentra un elemento

void elimult (lista **p, int x);
// elimina la ultima ocurrencia de un elemento

void swap (int *x, int *y);
// procedimiento importante segun el problema a resolver

void insertarCabeza(lista **p, int x);
// inserta x por cabeza de la lista

void insertarfinal(lista **p, int x);
// insertar x por cola de la lista

void insertarPreciso(lista **p, int x, int a);
// insertar x por cola de la lista

void muestra(lista *p);
// muestra la lista por pantalla
#include  "Listas.cpp"
#endif