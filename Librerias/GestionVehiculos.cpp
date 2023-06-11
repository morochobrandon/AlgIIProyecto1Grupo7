#include "GestionVehiculos.h"

void muestra(tListaConductores *p){
// muestra la tListaConductores por pantalla
tListaConductores *t = p;
cout<<"\n\n\n\t\t";
    while (t){
    muestraVehiculoEspecifico(t);
    cout<<"\n\n\n\t\t";
    t = t->prox;
    };
printf("NULL\n\n");
};

void validarLista(tListaConductores *p){
// muestra la tListaConductores por pantalla
tListaConductores *t = p;
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

void mostrarOpciones(){
cout << "1. Agregar vehiculo" << endl;
cout << "2. Modificar vehiculo" << endl;
cout << "3. Eliminar vehiculo" << endl;
cout << "4. Consultar vehiculo" << endl;
cout << "5. Validar Lista" << endl;
cout << "6. Simular carrera" << endl;
cout << "7. Mostrar tabla de posiciones" << endl;
cout << "8. Salir" << endl;
cout << "9. Mostrar todos los vehiculos" << endl;
}

void agregarVehiculo(tListaConductores **p, string nombreEsp , string nombreEn , string piloto , int tipoCaucho , int tamCaucho,  int mT , int velocidad, int comoSeVeElVehiculo ){
// inserta x por cabeza de la tListaConductores
tListaConductores *t = new tListaConductores;
t->nombreEs = nombreEsp;
t->nombreEn = nombreEn;
t->conductor = piloto;
t->tipoCaucho = tipoCaucho;
t->tamanoCaucho = tamCaucho;
t->monsterTruck = mT;
t->velocidad = velocidad;
t->prox = *p;
*p= t;

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

void llenarDatosVehiculo(tListaConductores **p, string nombreEsp , string nombreEn , string piloto ,int tipoDeCaucho , int tamanoDeCaucho, int tamanoMonster, int velocidadDelCarro , int comoSeVeElVehiculo ){
// Modifica los datos de un nodo de la tListaConductores
tListaConductores *t = *p;

t->nombreEs = nombreEsp;
t->nombreEn = nombreEn;
t->conductor = piloto;
t->tipoCaucho = tipoDeCaucho;
t->tamanoCaucho = tamanoDeCaucho;
t->monsterTruck = tamanoMonster;
t->velocidad = velocidadDelCarro;


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

void consultarVehiculo(tListaConductores *p) {
string busqueda;
cout << "Ingrese el nombre del vehiculo en español o en ingles: ";
getline(cin, busqueda);
cin.ignore();

tListaConductores *encontrado = nullptr;
tListaConductores *t = p;
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
    t = p;
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
    t = p;
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

void eliminarVehiculo(tListaConductores **p){
string busqueda;
cout << "Ingrese el nombre del vehiculo en español o en ingles: ";
getline(cin, busqueda);

tListaConductores *encontrado = nullptr;
tListaConductores *t = *p ;
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
        if(*p == encontrado){ // lo que hace es eliminar el nodo con la estructura a eliminar si esta en la cabeza
          *p = (*p)->prox;
            delete encontrado;
            encontrado = *p; 
            cout<<"el elemento a eliminar estaba en la primera casilla\n";
            cout<<"el elemento fue eliminado exitosamente\n";   
        }else{
            t = *p;
            while (t->prox != encontrado) t = t->prox;
            t->prox = encontrado->prox;
            delete encontrado;
            cout<<"el elemento a eliminar estaba por la tListaConductores\n";
            cout<<"el elemento fue eliminado exitosamente\n";  
        }
} else {
    // si hay varios vehículos encontrados, pedir al usuario que seleccione uno por conductor
    cout << "Se encontraron varios vehículos con ese nombre. Por favor seleccione el conductor del vehículo que desea buscar:" << endl;
    t = *p;
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
    t = *p;
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

   if(*p == encontrado){ // lo que hace es eliminar el nodo con la estructura a eliminar si esta en la cabeza
          *p = (*p)->prox;
            delete encontrado;
            encontrado = *p; 
            cout<<"el elemento a eliminar estaba en la primera casilla\n";
            cout<<"el elemento fue eliminado exitosamente\n";   
        }else{
            t = *p;
            while (t->prox != encontrado) t = t->prox;
            t->prox = encontrado->prox;
            delete encontrado;
            cout<<"el elemento a eliminar estaba por la tListaConductores\n";
            cout<<"el elemento fue eliminado exitosamente\n";  
        }

    
}
system("pause");
}

void modificarVehiculo(tListaConductores **p){
string nombreEsp , nombreEn , piloto;
int bomba, piedra, liquido,tipoDeCaucho ,tamanoDeCaucho, velocidadDelCarro,comoSeVeElVehiculo;
string busqueda;

cout << "Ingrese el nombre del vehiculo en español o en ingles: ";
getline(cin, busqueda);
tListaConductores *encontrado = nullptr;
tListaConductores *t = *p;
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
    t = *p;
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
    t = *p;
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

void pedirDatosVehiculo(tListaConductores **p){

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
    cout << "\n\n Ingrese el tipo de caucho \n\n";
    cout << "\n 1.Todo terreno";
    cout << "\n 2.Normarles";
    cout << "\n 3.Anti coleo";
    cout << "\n\n (el numero que esta al lado de su opcion)\n\n";
    cout << "\n Ingrese la opcion elegida: ";
    cin>>tipoDeCaucho;
}while(!((tipoDeCaucho>=1)&&(tipoDeCaucho<=3)));

do {
    cout << "\n\n Ingrese el tamano de caucho: \n\n";
    cout << "\n 1.Monster truck";
    cout << "\n 2.Normales";
    cout << "\n 3.Pegado al piso";
    cout << "\n\n (el numero que esta al lado de su opcion)\n\n";
    cout << "\n Ingrese la opcion elegida: ";
    cin>>tamanoDeCaucho;

}while(!((tamanoDeCaucho>=1)&&(tamanoDeCaucho<=3)));
    if (tamanoDeCaucho=1){
     do{
        cout << "\n\n Ingrese el tipo de Monster Truck: \n\n";
        cout << "\n 1. Monster Truck 1";
        cout << "\n 2. Monster Truck 2";
        cout << "\n 3. Monster Truck 3";
        cout << "\n 4. Monster Truck 4";
        cout << "\n 5. Monster Truck 5";
        cout << "\n Ingrese la opcion elegida: ";
        cin>>tamanoMonster;
     }while(!((tamanoMonster>=1)&&(tamanoMonster<=5)));
    }else{
        tamanoMonster=0;
    }
        

fflush(stdin);
do {
    cout << "\n\n Ingrese la velocidad del vehiculo: \n\n";
    cout << "\n 1.Perezoso";
    cout << "\n 2.Crucero";
    cout << "\n 3.SuperFerrari";
    cout << "\n 4.Delorean";
    cout << "\n\n (el numero que esta al lado de su opcion)\n\n";
    cout << "\n Ingrese la opcion elegida: ";
    cin>>velocidadDelCarro;
}while(!((velocidadDelCarro>=1)&&(velocidadDelCarro<=4)));
fflush(stdin);

do{
    cout<< "Ingrese como se ve el vehiculo en pantalla: \n";
    cout<<"1  = ¥\n"; 
    cout<<"2  = @\n";
    cout<<"3  =  ©\n";
    cout<<"4  =  £\n";
    cout<<"5  =  Ç\n";
    cout<<"6  =  $\n";
    cout<<"7  =  Ø\n";
    cout<<"8  =  æ\n";
    cout<<"9  =  þ\n";
    cout<<"10 =  §\n";
    cout<<"15 =  Ð\n";
    cout<<"opcion : ";

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
agregarVehiculo(p, nombreEsp , nombreIngles , piloto ,tipoDeCaucho ,tamanoDeCaucho, tamanoMonster, velocidadDelCarro ,comoSeVeElVehiculo );
cout <<"\n Los datos agregados fueron: \n";
muestraVehiculoEspecifico(*p);
cout <<"\n Desea cambiar algo?\n";
do{
    cout <<"\n 1. Si 2. No\n";
    cin>>opcion;
}while(!((opcion>=1)&&(opcion<=2)));
if(opcion==1){
    modificarDatosDelVehiculoAux(p);
}
cout <<"\n todo se agrego correctamente \n";
}

void muestraVehiculoEspecifico(tListaConductores *p){
// muestra la tListaConductores por pantalla
tListaConductores *t = p;
cout<<"\n\n\n\t\t";

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

cout<<"\n\n\n\t\t";
};

void modificarDatosDelVehiculoAux(tListaConductores **p){
tListaConductores *encontrado = *p;

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
cout<<"\n\n que elementos deseas modificar\n\n";
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
            cout << "\n\n escribe nuevo tipo de caucho de estas opciones:\n\n";
            cout << "\n 1.Todo terreno";
            cout << "\n 2.Normales";
            cout << "\n 3.Anti coleo";
            cout << "\n\n (el numero que esta al lado de su opcion)\n\n";
            cout << "\n Ingrese la opcion elegida: ";
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
            cout << "\n\n Ingrese el tamano de nuevo caucho: \n\n";
            cout << "\n 1.Monster truck";
            cout << "\n 2.Normal";
            cout << "\n 3.Pegados al piso";
            cout << "\n\n (el numero que esta al lado de su opcion)\n\n";
            cout << "\n Ingrese la opcion elegida: ";
            cin>>tamanoDeCaucho;
        } while(!((tamanoDeCaucho>=1)&&(tamanoDeCaucho<=3)));
         if (tamanoDeCaucho==1)
        {
            do{
              cout << "\n\n Ingrese el tipo de Monster Truck: \n\n";
            cout << "\n 1. Monster Truck 1";
            cout << "\n 2. Monster Truck 2";
            cout << "\n 3. Monster Truck 3";
            cout << "\n 4. Monster Truck 4";
            cout << "\n 5. Monster Truck 5";
            cout << "\n\n ingrese su opcion: ";
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
        cout << "\n\n Ingrese la velocidad del vehiculo: \n\n";
        cout << "\n 1.Perezoso";
        cout << "\n 2.Crucero";
        cout << "\n 3.SuperFerrari";
        cout << "\n 4.Delorean";
        cout << "\n\n (el numero que esta al lado de su opcion)\n\n";
        cout << "\n Ingrese la opcion elegida: ";
        cin>>velocidadDelCarro;
    }while(!((velocidadDelCarro>=1)&&(velocidadDelCarro<=4)));
    fflush(stdin);
    } else if(datoVehiculoModificar== 7)
    {
        do{
            cout<< "Ingrese como se ve el vehiculo en pantalla: \n";
            cout<<"1  = ¥\n"; 
            cout<<"2  = @\n";
            cout<<"3  =  ©\n";
            cout<<"4  =  £\n";
            cout<<"5  =  Ç\n";
            cout<<"6  =  $\n";
            cout<<"7  =  Ø\n";
            cout<<"8  =  æ\n";
            cout<<"9  =  þ\n";
            cout<<"10 =  §\n";
            cout<<"15 =  Ð\n";
            cout<<"opcion : ";

            cin>>comoSeVeElVehiculo;
        }while(!((comoSeVeElVehiculo>=1)&&(comoSeVeElVehiculo<=15)));
        llenarDatosVehiculo(p,encontrado->nombreEs,encontrado->nombreEn,encontrado->conductor,encontrado->tipoCaucho,encontrado->tamanoCaucho,encontrado->monsterTruck,encontrado->velocidad,comoSeVeElVehiculo);
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
    llenarDatosVehiculo(p, nombreEsp, nombreEn, piloto, tipoDeCaucho, tamanoDeCaucho, tamanoMonster, velocidadDelCarro, comoSeVeElVehiculo);
    cout<<"\n\n vehiculo modificado con exito \n\n";
}

void cargar_archivo2(tListaConductores **p) {
    string nombreEs, nombreEn, conductor, comoSeVeElVehiculo;
    int tipoCaucho, tamanoCaucho, tamanoMonster, velocidad;

    ifstream arch;
    arch.open("Librerias/archivos/vehiculos.txt", ios::in);
    while(!arch.eof()){
        arch >> nombreEs >> nombreEn >> conductor >> tipoCaucho >> tamanoCaucho >> tamanoMonster >> velocidad >>comoSeVeElVehiculo;
        if (!arch.eof()){
            nuevo = new tListaConductores;
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
    *p = primero;
}

void cargar_archivo3(tListaConductores **p) {
    ifstream arch("Librerias/archivos/vehiculos.txt");

    tListaConductores* primero = NULL;
    tListaConductores* ultimo = NULL;
    tListaConductores* nuevo;

    string linea;
    while (getline(arch, linea)) {
        stringstream ss(linea);
        nuevo = new tListaConductores;

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

    *p = primero;
}

void descargar_archivo3(tListaConductores* primero) {
    ofstream arch("Librerias/archivos/vehiculos.txt");

    tListaConductores* actual = primero;

    while (actual != NULL) {
        arch << actual->nombreEs << "/" << actual->nombreEn << "/" << actual->conductor << "/" << actual->tipoCaucho << "/" << actual->tamanoCaucho << "/" << actual->monsterTruck << "/"<< actual->velocidad << "/" <<actual->vehiculoEnPantalla<< endl;
        actual = actual->prox;
    }

    arch.close();

    cout <<"se guardo en el archivo vehiculo\n";
}

void eliminartListaConductores(tListaConductores **p){
	tListaConductores *t = *p;
	while (t) {
		*p = (*p)->prox;
		delete t;
		t = *p;
	}
	cout<<"la tListaConductores fue eliminada exitosamente\n";
	system("pause");
}
