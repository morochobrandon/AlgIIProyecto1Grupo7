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
        cout << "Carril " << carrilAux->vehiculo->nombreEs;
        tKilometro *kilometro = carrilAux->primerKilometro;
        while (kilometro != NULL) {
            cout << "Kilometro " << kilometro->ordinalKilometro;
            if (kilometro->vehiculoPresente) {
                cout << "Vehiculo " << carrilAux->vehiculo->nombreEs;
            }
            if (kilometro->obstaculoEncontrado) {
                cout << "Obstaculo " << kilometro->obstaculo.sprite;
            }
            kilometro = kilometro->prox;
        }
        cout << endl;
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
/*    srand(time(NULL));
    int posicionObstaculo = rand() % 100;
    int posicionKilometro = rand() % 100;
    int posicionCarril = rand() % 100;
    int posicionCarrilAux = 0;
    int posicionKilometroAux = 0;
    int posicionObstaculoAux = 0;
    tCarril *carrilAux = pista->primerCarril;
    while (carrilAux != NULL) {
        if (posicionCarrilAux == posicionCarril) {
            tKilometro *kilometroAux = carrilAux->primerKilometro;
            while (kilometroAux != NULL) {
                if (posicionKilometroAux == posicionKilometro) {
                    tObstaculo *obstaculoAux = kilometroAux->primerObstaculo;
                    while (obstaculoAux != NULL) {
                        if (posicionObstaculoAux == posicionObstaculo) {
                            obstaculoAux->presentes = new tObstaculo;
                            obstaculoAux->presentes->sprite = 'O';
                            obstaculoAux->presentes->prox = NULL;
                            obstaculoAux->obstaculoEncontrado = true;
                            break;
                        }
                        posicionObstaculoAux++;
                        obstaculoAux = obstaculoAux->prox;
                    }
                    break;
                }
                posicionKilometroAux++;
                kilometroAux = kilometroAux->prox;
            }
            break;
        }
        posicionCarrilAux++;
        carrilAux = carrilAux->prox;
    }*/
}



using namespace std;