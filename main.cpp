#include "Librerias\menus.h"

    int main(){
    tListaVehiculos *listaCompetidores=nullptr;
    cargar_archivo3(&listaCompetidores);
    muestra(listaCompetidores);
    primero = listaCompetidores;
    descargar_archivo3(primero);
    tPista *pista = inicializarPista();
    //menú principal
    menuPrincipal(pista,&listaCompetidores);
    cout<<"\n\n";
    system("pause");
    system("cls");
    return 0;
}