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
        EnviarPoligono (pol, poligonosout);
    }
            //unsigned cond = 60;
            //if (FiltroPerimetro(pol, cond));
            //{
                //EnviarPoligono (pol, poligonosout);
            //} 
    
    system("PAUSE()");
}