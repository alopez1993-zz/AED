#include "stream.h"
#include <fstream>

// Funciones de extracción

bool ExtraerPoligono (Poligono& pol, ifstream& in)
{
    ExtraerColor (pol, in);
    ExtraerPuntos (pol, in);
    return bool {in};
}

bool ExtraerColor (Poligono& pol, ifstream& in)
{
    char coma;
    in >> pol.colorpol.R;
    in >> coma;
    in >> pol.colorpol.G;
    in >> coma;
    in >> pol.colorpol.B;
    return bool {in};

}

bool ExtraerPuntos (Poligono& pol, ifstream& in)
{
    while ( in.get() != ';') // así lee de caracter en caracter y puede identificar el ";"
    {
        char coma;
        Punto punto;
        in >> punto.x;
        in >> coma;
        in >> punto.y;
        AddVertice (pol, punto);
    }
    
    return bool {in};
}

void AddVertice (Poligono& pol, Punto punto) // Nueva version. La de la tarea de Poligonos anterior no servia, ya que solo agregaba al final.
    {
        pol.puntospol.at (pol.p) = punto ;
        pol.p = pol.p++ ; // mueve una posicion la direccion del array a agregar el proximo punto.
    }

// Funciones de envío

bool EnviarPoligono (Poligono& pol, ofstream& out)
{
    EnviarColor (pol, out);
    EnviarPuntos (pol, out);
    return bool {out};
}

bool EnviarColor (Poligono& pol, ofstream& out)
{
    out << '(' << pol.colorpol.R << ',' << pol.colorpol.G << ','<< pol.colorpol.B<< ") ";
    return bool {out};
}

bool EnviarPuntos (Poligono& pol, ofstream& out)
{
    for (int i = 0; i != pol.p+1; i++) // así lee de caracter en caracter y puede identificar el ";"
    {
        out <<'('<< pol.puntospol.at(i).x <<','<< pol.puntospol.at(i).y<< ")\n";
    }
    return bool {out};
}