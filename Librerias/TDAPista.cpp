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


void generarPista(tPista *pista, tListaVehiculos *vehiculos, bool random) {
    srand(time(NULL));
    bool lleg=false;
    string auxS;
    int vehiculoABuscar;
    int contadorVehiculos = cantidadVehiculos(vehiculos);
    fflush(stdin);
    cout << "Ingrese el nombre de la pista: ";
    cin >> pista->nombre;
    
    do
    {
        fflush(stdin); //
        cout << "Ingrese la cantidad de carriles: ";
        getline(cin, auxS);
    } while (!esEntero(auxS));
        pista->numeroCarriles = stoi(auxS);
    for (int i = 0; i < pista->numeroCarriles; i++) {
        tCarril *carril = new tCarril;
        if(!random){
            muestraVehiculoSimple(vehiculos);
            do
            {
                do
                {
                    cout << "Selecciona el vehiculo para el carril " << i << "(ingrese el numero a un lado): ";
                    getline(cin, auxS);
                } while (!esEntero(auxS));
                vehiculoABuscar=stoi(auxS);
            } while ((vehiculoABuscar<1)||(vehiculoABuscar > contadorVehiculos));
        }else{
            vehiculoABuscar=rand() % contadorVehiculos + 1;
        }
    
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
    generarObstaculos(pista);
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
                        kilometroAux->obstaculoPresente=true;
                        
                    }else{kilometroAux->obstaculo->display=0; kilometroAux->obstaculoPresente=false;}
                    break;}
                case 2:{
                    if (!obsPiedra)
                    {
                        kilometroAux->obstaculo->display = 2;
                        obsPiedra=true;
                        kilometroAux->obstaculoPresente=true;
                    }else{kilometroAux->obstaculo->display=0; kilometroAux->obstaculoPresente=false;}
                    break;}
                case 3:{
                    if (!obsliquido)
                    {
                        kilometroAux->obstaculo->display = 3;
                        obsliquido=true;
                        kilometroAux->obstaculoPresente=true;
                    }else{kilometroAux->obstaculo->display=0; kilometroAux->obstaculoPresente=false;}
                    break;}
                }
            } else
            {
                kilometroAux->obstaculo->display=0; kilometroAux->obstaculoPresente=false;
            }
            
            kilometroAux = kilometroAux->prox;
        }
        carrilAux = carrilAux->prox;
    }
}


void insercion(tListaVehiculos **p){
	tListaVehiculos *ax=*p, *t=*p; 
	int velocidades;
    string nombreEsp , nombreEng, pilotos;

	while (ax->prox!=NULL){
		t=ax->prox;		
		while (t!=NULL){							
			if(ax->duracionEnPista > t->duracionEnPista){ // "< de Mayor a menor" y "> de menor a mayor"
				nombreEsp = ax->nombreEs;
                ax->nombreEs = t->nombreEs;
                t->nombreEs = nombreEsp;

                nombreEng = ax->nombreEn;
                ax->nombreEn = t->nombreEn;
                t->nombreEn = nombreEng;

                pilotos = ax->conductor;
                ax->conductor = t->conductor;
                t->conductor = pilotos;
                
                velocidades = ax->duracionEnPista;
				ax->duracionEnPista=t->duracionEnPista;
				t->duracionEnPista=velocidades;
			}
			t=t->prox;
		}
	ax=ax->prox;	
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
    insercion(&tablaVehiculos);
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
    while (!lleg){
        mostrarPista(p);
        {usleep(100000);  } // 1 * 10^(-6) la carrera sera entre 1-8 seg
        modificarPociciones(p);
        system("cls");
    }
}


//función que modifica la posición de un vehiculo en la pista.
void modificarUnVehiculo(tCarril *carrilAux, tPista *pista){ // mover uno a la derecha 
    tKilometro *kilometroAux = carrilAux->ubicacionVehiculo;
    carrilAux->vehiculo->contadorAux = carrilAux->vehiculo->contadorAux + 0.2 ; // contador debe empezar en 0 , se hace en gestion de vehiculo
    
    while(carrilAux->vehiculo->contadorAux >= 0.3 && !carrilAux->terminoCarrera){ // 0.3 dato minimo que coloque para entrar a la condicion
    if (kilometroAux->prox!=NULL){
        if (validarSiPuedeMover(carrilAux,pista)){
        kilometroAux->vehiculoPresente=false;
        kilometroAux->prox->vehiculoPresente=true;
        carrilAux->ubicacionVehiculo=kilometroAux->prox;
        }else{
            break;
            }
    }else if (carrilAux->terminoCarrera==false){
        carrilAux->terminoCarrera=true;
        auto end = std::chrono::system_clock::now();
        auto elipsetime = std::chrono::duration_cast<std::chrono::milliseconds>(end - pista->tiempoInicio).count();
        carrilAux->vehiculo->duracionEnPista = elipsetime;
        llegaronTodos(pista, &lleg);
    } 
    } // while fin
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


bool validarSiPuedeMover(tCarril *carrilAux, tPista *pista){
    double tiempoEnNodo ;
    double longitud = pista->longitud;
    double velocidadKm = carrilAux->vehiculo->velocidadKm;
    double resBomba = carrilAux->vehiculo->resBomba;
    double resPiedra = carrilAux->vehiculo->resPiedra;
    double resLiquido = carrilAux->vehiculo->resLiquido;
    // 1 = bomba
    // 2 = piedra
    // 3 = liquido

    if (carrilAux->ubicacionVehiculo->obstaculoPresente){

        if (carrilAux->ubicacionVehiculo->obstaculo->display==1)
        {
            tiempoEnNodo = (longitud/velocidadKm)+((velocidadKm*resBomba)/1000);
        }else if (carrilAux->ubicacionVehiculo->obstaculo->display==2)
            {
                tiempoEnNodo = (longitud/velocidadKm)+((velocidadKm*resPiedra)/1000);
            }
            else if (carrilAux->ubicacionVehiculo->obstaculo->display==3)
                { 
                    tiempoEnNodo = (longitud/velocidadKm)+((velocidadKm*resLiquido)/1000); 
                }
        if (carrilAux->vehiculo->contadorAux < tiempoEnNodo ){
            return false;
        }else {
            carrilAux->vehiculo->contadorAux = (carrilAux->vehiculo->contadorAux - tiempoEnNodo);
            return true;
        }
    }else{
        tiempoEnNodo = (longitud/velocidadKm); 
        if (carrilAux->vehiculo->contadorAux < tiempoEnNodo ){
            return false;
        }else {
            carrilAux->vehiculo->contadorAux = (carrilAux->vehiculo->contadorAux - tiempoEnNodo);
            return true;
        }
    }
}

void descargarArchivoPista(tListaVehiculos *tabla) {
    ofstream arch("Librerias/Archivos/tablaDePosiciones.txt");

    tListaVehiculos* actual = tabla;
    int cont=0;
    while (actual != NULL) {
        arch <<++cont << ". "<< actual->nombreEs<< "/" << actual->nombreEn << "/" << actual->conductor << "/" <<actual->duracionEnPista<< endl;
        actual = actual->prox;
    }

    arch.close();
}