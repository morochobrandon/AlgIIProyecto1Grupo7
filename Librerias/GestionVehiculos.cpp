#include "GestionVehiculos.h"

void muestra(tListaVehiculos *listaCompetidores){
    // muestra la tListaVehiculos por pantalla
    tListaVehiculos *t = listaCompetidores;
    cout<<"\n\n\n";
        while (t){
        muestraVehiculoEspecifico(t);
        cout<<"\n\n\n";
        t = t->prox;
        };
    if (listaCompetidores == NULL){
    printf("NULL\n\n");
    }
};

void validarLista(tListaVehiculos *listaCompetidores){
    // muestra la tListaVehiculos por pantalla
    tListaVehiculos *t = listaCompetidores;
    bool invalido = false;
        while (t){
        if(!(validarVehiculo(t->tipoCaucho , t->tamanoCaucho, t->monsterTruck, t->velocidad)&&(validarResistencias1(t->monsterTruck, t->resBomba, t->resPiedra, t->resLiquido, t->velocidadKm)||validarResistencias2(t->velocidad,t->monsterTruck, t->resBomba, t->resPiedra, t->resLiquido, t->velocidadKm)))){
            cout << "El vehiculo: " << t->nombreEs << " no es valido" << endl;
            invalido = true;
        }
        t = t->prox;
        };
    if(invalido){
        cout<< "\n Por favor modificar los vehiculos mencionados \n\n";
    }
};

void agregarVehiculo(tListaVehiculos **listaCompetidores, string nombreEsp , string nombreEn , string piloto , int tipoCaucho , int tamCaucho,  int mT , int velocidad,int velocidadKm , int comoSeVeElVehiculo, int resistenciaBomba, int resistenciaPiedra, int resistenciaLiquido ){
    // inserta x por cabeza de la tListaVehiculos
    tListaVehiculos *t = new tListaVehiculos;
    t->nombreEs = nombreEsp;
    t->nombreEn = nombreEn;
    t->conductor = piloto;
    t->tipoCaucho = tipoCaucho;
    t->tamanoCaucho = tamCaucho;
    t->monsterTruck = mT;
    t->velocidad = velocidad;
    t->velocidadKm = velocidadKm;
    t->resBomba = resistenciaBomba;
    t->resPiedra = resistenciaPiedra;
    t->resLiquido = resistenciaLiquido;
    t->prox = *listaCompetidores;
    *listaCompetidores= t;

    if (comoSeVeElVehiculo == 1){
        t->vehiculoEnPantalla = "¥";
    }else if ( comoSeVeElVehiculo == 2){
        t->vehiculoEnPantalla = "@";
    }else if ( comoSeVeElVehiculo == 3){
        t->vehiculoEnPantalla = "©";
    }else if ( comoSeVeElVehiculo == 4){
        t->vehiculoEnPantalla = "£";
    }else if ( comoSeVeElVehiculo == 5){
        t->vehiculoEnPantalla = "Ç";
    }else if ( comoSeVeElVehiculo == 6){
        t->vehiculoEnPantalla = "$";
    }else if ( comoSeVeElVehiculo == 7){
        t->vehiculoEnPantalla = "Ø";
    }else if ( comoSeVeElVehiculo == 8){
        t->vehiculoEnPantalla = "æ";
    }else if ( comoSeVeElVehiculo == 9){
        t->vehiculoEnPantalla = "þ";
    }else if ( comoSeVeElVehiculo == 10){
        t->vehiculoEnPantalla = "§";
    }else if ( comoSeVeElVehiculo == 11){
        t->vehiculoEnPantalla = "®";
    }else if ( comoSeVeElVehiculo == 12){
        t->vehiculoEnPantalla = "ª";
    }else if ( comoSeVeElVehiculo == 13){
        t->vehiculoEnPantalla = "º";
    }else if ( comoSeVeElVehiculo == 14){
        t->vehiculoEnPantalla = "Æ";
    }else if ( comoSeVeElVehiculo == 15){
        t->vehiculoEnPantalla = "Ð";
    } 

}

