#include "Menus.h"

void menuPrincipal(tPista *pista, tListaVehiculos **listaCompetidores){
    do
    {
        cout << "Bienvenido al juego de Autos Locos. Apuesta por tu carro favorito" << endl;
        cout << "\n\n 1. Gestion de vehiculos" << endl;
        cout << " 2. Juego principal y gestion de pistas" << endl;
        cout << " 0. Salir" << endl;
        cout << "\n Nota: Si entra al juego sin pasar por gestion de vehiculos, se cargaran los vehiculos por defecto." << endl;
        validarLista(*listaCompetidores);
        opcion=pedirDatoInt("Ingrese una opcion: ");
        system("cls");
        cout<<"\n la opcion fue: "<<opcion<<endl;
        system("pause");
        switch (opcion)
        {
        case 1:
            opcionesGestionDeVehiculos(pista, listaCompetidores);
            break;
        case 2:
            pista1(pista, *listaCompetidores);
            break;
        case 0:
            cout<<"Saliendo."<<endl;
            eliminartListaVehiculos(listaCompetidores);
            break;
        
        default:
            cout << "Opcion invalida. Por favor, seleccione una opcion valida." << endl;
            break;
        }
    }while (opcion!=0);
    opcion=-1;
}

void pista1(tPista *pista, tListaVehiculos *listaCompetidores){
    do
    {
        system("cls");
        cout<<"\n 1. Ingresar datos para generar la pista";
        cout<<"\n 2. Generar pista aleatoria";
        cout<<"\n 0. regresar\n";
        opcion=pedirDatoInt("Ingrese una opcion: ");
        system("cls");
        cout<<"\n la opcion fue: "<<opcion<<endl;
        system("pause");
        switch (opcion)
        {
            case 1:
                lleg=false;
                destruirPista(pista);
                pista=inicializarPista();
                generarPista(pista, listaCompetidores, false);
                pista2(pista, listaCompetidores);
                break;
            case 2:
                lleg=false;
                destruirPista(pista);
                pista=inicializarPista();
                generarPista(pista, listaCompetidores, true);
                pista2(pista, listaCompetidores);
                break;
            case 0:
                destruirPista(pista);
                cout << "Saliendo." << endl;
                break;
            default:
                cout << "Opcion invalida. Por favor, seleccione una opcion valida." << endl;
                break;
        }
    } while (opcion!=0);
    opcion=-1;
}

void pista2(tPista *pista, tListaVehiculos *listaCompetidores){
    do
    {
        system("cls");
        cout<<"\n 1. Mostrar pista";
        cout<<"\n 2. iniciar carrera";
        cout<<"\n 0. regresar\n";
        opcion=pedirDatoInt("Ingrese una opcion: ");
        system("cls");
        cout<<"\n la opcion fue: "<<opcion<<endl;
        system("pause");
        switch (opcion)
        {
            case 1:
                mostrarPista(pista);
                system("pause");
                break;
            case 2:
                simularCarrera(pista);
                cout<<"\n\n";
                cout << "La carrera ha finalizado." << endl;
                system("pause");
                system("cls");
                while (opcion!=0)
                {
                    cout << "Quieres ver y guardar la tabla de posiciones?" << endl;
                    cout << "0. No" << endl;
                    cout << "1. Si" << endl;
                    opcion=pedirDatoInt("Ingrese una opcion: ");
                    system("cls");
                    cout<<"\n la opcion fue: "<<opcion<<endl;
                    system("pause");
                    switch (opcion)
                    {
                        case 1:
                            tListaVehiculos *tabla;
                            tabla = tablaDePosiciones(pista);
                            mostrarTablaDePosiciones(tabla);
                            system("pause");
                            descargarArchivoPista(tabla);
                            eliminartListaVehiculos(&tabla);
                            opcion=0;
                            break;
                        case 0:
                            break;
                        default:
                            cout << "Opcion invalida. Por favor, seleccione una opcion valida." << endl;
                            break;
                    }
                }
                
                break;
            case 0:
                cout << "Saliendo." << endl;
                break;
            default:
                cout << "Opcion invalida. Por favor, seleccione una opcion valida." << endl;
                break;
        }
    } while (opcion!=0);
}

void opcionesGestionDeVehiculos(tPista *pista, tListaVehiculos **listaCompetidores) {
    do
    {   
        cout << "1. Agregar vehiculo" << endl;
        cout << "2. Modificar vehiculo" << endl;
        cout << "3. Eliminar vehiculo" << endl;
        cout << "4. Consultar vehiculo" << endl;
        cout << "5. Mostrar todos los vehiculos" << endl;
        cout << "0. Salir" << endl;
        validarLista(*listaCompetidores);
        opcion=pedirDatoInt("Ingrese una opcion: ");
        system("cls");
        cout<<"\n la opcion fue: "<<opcion<<endl;
        switch (opcion)
        {
            case 1:
                pedirDatosVehiculo(listaCompetidores);
                descargar_archivo3(*listaCompetidores);
                break;
            case 2:
                modificarVehiculo(listaCompetidores);
                descargar_archivo3(*listaCompetidores);
                break;
            case 3:
                eliminarVehiculo(listaCompetidores);
                descargar_archivo3(*listaCompetidores);
                break;
            case 4:
                consultarVehiculo(*listaCompetidores); 
                break;
            case 5:
                muestra(*listaCompetidores);
                break;
            case 0:
                fflush(stdin);
                cout << "Saliendo." << endl;
                system("pause");
                break;
            default:
                cout << "Opcion invalida. Por favor, seleccione una opcion valida." << endl;
                break;
        }
    } while (opcion!=0);
    opcion=-1;
}

