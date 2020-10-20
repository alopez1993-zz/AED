/*
Axel Javier Lopez
09092020
Tipo de Dato: Poligono
*/

// Tipo Color: Implementación, Parte Privada

#include "poligono.h"

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
    
    unsigned PerimetroPol (const Poligono& poligono) 
    {
       unsigned perimetro;

       for (int i = 0; i <= (poligono).p; ++i)
       {
           unsigned lado = GetDistancia (poligono.puntospol.at (i), poligono.puntospol.at (i+1));
           perimetro = perimetro + lado; 
       }

       perimetro = GetDistancia (poligono.puntospol.at (0), poligono.puntospol.at ((poligono).p));
       return perimetro;
    }