void llenarDatosVehiculo(tListaVehiculos **listaCompetidores, string nombreEsp , string nombreEn , string piloto ,int tipoDeCaucho , int tamanoDeCaucho, int tamanoMonster, int velocidadDelCarro ,int velocidadDelCarroKm  , int comoSeVeElVehiculo, int resistenciaBomba, int resistenciaPiedra, int resistenciaLiquido){
    // Modifica los datos de un nodo de la tListaVehiculos
    tListaVehiculos *t = *listaCompetidores;

    t->nombreEs = nombreEsp;
    t->nombreEn = nombreEn;
    t->conductor = piloto;
    t->tipoCaucho = tipoDeCaucho;
    t->tamanoCaucho = tamanoDeCaucho;
    t->monsterTruck = tamanoMonster;
    t->velocidad = velocidadDelCarro;
    t->velocidadKm = velocidadDelCarroKm;
    t->resBomba = resistenciaBomba;
    t->resPiedra = resistenciaPiedra;
    t->resLiquido = resistenciaLiquido;


    if (comoSeVeElVehiculo == 1){
        t->vehiculoEnPantalla = "¥";
    }else if ( comoSeVeElVehiculo == 2){
        t->vehiculoEnPantalla = "@";
    }else if ( comoSeVeElVehiculo == 3){
        t->vehiculoEnPantalla = "©";
    }else if ( comoSeVeElVehiculo == 4){
        t->vehiculoEnPantalla = "£";
    }else if ( comoSeVeElVehiculo == 5){
        t->vehiculoEnPantalla = "Ç";
    }else if ( comoSeVeElVehiculo == 6){
        t->vehiculoEnPantalla = "$";
    }else if ( comoSeVeElVehiculo == 7){
        t->vehiculoEnPantalla = "Ø";
    }else if ( comoSeVeElVehiculo == 8){
        t->vehiculoEnPantalla = "æ";
    }else if ( comoSeVeElVehiculo == 9){
        t->vehiculoEnPantalla = "þ";
    }else if ( comoSeVeElVehiculo == 10){
        t->vehiculoEnPantalla = "§";
    }else if ( comoSeVeElVehiculo == 11){
        t->vehiculoEnPantalla = "®";
    }else if ( comoSeVeElVehiculo == 12){
        t->vehiculoEnPantalla = "ª";
    }else if ( comoSeVeElVehiculo == 13){
        t->vehiculoEnPantalla = "º";
    }else if ( comoSeVeElVehiculo == 14){
        t->vehiculoEnPantalla = "Æ";
    }else if ( comoSeVeElVehiculo == 15){
        t->vehiculoEnPantalla = "Ð";
    } 
}

void consultarVehiculo(tListaVehiculos *listaCompetidores) {
    string busqueda;
    cout << "Ingrese el nombre del vehiculo en español o en ingles: ";
    getline(cin, busqueda);
    tListaVehiculos *encontrado = nullptr;
    tListaVehiculos *t = listaCompetidores;
    int contador = 0;

    // buscar el primer vehículo que coincida con el nombre dado
    while (t) {
        if (t->nombreEs.find(busqueda) != string::npos || t->nombreEn.find(busqueda) != string::npos) {
            encontrado = t;
            contador++;
        }
        t = t->prox;
    }

    if (!encontrado) {
        cout << "No se encontró ningún vehículo que coincida con la búsqueda." << endl;
        return;
    }

    if (contador == 1) {
        muestraVehiculoEspecifico(encontrado);
        cout << endl;
    } else {
        // si hay varios vehículos encontrados, pedir al usuario que seleccione uno por conductor
        cout << "Se encontraron varios vehículos con ese nombre. Por favor seleccione el conductor del vehículo que desea buscar:" << endl;
        t = listaCompetidores;
        contador = 0;
        while (t) {
            if (t->nombreEs.find(busqueda) != string::npos || t->nombreEn.find(busqueda) != string::npos) {
                contador++;
                cout << contador << ". " << t->conductor << endl;
            }
            t = t->prox;
        }
        cout << "Coloque el numero que acompana al piloto que desea ver la informacion de su vehiculo" << endl;
        cout << "opcion: ";
        int seleccion;
        cin >> seleccion;
        t = listaCompetidores;
        contador = 0;
        while (t) {
            if (t->nombreEs.find(busqueda) != string::npos || t->nombreEn.find(busqueda) != string::npos) {
                contador++;
                if (contador == seleccion) {
                    encontrado = t;
                    break;
                }
            }
            t = t->prox;
        }

        if (!encontrado) {
            cout << "Selección inválida." << endl;
            return;
        }
        muestraVehiculoEspecifico(encontrado);
        cout << endl;
    }
    system("pause");
}

