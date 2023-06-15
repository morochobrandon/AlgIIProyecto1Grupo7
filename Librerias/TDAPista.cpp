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
            auxKilometro->obstaculo = NULL;
            tKilometro *auxKilometro2 = auxKilometro->prox;
            delete auxKilometro;
            auxKilometro = auxKilometro2;
        }
        auxCarril->vehiculo = NULL;
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
//función que ordena la lista de vehículos de menor a mayor según el tiempo que tardaron en llegar a la meta.
void ordenarListaVehiculos(tListaVehiculos **head){
    if (*head == NULL || (*head)->prox == NULL) {
        return;
    }
    tListaVehiculos *actual = *head;
    tListaVehiculos *proximo = actual->prox;
    tListaVehiculos *prev = NULL;
    while (proximo != NULL) {
        if (proximo->duracionEnPista < actual->duracionEnPista) {
            if (prev != NULL) {
                prev->prox = proximo;
            } else {
                *head = proximo;
            }
            actual->prox = proximo->prox;
            proximo->prox = actual;
            prev = proximo;
            proximo = actual->prox;
        } else {
            prev = actual;
            actual = proximo;
            proximo = proximo->prox;
        }
    }
}

//función que guarda los vehiculos de cada carril en una lista de vehiculos ordenados por el tiempo que tardaron en llegar a la meta.
tListaVehiculos *tablaDePosiciones(tPista *pista) {
    tCarril *carrilAux = pista->primerCarril;
    tListaVehiculos *tablaVehiculos =new tListaVehiculos;
    tListaVehiculos *vehiculoAux=tablaVehiculos;
    while (carrilAux->prox != NULL) {
        vehiculoAux->nombreEs = carrilAux->vehiculo->nombreEs;
        vehiculoAux->nombreEn = carrilAux->vehiculo->nombreEn;
        vehiculoAux->conductor = carrilAux->vehiculo->conductor;
        vehiculoAux->tipoCaucho = carrilAux->vehiculo->tipoCaucho;
        vehiculoAux->tamanoCaucho = carrilAux->vehiculo->tamanoCaucho;
        vehiculoAux->velocidadKm = carrilAux->vehiculo->velocidadKm;
        vehiculoAux->vehiculoEnPantalla = carrilAux->vehiculo->vehiculoEnPantalla;
        vehiculoAux->duracionEnPista = carrilAux->vehiculo->duracionEnPista;
        vehiculoAux->prox =new tListaVehiculos;
        vehiculoAux = vehiculoAux->prox;
        carrilAux = carrilAux->prox;
    }
    vehiculoAux->nombreEs = carrilAux->vehiculo->nombreEs;
    vehiculoAux->nombreEn = carrilAux->vehiculo->nombreEn;
    vehiculoAux->conductor = carrilAux->vehiculo->conductor;
    vehiculoAux->tipoCaucho = carrilAux->vehiculo->tipoCaucho;
    vehiculoAux->tamanoCaucho = carrilAux->vehiculo->tamanoCaucho;
    vehiculoAux->velocidadKm = carrilAux->vehiculo->velocidadKm;
    vehiculoAux->vehiculoEnPantalla = carrilAux->vehiculo->vehiculoEnPantalla;
    vehiculoAux->duracionEnPista = carrilAux->vehiculo->duracionEnPista;
    vehiculoAux->prox=NULL;
    ordenarListaVehiculos(&tablaVehiculos);
    return tablaVehiculos;
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
    p->tiempoInicio = std::chrono::system_clock::now();
        system("cls");
    while (!lleg){
        mostrarPista(p);
        modificarPociciones(p);
        usleep(250000);  // 1 * 10^(-6) la carrera sera entre 1-8 seg
        system("cls");
    }
}

