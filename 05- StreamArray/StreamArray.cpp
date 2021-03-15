#include "StreamArray.h"
#include <fstream>
#include <iostream>
#include <cmath>


// Funciones de extracción

bool ParsearPoligono (ifstream& in, Poligono& pol)
{
    if (not ParsearColor (in, pol)) return false;
    if (not ParsearPuntos (in, pol)) return false;
    if (not ParsearPuntoComa (in)) return false;
    return bool {in};
}

bool ParsearColor (ifstream& in, Poligono& pol)
{
    int entero;

    in >> entero;
    pol.colorpol.R = entero;

    {char caracter = '%'; in >> caracter; if (',' != caracter) return false;} // Parsear Coma ()
    
    in >> entero;
    pol.colorpol.G = entero;

    {char caracter = '%'; in >> caracter; if (',' != caracter) return false;} // Parsear Coma ()
    
    in >> entero;
    pol.colorpol.B = entero;
    
    return bool {in};

}

bool ParsearPuntos (ifstream& in, Poligono& pol)
{
    pol.p = 0;
    for (Punto punto; ParsearPunto (in, punto);)
    {
        AddVertice (pol, punto);
    }
    return ParsearPunto;
}

bool ParsearPunto (ifstream& in, Punto& punto){
    char coma;
    in >> punto.x;
    in >> coma;
    in >> punto.y;
    
    return coma == ',' and bool {in};
}
    
bool ParsearPuntoComa (ifstream& in){
    in.clear (); //Libero flujo de entrada
    char c; //
    in >> c;
    return c == ';' and bool {in};
}

// Funciones de envío

void EnviarPoligono (Poligono& pol, ofstream& out)
{
    out << "Polígono:\n";
    EnviarColor (pol, out);
    EnviarPuntos (pol, out);
    EnviarPerimetro (pol, out);
}

void EnviarColor (Poligono& pol, ofstream& out)
{
    out << "Color:" << '(' << static_cast<int>(pol.colorpol.R) << ',' << static_cast<int>(pol.colorpol.G) << ','<< static_cast<int>(pol.colorpol.B)<< ")\n";
}

void EnviarPuntos (Poligono& pol, ofstream& out)

{
    out << "Puntos:";
    for (int i = 0; i < pol.p; i++) // así lee de caracter en caracter y puede identificar el ";"
    {
        out <<'('<< pol.puntospol.at(i).x <<','<< pol.puntospol.at(i).y<< ") ";
    }
    out << '\n';
}

void EnviarPerimetro (Poligono& pol, ofstream& out){
    out << "Perímetro:" << GetPerimetro (pol) << "\n\n";
}



//Funciones de dato
void AddVertice (Poligono& pol, Punto punto) // Nueva version. La de la tarea de Poligonos anterior no servia, ya que solo agregaba al final.
    { 
        pol.puntospol.at (pol.p).x = punto.x;
        pol.puntospol.at (pol.p).y = punto.y;
        ++pol.p ; // mueve una posicion la direccion del array a agregar el proximo punto.
    }

float GetPerimetro (const Poligono& pol){
double resultado = 0;
for (int i = pol.p - 1; i > 0 ; i--){
    resultado = resultado + GetDistancia(pol.puntospol.at(i), pol.puntospol.at(i-1));
}
return resultado + GetDistancia(pol.puntospol.at(pol.p-1), pol.puntospol.at(0));
}

float GetDistancia (const Punto& p1, const Punto& p2)
{
  float distancia;
  distancia = sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
  return distancia;

}

void FiltroPerimetro (Poligono& pol, const unsigned& cond, ofstream& out)
{
    if (GetPerimetro (pol) > cond) EnviarPoligono (pol, out);
    
}

void MostrarPoligono (const Poligono& pol)
{
   cout << "Poligono:\n";
   MostrarColor (pol);  
   MostrarPuntos (pol);
   MostrarPerimetro (pol);
}

void MostrarColor (const Poligono& pol)
{
    cout << "Color:(" <<
        static_cast<int>(pol.colorpol.R) << ',' << 
        static_cast<int>(pol.colorpol.G) << ',' << 
        static_cast<int>(pol.colorpol.B) << ")\n";
}

void MostrarPuntos (const Poligono& pol)
{
    cout << "Puntos:";
    for (int i = 0; i < pol.p; i++)
    {
        cout << '(' << pol.puntospol.at(i).x << ',' << pol.puntospol.at(i).y << ")";
    }
    cout << '\n';
}

void MostrarDistancia (const Poligono& pol)
{
    cout << '\n' << "Distancia entre los dos primeros puntos:" << GetDistancia (pol.puntospol.at(0), pol.puntospol.at(1)) << '\n';
}

void MostrarPerimetro (const Poligono& pol)
{
    cout << "Perimetro:" << GetPerimetro (pol) << "\n\n";
}





