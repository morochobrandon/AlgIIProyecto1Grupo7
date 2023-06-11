#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>


using namespace std;

void mostrarOpciones(){
    cout<<"\n 1. Generación de la pista";
    cout<<"\n 2. Mostrar pista";
    cout<<"\n 3. Cargar competidores";
    cout<<"\n 4. iniciar carrera";
    cout<<"\n 0. regresar";
}

#include "menu.cpp"
#endif /* MENU_H */
