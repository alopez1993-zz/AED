#include <iostream>
#include <cassert>
#include <array>
#include <string>

using namespace std;
int main () 
{
    struct punto {double x, y;};
    struct triangulo {array<punto, 3> puntostri; string colortri;};
    struct poligono { unsigned p; array<punto, 50> puntospol; string colorpol;};

    void SetPuntoTri (triangulo&, punto, unsigned); //el unsigned será la posición del punto a cambiar
    void SetPuntoPol (poligono&, punto, unsigned); //el unsigned será la posición del punto a cambiar
    
    void AgregarPuntoFinal (poligono&, punto);
    
    void CambiarColorPol (poligono&, string); //el string será el color nuevo
    void CambiarColorTri (triangulo&, string); //el string será el color nuevo
    
    punto QuitarPuntoPol (poligono&);
    // PuntoEliminado = QuitarPuntoPol (pentágono1)
    
    string GetColorTri (const triangulo&);
    string GetColorPol (const poligono&);
    // ColorPoligono = GetColorPol (pentágono1)
    
    string GetPuntoPol (const poligono&, unsigned); //el unsigned será la posición del punto a pedir
    string GetPuntoTri (const triangulo&, unsigned); //el unsigned será la posición del punto a pedir
    
    double LongitudLadoPol (const poligono&, unsigned, unsigned); // los unsigned serán la posición de dos puntos adyacentes
    double LongitudLadoTri (const poligono&, unsigned, unsigned); // los unsigned serán la posición de dos puntos adyacentes
    
    using angulos = array<unsigned,3>;
    angulos angulostri (const triangulo&); //esta función convocaría a LongitudLadoTri 3 veces, una por cada lado, y a una función coseno. Teorema del coseno.
    // devuelve los 3 angulos del triangulo

    system("PAUSE()");
    return 0;
}