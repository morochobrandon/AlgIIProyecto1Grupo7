#include "Menus.h"

void OpcionesPista(tPista *pista, tListaVehiculos *p){
    do
    {
        cout<<"\n 1. Generación de la pista";
        cout<<"\n 2. Mostrar pista";
        cout<<"\n 3. Cargar competidores";
        cout<<"\n 4. iniciar carrera";
        cout<<"\n 0. regresar";
        opcion=pedirDatoInt("Ingrese una opcion: ");
        system("cls");
        cout<<"\n la opcion fue: "<<opcion<<endl;
        switch (opcion)
        {
            case 1:
                pedirDatosPista(pista, p);
                generarObstaculos(pista);
                break;
            case 2:
                mostrarPista(pista);
                break;
            case 3:
                cout << "aún no." << endl; 
                break;
            case 4:
                cout << "aún no." << endl; 
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

void opcionesGestionDeVehiculos(tPista *pista, tListaVehiculos *p) {
    do
    {
        cout << "1. Agregar vehiculo" << endl;
        cout << "2. Modificar vehiculo" << endl;
        cout << "3. Eliminar vehiculo" << endl;
        cout << "4. Consultar vehiculo" << endl;
        cout << "5. Validar Lista" << endl;
        cout << "6. Simular carrera" << endl;
        cout << "7. Mostrar tabla de posiciones" << endl;
        cout << "8. Mostrar todos los vehiculos" << endl;
        cout << "0. Salir" << endl;
        opcion=pedirDatoInt("Ingrese una opcion: ");
        system("cls");
        cout<<"\n la opcion fue: "<<opcion<<endl;
        switch (opcion)
        {
            case 1:
                pedirDatosVehiculo(&p);
                break;
            case 2:
                modificarVehiculo(&p);
                break;
            case 3:
                eliminarVehiculo(&p);
                break;
            case 4:
                consultarVehiculo(p); 
                break;
            case 5:
                validarLista(p);
                break;
            case 6:
                OpcionesPista(pista, p);
                break;
            case 7:
                cout << "aún no." << endl;
                break;
            case 8:
                muestra(p);
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