#include "TDAPista.h"
bool lleg=false; //variable global para saber si el vehiculo llego a la meta
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
        cout << "Carril " << carrilAux->vehiculo->nombreEs << endl; // vehiculo en el segundo carril no apunta a su respectivo vehículo
        tKilometro *kilometroAux = carrilAux->primerKilometro;
        while (kilometroAux != NULL) { 
           // cout << "" << kilometroAux->ordinalKilometro;
            if (kilometroAux->vehiculoPresente) {
                cout << "" << carrilAux->vehiculo->vehiculoEnPantalla;
            }else {
                cout << "" << kilometroAux->obstaculo->aDisplay[kilometroAux->obstaculo->display];
            }
            kilometroAux = kilometroAux->prox;
        }
        cout<<endl;
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
            Kilometroaux->obstaculo= NULL;
            Kilometroaux->vehiculoPresente=false;
            if (carril->primerKilometro == NULL) {
                carril->primerKilometro = Kilometroaux;
                carril->ultimoKilometro = Kilometroaux;
                carril->ubicacionVehiculo = Kilometroaux;
                Kilometroaux->vehiculoPresente=true;
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
    }pista->ultimoCarril->prox=NULL;
}

//función que genera los obstáculos en el kilometro tomando en cuenta que: En cada carril puede aparecer de manera aleatoria máximo 3 obstáculos: sin obstáculo, una bomba, una piedra, o líquido resbaladizo, que se muestra en la pista con los caracteres: -, ¤, ¶, ≠, respectivamente.
void generarObstaculos(tPista *pista) {
    srand(time(NULL));
    tCarril *carrilAux = pista->primerCarril;
    bool obsPiedra=false;
    bool obsBomba=false;
    bool obsliquido=false;

    while (carrilAux != NULL) {
        bool obsPiedra=false;
        bool obsBomba=false;
        bool obsliqui=false;
        tKilometro *kilometroAux = carrilAux->primerKilometro;
        while (kilometroAux != NULL) {
            kilometroAux->obstaculo= new tObstaculo;
            kilometroAux->obstaculo->display = rand() % 40;

            if (kilometroAux->obstaculo->display <=3) {
                switch (kilometroAux->obstaculo->display)
                {
                case 1:{    //bomba
                    if (!obsBomba)
                    {
                        kilometroAux->obstaculo->display = 1;
                        obsBomba=true;
                    }else{kilometroAux->obstaculo->display=0;}
                    break;}
                case 2:{
                    if (!obsPiedra)
                    {
                        kilometroAux->obstaculo->display = 2;
                        obsPiedra=true;
                    }else{kilometroAux->obstaculo->display=0;}
                    break;}
                case 3:{
                    if (!obsliquido)
                    {
                        kilometroAux->obstaculo->display = 3;
                        obsliquido=true;
                    }else{kilometroAux->obstaculo->display=0;}
                    break;}
                }
            } else
            {
                kilometroAux->obstaculo->display=0;
            }
            
            kilometroAux = kilometroAux->prox;
        }
        carrilAux = carrilAux->prox;
    }
}

bool llego(tCarril *carril){
    if (carril->ubicacionVehiculo==carril->ultimoKilometro){
        return true;}
    return false;
}

bool llegaronTodos(tPista *pista, bool *lleg){
    tCarril *carrilAux = pista->primerCarril;
    while (carrilAux != NULL) {
        if (!llego(carrilAux)){ *lleg=false; return false;}
        carrilAux = carrilAux->prox;
    }
    *lleg=true;
    return true;
}

void simularCarrera(tPista *p){  
    tCarril *carrilAux = p->primerCarril;
    
    while (!lleg){
        system("cls");
        modificarPociciones(p);
        mostrarPista(p);
        usleep(500000);  // 1 * 10^(-6) la carrera sera entre 1-8 seg
       
    
    }
    
}

void modificarUnaPosicion(tCarril *carrilAux, tPista *pista){ // mover uno a la derecha 
    tKilometro *kilometroAux = carrilAux->ubicacionVehiculo;
    if (kilometroAux->prox!=NULL){
        kilometroAux->vehiculoPresente=false;
        kilometroAux->prox->vehiculoPresente=true;
        carrilAux->ubicacionVehiculo=kilometroAux->prox;
    }else
    {
        llegaronTodos(pista, &lleg);
    }
}

void modificarPociciones(tPista *pistaAux){ // pararse en ubicacion del vehiculo 
    tCarril *carrilAux = pistaAux->primerCarril;
    for (int i = 0; i < pistaAux->numeroCarriles; i++)
    {
        //aquí
        modificarUnaPosicion(carrilAux, pistaAux);
        carrilAux = carrilAux->prox;
    }
}