//función que muestra la tabla de ganadores de la carrera.
void mostrarTablaDePosiciones(tListaVehiculos *tablaVehiculos) {
    tListaVehiculos *vehiculoAux = tablaVehiculos;
    while (vehiculoAux != NULL) {
        cout << "Nombre: " << vehiculoAux->nombreEs << endl;
        cout << "Nombre en ingles: " << vehiculoAux->nombreEn << endl;
        cout << "Conductor: " << vehiculoAux->conductor << endl;
        cout << "Tipo de caucho: " << vehiculoAux->tipoCaucho << endl;
        cout << "Tamano de caucho: " << vehiculoAux->tamanoCaucho << endl;
        cout << "Velocidad: " << vehiculoAux->velocidadKm << endl;
        cout << "Vehiculo en pantalla: " << vehiculoAux->vehiculoEnPantalla << endl;
        cout << "Duracion en pista: " << vehiculoAux->duracionEnPista << endl<<endl;
        vehiculoAux = vehiculoAux->prox;
    }
}

//función que modifica la posición de un vehiculo en la pista.
void modificarUnVehiculo(tCarril *carrilAux, tPista *pista){ // mover uno a la derecha 
    tKilometro *kilometroAux = carrilAux->ubicacionVehiculo;
    carrilAux->vehiculo->contadorAux++; // contador debe empezar en 0 , se hace en gestion de vehiculo
    
    //   while(carrilAux->vehiculo->contadorAux >= 1){
        if (kilometroAux->prox!=NULL){
        //     if (validarSiPuedeMover(carrilAux,pista,carrilAux->vehiculo->contadorAux)){
            kilometroAux->vehiculoPresente=false;
            kilometroAux->prox->vehiculoPresente=true;
            carrilAux->ubicacionVehiculo=kilometroAux->prox;
        }
       // } fin if validar
        else if (carrilAux->terminoCarrera==false){
            carrilAux->terminoCarrera=true;
            auto end = std::chrono::system_clock::now();
            auto elipsetime = std::chrono::duration_cast<std::chrono::seconds>(end - pista->tiempoInicio).count();
            carrilAux->vehiculo->duracionEnPista = elipsetime;
        }
        else if (carrilAux->terminoCarrera==true) {
            llegaronTodos(pista, &lleg);
        }
    //  }  // while fin
}

void modificarPociciones(tPista *pistaAux){ // pararse en ubicacion del vehiculo 
    tCarril *carrilAux = pistaAux->primerCarril;
    for (int i = 0; i < pistaAux->numeroCarriles; i++)
    {
        //aquí
        modificarUnVehiculo(carrilAux, pistaAux);
        carrilAux = carrilAux->prox;
    }
}

/*
int validarSiPuedeMover(tCarril *carrilAux, tPista *pista ,double contador ){
    double tiempoEnNodo ;
    // 1 = bomba
    // 2 = piedra
    // 3 = liquido
    if (carrilAux->ubicacionVehiculo->obstaculoPresente){

        if (carrilAux->ubicacionVehiculo->obstaculo->display==1){ tiempoEnNodo = (pista->longitud/carrilAux->vehiculo->velocidadKm)*((carrilAux->vehiculo->resistenciaBomba / 100) + 1);
        }else if (carrilAux->ubicacionVehiculo->obstaculo->display==2){ tiempoEnNodo = (pista->longitud/carrilAux->vehiculo->velocidadKm)*((carrilAux->vehiculo->resistenciaPiedra / 100) + 1);
            }else if (carrilAux->ubicacionVehiculo->obstaculo->display==3){ tiempoEnNodo = (pista->longitud/carrilAux->vehiculo->velocidadKm)*((carrilAux->vehiculo->resistenciaLiquido / 100) + 1);}   
        if (contador >= tiempoEnNodo ) {
                contador = contador - tiempoEnNodo;
            return 1;
        }
    }else {
            tiempoEnNodo = (pista->longitud/carrilAux->vehiculo->velocidadKm); // 80 , 120  = 0,66
            if (contador >= tiempoEnNodo ) { 
                contador = contador - tiempoEnNodo; // 1.02 - 0.66 = 0.36
            return 1;
        }
    }
    return 0;
}
*/