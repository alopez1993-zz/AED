// Tipo Color: Implementación, Parte Pública
#ifndef BANDERA_DE_QUE_YA_SE_INCLUYO_EL_HEADER_DEL_TIPO_STREAM
#define BANDERA_DE_QUE_YA_SE_INCLUYO_EL_HEADER_DEL_TIPO_STREAM

#include <iostream>
#include <array>
#include <string>

using namespace std;

    struct Color {uint8_t R, G, B;};     
    struct Punto {double x, y;};
    struct Poligono { unsigned p; array<Punto, 50> puntospol; Color colorpol;}; //p marca la cantidad de puntos que tiene el polígono
    //n marca la cantidad máxima posible de puntos
    bool ParsearPoligono (ifstream& in, Poligono& pol);
    bool ParsearPuntos (ifstream& in, Poligono& pol);
    bool ParsearPunto (ifstream& in, Punto& punto);
    bool ParsearColor (ifstream& in, Poligono& pol);
    bool ParsearPuntoComa (ifstream& in);
    void AddVertice (Poligono& pol, Punto punto); 
    void EnviarPoligono (Poligono& pol, ofstream& out);
    void EnviarPerimetro (Poligono& pol, ofstream& out);
    void EnviarColor (Poligono&, ofstream&);
    void EnviarPuntos (Poligono&, ofstream&); 
    float GetPerimetro (const Poligono& poligono);
    float GetDistancia (const Punto& punto1, const Punto& punto2);
    void FiltroPerimetro (Poligono& pol, const unsigned& cond, ofstream& out);
    void MostrarPoligono (const Poligono& pol);
    void MostrarColor (const Poligono& pol);  
    void MostrarPuntos (const Poligono& pol);
    void MostrarDistancia (const Poligono& pol);
    void MostrarPerimetro (const Poligono& pol);
#endif