void eliminarVehiculo(tListaVehiculos **listaCompetidores){
    string busqueda;
    cout << "Ingrese el nombre del vehiculo en español o en ingles: ";
    getline(cin, busqueda);

    tListaVehiculos *encontrado = nullptr;
    tListaVehiculos *t = *listaCompetidores ;
    int contador = 0;

    // buscar el primer vehículo que coincida con el nombre dado  , se parara en el ultimo que cumpla las caracteristicas dadas por el usuario
    while (t) {
        if (t->nombreEs.find(busqueda) != string::npos || t->nombreEn.find(busqueda) != string::npos){
            encontrado = t;
            contador++;
        }
        t = t->prox;
    }

    if (!encontrado) {
        cout << "No se encontró ningún vehículo que coincida con la búsqueda." << endl;
        return;
    }

    if (contador == 1) {
            if(*listaCompetidores == encontrado){ // lo que hace es eliminar el nodo con la estructura a eliminar si esta en la cabeza
            *listaCompetidores = (*listaCompetidores)->prox;
                delete encontrado;
                encontrado = *listaCompetidores; 
                cout<<"el elemento a eliminar estaba en la primera casilla\n";
                cout<<"el elemento fue eliminado exitosamente\n";   
            }else{
                t = *listaCompetidores;
                while (t->prox != encontrado) t = t->prox;
                t->prox = encontrado->prox;
                delete encontrado;
                cout<<"el elemento a eliminar estaba por la tListaVehiculos\n";
                cout<<"el elemento fue eliminado exitosamente\n";  
            }
    } else {
        // si hay varios vehículos encontrados, pedir al usuario que seleccione uno por conductor
        cout << "Se encontraron varios vehículos con ese nombre. Por favor seleccione el conductor del vehículo que desea buscar:" << endl;
        t = *listaCompetidores;
        contador = 0;
        while (t) {
            if (t->nombreEs.find(busqueda) != string::npos || t->nombreEn.find(busqueda) != string::npos) {
                contador++;
                cout << contador << ". " << t->conductor << endl;
            }
            t = t->prox;
        }
        cout << "Coloque el numero que acompana al piloto que desea ver la informacion de su vehiculo" << endl;
        cout << "opcion: ";
        int seleccion;
        cin >> seleccion;
        t = *listaCompetidores;
        contador = 0;
        while (t) {
            if (t->nombreEs.find(busqueda) != string::npos || t->nombreEn.find(busqueda) != string::npos) {
                contador++;
                if (contador == seleccion) {
                    encontrado = t;
                    break;
                }
            }
            t = t->prox;
        }

        if (!encontrado) {
            cout << "Selección inválida." << endl;
            return;
        }

    // donde se elimina el nodo

    if(*listaCompetidores == encontrado){ // lo que hace es eliminar el nodo con la estructura a eliminar si esta en la cabeza
            *listaCompetidores = (*listaCompetidores)->prox;
                delete encontrado;
                encontrado = *listaCompetidores; 
                cout<<"el elemento a eliminar estaba en la primera casilla\n";
                cout<<"el elemento fue eliminado exitosamente\n";   
            }else{
                t = *listaCompetidores;
                while (t->prox != encontrado) t = t->prox;
                t->prox = encontrado->prox;
                delete encontrado;
                cout<<"el elemento a eliminar estaba por la tListaVehiculos\n";
                cout<<"el elemento fue eliminado exitosamente\n";  
            }

        
    }
    system("pause");
}

void modificarVehiculo(tListaVehiculos **listaCompetidores){
    string nombreEsp , nombreEn , piloto;
    int bomba, piedra, liquido,tipoDeCaucho ,tamanoDeCaucho, velocidadDelCarro,comoSeVeElVehiculo;
    string busqueda;

    cout << "Ingrese el nombre del vehiculo en español o en ingles: ";
    getline(cin, busqueda);
    tListaVehiculos *encontrado = nullptr;
    tListaVehiculos *t = *listaCompetidores;
    int contador = 0 , datoVehiculoModificar =0;

    // buscar el primer vehículo que coincida con el nombre dado
    while (t) {
        if (t->nombreEs.find(busqueda) != string::npos || t->nombreEn.find(busqueda) != string::npos) {
            encontrado = t;
            contador++;
        }
        t = t->prox;
    }

    if (!encontrado) {
        cout << "No se encontró ningún vehículo que coincida con la búsqueda." << endl;
        return;
    }

    if (contador == 1) {
        modificarDatosDelVehiculoAux(&encontrado);
    } else {
        // si hay varios vehículos encontrados, pedir al usuario que seleccione uno por conductor
        cout << "Se encontraron varios vehículos con ese nombre. Por favor seleccione el conductor del vehículo que desea buscar:" << endl;
        t = *listaCompetidores;
        contador = 0;
        while (t) {
            if (t->nombreEs.find(busqueda) != string::npos || t->nombreEn.find(busqueda) != string::npos) {
                contador++;
                cout << contador << ". " << t->conductor << endl;
            }
            t = t->prox;
        }
        cout << "Coloque el numero que acompana al piloto que desea ver la informacion de su vehiculo" << endl;
        cout << "opcion: ";
        int seleccion;
        cin >> seleccion;
        t = *listaCompetidores;
        contador = 0;
        while (t) {
            if (t->nombreEs.find(busqueda) != string::npos || t->nombreEn.find(busqueda) != string::npos) {
                contador++;
                if (contador == seleccion) {
                    encontrado = t;
                    break;
                }
            }
            t = t->prox;
        }

        if (!encontrado) {
            cout << "Selección inválida." << endl;
            return;
        }
        modificarDatosDelVehiculoAux(&encontrado);
    }
    system("pause");
}

