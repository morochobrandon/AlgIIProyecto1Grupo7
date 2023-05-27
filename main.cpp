#include <iostream>
using namespace std;

struct lista{
string nombre_es;
string nombre_en;
string conductor;
//string tipo_caucho;
//string tamano_caucho;
//string velocidad;
int resistencia_bomba;
int resistencia_piedra;
int resistencia_liquido;
lista* prox;
};

/*
struct Carril{
int numerosDeCarriles;
Vehiculos vehiculos;
};
*/

/*
struct Carrera{
lista* inicio;
int dimension;
};
/
/
typedef struct {
char* tipo; // tipo de obstaculo
int tiempo; // tiempo que afecta al vehiculo
} Obstaculo;

typedef struct {
lista* carriles;
lista* obstaculos;
lista* vehiculos;
} Juego;
*/

void agregarVehiculo(lista **p, string nombreEsp , string nombregringo , string piloto , int bomba , int piedra , int liquido);
void muestra(lista *p);
void mostrarOpciones();
void consultarVehiculo(lista *p);
void eliminarVehiculo(lista **p);
void modificarVehiculo(lista **p);

int main(){
lista * p=nullptr;
int opcion=-1;

//fflush(stdin);  //por si las variables se ponen graciosas jajajajaj

string nombreEsp , nombregringo , piloto;
int bomba , piedra , liquido;

agregarVehiculo(&p, "Super Ferrari" , "Army Surplus Special" , "Sargento Blast" , 4 , 1 , 1);
agregarVehiculo(&p, "Super Ferrari" , "Army Surplus Special" , "Soldado Meekly" , 4 , 1 , 1); 
agregarVehiculo(&p, "Antiguomovil" , "Bulletproof Bomb" , "Hermanos Anticuados" , 3 , 1 , 2);
agregarVehiculo(&p, "Alambique Veloz" , "Roaring Plenty" , "Lucas el Loco" , 2 , 1 , 3);
agregarVehiculo(&p, "Alambique Veloz" , "Roaring Plenty" , "Osvaldo el Oso" , 2 , 1 , 3);
agregarVehiculo(&p, "Superheterodino" , "Turbo Terrific" , "Peter Perfecto" , 1 , 1 , 4);
agregarVehiculo(&p, "Troncoswagen " , " Arkansas Chugabug" , " Tio Tomas" , 1 , 4 , 1);
agregarVehiculo(&p, "Troncoswagen" , "Arkansas Chugabug" , "Oso Miedoso" , 2 , 2 , 2);
agregarVehiculo(&p, "Super Convertible" , "Mean Machine" , "Pierre Nodoyuna" , 3 , 3 , 0);
agregarVehiculo(&p, "Super Convertible" , "Mean Machine" , " Patan" , 3 , 2 , 1);
agregarVehiculo(&p, "Rocomovil" , "Bouldermobile" , "Hermanos Macana, Piedro y Roco" , 4 , 0 , 2);
agregarVehiculo(&p, "El Espantomovil" , "Creepy Coupe" , " Los Tenebrosos" , 2 , 3 , 1);
agregarVehiculo(&p, " Auto_Convertible" , "Convert-a-car" , " profesor Locovich" , 3 , 0 , 3);
agregarVehiculo(&p, " Stuka Rakuda" , "Crimson Haybailer" , "Baron Hans Fritz" , 1 , 3 , 2);
agregarVehiculo(&p, " Compact Pussycat" , "  Compact Pussycat " , "Penelope Glamour" , 0, 3 , 3);

while (opcion!=0){
	mostrarOpciones();
    cout<<"\n Opcion  :";
	cin>>opcion;
    cin.ignore();
	system("cls");
	cout<<"\n la opcion fue"<<opcion;
if (opcion == 1){
	cout << "\nIngrese el nombre del vehiculo en español: ";
getline(cin, nombreEsp);
cout << "\nIngrese el nombre del vehiculo en ingles: ";
getline(cin, nombregringo);
cout << "\nIngrese el nombre del conductor: ";
getline(cin, piloto);
/* cout << "Ingrese el tipo de caucho utilizado: ";
cout << "Ingrese el tamaño del caucho utilizado: ";
cout << "Ingrese la velocidad maxima del vehiculo: "; */
cout << "Ingrese la resistencia de la bomba del vehiculo: ";
cin >>bomba;
cout << "Ingrese la resistencia a las piedras del vehiculo: ";
cin >>piedra;
cout << "Ingrese la resistencia a los liquidos del vehiculo: ";
cin >>liquido;
agregarVehiculo(&p, nombreEsp , nombregringo , piloto , bomba , piedra , liquido);
} else if (opcion == 2){
			modificarVehiculo(&p);
      //  modificarVehiculo(vehiculos);
} else if (opcion == 3){
		eliminarVehiculo(&p);
       //  eliminarVehiculo(vehiculos);
} else if (opcion == 4){
        consultarVehiculo(p);
      //  consultarVehiculo(vehiculos);
}else if (opcion == 5){
      //  generarCarriles(vehiculos);
}else if (opcion == 6){

      //  simularCarrera(vehiculos);
}else if (opcion == 7){
      //  mostrarTabla(vehiculos);
}else if (opcion == 9){
	muestra(p);
	} else {
	cout << "Opcion invalida. Por favor, seleccione una opcion valida." << endl;
}
}
cout<<"\n\n";
if (opcion) system("pause");
system("cls");
//eliminar lista
eliminarLista(&p);
return 0;

}

