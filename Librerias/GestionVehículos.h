/*Características del juego:

El juego se ejecuta en la consola del sistema operativo del usuario, al inicio del programa se indica cuántos vehículos van a participar, que formarán parte de una lista. Cada vehículo corre en su propio carril, cada carril es una línea horizontal en la pantalla que va desde el extremo izquierdo al derecho.

Los vehículos son representados en la pantalla por un símbolo que puede ser: #,$,%,&,*. Además cuenta con los siguientes atributos: Velocidad y resistencia.

Una vez que se indica la cantidad de carriles, se colocan las características de cada vehículo.

En un archivo están las configuraciones de los vehículos, estas son:

● Velocidad: perezoso, crucero, el super ferrari, Delorean.

● Resistencia: es un valor que determina la capacidad de resistir a obstáculos que se pueden encontrar en el camino, los cuales puede ser: bombas, piedras, líquido resbaladizo, cada atributo tiene una valor que determina el nivel de resistencia para cada tipo de obstáculo, pero eso depende de las características del carro como tipos de cauchos y tamaño.

● Tipos de cauchos:

◦ Normales

◦ Anti coleo (permiten rodar sobre líquidos que pueden ocasionar pérdida de la dirección sino cuenta con esta característica)

◦ Todo terreno (tiene mayor resistencia a los obstáculos, esta va en una escala de 1 a 5, mientras mayor el número podrá evitar mejor los obstáculos) pero no tienen propiedad de anti coleo.

● Tamaño de los cauchos:

◦ Pegado al piso (son los carros más rápidos, su velocidad puede ser El súper Ferrari, Delorean),

◦ Normales (su velocidad puede ser : perezoso , crucero),

◦ MonsterTruck (son los más altos pero también son muy lentos, su velocidad es perezoso)

● En cada carril puede aparecer MÁXIMO un obstáculo solamente de cada tipo.

● De acuerdo a las características anteriores, se pueden configurar muchos tipos de vehículos, cada vehículo debe tener un nombre, seleccionado de la siguiente lista: ◦ El Rocomóvil (The Bouldermobile) conducido por los Hermanos Macana, Piedro y Roco (The Slag Brothers, Rock and Gravel)2. ◦ El Espantomóvil (The Creepy Coupe) pilotado por Los Tenebrosos (The Gruesome Twosome). ◦ El Auto/Súper Convertible (Convert-a-car) al volante el profesor Locovich (Pat Pending).

◦ El Stuka Rakuda (The Crimson Haybailer) conducido por el Barón Hans Fritz (The Red Max).

◦ El Compact Pussycat conducido por Penélope Glamour (Penelope Pitstop).

◦ El Súper Ferrari (The Army Surplus Special) conducido por el Sargento Blast y el Soldado Meekly.

◦ El Antiguomóvil (The Bulletproof Bomb) conducido por los Hermanos Anticuados (The Ant Hill Mob).

◦ El Alambique Veloz (The Roaring Plenty) conducido por Lucas el Loco (Lazy Luke) y Osvaldo el Oso (Blubber Bear).

◦ El Superheterodino (The Turbo Terrific) conducido por Peter Perfecto (Peter Perfect).

◦ El Troncoswagen (The Arkansas Chugabug) conducido por Tío Tomás (Rufus Ruffcut) y Oso Miedoso (Sawtooth).

◦ El Super Convertible (The Mean Machine) conducido por Pierre Nodoyuna (Dick Dastardly) y Patán (Muttley).

En esta versión, cada vehículo tiene asignado los atributos por defecto.

Debe considerar una lista de vehículos. Cada vehículo tiene los siguientes atributos:

● Nombre en español

● Nombre el inglés

● Nombre del o los conductores

● Tipo de caucho

● Tamaño de caucho

● Velocidad

● Tiempo de disminución de velocidad

FALTA LOS VALORES PARA LOS ATRIBUTOS: Resistencia, velocidad, tipo caucho, tamaño caucho, tiempo de disminución, factor, el cual será representado por una tabla que se enviará posteriormente en la versión 2.

Aplicación de gestión de vehículos.

Se debe crear una aplicación por separado que permite:

● Agregar: permite agregar un vehículo nuevo con la información de los atributos. Al registrar la nueva información se debe indicar al usuario con un mensaje indicando que fue realizado satisfactoriamente el registro y mostrar la información completa del mismo.

● Modificar: permite modificar la información de un vehículo que es previamente seleccionado por consola. EL flujo debe ser el siguiente:

o Se muestra la lista de vehículos con un número de opción que lo identifique.

o El usuario selecciona la opción del vehículo que desea modificar.

o Se muestra toda la información del vehículo acompañado con un número de opción que identifica el atributo.

o El usuario selecciona la opción del atributo que desea modificar.

o Modificar el valor del atributo.

o Se realiza la modificación.

o Se muestra al usuario un mensaje si la modificación se hizo exitosamente o si no se pudo hacer indicando por qué.

o Si fue exitosa la modificación se muestra toda la información del vehículo.

● Eliminar: permite eliminar la información de un vehículo que es previamente seleccionado mediante un número de opción asociado a cada vehículo.

● Una vez eliminado el vehículo, se muestra el mensaje que se eliminó exitosamente y se muestra al usuario el vehículo eliminado junto con la información de los atributos.

● Lista: muestra todos los vehículos con sus atributos.

● Consultar: permite consultar la información de un vehículo. Se muestra un listado de vehículos, el usuario selecciona el vehículo que desea consultar y la aplicación muestra toda la información.

● Consultar: permite seleccionar un vehículo mediante un número de opción y muestra los valores de los atributos.

● Regresar: regresa siempre a la pantalla anterior.

● Salir: sale del sistema.

Cada vez que se agrega, modifica o elimina, debe realizar la acción en la lista de vehículos y en el archivo de texto que mantiene la información.*/
#ifndef GestionVehiculos_H
#define GestionVehiculos_H
#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>
#include <ctime>

using namespace std;


#endif // GestionVehiculos_H