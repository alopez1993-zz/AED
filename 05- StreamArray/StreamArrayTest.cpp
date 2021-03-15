#include "StreamArray.h"
#include <fstream>
#include <cmath>

int main ()
{
    // Creo el archivo fuente y el archivo de salida

    ifstream poligonosin ("poligonos.txt");
    ofstream poligonosout ("poligonosout.txt"/*ios::out*/); //si el archivo no existe lo crea y si existe lo reemplaza.
     
      
    for (Poligono pol; ExtraerPoligono (pol, poligonosin);) //mientras se haya exraído un polígono, mandar al archivo de salida
    {
            MostrarColor (pol);
            MostrarPuntos (pol);
            MostrarPoligono (pol);
            //if (FiltroPerimetro (pol))
            
            EnviarPoligono (pol, poligonosout);
            

    }
    
    system("PAUSE()");
}