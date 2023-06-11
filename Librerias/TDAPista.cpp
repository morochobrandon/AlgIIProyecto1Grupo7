#include "TDAPista.h"

tPista *crearPista() {
    tPista *pista = new tPista;
    pista->primerCarril = NULL;
    pista->ultimoCarril = NULL;
    pista->numeroCarriles = 0;
    return pista;
}

void mostrarPista(tPista pista) {
    tCarril *carrilAux = pista.primerCarril;
    while (carrilAux != NULL) {
        cout << "Carril " << carrilAux->vehiculo->nombre_es << endl;
        tKilometro *kilometro = carrilAux->primerKilometro;
        while (kilometro != NULL) {
            cout << "Kilometro " << kilometro->ordinalKilometro << endl;
            if (kilometro->vehiculoPresente) {
                cout << "Vehiculo " << carrilAux->vehiculo->nombre_es << endl;
            }
            if (kilometro->obstaculoEncontrado) {
                cout << "Obstaculo " << kilometro->obstaculo->nombre << endl;
            }
            kilometro = kilometro->prox;
        }
        carrilAux = carrilAux->prox;
    }
}

void vehiculoEnPista(tPista *pista, tVehiculo vehiculo) {
    tCarril *carrilAux = pista->primerCarril;
    while (carrilAux != NULL) {
        if (carrilAux->vehiculo->nombre_es == vehiculo.nombre_es) {
            carrilAux->vehiculo = &vehiculo;
            break;
        }
        carrilAux = carrilAux->prox;
    }
}



using namespace std;
