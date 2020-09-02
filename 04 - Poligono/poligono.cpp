#include <iostream>
#include <cassert>
#include <array>

using namespace std;
int main () 
{
    struct punto {double x, y;};
    struct triangulo {array<punto, 3> puntostri; string colortri};
    struct poligono { unsigned p; array<punto, 50> puntospol; string colorpol;};

    void SetPuntoTri (triangulo&, punto);
    void SetPuntoPol (poligono&, punto, unsigned);
    void AgregarPuntoFinal (poligono&, punto);
    void CambiarColorPol (poligono&, string);
    void CambiarColorTri (triangulo&, string);
    punto QuitarPuntoTri (triangulo&);
    punto QuitarPuntoPol (poligono&);
    // PuntoEliminado = QuitarPuntoPol (pentágono1)
    color GetColorPol (const poligono&)
    // ColorPoligono = GetColorPol (pentágono1)

    
}