bool validarVehiculo(int tipoDeCaucho , int tamanoDeCaucho, int tamanoMonster, int velocidadDelCarro){
    if((velocidadDelCarro==1 && tamanoDeCaucho==1 && tipoDeCaucho==1 && (tamanoMonster<6 && tamanoMonster>0)) ||  ((velocidadDelCarro==2 || velocidadDelCarro==1)&& tamanoDeCaucho==2 && tipoDeCaucho==2 && tamanoMonster==0) || ((velocidadDelCarro==3 || velocidadDelCarro==4 )&& tamanoDeCaucho==3 && tipoDeCaucho==3 && tamanoMonster==0) ){
        return true;
    }else{
        return false;
    }
}

bool validarResistencias1(int tamanoMonster, int resBomba, int resPiedra, int resLiquido, int velocidadkm){
    if((tamanoMonster==1 && resBomba==15 && resPiedra==20 && resLiquido==30 && velocidadkm==140)|| (velocidadkm==120 && tamanoMonster==2 && resBomba==12 && resPiedra==17 && resLiquido==25) ||(tamanoMonster==3 && resBomba==10 && resPiedra==15 && resLiquido==20 && velocidadkm==110)||(tamanoMonster==4 && resBomba==7 && resPiedra==10 && resLiquido==15 && velocidadkm==100)||(tamanoMonster==5 && resBomba==5 && resPiedra==5 && resLiquido==10 && velocidadkm==80)){
        return true;
    }else{
        return false;
    }
}

bool validarResistencias2(int velocidadDelCarro,int tamanoMonster, int resBomba, int resPiedra, int resLiquido, int velocidadkm){
    if((velocidadDelCarro==1 && tamanoMonster==0 && resBomba==15 && resPiedra==20 && resLiquido==30 && velocidadkm==120)||(velocidadDelCarro==2 && tamanoMonster==0 && resBomba==20 && resPiedra==25 && resLiquido==35 && velocidadkm==140)||(velocidadDelCarro==3 && tamanoMonster==0 && resBomba==25 && resPiedra==30 && resLiquido==20 && velocidadkm==160)||(velocidadDelCarro==4 && tamanoMonster==0 && resBomba==35 && resPiedra==40 && resLiquido==15 && velocidadkm==180)){
        return true;
    }else{
        return false;
    }
}

