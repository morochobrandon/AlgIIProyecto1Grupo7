#include "TDAPista.h"

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
            delete auxKilometro->obstaculo;
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

void pedirDatosPista(tPista *pista, tListaVehiculos *vehiculos) {
    string auxS;
    int vehiculoABuscar;
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
        vehiculoABuscar=stoi(auxS);
        convertirVehiculo(vehiculos, vehiculoABuscar, &carril->vehiculo);
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

//función que genera los obstáculos en el kilometro tomando en cuenta que: En cada carril puede aparecer de manera aleatoria máximo 3 obstáculos: sin obstáculo, una bomba, una piedra, o líquido resbaladizo, que se muestra en la pista con los caracteres: -, ¤, ¶, ≠, respectivamente.
void generarObstaculos(tPista *pista) {
    tCarril *carrilAux = pista->primerCarril;
    const int maxObstaculos = 3;
    int obstaculos = 0;
    while (carrilAux != NULL && obstaculos <= maxObstaculos) {
        tKilometro *kilometroAux = carrilAux->primerKilometro;
        while (kilometroAux != NULL) {
            kilometroAux->obstaculo->display = rand() % 100;

            if (kilometroAux->obstaculo->display <=24) {
                switch (kilometroAux->obstaculo->display)
                {
                case 0 ... 8:
                    kilometroAux->obstaculo->display = 1;
                    break;
                case 9 ... 16:
                    kilometroAux->obstaculo->display = 2;
                    break;
                case 17 ... 24:
                    kilometroAux->obstaculo->display = 2;
                    break;
                
                default:
                    kilometroAux->obstaculo->display = 0;
                    break;
                }
            }
            kilometroAux = kilometroAux->prox;
        }
        carrilAux = carrilAux->prox;
    }
}