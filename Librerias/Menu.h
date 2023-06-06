#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>


using namespace std;

void mostrarOpciones(){
    cout<<"\n 1. Agregar vehiculo";
    cout<<"\n 2. Modificar vehiculo";
    cout<<"\n 3. Eliminar vehiculo";
    cout<<"\n 4. Consultar vehiculo";
    cout<<"\n 5. Generar carriles";
    cout<<"\n 6. Simular carrera";
    cout<<"\n 7. Mostrar vehiculos";
    cout<<"\n 0. Salir";
}

#include "menu.cpp"
#endif /* MENU_H */
