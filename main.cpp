#include "Librerias\TDAPista.h"
#include "Librerias\menus.h"

    int main(){
    tListaVehiculos *listaCompetidores=nullptr;

    //fflush(stdin);  //por si las variables se ponen graciosas jajajajaj

    string nombreEsp , nombregringo , piloto;
    int bomba , piedra , liquido;
    /*
    void agregarVehiculo(tListaVehiculos **listaCompetidores, string nombreEsp , string nombreEn , string piloto , int tipoCaucho , int tamCaucho,  int mT , int velocidad, int comoSeVeElVehiculo );
    llenarDatosVehiculo(&listaCompetidores, "SuperFerrari"     , "ArmySurplusSpecial" , "SargentoBlast"              , 1          ,     1        , 1               ,   1   ,   3    ,   0     ,        1          );
    llenarDatosVehiculo(&listaCompetidores, "SuperFerrari"     , "ArmySurplusSpecial" , "SoldadoMeekly"              , 2          ,     1        , 1               ,   1   ,   3    ,   1     ,        2          ); 
    llenarDatosVehiculo(&listaCompetidores, "Antiguomovil"     , "BulletproofBomb"    , "HermanosAnticuados"         , 3          ,     1        , 2               ,   1   ,   3    ,   0     ,        3          );
    llenarDatosVehiculo(&listaCompetidores, "AlambiqueVeloz"   , "RoaringPlenty"      , "LucaselLoco"                , 2          ,     1        , 3               ,   1   ,   3    ,   1     ,        4          );
    llenarDatosVehiculo(&listaCompetidores, "AlambiqueVeloz"   , "RoaringPlenty"      , "OsvaldoelOso"               , 2          ,     1        , 3               ,   1   ,   3    ,   1     ,        5          );
    llenarDatosVehiculo(&listaCompetidores, "Superheterodino"  , "TurboTerrific"      , "PeterPerfecto"              , 1          ,     1        , 4               ,   1   ,   2    ,   0     ,        6          );
    llenarDatosVehiculo(&listaCompetidores, "Troncoswagen "    , "ArkansasChugabug"   , "TioTomas"                   , 1          ,     2        , 1               ,   2   ,   2    ,   0     ,        7          );
    llenarDatosVehiculo(&listaCompetidores, "Troncoswagen"     , "ArkansasChugabug"   , "OsoMiedoso"                 , 2          ,     2        , 2               ,   2   ,   2    ,   1     ,        8          );
    llenarDatosVehiculo(&listaCompetidores, "SuperConvertible" , "MeanMachine"        , "PierreNodoyuna"             , 3          ,     3        , 3               ,   2   ,   2    ,   0     ,        9          );
    llenarDatosVehiculo(&listaCompetidores, "SuperConvertible" , "MeanMachine"        , "Patan"                      , 3          ,     2        , 1               ,   2   ,   2    ,   0     ,        10         );
    llenarDatosVehiculo(&listaCompetidores, "Rocomovil"        , "Bouldermobile"      , "HermanosMacana,PiedroyRoco" , 1          ,     2        , 2               ,   2   ,   2    ,   0     ,        11         );
    llenarDatosVehiculo(&listaCompetidores, "ElEspantomovil"   , "CreepyCoupe"        , " LosTenebrosos"             , 2          ,     3        , 1               ,   3   ,   1    ,   1     ,        12         );
    llenarDatosVehiculo(&listaCompetidores, "AutoConvertible" , "Convert-a-car"       , "profesorLocovich"           , 3          ,     2        , 3               ,   3   ,   1    ,   0     ,        13         );
    llenarDatosVehiculo(&listaCompetidores, "StukaRakuda"     , "CrimsonHaybailer"    , "BaronHansFritz"             , 1          ,     3        , 2               ,   3   ,   1    ,   0     ,        14         );
    llenarDatosVehiculo(&listaCompetidores, "CompactPussycat" , "CompactPussycat"     , "PenelopeGlamour"            , 2          ,     3        , 3               ,   3   ,   1    ,   1     ,        15         );
    */
    cargar_archivo3(&listaCompetidores);
    //agregarVehiculo(&listaCompetidores, "SuperFerrari"     , "ArmySurplusSpecial" , "SargentoBlast"              , 1          ,     1        , 1               ,   1   ,   3     );
    muestra(listaCompetidores);

    primero = listaCompetidores;
    descargar_archivo3(primero);
    tPista *pista = inicializarPista();
    menuNuevoVehiculo();
    opcionesGestionDeVehiculos(pista, listaCompetidores);

    eliminartListaVehiculos(&listaCompetidores);
    cout<<"\n\n";
    system("pause");
    system("cls");
    destruirPista(pista);
    return 0;
}