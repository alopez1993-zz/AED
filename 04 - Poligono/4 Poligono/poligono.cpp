/*
Axel Javier Lopez
09092020
Tipo de Dato: Color
*/

#include <iostream>
#include <cassert>
#include <array>
#include <string>
#include <cmath>

using namespace std;

    struct Color {uint8_t R, G, B;};     
    struct Punto {double x, y;};
    const unsigned n = 9;
    struct Poligono { unsigned p; array<Punto, n> puntospol; Color colorpol;}; //p marca la cantidad de puntos que tiene el polígono

    void AddVertice (Poligono&, Punto); //Agrega un punto al final del array de puntos
    Punto GetVertice (Poligono&, unsigned); //el unsigned será la posición del punto a obtener
    void SetVertice (Poligono&, Punto, unsigned); //el unsigned será la posición del punto a cambiar
    void SetColorPol (Poligono&, Color); //el string será el color a  cambiar
    void RemoveVertice (Poligono&); // Remueve el último punto del array de puntos   
    Color GetColorPol (const Poligono&);   //devuelve el color del polígono
    unsigned GetCantidadLados (const Poligono&); // los unsigned serán la posición de dos puntos adyacent
    //devuelve la longitud de uno de sus lados  
    unsigned GetDistancia (Punto, Punto); //Calcula distancia entre puntos
    unsigned PerimetroPol (const Poligono&); //esta función convoca a GetDistancia para poder sumar la magnitud de los lados
    //devuelve el perímetro del polígono. Elegí unsigned para hacer más fácil los assert
  

int main ()
{
    Poligono pol;
    pol.p =  3;
    pol.puntospol = {-6,3,{0,0},{5,2},{-3,4}};
    pol.colorpol = {255,0,0};

    Punto origen;

    RemoveVertice (pol); //Ejemplo visto en clase. Remueve realmente el último punto?
    AddVertice (pol, {-3,4}); //Vuelve a agregarle el punto que le sacó RemoveVertice (En realidad no lo remueve?)
    SetVertice (pol, {3,-2}, 1);
    SetColorPol (pol, {255,40,25});

    assert (4 == pol.puntospol.at(3).y );
    assert (-6 == (GetVertice (pol, 0)).x );
    assert (-2 == (GetVertice (pol, 1)).y );
    assert (25 == (GetColorPol (pol)).B );
    assert (4 == GetCantidadLados (pol));
    assert (3 == pol.p); 
    assert (29 == PerimetroPol (pol) );

    system("PAUSE()");
    return 0;
}

   void AddVertice (Poligono& pol, Punto punto)
   {
       if (pol.p < n) // si esto no se cumple, no puedo agregar otro punto
       {
           pol.puntospol.at(pol.p++) = punto;
       }
   }

    Punto GetVertice (Poligono& poligono, unsigned posicion)
    {
        return poligono.puntospol.at (posicion);

    }
   
    void SetVertice (Poligono& poligono, Punto punto, unsigned posicion)
    {
        poligono.puntospol.at (posicion) = punto;
    }

    void SetColorPol (Poligono& poligono, Color color)
    {
        poligono.colorpol = color;

    }

    void RemoveVertice (Poligono& poligono)
    {
        poligono.p --;
        poligono.puntospol[poligono.p];
    }

    Color GetColorPol (const Poligono& poligono)
    {
        return poligono.colorpol;
    }

    unsigned GetCantidadLados (const Poligono& poligono)
    {
        unsigned lados = poligono.p + 1;
        return lados;
    }

    unsigned GetDistancia (Punto punto1, Punto punto2)
    {
        unsigned distancia;
        distancia = sqrt ((pow(punto2.x,2)-pow(punto1.x,2))+(pow(punto2.y,2)-pow(punto1.y,2)));
  
        return distancia;

    }
    
    unsigned PerimetroPol (const Poligono& poligono) //Implementado con la idea de no utilizar bucles (no es la idealidad)
    {
       unsigned lado1 = GetDistancia (poligono.puntospol.at (0), poligono.puntospol.at (1));
       unsigned lado2 = GetDistancia (poligono.puntospol.at (1), poligono.puntospol.at (2));
       unsigned lado3 = GetDistancia (poligono.puntospol.at (2), poligono.puntospol.at (3));
       unsigned lado4 = GetDistancia (poligono.puntospol.at (3), poligono.puntospol.at (4));
       unsigned lado5 = GetDistancia (poligono.puntospol.at (4), poligono.puntospol.at (5));
       unsigned lado6 = GetDistancia (poligono.puntospol.at (5), poligono.puntospol.at (6));
       unsigned lado7 = GetDistancia (poligono.puntospol.at (6), poligono.puntospol.at (7));
       unsigned lado8 = GetDistancia (poligono.puntospol.at (7), poligono.puntospol.at (8));
       unsigned lado9 = GetDistancia (poligono.puntospol.at (8), poligono.puntospol.at (9));
       unsigned lado10 = GetDistancia (poligono.puntospol.at (9), poligono.puntospol.at (0));

       unsigned perimetro = lado1+lado2+lado3+lado4+lado5+lado6+lado7+lado8+lado9+lado10; 
       return perimetro;
    }