#include "Librerias\GestionVehículos.h"
int main(){
lista * s=nullptr;
tVehiculo *p=nullptr;
int opcion=-1;

//fflush(stdin);  //por si las variables se ponen graciosas jajajajaj


/*
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
*/
while (opcion!=0){
	mostrarOpciones();
    cout<<"\n Opcion  :";
	cin>>opcion;
    cin.ignore();
	system("cls");
	cout<<"\n la opcion fue"<<opcion;
if (opcion == 1){

 pedirDatosVehiculo(*p);


} else if (opcion == 2){
			//modificarVehiculo(&p);
      //  modificarVehiculo(vehiculos);
} else if (opcion == 3){
		//eliminarVehiculo(&p);
       //  eliminarVehiculo(vehiculos);
} else if (opcion == 4){
       // consultarVehiculo(p);
      //  consultarVehiculo(vehiculos);
}else if (opcion == 5){
      //  generarCarriles(vehiculos);
}else if (opcion == 6){

      //  simularCarrera(vehiculos);
}else if (opcion == 7){
      //  mostrarTabla(vehiculos);
}else if (opcion == 9){
	//muestra(p);
	} else {
	cout << "Opcion invalida. Por favor, seleccione una opcion valida." << endl;
}
}
cout<<"\n\n";
if (opcion) system("pause");
system("cls");
//eliminar lista
//eliminarLista(&p);
return 0;

}