void menuVelocidadVehiculo(){
        cout << "\n\n Ingrese la velocidad del vehiculo: \n\n";
        cout << "\n 1.Perezoso";
        cout << "\n 2.Crucero";
        cout << "\n 3.SuperFerrari";
        cout << "\n 4.Delorean";
        cout << "\n\n (el numero que esta al lado de su opcion)\n\n";
        cout << "\n Ingrese la opcion elegida: ";
}

void menuTipoDeMonsterTruck(){
        cout << "\n\n Ingrese el tipo de Monster Truck: \n\n";
        cout << "\n 1. Monster Truck 1";
        cout << "\n 2. Monster Truck 2";
        cout << "\n 3. Monster Truck 3";
        cout << "\n 4. Monster Truck 4";
        cout << "\n 5. Monster Truck 5";
        cout << "\n\n (el numero que esta al lado de su opcion)\n\n";
        cout << "\n Ingrese la opcion elegida: ";
}

void menuComoSeVeElVehiculo(){
        cout<< "Ingrese como se ve el vehiculo en pantalla: \n";
        cout<<"1  =  ¥\n"; 
        cout<<"2  =  @\n";
        cout<<"3  =  ©\n";
        cout<<"4  =  £\n";
        cout<<"5  =  Ç\n";
        cout<<"6  =  $\n";
        cout<<"7  =  Ø\n";
        cout<<"8  =  æ\n";
        cout<<"9  =  þ\n";
        cout<<"10 =  §\n";
        cout<<"11 =  ®\n";
        cout<<"12 =  ª\n";
        cout<<"13 =  º\n";
        cout<<"14 =  Æ\n";
        cout<<"15 =  Ð\n";
        cout<<"opcion : ";
}

void menuTipoDeCaucho(){
    cout << "\n\n Ingrese el tipo de caucho \n\n";
    cout << "\n 1.Todo terreno";
    cout << "\n 2.Normarles";
    cout << "\n 3.Anti coleo";
    cout << "\n\n (el numero que esta al lado de su opcion)\n\n";
    cout << "\n Ingrese la opcion elegida: ";
}

void menuTamanoDeCaucho(){
    cout << "\n\n Ingrese el tamano de caucho: \n\n";
    cout << "\n 1.Monster truck";
    cout << "\n 2.Normales";
    cout << "\n 3.Pegado al piso";
    cout << "\n\n (el numero que esta al lado de su opcion)\n\n";
    cout << "\n Ingrese la opcion elegida: ";
}

void menuNuevoVehiculo(){
    cout<<"\n"<<left<<setw(17)<<"Velocidad "    <<setw(13)<<"Tipo Caucho " <<setw(16)<<"Tamano Caucho"  <<setw(13)<<"Velocidad km/h"<<endl;
    cout<<left<<setw(17)<<"1. Perezoso "     <<setw(13)<<"Todo Terreno "<<setw(16)<<"Monster Truck 1 "<<setw(5)<<"140"<<endl;
    cout<<left<<setw(17)<<"2. Perezoso "     <<setw(13)<<"Todo Terreno "<<setw(16)<<"Monster Truck 2 "<<setw(5)<<"120"<<endl;
    cout<<left<<setw(17)<<"3. Perezoso "     <<setw(13)<<"Todo Terreno "<<setw(16)<<"Monster Truck 3 "<<setw(5)<<"110"<<endl;
    cout<<left<<setw(17)<<"4. Perezoso "     <<setw(13)<<"Todo Terreno "<<setw(16)<<"Monster Truck 4 "<<setw(5)<<"100"<<endl;
    cout<<left<<setw(17)<<"5. Perezoso "     <<setw(13)<<"Todo Terreno "<<setw(16)<<"Monster Truck 5 "<<setw(5)<< "80"<<endl;
    cout<<left<<setw(17)<<"6. Perezoso "     <<setw(13)<<"Normales "    <<setw(16)<<"Normales "       <<setw(5)<<"120"<<endl;
    cout<<left<<setw(17)<<"7. Crucero "      <<setw(13)<<"Normales "    <<setw(16)<<"Normales "       <<setw(5)<<"140"<<endl;
    cout<<left<<setw(17)<<"8. super ferrari "<<setw(13)<<"Anti Coleo "  <<setw(16)<<"Pegado al piso " <<setw(5)<<"160"<<endl;
    cout<<left<<setw(17)<<"9. Delorean "     <<setw(13)<<"Anti Coleo "  <<setw(16)<<"Pegado al piso " <<setw(5)<<"180\n\n";
}