void agregarVehiculo(lista **p, string nombreEsp , string nombregringo , string piloto , int bomba , int piedra , int liquido){
// inserta x por cabeza de la lista
lista *t = new lista;
t->nombre_es = nombreEsp;
t->nombre_en = nombregringo;
t->conductor = piloto;
t->resistencia_bomba = bomba;
t->resistencia_piedra = piedra;
t->resistencia_liquido = liquido;
t->prox = *p;
*p= t;
cout <<"\n todo se agrego correctamente \n";
}

void muestra(lista *p){
// muestra la lista por pantalla
lista *t = p;
cout<<"\n\n\n\t\t";
while (t){
cout<<"["<<t->nombre_es<<"]\n";
cout<<"["<<t->nombre_en<<"]\n";
cout<<"["<<t->conductor<<"]\n";
cout<<"["<<t->resistencia_bomba<<"]\n";
cout<<"["<<t->resistencia_piedra<<"]\n";
cout<<"["<<t->resistencia_liquido<<"]\n";
cout<<"\n\n\n\t\t";
t = t->prox;
};
printf("NULL\n\n");
};

void mostrarOpciones(){
cout << "1. Agregar vehiculo" << endl;
cout << "2. Modificar vehiculo" << endl;
cout << "3. Eliminar vehiculo" << endl;
cout << "4. Consultar vehiculo" << endl;
cout << "5. Generar carriles de la carrera" << endl;
cout << "6. Simular carrera" << endl;
cout << "7. Mostrar tabla de posiciones" << endl;
cout << "8. Salir" << endl;
cout << "9. Mostrar todos los vehiculos" << endl;
}

