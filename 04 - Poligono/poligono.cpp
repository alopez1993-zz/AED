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
    
    void SetColorPol (poligono&, string); //el string será el color a  cambiar
    void SetColorTri (triangulo&, string); //el string será el color a cambiar
    
    punto QuitarPuntoPol (poligono&, unsigned); //el unsigned será la posición del punto a quitar
    // PuntoEliminado = QuitarPuntoPol (pentágono1)
    
    string GetColorTri (const triangulo&);
    //devuelve el color del triangulo
    string GetColorPol (const poligono&);
    //devuelve el color del polígono
    // ColorPoligono = GetColorPol (pentágono1)
    
    string GetPuntoPol (const poligono&, unsigned); //el unsigned será la posición del punto a pedir
    string GetPuntoTri (const triangulo&, unsigned); //el unsigned será la posición del punto a pedir
    
    double LongitudLadoPol (const poligono&, unsigned, unsigned); // los unsigned serán la posición de dos puntos adyacentes
    //devuelve la longitud de uno de sus lados
    double LongitudLadoTri (const poligono&, unsigned, unsigned); // los unsigned serán la posición de dos puntos adyacentes
    //devuelve la longitud de uno de sus lados
    
    using angulos = array<unsigned,3>;
    angulos angulostri (const triangulo&); //esta función convocaría a LongitudLadoTri 3 veces, una por cada lado, y a una función coseno. Teorema del coseno.
    // devuelve los 3 angulos del triangulo

    double PerimetroPol (const poligono&); //esta función convocaría a LongitudLadoPol para poder sumar la magnitud de los lados
    //devuelve el perímetro del polígono
    double PerimetroTri (const triangulo&); //esta función convocaría a LongitudLadoPol para poder sumar la magnitud de los lados
    // devuelve el perímetro del polígono

    double AlturaTriangulo (const triangulo&); //devuelve la altura del triángulo, convocaría a LongitudLadoTri 3 veces para obtener cada lado del triángulo y calcular la altura.
    double AreaTriangulo (const triangulo&); // devuelve el área del triángulo, convocaría a AlturaTriángulo


    system("PAUSE()");
    return 0;
}