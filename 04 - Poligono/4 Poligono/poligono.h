// Tipo Color: Implementación, Parte Pública
#ifndef BANDERA_DE_QUE_YA_SE_INCLUYO_EL_HEADER_DEL_TIPO_POLIGONO
#define BANDERA_DE_QUE_YA_SE_INCLUYO_EL_HEADER_DEL_TIPO_POLIGONO

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
    //n marca la cantidad máxima posible de puntos
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
  
#endif