#include "stream.h"
#include <fstream>

int main ()
{
    // Creo el archivo fuente y el archivo de salida

    ifstream poligonosin ("poligonos.txt");
    ofstream poligonosout;
    poligonosout.open ("poligonosout.txt",ios::out); //si el archivo no existe lo crea y si no existe lo reemplaza.
 
    Poligono pol;
    pol.p = 0; // seteo en 0 la primer posicion para agregar
        
    while (ExtraerPoligono (pol, poligonosin)) //mientras se haya exraído un polígono, mandar al archivo de salida
    {
        EnviarPoligono (pol, poligonosout);
    }
    
    system("PAUSE()");
    return 0;
}