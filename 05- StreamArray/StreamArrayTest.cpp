#include "StreamArray.h"
#include <fstream>
#include <iostream>
#include <array>
#include <string>
#include <cmath>
#include <cassert>

int main ()
{
    // Creo el archivo fuente y el archivo de salida

    ifstream poligonosin ("poligonos.txt");
    ofstream poligonosout ("poligonosout.txt"/*ios::out*/); //si el archivo no existe lo crea y si existe lo reemplaza.
     
    for (Poligono pol; ParsearPoligono (poligonosin, pol);) //mientras se haya exraído un polígono, mandar al archivo de salida
    {
        MostrarPoligono (pol);
        unsigned cond = 60; //Cota inferior de perímetro
        FiltroPerimetro (pol, cond, poligonosout);
    }
    
    system("PAUSE()");
}