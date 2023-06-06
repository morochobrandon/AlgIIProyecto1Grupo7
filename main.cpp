#include "Librerias\GestionVehículos.h"




int main(){
lista * p=nullptr;

int opcion=-1;

//fflush(stdin);  //por si las variables se ponen graciosas jajajajaj

string nombreEsp , nombregringo , piloto;
int bomba , piedra , liquido;
/*
//llenarDatosVehiculo(&p,  nombreEsp       ,  nombregringo        ,  piloto                      ,tipoDeCaucho,tamanoDeCaucho,velocidadDelCarro,bombas,piedras,liquidos,comoSeVeElVehiculo);
llenarDatosVehiculo(&p, "SuperFerrari"     , "ArmySurplusSpecial" , "SargentoBlast"              , 1          ,     1        , 1               ,   1   ,   3    ,   0     ,        1          );
llenarDatosVehiculo(&p, "SuperFerrari"     , "ArmySurplusSpecial" , "SoldadoMeekly"              , 2          ,     1        , 1               ,   1   ,   3    ,   1     ,        2          ); 
llenarDatosVehiculo(&p, "Antiguomovil"     , "BulletproofBomb"    , "HermanosAnticuados"         , 3          ,     1        , 2               ,   1   ,   3    ,   0     ,        3          );
llenarDatosVehiculo(&p, "AlambiqueVeloz"   , "RoaringPlenty"      , "LucaselLoco"                , 2          ,     1        , 3               ,   1   ,   3    ,   1     ,        4          );
llenarDatosVehiculo(&p, "AlambiqueVeloz"   , "RoaringPlenty"      , "OsvaldoelOso"               , 2          ,     1        , 3               ,   1   ,   3    ,   1     ,        5          );
llenarDatosVehiculo(&p, "Superheterodino"  , "TurboTerrific"      , "PeterPerfecto"              , 1          ,     1        , 4               ,   1   ,   2    ,   0     ,        6          );
llenarDatosVehiculo(&p, "Troncoswagen "    , "ArkansasChugabug"   , "TioTomas"                   , 1          ,     2        , 1               ,   2   ,   2    ,   0     ,        7          );
llenarDatosVehiculo(&p, "Troncoswagen"     , "ArkansasChugabug"   , "OsoMiedoso"                 , 2          ,     2        , 2               ,   2   ,   2    ,   1     ,        8          );
llenarDatosVehiculo(&p, "SuperConvertible" , "MeanMachine"        , "PierreNodoyuna"             , 3          ,     3        , 3               ,   2   ,   2    ,   0     ,        9          );
llenarDatosVehiculo(&p, "SuperConvertible" , "MeanMachine"        , "Patan"                      , 3          ,     2        , 1               ,   2   ,   2    ,   0     ,        10         );
llenarDatosVehiculo(&p, "Rocomovil"        , "Bouldermobile"      , "HermanosMacana,PiedroyRoco" , 1          ,     2        , 2               ,   2   ,   2    ,   0     ,        11         );
llenarDatosVehiculo(&p, "ElEspantomovil"   , "CreepyCoupe"        , " LosTenebrosos"             , 2          ,     3        , 1               ,   3   ,   1    ,   1     ,        12         );
llenarDatosVehiculo(&p, "AutoConvertible" , "Convert-a-car"       , "profesorLocovich"           , 3          ,     2        , 3               ,   3   ,   1    ,   0     ,        13         );
llenarDatosVehiculo(&p, "StukaRakuda"     , "CrimsonHaybailer"    , "BaronHansFritz"             , 1          ,     3        , 2               ,   3   ,   1    ,   0     ,        14         );
llenarDatosVehiculo(&p, "CompactPussycat" , "CompactPussycat"     , "PenelopeGlamour"            , 2          ,     3        , 3               ,   3   ,   1    ,   1     ,        15         );
 */

cargar_archivo3(&p);
muestra(p);

primero = p;
descargar_archivo3(primero);

while (opcion!=0){
mostrarOpciones();
cout<<"\n Opcion  :";
cin>>opcion;
cin.ignore();
system("cls");
cout<<"\n la opcion fue"<<opcion;
if (opcion == 1){
      pedirDatosVehiculo(&p);
} else if (opcion == 2){
      modificarVehiculo(&p);
} else if (opcion == 3){
      eliminarVehiculo(&p);
} else if (opcion == 4){
      consultarVehiculo(p); 
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
eliminarLista(&p);
cout<<"\n\n";
if (opcion) system("pause");
system("cls");
return 0;

}