void pedirDatosVehiculo(tListaVehiculos **listaCompetidores){

    string nombreEsp , nombreIngles , piloto, auxS;
    int tipoDeCaucho ,tamanoDeCaucho, tamanoMonster=0 ,velocidadDelCarro , velocidadDelCarroPorKilometro,comoSeVeElVehiculo, resistenciaBomba, resistenciaPiedra, resistenciaLiquido, opcion, opcion2;

    //Agrega un vehiculo con datos ingresados por el usuario
    cout << "\nIngrese el nombre del vehiculo en español: ";
    getline(cin, nombreEsp);
    cout << "\nIngrese el nombre del vehiculo en ingles: ";
    getline(cin, nombreIngles);
    cout << "\nIngrese el nombre del conductor: ";
    getline(cin, piloto);
    do{
        menuComoSeVeElVehiculo();
        do{
            getline(cin, auxS);
        } while (!esEntero(auxS));
        comoSeVeElVehiculo = stoi(auxS);
    }while(!((comoSeVeElVehiculo>=1)&&(comoSeVeElVehiculo<=15)));

    do{
        menuNuevoVehiculo();
        do{
            cout << "\n Elija como quiere su vehiculo:";
            getline(cin, auxS);
        } while (!esEntero(auxS));
        opcion = stoi(auxS);
        fflush(stdin);
        if (!((opcion>=1)&&(opcion<=9)))
            cout << "\nOpcion invalida, intente de nuevo\n";
        cout << "Opcion: " << opcion << endl;
    } while (!((opcion>=1)&&(opcion<=9)));
    
    switch (opcion){
        case 1:
            tipoDeCaucho=1;
            tamanoDeCaucho=1;
            tamanoMonster=1;
            velocidadDelCarro=1;
            velocidadDelCarroPorKilometro=140;
            resistenciaBomba=15;
            resistenciaPiedra=20;
            resistenciaLiquido=30;
            break;
        case 2:
            tipoDeCaucho=1;
            tamanoDeCaucho=1;
            tamanoMonster=2;
            velocidadDelCarro=1;
            velocidadDelCarroPorKilometro=120;
            resistenciaBomba=12;
            resistenciaPiedra=17;
            resistenciaLiquido=25;
            break;
        case 3:
            tipoDeCaucho=1;
            tamanoDeCaucho=1;
            tamanoMonster=3;
            velocidadDelCarro=1;
            velocidadDelCarroPorKilometro=110;
            resistenciaBomba=10;
            resistenciaPiedra=15;
            resistenciaLiquido=20;
            break;
        case 4:
            tipoDeCaucho=1;
            tamanoDeCaucho=1;
            tamanoMonster=4;
            velocidadDelCarro=1;
            velocidadDelCarroPorKilometro=100;
            resistenciaBomba=7;
            resistenciaPiedra=10;
            resistenciaLiquido=15;
            break;
        case 5:
            tipoDeCaucho=1;
            tamanoDeCaucho=1;
            tamanoMonster=5;
            velocidadDelCarro=1;
            velocidadDelCarroPorKilometro=80;
            resistenciaBomba=5;
            resistenciaPiedra=5;
            resistenciaLiquido=10;
            break;
        case 6:
            tipoDeCaucho=2;
            tamanoDeCaucho=2;
            tamanoMonster=0;
            velocidadDelCarro=1;
            velocidadDelCarroPorKilometro=120;
            resistenciaBomba=15;
            resistenciaPiedra=20;
            resistenciaLiquido=30;
            break;
        case 7:
            tipoDeCaucho=2;
            tamanoDeCaucho=2;
            tamanoMonster=0;
            velocidadDelCarro=2;
            velocidadDelCarroPorKilometro=140;
            resistenciaBomba=20;
            resistenciaPiedra=25;
            resistenciaLiquido=35;
            break;
        case 8:
            tipoDeCaucho=3;
            tamanoDeCaucho=3;
            tamanoMonster=0;
            velocidadDelCarro=3;
            velocidadDelCarroPorKilometro=160;
            resistenciaBomba=25;
            resistenciaPiedra=30;
            resistenciaLiquido=20;
            break;
        case 9:
            tipoDeCaucho=3;
            tamanoDeCaucho=3;
            tamanoMonster=0;
            velocidadDelCarro=4;
            velocidadDelCarroPorKilometro=180;
            resistenciaBomba=35;
            resistenciaPiedra=40;
            resistenciaLiquido=15;
            break;
    }
    
    agregarVehiculo(listaCompetidores, nombreEsp , nombreIngles , piloto ,tipoDeCaucho ,tamanoDeCaucho, tamanoMonster, velocidadDelCarro,velocidadDelCarroPorKilometro, comoSeVeElVehiculo, resistenciaBomba, resistenciaPiedra, resistenciaLiquido);
    cout <<"\n Los datos agregados fueron: \n";
    muestraVehiculoEspecifico(*listaCompetidores);
    cout <<"\n Desea cambiar algo?\n";
    do{
        cout <<"\n 1. Si 2. No\n";
        cin>>opcion2;
    }while(!((opcion2>=1)&&(opcion2<=2)));
    if(opcion2==1){
        modificarDatosDelVehiculoAux(listaCompetidores);
    }
    cout <<"\n todo se agrego correctamente \n";
}

void muestraVehiculoEspecifico(tListaVehiculos *listaCompetidores){
    // muestra la tListaVehiculos por pantalla
    tListaVehiculos *t = listaCompetidores;
    cout<<"\n\n\n";

    cout<<"nombre en espanol:"<<"["<<t->nombreEs<<"]\n";
    cout<<"nombre en ingles:"<<"["<<t->nombreEn<<"]\n";
    cout<<"nombre del conductor:"<<"["<<t->conductor<<"]\n";
    cout<<"tipo de caucho:"<<"["<<t->aTipoCaucho[t->tipoCaucho]<<"]\n";
    cout<<"tamano de caucho:"<<"["<<t->aTamanoCaucho[t->tamanoCaucho];
    if (t->monsterTruck != 0){
        cout<<" "<<t->monsterTruck;}
    cout<<"]\n";
    cout<<"velocidad del vehiculo:"<<"["<<t->aVelocidad[t->velocidad]<<"]\n";
    cout<<"como se ve el vehiculo:"<<"["<<t->vehiculoEnPantalla<<"]\n";

    cout<<"\n\n\n";
};

