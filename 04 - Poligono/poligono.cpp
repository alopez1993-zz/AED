#include <iostream>
#include <cassert>
#include <array>
#include <string>

using namespace std;

    struct Color {int R, G, B;};
    const Color black = {0,0,0};
    const Color white = {255,255,255};
    const Color red = {255,0,0};
    const Color green = {0,255,0};
    const Color blue = {0,0,255};
    const Color yellow = {255,255,0};
    const Color cyan = {0,255,255};
    const Color magenta = {255,0,255};

    Color sumarcolor (Color, Color);
    Color restarcolor (Color, Color);
    Color mezcla (Color color1, Color color2);

    
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

int main ()
{
    assert ( {255,255,0} = sumarcolor ( {255,0,0}, {0,255,0}) );
    assert ( {255,255,0} = restarcolor (white, blue) );
    assert ( {127,127,127}= mezcla (blue, yellow) );
    assert (cyan = complementario (rojo))

    system("PAUSE()");
    return 0;
}

    Color sumarcolor (Color color1, Color color2) 
    {
        Color colorsuma;

        color1.R + color2.R > 255? 255 :
        color1.R + color2.R = colorsuma.R;

        color1.G + color2.G > 255? 255 :
        color1.G + color2.G = colorsuma.G;

        color1.B + color2.B > 255? 255 :
        color1.B + color2.B = colorsuma.B;
        
        return colorsuma;
    }

    Color restarcolor (Color color1, Color color2) 
    {
        Color colorresta;

        color1.R - color2.R > 0? 0 :
        color1.R - color2.R = colorresta.R;

        color1.G - color2.G > 0? 0 :
        color1.G - color2.G = colorresta.G;

        color1.B - color2.B > 0? 0 :
        color1.B - color2.B = colorresta.B;
        
        return colorresta;
    }
    
    Color mezcla (Color color1, Color color2){
        
        Color colormezcla;

        (color1.R + color2.R)/2 = colormezcla.R;
        (color1.G + color2.G)/2 = colormezcla.G;
        (color1.B + color2.B)/2 = colormezcla.B;

        return colormezcla





    }


