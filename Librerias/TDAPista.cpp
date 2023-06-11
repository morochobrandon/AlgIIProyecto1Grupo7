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
        cout << "Carril " << carrilAux->vehiculo->nombreEs << endl;
        tKilometro *kilometro = carrilAux->primerKilometro;
        while (kilometro != NULL) {
            cout << "Kilometro " << kilometro->ordinalKilometro << endl;
            if (kilometro->vehiculoPresente) {
                cout << "Vehiculo " << carrilAux->vehiculo->nombreEs << endl;
            }
            if (kilometro->obstaculoEncontrado) {
                cout << "Obstaculo " << kilometro->presentes->sprite << endl;
            }
            kilometro = kilometro->prox;
        }
        carrilAux = carrilAux->prox;
    }
}

void vehiculoEnPista(tPista *pista, tVehiculo vehiculo) {
    tCarril *carrilAux = pista->primerCarril;
    while (carrilAux != NULL) {
        if (carrilAux->vehiculo->nombreEs == vehiculo.nombreEs) {
            carrilAux->vehiculo = &vehiculo;
            break;
        }
        carrilAux = carrilAux->prox;
    }
}

void destruirPista(tPista *pista){
    tCarril *auxCarril = pista->primerCarril;
    while (auxCarril != NULL) {
        tKilometro *auxKilometro = auxCarril->primerKilometro;
        while (auxKilometro != NULL) {
            tKilometro *auxKilometro2 = auxKilometro->prox;
            delete auxKilometro;
            auxKilometro = auxKilometro2;
        }
        delete auxCarril->vehiculo;
        tCarril *auxCarril2 = auxCarril->prox;
        delete auxCarril;
        auxCarril = auxCarril2;
    }
}

void generarObstaculos(tPista *pista, int cantidadObstaculos){
    int cantidadCarriles = pista->numeroCarriles;
    int cantidadKilometros = 10;
    int cantidadObstaculosPorCarril = cantidadObstaculos / cantidadCarriles;
    int cantidadObstaculosRestantes = cantidadObstaculos % cantidadCarriles;
    tCarril *carrilAux = pista->primerCarril;
    while (carrilAux != NULL) {
        tKilometro *kilometroAux = carrilAux->primerKilometro;
        while (kilometroAux != NULL) {
            int cantidadObstaculosPorKilometro = cantidadObstaculosPorCarril / cantidadKilometros;
            int cantidadObstaculosRestantesPorKilometro = cantidadObstaculosPorCarril % cantidadKilometros;
            for (int i = 0; i < cantidadObstaculosPorKilometro; i++) {
                int posicionObstaculo = rand() % 10;
                tObstaculo *obstaculo = new tObstaculo;
                obstaculo->sprite = "O";
                obstaculo->posicion = posicionObstaculo;
                obstaculo->prox = NULL;
                kilometroAux->presentes = obstaculo;
                kilometroAux->obstaculoEncontrado = true;
                kilometroAux = kilometroAux->prox;
            }
            if (cantidadObstaculosRestantesPorKilometro > 0) {
                int posicionObstaculo = rand() % 10;
                tObstaculo *obstaculo = new tObstaculo;
                obstaculo->sprite = "O";
                obstaculo->posicion = posicionObstaculo;
                obstaculo->prox = NULL;
                kilometroAux->presentes = obstaculo;
                kilometroAux->obstaculoEncontrado = true;
                kilometroAux = kilometroAux->prox;
                cantidadObstaculosRestantesPorKilometro--;
            }
            kilometroAux = kilometroAux->prox;
        }
        if (cantidadObstaculosRestantes > 0) {
            int posicionObstaculo
}
}
}

using namespace std;