void muestraVehiculoSimple(tListaVehiculos *listaCompetidores){
    tListaVehiculos *t = listaCompetidores;
    int i=0;
        cout<<"\n\n\n\t\t";
            while (t){
            i++;
            cout<<i<<". "<<t->nombreEs<<" conducido por "<< t->conductor<<"\n";
            cout<<"\n\n\t";
            t = t->prox;
            };
        if (listaCompetidores == NULL){
        printf("NULL\n\n");
        }
}

void modificarDatosDelVehiculoAux(tListaVehiculos **listaCompetidores){
    tListaVehiculos *encontrado = *listaCompetidores;

    string nombreEsp=encontrado->nombreEs , nombreEn=encontrado->nombreEn , piloto=encontrado->conductor, auxS;
    int tipoDeCaucho=encontrado->tipoCaucho ,tamanoDeCaucho= encontrado->tamanoCaucho, tamanoMonster=encontrado->monsterTruck, velocidadDelCarro=encontrado->velocidad , velocidadDelCarroPorKilometro = encontrado->velocidadKm, comoSeVeElVehiculo=0, datoVehiculoModificar, seguirModificando=0,resistenciaBomba=encontrado->resBomba, resistenciaPiedra=encontrado->resPiedra, resistenciaLiquido=encontrado->resLiquido, opcion;
    do{
    cout<<"\n\ndatos del vehiculo\n\n";
    cout<<1<<".  nombre en espanol:"<<"["<<nombreEsp<<"]\n";
    cout<<2<<".  nombre en ingles:"<<"["<<nombreEn<<"]\n";
    cout<<3<<".  nombre del conductor:"<<"["<<piloto<<"]\n";
    cout<<4<<".  como se ve el vehiculo:"<<"["<<encontrado->vehiculoEnPantalla<<"]\n";
    cout<<5<<".  Datos del vehiculo:\n";
    cout<<"\t\t tipo de caucho:"<<"["<<encontrado->aTipoCaucho[tipoDeCaucho]<<"]\n";
    cout<<"\t\t tamano de caucho:"<<"["<<encontrado->aTamanoCaucho[tamanoDeCaucho ];
            if (tamanoMonster != 0){
                cout<<" "<<tamanoMonster;}
            cout<<"]\n";
    cout<<"\t\t velocidad del vehiculo:"<<"["<<encontrado->aVelocidad[velocidadDelCarro]<<"]\n";
    cout<<"\t\t velocidad del vehiculo por kilometro:"<<"["<<encontrado->velocidadKm<<"]\n";
    cout<<6<<". ninguno \n\n";
    cout<<"\n\n que elementos deseas modificar?\n\n";
    do{
        
        do{
            cout<<"elija su opcion: ";
            getline(cin, auxS);
        } while (!esEntero(auxS));
        datoVehiculoModificar = stoi(auxS);
        if (!((datoVehiculoModificar>=1)&&(datoVehiculoModificar<=6)))
            cout << "\nOpcion invalida, intente de nuevo\n";
        cout << "Opcion: " << opcion << endl;
        cin>>datoVehiculoModificar;
    } while( !( (datoVehiculoModificar >= 1)&& (datoVehiculoModificar <=6)));

    if (datoVehiculoModificar == 1){
        cout <<"Nombre en español: " << nombreEsp << endl;
        cout <<"Escribe nuevo nombre:";
        cin>>nombreEsp;
        fflush(stdin);
    } else if(datoVehiculoModificar == 2){
        cout <<"Nombre en ingles: " << nombreEn << endl;
        cout <<"Escribe nuevo nombre:";
        cin>>nombreEn;
        fflush(stdin);
        } else if(datoVehiculoModificar == 3)
        {
            cout << "Conductor: " << piloto << endl;
            cout<<"escribe nuevo nombre de conductor";
            cin>>piloto;
            fflush(stdin);
        }else if(datoVehiculoModificar== 4)
        {
            do{
                cout << "\n\tnuevo\t\n";
                menuComoSeVeElVehiculo();
                do{
                    getline(cin, auxS);
                } while (!esEntero(auxS));
                comoSeVeElVehiculo= stoi(auxS);
            }while(!((comoSeVeElVehiculo>=1)&&(comoSeVeElVehiculo<=15)));
            llenarDatosVehiculo(listaCompetidores,encontrado->nombreEs,encontrado->nombreEn,encontrado->conductor,encontrado->tipoCaucho,encontrado->tamanoCaucho,encontrado->monsterTruck,encontrado->velocidad , encontrado->velocidadKm ,comoSeVeElVehiculo, encontrado->resBomba, encontrado->resPiedra, encontrado->resLiquido);
            fflush(stdin);
        }else if(datoVehiculoModificar == 5)
        {
            do{
                menuNuevoVehiculo();
                do{
                    cout << "\n Elija como quiere su vehiculo:";
                    getline(cin, auxS);
                } while (!esEntero(auxS));
                opcion = stoi(auxS);
                fflush(stdin); 
                if (!((opcion>=1)&&(opcion<=9)))
                    cout << "\nOpcion invalida, intente de nuevo\n";
                cout << "Opcion: " << opcion << endl;
            } while (!((opcion>=1)&&(opcion<=9)));

            switch (opcion){
                case 1:
                    tipoDeCaucho=1;
                    tamanoDeCaucho=1;
                    tamanoMonster=1;
                    velocidadDelCarro=1;
                    velocidadDelCarroPorKilometro=140;
                    resistenciaBomba=15;
                    resistenciaPiedra=20;
                    resistenciaLiquido=30;
                    break;
                case 2:
                    tipoDeCaucho=1;
                    tamanoDeCaucho=1;
                    tamanoMonster=2;
                    velocidadDelCarro=1;
                    velocidadDelCarroPorKilometro=120;
                    resistenciaBomba=12;
                    resistenciaPiedra=17;
                    resistenciaLiquido=25;
                    break;
                case 3:
                    tipoDeCaucho=1;
                    tamanoDeCaucho=1;
                    tamanoMonster=3;
                    velocidadDelCarro=1;
                    velocidadDelCarroPorKilometro=110;
                    resistenciaBomba=10;
                    resistenciaPiedra=15;
                    resistenciaLiquido=20;
                    break;
                case 4:
                    tipoDeCaucho=1;
                    tamanoDeCaucho=1;
                    tamanoMonster=4;
                    velocidadDelCarro=1;
                    velocidadDelCarroPorKilometro=100;
                    resistenciaBomba=7;
                    resistenciaPiedra=10;
                    resistenciaLiquido=15;
                    break;
                case 5:
                    tipoDeCaucho=1;
                    tamanoDeCaucho=1;
                    tamanoMonster=5;
                    velocidadDelCarro=1;
                    velocidadDelCarroPorKilometro=80;
                    resistenciaBomba=5;
                    resistenciaPiedra=5;
                    resistenciaLiquido=10;
                    break;
                case 6:
                    tipoDeCaucho=2;
                    tamanoDeCaucho=2;
                    tamanoMonster=0;
                    velocidadDelCarro=1;
                    velocidadDelCarroPorKilometro=120;
                    resistenciaBomba=15;
                    resistenciaPiedra=20;
                    resistenciaLiquido=30;
                    break;
                case 7:
                    tipoDeCaucho=2;
                    tamanoDeCaucho=2;
                    tamanoMonster=0;
                    velocidadDelCarro=2;
                    velocidadDelCarroPorKilometro=140;
                    resistenciaBomba=20;
                    resistenciaPiedra=25;
                    resistenciaLiquido=35;
                    break;
                case 8:
                    tipoDeCaucho=3;
                    tamanoDeCaucho=3;
                    tamanoMonster=0;
                    velocidadDelCarro=3;
                    velocidadDelCarroPorKilometro=160;
                    resistenciaBomba=25;
                    resistenciaPiedra=30;
                    resistenciaLiquido=20;
                    break;
                case 9:
                    tipoDeCaucho=3;
                    tamanoDeCaucho=3;
                    tamanoMonster=0;
                    velocidadDelCarro=4;
                    velocidadDelCarroPorKilometro=180;
                    resistenciaBomba=35;
                    resistenciaPiedra=40;
                    resistenciaLiquido=15;
                    break;
            }
        }else if(datoVehiculoModificar == 6){
            cout<<"\n\nNo se modifico ningun dato \n\n";
        }

        do{
            cout<<"Desea seguir modificando datos del vehiculo? \n";
            cout<<"1. Si 2. No \n";
            cout<<"opcion : \n";
            cin>>seguirModificando;
        }while(!((seguirModificando>=1)&&(seguirModificando<=2)));
        fflush(stdin);
        }while((seguirModificando==1));
        llenarDatosVehiculo(listaCompetidores, nombreEsp, nombreEn, piloto, tipoDeCaucho, tamanoDeCaucho, tamanoMonster, velocidadDelCarro , velocidadDelCarroPorKilometro, comoSeVeElVehiculo, resistenciaBomba, resistenciaPiedra, resistenciaLiquido);
        cout<<"\n\n vehiculo modificado con exito \n\n";
}
/*
void cargar_archivo2(tListaVehiculos **listaCompetidores) {
    string nombreEs, nombreEn, conductor, comoSeVeElVehiculo;
    int tipoCaucho, tamanoCaucho, tamanoMonster, velocidad;

    ifstream arch;
    arch.open("Librerias/archivos/vehiculos.txt", ios::in);
    while(!arch.eof()){
        arch >> nombreEs >> nombreEn >> conductor >> tipoCaucho >> tamanoCaucho >> tamanoMonster >> velocidad >>comoSeVeElVehiculo;
        if (!arch.eof()){
            nuevo = new tListaVehiculos;
            nuevo->nombreEs = nombreEs;
            nuevo->nombreEn = nombreEn;
            nuevo->conductor = conductor;
            nuevo->tipoCaucho = tipoCaucho;
            nuevo->tamanoCaucho = tamanoCaucho;
            nuevo->velocidad = velocidad;
            nuevo->vehiculoEnPantalla = comoSeVeElVehiculo;
            if (primero == NULL) {
            primero = nuevo;
            primero->prox = NULL;
            ultimo = primero;
            } else {
            ultimo->prox = nuevo;
            nuevo->prox = NULL;
            ultimo = nuevo;
            }
        }
    }  arch.close();
    *listaCompetidores = primero;
}
*/

