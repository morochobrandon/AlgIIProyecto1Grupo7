#include "Wgui.h"
#include "..\Menus.h" 

int mo(){
    int a =0;
    mostrarOpciones();
    do
    {
        cin>>a;
        switch (a)
        {
        case 1:
            linea(1,1,1,1);
            break;
        
        case 2:
            circulo(1,1,1);
            break;
        
        default:
            system("pause");
            system ("cls");;
            a=1;
        }
    } while (a != 0);
    system("pause");
    system ("cls");
    return 0;
}
