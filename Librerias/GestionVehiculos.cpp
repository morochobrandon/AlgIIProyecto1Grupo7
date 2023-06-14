#include "GestionVehiculos.h"
#include "Menus.h"

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
        if(!validarVehiculo(t->tipoCaucho , t->tamanoCaucho, t->monsterTruck, t->velocidad)){
            cout << "El vehiculo " << t->nombreEs << " no es valido" << endl;
            invalido = true;
        }
        t = t->prox;
        };
    if(invalido){
        cout<< "\n Por favor modificar los vehiculos mencionados \n\n";
    }
};

void agregarVehiculo(tListaVehiculos **listaCompetidores, string nombreEsp , string nombreEn , string piloto , int tipoCaucho , int tamCaucho,  int mT , int velocidad,int velocidadKm , int comoSeVeElVehiculo ){
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

void llenarDatosVehiculo(tListaVehiculos **listaCompetidores, string nombreEsp , string nombreEn , string piloto ,int tipoDeCaucho , int tamanoDeCaucho, int tamanoMonster, int velocidadDelCarro ,int velocidadDelCarroKm  , int comoSeVeElVehiculo ){
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
    cin.ignore();

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
    if((velocidadDelCarro==1 && (tamanoDeCaucho==1 || tamanoDeCaucho==2) && tipoDeCaucho==1) || (velocidadDelCarro==2 && tamanoDeCaucho==2 && tipoDeCaucho==2) || ((velocidadDelCarro==3 || velocidadDelCarro==4 )&& tamanoDeCaucho==3 && tipoDeCaucho==3) ){
        return true;
    }else{
        return false;
    }
}

void pedirDatosVehiculo(tListaVehiculos **listaCompetidores){

    string nombreEsp , nombreIngles , piloto;
    int tipoDeCaucho ,tamanoDeCaucho, tamanoMonster=0 ,velocidadDelCarro,comoSeVeElVehiculo, opcion;

    //Agrega un vehiculo con datos ingresados por el usuario
    do{
    cout << "\nIngrese el nombre del vehiculo en español: ";
    getline(cin, nombreEsp);
    cout << "\nIngrese el nombre del vehiculo en ingles: ";
    getline(cin, nombreIngles);
    cout << "\nIngrese el nombre del conductor: ";
    getline(cin, piloto);

    do {
        menuTipoDeCaucho();
        cin>>tipoDeCaucho;
    }while(!((tipoDeCaucho>=1)&&(tipoDeCaucho<=3)));

    do {
        menuTamanoDeCaucho();
        cin>>tamanoDeCaucho;

    }while(!((tamanoDeCaucho>=1)&&(tamanoDeCaucho<=3)));
        if (tamanoDeCaucho=1){
        do{
            menuTipoDeMonsterTruck();
            cin>>tamanoMonster;
        }while(!((tamanoMonster>=1)&&(tamanoMonster<=5)));
        }else{
            tamanoMonster=0;
        }
            

    fflush(stdin);
    do {
        menuVelocidadVehiculo();
        cin>>velocidadDelCarro;
    }while(!((velocidadDelCarro>=1)&&(velocidadDelCarro<=4)));
    fflush(stdin);

    do{
        menuComoSeVeElVehiculo();
        cin>>comoSeVeElVehiculo;
    }while(!((comoSeVeElVehiculo>=1)&&(comoSeVeElVehiculo<=15)));
        fflush(stdin);
        if (!validarVehiculo(tipoDeCaucho ,tamanoDeCaucho, tamanoMonster, velocidadDelCarro)){
            cout<<"el vehiculo no es valido para la carrera\n";
            cout<<"Los datos que ingreso fueron: \n";
            if (tipoDeCaucho == 1){
                cout<<"Todo terreno\n";
            }else if (tipoDeCaucho == 2){
                cout<<"Normales\n";
            }else if (tipoDeCaucho == 3){
                cout<<"Anti coleo\n";
            }

            if (tamanoDeCaucho == 1){
                cout<< "Monster truck"<<tamanoMonster<<"\n";
            }else if (tamanoDeCaucho == 2){
                cout<< "Normales\n";
            }else if (tamanoDeCaucho == 3){
                cout<< "Pegado al piso\n";
            }

            if (velocidadDelCarro == 1){
                cout<< "Perezoso\n";
            }else if (velocidadDelCarro == 2){
                cout<< "Crucero\n";
            }else if (velocidadDelCarro == 3){
                cout<< "Super Ferrari\n";
            }else if (velocidadDelCarro == 4){
                cout<< "Delorean\n";
            }
            cout<<"Recuerda las reglas para la creacion del vehiculo\n";
        }
        

    }while(!(validarVehiculo(tipoDeCaucho ,tamanoDeCaucho, tamanoMonster, velocidadDelCarro)));
    agregarVehiculo(listaCompetidores, nombreEsp , nombreIngles , piloto ,tipoDeCaucho ,tamanoDeCaucho, tamanoMonster, velocidadDelCarro ,comoSeVeElVehiculo );
   // cout <<"\n Su opcion ue la "<< <<"\n";
    cout <<"\n Los datos agregados fueron: \n";
    muestraVehiculoEspecifico(*listaCompetidores);
    cout <<"\n Desea cambiar algo?\n";
    do{
        cout <<"\n 1. Si 2. No\n";
        cin>>opcion;
    }while(!((opcion>=1)&&(opcion<=2)));
    if(opcion==1){
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

    string nombreEsp=encontrado->nombreEs , nombreEn=encontrado->nombreEn , piloto=encontrado->conductor;
    int tipoDeCaucho=encontrado->tipoCaucho ,tamanoDeCaucho= encontrado->tamanoCaucho, tamanoMonster=encontrado->monsterTruck, velocidadDelCarro=encontrado->velocidad, comoSeVeElVehiculo=0, datoVehiculoModificar, seguirModificando=0;
    do{
    cout<<"\n\ndatos del vehiculo\n\n";
    cout<<1<<".  nombre en espanol:"<<"["<<nombreEsp<<"]\n";
    cout<<2<<".  nombre en ingles:"<<"["<<nombreEn<<"]\n";
    cout<<3<<".  nombre del conductor:"<<"["<<piloto<<"]\n";
    cout<<4<<".  tipo de caucho:"<<"["<<encontrado->aTipoCaucho[tipoDeCaucho]<<"]\n";
    cout<<5<<".  tamano de caucho:"<<"["<<encontrado->aTamanoCaucho[tamanoDeCaucho ];
    if (tamanoMonster != 0){
        cout<<" "<<tamanoMonster;}
    cout<<"]\n";
    cout<<6<<".  velocidad del vehiculo:"<<"["<<encontrado->aVelocidad[velocidadDelCarro]<<"]\n";
    cout<<7<<".  como se ve el vehiculo:"<<"["<<encontrado->vehiculoEnPantalla<<"]\n";
    cout<<8<<". ninguno \n\n";
    cout<<"\n\n que elementos deseas modificar?\n\n";
    do{
        cout<<"eliga su opcion: ";
        cin>>datoVehiculoModificar;
    } while( !( (datoVehiculoModificar >= 1)&& (datoVehiculoModificar <=8)));

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
        }else if(datoVehiculoModificar == 4)
        {
            cout << "tipo de caucho: " << encontrado->aTipoCaucho[tipoDeCaucho] << endl;
            do
            {
                cout << "\n\tnuevo\t\n";
                menuTipoDeCaucho();
                cin>>tipoDeCaucho;
            } while(!((tipoDeCaucho>=1)&&(tipoDeCaucho<=3)));
            fflush(stdin);
        } else if(datoVehiculoModificar == 5)
        {
            cout << "tamano de caucho: " << encontrado->aTamanoCaucho[tamanoDeCaucho];  
            if (tamanoDeCaucho==1){
                cout<<" "<<tamanoMonster<<endl;
            }
            do
            {
                cout << "\n\tnuevo\t\n";
                menuTamanoDeCaucho();
                cin>>tamanoDeCaucho;
            } while(!((tamanoDeCaucho>=1)&&(tamanoDeCaucho<=3)));
            if (tamanoDeCaucho==1)
            {
                do{
                    cout << "\n\tnuevo\t\n";
                    menuTipoDeMonsterTruck();
                    cin>>tamanoMonster;
                }while(!((tamanoMonster>=1)&&(tamanoMonster<=5)));
            }
            else
            {
                tamanoMonster=0;
            }
            fflush(stdin);
        } else if(datoVehiculoModificar == 6)
        {
        cout << "velocidad del vehiculo: " << velocidadDelCarro << endl;
        do {
            cout << "\n\tnuevo\t\n";
            menuVelocidadVehiculo();
            cin>>velocidadDelCarro;
        }while(!((velocidadDelCarro>=1)&&(velocidadDelCarro<=4)));
        fflush(stdin);
        } else if(datoVehiculoModificar== 7)
        {
            do{
                cout << "\n\tnuevo\t\n";
                menuComoSeVeElVehiculo();
                cin>>comoSeVeElVehiculo;
            }while(!((comoSeVeElVehiculo>=1)&&(comoSeVeElVehiculo<=15)));
            llenarDatosVehiculo(listaCompetidores,encontrado->nombreEs,encontrado->nombreEn,encontrado->conductor,encontrado->tipoCaucho,encontrado->tamanoCaucho,encontrado->monsterTruck,encontrado->velocidad,comoSeVeElVehiculo);
            fflush(stdin);
        }else if(datoVehiculoModificar == 8){
            cout<<"\n\nNo se modifico ningun dato \n\n";
        }

        do{
            cout<<"Desea seguir modificando datos del vehiculo? \n";
            cout<<"1. Si 2. No \n";
            cout<<"opcion : \n";
            cin>>seguirModificando;
        }while(!((seguirModificando>=1)&&(seguirModificando<=2)));
        fflush(stdin);
        if ((!(validarVehiculo(tipoDeCaucho, tamanoDeCaucho, tamanoMonster, velocidadDelCarro)))&&(seguirModificando==2))
        {
            cout<<"El vehiculo no es valido, por favor recuerde las reglas para la creacion de vehiculos\n\n";
        }
        
        }while((!(validarVehiculo(tipoDeCaucho, tamanoDeCaucho, tamanoMonster, velocidadDelCarro)))||(seguirModificando==1));
        llenarDatosVehiculo(listaCompetidores, nombreEsp, nombreEn, piloto, tipoDeCaucho, tamanoDeCaucho, tamanoMonster, velocidadDelCarro, comoSeVeElVehiculo);
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

    tListaVehiculos* primero = NULL;
    tListaVehiculos* ultimo = NULL;
    tListaVehiculos* nuevo;

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
        arch << actual->nombreEs << "/" << actual->nombreEn << "/" << actual->conductor << "/" << actual->tipoCaucho << "/" << actual->tamanoCaucho << "/" << actual->monsterTruck << "/"<< actual->velocidad << "/" <<actual->vehiculoEnPantalla<< endl;
        actual = actual->prox;
    }

    arch.close();
}

void eliminartListaVehiculos(tListaVehiculos **listaCompetidores){
	tListaVehiculos *t = *listaCompetidores;
	while (t) {
		*listaCompetidores = (*listaCompetidores)->prox;
		delete t;
		t = *listaCompetidores;
	}
	cout<<"la tListaVehiculos fue eliminada exitosamente\n";
	system("pause");
}

void convertirVehiculo(tListaVehiculos *listaCompetidores, int cont, tListaVehiculos **vehiculo) {
    tListaVehiculos *aux = listaCompetidores;
    for (int i = 1; i < cont && aux != NULL; i++) {
        aux = aux->prox;
    }
    *vehiculo = aux;
}