void consultarVehiculo(lista *p) {
string busqueda;
cout << "Ingrese el nombre del vehiculo en español o en ingles: ";
getline(cin, busqueda);
cin.ignore();

lista *encontrado = nullptr;
lista *t = p;
int contador = 0;

// buscar el primer vehículo que coincida con el nombre dado
while (t) {
    if (t->nombre_es.find(busqueda) != string::npos || t->nombre_en.find(busqueda) != string::npos) {
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
    cout << "Nombre en español: " << encontrado->nombre_es << endl;
    cout << "Nombre en inglés: " << encontrado->nombre_en << endl;
    cout << "Conductor: " << encontrado->conductor << endl;
    cout << "Resistencia a labomba: " << encontrado->resistencia_bomba << endl;
	cout << "Resistencia a las piedras: " << encontrado->resistencia_piedra << endl;
    cout << "Resistencia a los líquidos: " << encontrado->resistencia_liquido << endl;
    cout << endl;
} else {
    // si hay varios vehículos encontrados, pedir al usuario que seleccione uno por conductor
    cout << "Se encontraron varios vehículos con ese nombre. Por favor seleccione el conductor del vehículo que desea buscar:" << endl;
    t = p;
    contador = 0;
    while (t) {
        if (t->nombre_es.find(busqueda) != string::npos || t->nombre_en.find(busqueda) != string::npos) {
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
        if (t->nombre_es.find(busqueda) != string::npos || t->nombre_en.find(busqueda) != string::npos) {
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

    cout << "Nombre en español: " << encontrado->nombre_es << endl;
    cout << "Nombre en inglés: " << encontrado->nombre_en << endl;
    cout << "Conductor: " << encontrado->conductor << endl;
    cout << "Resistencia a labomba: " << encontrado->resistencia_bomba << endl;
	cout << "Resistencia a las piedras: " << encontrado->resistencia_piedra << endl;
    cout << "Resistencia a los líquidos: " << encontrado->resistencia_liquido << endl;
    cout << endl;
}
system("pause");
}


void eliminarVehiculo(lista **p){
string busqueda;
cout << "Ingrese el nombre del vehiculo en español o en ingles: ";
getline(cin, busqueda);

lista *encontrado = nullptr;
lista *t = *p ;
int contador = 0;

// buscar el primer vehículo que coincida con el nombre dado  , se parara en el ultimo que cumpla las caracteristicas dadas por el usuario
while (t) {
    if (t->nombre_es.find(busqueda) != string::npos || t->nombre_en.find(busqueda) != string::npos) {
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
            cout<<"el elemento a eliminar estaba por la lista\n";
            cout<<"el elemento fue eliminado exitosamente\n";  
        }
} else {
    // si hay varios vehículos encontrados, pedir al usuario que seleccione uno por conductor
    cout << "Se encontraron varios vehículos con ese nombre. Por favor seleccione el conductor del vehículo que desea buscar:" << endl;
    t = *p;
    contador = 0;
    while (t) {
        if (t->nombre_es.find(busqueda) != string::npos || t->nombre_en.find(busqueda) != string::npos) {
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
        if (t->nombre_es.find(busqueda) != string::npos || t->nombre_en.find(busqueda) != string::npos) {
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
            cout<<"el elemento a eliminar estaba por la lista\n";
            cout<<"el elemento fue eliminado exitosamente\n";  
        }

    
}
system("pause");
}
//eliminar lista
void eliminarLista(lista **p){
	lista *t = *p;
	while (t) {
		*p = (*p)->prox;
		delete t;
		t = *p;
	}
	cout<<"la lista fue eliminada exitosamente\n";
	system("pause");
}
void modificarVehiculo(lista **p){
    string nombreEsp , nombregringo , piloto;
int bomba =0, piedra=0 , liquido=0;
string busqueda;
cout << "Ingrese el nombre del vehiculo en español o en ingles: ";
getline(cin, busqueda);
lista *encontrado = nullptr;
lista *t = *p;
int contador = 0 , datoVehiculoModificar =0;

// buscar el primer vehículo que coincida con el nombre dado
while (t) {
    if (t->nombre_es.find(busqueda) != string::npos || t->nombre_en.find(busqueda) != string::npos) {
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

    cout<<"\n\ndatos del vehiculo\n\n";
    cout <<1<< ". Nombre en español: " << encontrado->nombre_es << endl;
    cout <<2<< ". Nombre en inglés: " << encontrado->nombre_en << endl;
    cout <<3<< ". Conductor: " << encontrado->conductor << endl;
    cout <<4<< ". Resistencia a labomba: " << encontrado->resistencia_bomba << endl;
    cout <<5<< ". Resistencia a las piedras: " << encontrado->resistencia_piedra << endl;
    cout <<6<< ". Resistencia a los líquidos: " << encontrado->resistencia_liquido << endl;
	cout<<"\n\n  ninguno \n\n";
	cout<<"\n\n que elementos deseas modificar\n\n";
    do{
		cout<<"eliga su opcion: ";
	cin>>datoVehiculoModificar;
    }while( !( (datoVehiculoModificar >= 0)&& (datoVehiculoModificar < 7)));
    
	if (datoVehiculoModificar == 1){
		cout <<"Nombre en español: " << encontrado->nombre_es << endl;
		cout <<"Escribe nuevo nombre:";
		cin>>nombreEsp;
		fflush(stdin);
		encontrado->nombre_es = nombreEsp;
	}else if(datoVehiculoModificar == 2){
		cout <<"Nombre en ingles: " << encontrado->nombre_en << endl;
		cout <<"Escribe nuevo nombre:";
		cin>>nombregringo;
		fflush(stdin);
		encontrado->nombre_en = nombregringo;
	}else if(datoVehiculoModificar == 3){
        cout << "Conductor: " << encontrado->conductor << endl;
        cout<<"escribe nuevo nombre de conductor";
        cin>>piloto;
        fflush(stdin);
        encontrado->conductor = piloto;
	}else if (datoVehiculoModificar == 4){
        cout << "Resistencia a labomba: " << encontrado->resistencia_bomba << endl;
        cout<<"escribe nuevo valor de la resistencia contra bombas: ";
        cin>>bomba;
        encontrado->resistencia_bomba = bomba;
	}else if (datoVehiculoModificar == 5){
		cout << "Resistencia a las piedras: " << encontrado->resistencia_piedra << endl;
		cout<<"escribe nuevo valor de la resistencia contra piedras: ";
		cin>>piedra;
	}else if(datoVehiculoModificar ==6){
        cout<<"Resistencia a los liquidos:"<<encontrado->resistencia_liquido<<endl;
        cout<<"escribe nuevo valor de la resistencia contra liquidos: ";
        cin>>liquido;
	}

} else {
    // si hay varios vehículos encontrados, pedir al usuario que seleccione uno por conductor
    cout << "Se encontraron varios vehículos con ese nombre. Por favor seleccione el conductor del vehículo que desea buscar:" << endl;
    t = *p;
    contador = 0;
    while (t) {
        if (t->nombre_es.find(busqueda) != string::npos || t->nombre_en.find(busqueda) != string::npos) {
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
        if (t->nombre_es.find(busqueda) != string::npos || t->nombre_en.find(busqueda) != string::npos) {
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

	cout<<"\n\ndatos del vehiculo\n\n";
    cout <<1<< ". Nombre en español: " << encontrado->nombre_es << endl;
    cout <<2<< ". Nombre en inglés: " << encontrado->nombre_en << endl;
    cout <<3<< ". Conductor: " << encontrado->conductor << endl;
    cout <<4<< ". Resistencia a labomba: " << encontrado->resistencia_bomba << endl;
    cout <<5<< ". Resistencia a las piedras: " << encontrado->resistencia_piedra << endl;
    cout <<6<< ". Resistencia a los líquidos: " << encontrado->resistencia_liquido << endl;
	cout<<"\n\n  ninguno \n\n";
	cout<<"\n\n que elementos deseas modificar\n\n";
    do{
		cout<<"eliga su opcion: ";
	cin>>datoVehiculoModificar;
    }while(!( (datoVehiculoModificar >= 0)&& (datoVehiculoModificar < 7)));
    
	if (datoVehiculoModificar == 1){
		cout <<"Nombre en español: " << encontrado->nombre_es << endl;
		cout <<"Escribe nuevo nombre:";
		cin>>nombreEsp;
		encontrado->nombre_es = nombreEsp;
	}else if(datoVehiculoModificar == 2){
		cout <<"Nombre en ingles: " << encontrado->nombre_en << endl;
		cout <<"Escribe nuevo nombre:";
		cin>>nombregringo;
		encontrado->nombre_en = nombregringo;
	}else if(datoVehiculoModificar == 3){
        cout << "Conductor: " << encontrado->conductor << endl;
        cout<<"escribe nuevo nombre de conductor:";
        cin>>piloto;
        encontrado->conductor = piloto;
	}else if (datoVehiculoModificar == 4){
        cout << "Resistencia a labomba: " << encontrado->resistencia_bomba << endl;
        cout<<"escribe nuevo valor de la resistencia contra bombas: ";
        cin>>bomba;
        encontrado->resistencia_bomba = bomba;
	}else if (datoVehiculoModificar == 5){
		cout << "Resistencia a las piedras: " << encontrado->resistencia_piedra << endl;
		cout<<"escribe nuevo valor de la resistencia contra piedras: ";
		cin>>piedra;
		encontrado->resistencia_piedra = piedra;
	}else if(datoVehiculoModificar ==6){
        cout<<"Resistencia a los liquidos:"<<encontrado->resistencia_liquido<<endl;
        cout<<"escribe nuevo valor de la resistencia contra liquidos: ";
        cin>>liquido;
        encontrado->resistencia_liquido = liquido;
	}
}
system("pause");
}