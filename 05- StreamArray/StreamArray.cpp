#include "StreamArray.h"
#include <fstream>
#include <cmath>

// Funciones de extracción

bool ExtraerPoligono (Poligono& pol, ifstream& in)
{
    if (not ExtraerColor (pol, in)) return false;
    if (not ExtraerPuntos (pol, in)) return false;
    return bool {in};
}

bool ExtraerColor (Poligono& pol, ifstream& in)
{
    int entero;

    in >> entero;
    pol.colorpol.R = entero;

    {char caracter = '%'; in >> caracter; if (',' != caracter) return false;} // Extraer Coma ()
    
    in >> entero;
    pol.colorpol.G = entero;

    {char caracter = '%'; in >> caracter; if (',' != caracter) return false;} // Extraer Coma ()
    
    in >> entero;
    pol.colorpol.B = entero;
  
    return bool {in};

}

bool ExtraerPuntos (Poligono& pol, ifstream& in)
{
    pol.p = 0; // seteo en 0 la primer posicion para agregar
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
        pol.puntospol.at (pol.p) = punto;
        ++pol.p ; // mueve una posicion la direccion del array a agregar el proximo punto.
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
    out << '(' << static_cast<int>(pol.colorpol.R) << ',' << static_cast<int>(pol.colorpol.G) << ','<< static_cast<int>(pol.colorpol.B)<< ")\n";
    return bool {out};
}

bool EnviarPuntos (Poligono& pol, ofstream& out)

{
    for (int i = 0; i < pol.p; i++) // así lee de caracter en caracter y puede identificar el ";"
    {
        out <<'('<< pol.puntospol.at(i).x <<','<< pol.puntospol.at(i).y<< ")\n";
    }
    return bool {out};
}

double PerimetroPol (const Poligono& poligono) 
    {
       double perimetro = 0;

       for (int i = 0; i < (poligono).p; ++i)
       {
           double lado = GetDistancia (poligono.puntospol.at (i), poligono.puntospol.at (i+1));
           perimetro = perimetro + lado; 
       }

       perimetro = perimetro + GetDistancia (poligono.puntospol.at (0), poligono.puntospol.at ((poligono).p));
       return perimetro;
    }

double GetDistancia (Punto punto1, Punto punto2)


    {
        double distancia;
        distancia = sqrt (pow(punto2.x - punto1.x,2)+ pow(punto2.y - punto1.y,2));
  
        return distancia;

    }

/*bool FiltroPerimetro (const Poligono& pol)
{
    if (PerimetroPol (pol) < 51) return true;
}*/

void MostrarPoligono (const Poligono& pol)
{
   void MostrarColor (const Poligono& pol);  
   void MostrarPuntos (const Poligono& pol);
   void MostrarDistancia (const Poligono& pol);
   void MostrarPerimetro (const Poligono& pol);
}


void MostrarColor (const Poligono& pol)
{
    cout << "\nColor:(" <<
        static_cast<int>(pol.colorpol.R) << ',' << 
        static_cast<int>(pol.colorpol.G) << ',' << 
        static_cast<int>(pol.colorpol.B) << ')';
}

void MostrarPuntos (const Poligono& pol)
{
    cout << "Puntos:";
    for (int i = 0; i < pol.p; i++)
    {
        cout << '(' << pol.puntospol.at(i).x << ',' << pol.puntospol.at(i).y << ')';
    }
}

void MostrarDistancia (const Poligono& pol)
{
    cout << '\n' << "Distancia entre los dos primeros puntos:" << GetDistancia (pol.puntospol.at(0), pol.puntospol.at(1)) << '\n';
}

void MostrarPerimetro (const Poligono& pol)
{
    cout << '\n' << "Perímetro:" << PerimetroPol (pol) << '\n';
}