void cargar_archivo3(tListaVehiculos **listaCompetidores) {
    ifstream arch("Librerias/archivos/vehiculos.txt");

    tListaVehiculos *primero = NULL;
    tListaVehiculos *ultimo = NULL;
    tListaVehiculos *nuevo;

    string linea;
    while (getline(arch, linea)) {
        stringstream ss(linea);
        nuevo = new tListaVehiculos;

        getline(ss, nuevo->nombreEs, '/');
        getline(ss, nuevo->nombreEn, '/');
        getline(ss, nuevo->conductor, '/');
        ss >> nuevo->tipoCaucho;
        ss.ignore(1, '/');
        ss >> nuevo->tamanoCaucho;
        ss.ignore(1, '/');
        ss >> nuevo->monsterTruck;
        ss.ignore(1, '/');
        ss >> nuevo->velocidad;
        ss.ignore(1, '/');
        ss >> nuevo->velocidadKm;
        ss.ignore(1, '/');
        ss >> nuevo->resBomba;
        ss.ignore(1, '/');
        ss >> nuevo->resPiedra;
        ss.ignore(1, '/');
        ss >> nuevo->resLiquido;
        ss.ignore(1, '/');
        getline(ss, nuevo->vehiculoEnPantalla);
        
        nuevo->prox = NULL;
        if (primero == NULL) {
            primero = nuevo;
            ultimo = nuevo;
        } else {
            ultimo->prox = nuevo;
            ultimo = nuevo;
        }
    }

    arch.close();

    *listaCompetidores = primero;
}

