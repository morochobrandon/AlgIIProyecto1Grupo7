#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>


using namespace std;

void mostrarOpciones(){
    cout<<"\n 1. Agregar ";
    cout<<"\n 2. Modificar ";
    cout<<"\n 3. Eliminar ";
    cout<<"\n 4. Consultar ";
    cout<<"\n 5. Generar ";
    cout<<"\n 6. Simular ";
    cout<<"\n 7. Mostrar ";
    cout<<"\n 0. Salir";
}

#include "menu.cpp"
#endif /* MENU_H */
