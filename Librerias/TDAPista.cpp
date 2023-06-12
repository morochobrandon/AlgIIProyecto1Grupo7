#include "TDAPista.h"
#include "esNumero.h"

tPista *inicializarPista() {
    tPista *pista = new tPista;
    pista->primerCarril = NULL;
    pista->ultimoCarril = NULL;
    pista->numeroCarriles = 0;
    return pista;
}

void mostrarPista(tPista *pista) {
    tCarril *carrilAux = pista->primerCarril;
    while (carrilAux != NULL) {
        cout << "Carril " << carrilAux->vehiculo->nombreEs << endl;
        tKilometro *kilometro = carrilAux->primerKilometro;
        while (kilometro != NULL) {
            cout << "Kilometro " << kilometro->ordinalKilometro << endl;
            if (kilometro->vehiculoPresente) {
                cout << "Vehiculo " << carrilAux->vehiculo->nombreEs << endl;
            }
                cout << "Obstaculo " << kilometro->obstaculo->aDisplay[kilometro->obstaculo->display] << endl;
            kilometro = kilometro->prox;
        }
        carrilAux = carrilAux->prox;
    }
}
/*
void vehiculoEnPista(tPista *pista, tVehiculo vehiculo) {
    tCarril *carrilAux = pista->primerCarril;
    while (carrilAux != NULL) {
        if (carrilAux->vehiculo->nombreEs == vehiculo.nombreEs) {
            carrilAux->vehiculo = &vehiculo;
            break;
        }
        carrilAux = carrilAux->prox;
    }
}*/

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

void pedirDatosPista(tListaVehiculos *vehiculos) {
    tPista *pista = new tPista;
    pista->primerCarril = NULL;
    pista->ultimoCarril = NULL;
    pista->numeroCarriles = 0;
    string auxS;
    int vehiculo;
    fflush(stdin);
    cout << "Ingrese el nombre de la pista: ";
    cin >> pista->nombre;
    do
    {
        cout << "Ingrese la cantidad de carriles: ";
        getline(cin, auxS);
    } while (!esEntero(auxS));
        pista->numeroCarriles = stoi(auxS);
    for (int i = 0; i < pista->numeroCarriles; i++) {
        tCarril *carril = new tCarril;
        muestraVehiculoSimple(vehiculos);
        do
        {
            cout << "Selecciona el vehiculo para el carril " << i << "(ingrese el numero a un lado): ";
            getline(cin, auxS);
        } while (!esEntero(auxS));
        vehiculo=stoi(auxS);
        convertirVehiculo(vehiculos, vehiculo, &carril->vehiculo);
        carril->primerKilometro = NULL;
        carril->ultimoKilometro = NULL;
        carril->ubicacionVehiculo = NULL;
        for (int i = 0; i < pista->longitud; i++) {
            tKilometro *Kilometroaux = new tKilometro;
            Kilometroaux->ordinalKilometro = i;
            if (carril->primerKilometro == NULL) {
                carril->primerKilometro = Kilometroaux;
                carril->ultimoKilometro = Kilometroaux;
            } else {
            carril->ultimoKilometro->prox = Kilometroaux;
            carril->ultimoKilometro = Kilometroaux;
            }
        }
        carril->ultimoKilometro->prox = NULL;
        if (pista->primerCarril == NULL) {
            pista->primerCarril = carril;
            pista->ultimoCarril = carril;
        } else {
            pista->ultimoCarril->prox = carril;
            pista->ultimoCarril = carril;
        }
    }
}

/*
void generarObstaculos(tPista *pista, int cantidadObstaculos){
    srand(time(NULL));
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
    }
}
*/