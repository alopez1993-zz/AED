#include <iostream>
#include <cassert>
#include <array>
#include <string>
#include <cmath>

using namespace std;

    struct Color {uint8_t R, G, B;};     
    struct Punto {double x, y;};
    struct Poligono { unsigned p; array<Punto, 9> puntospol; Color colorpol;};




    void AddVertice (Poligono&, Punto);
    Punto GetVertice (Poligono&, Punto, unsigned); //el unsigned será la posición del punto a obtener
    void SetVertice (Poligono&, Punto, unsigned); //el unsigned será la posición del punto a cambiar
    void SetColorPol (Poligono&, Color); //el string será el color a  cambiar
    void RemoveVertice (Poligono&, unsigned);    
    Color GetColorPol (const Poligono&);   //devuelve el color del polígono
    unsigned GetCantidadLados (const Poligono&); // los unsigned serán la posición de dos puntos adyacent
    //devuelve la longitud de uno de sus lados  
    float GetDistancia (Punto, Punto); //Calcula distancia entre puntos
    float PerimetroPol (const Poligono&); //esta función convocaría a LongitudLadoPol para poder sumar la magnitud de los lados
    //devuelve el perímetro del polígono 
  

int main ()
{
    Poligono poligono1 { 5}; {1,2,3;} {1,2,3;} {1,2,3;} {1,2,3;} {1,2,3;} {0,0,0;} {0,0,0;} {0,0,0;} {0,0,0;};} 255,0,0;};
    
    assert 
    system("PAUSE()");
    return 0;
}

   void AddVertice (Poligono poligono, Punto punto)
   {
       poligono.p = poligono.p+1;
       int posicion = poligono.p;
       poligono.puntospol.at (posicion)  = punto;

   }

    Punto GetVertice (Poligono poligono, Punto punto, unsigned posicion)
    {
        return poligono.puntospol.at (posicion);

    }
   
    void SetVertice (Poligono poligono, Punto punto, unsigned posicion)
    {
        poligono.puntospol.at (posicion) = punto;
    }

    void SetColorPol (Poligono poligono, Color color)
    {
        poligono.colorpol = color;

    }

    void RemoveVertice (Poligono poligono)
    {
        poligono.p = poligono.p - 1;
    }

    Color GetColorPol (Poligono poligono)
    {
        return poligono.colorpol;
    }

    unsigned GetCantidadLados (Poligono poligono)
    {
        return poligono.p;
    }

    float GetDistancia (Punto punto1, Punto punto2)
    {
        float distancia;
        distancia = sqrt ((pow(punto2.x,2)-pow(punto1.x,2))+(pow(punto2.y,2)-pow(punto1.y,2)));
  
        return distancia;

    }
    
    float PerimetroPol (Poligono poligono) //Implementado con la idea de no utilizar bucles (no es la idealidad)
    {
       float lado1 = GetDistancia (poligono.puntospol.at (0), poligono.puntospol.at (1));
       float lado2 = GetDistancia (poligono.puntospol.at (1), poligono.puntospol.at (2));
       float lado3 = GetDistancia (poligono.puntospol.at (2), poligono.puntospol.at (3));
       float lado4 = GetDistancia (poligono.puntospol.at (3), poligono.puntospol.at (4));
       float lado5 = GetDistancia (poligono.puntospol.at (4), poligono.puntospol.at (5));
       float lado6 = GetDistancia (poligono.puntospol.at (5), poligono.puntospol.at (6));
       float lado7 = GetDistancia (poligono.puntospol.at (6), poligono.puntospol.at (7));
       float lado8 = GetDistancia (poligono.puntospol.at (7), poligono.puntospol.at (8));
       float lado9 = GetDistancia (poligono.puntospol.at (8), poligono.puntospol.at (9));
       float lado10 = GetDistancia (poligono.puntospol.at (9), poligono.puntospol.at (0));

       float perimetro = lado1+lado2+lado3+lado4+lado5+lado6+lado7+lado8+lado9+lado10; 
       return perimetro;
    }