void descargar_archivo3(tListaVehiculos* primero) {
    ofstream arch("Librerias/archivos/vehiculos.txt");

    tListaVehiculos* actual = primero;

    while (actual != NULL) {
        arch << actual->nombreEs << "/" << actual->nombreEn << "/" << actual->conductor << "/" << actual->tipoCaucho << "/" << actual->tamanoCaucho << "/" << actual->monsterTruck << "/"<< actual->velocidad << "/" << actual->velocidadKm << "/" << actual->resBomba << "/" << actual->resPiedra << "/" << actual->resLiquido << "/" << actual->vehiculoEnPantalla << endl;
        actual = actual->prox;
    }

    arch.close();
}

void eliminartListaVehiculos(tListaVehiculos *listaCompetidores){
	tListaVehiculos *t = listaCompetidores;
	while (listaCompetidores != NULL) {
		listaCompetidores = listaCompetidores->prox;
		delete t;
		t = listaCompetidores;
	}
	cout<<"la tListaVehiculos fue eliminada exitosamente\n";
}

void convertirVehiculo(tListaVehiculos *listaCompetidores, int cont, tListaVehiculos **vehiculo) {
    tListaVehiculos *aux = listaCompetidores;
    for (int i = 1; i < cont && aux != NULL; i++) {
        aux = aux->prox;
    }
    *vehiculo = aux;
}