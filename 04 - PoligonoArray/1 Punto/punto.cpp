/*
Axel Javier Lopez
09092020
Tipo de Dato: Punto
*/

#include <iostream>
#include <cassert>
#include <array>
#include <string>
#include <cmath>

using namespace std;

//Declaración variable
struct Punto {double x, y;};



//Prototipos operaciones
float GetDistanciaAlOrigen (Punto);
float GetDistancia (Punto, Punto);
bool IsIgual (Punto, Punto);

int main ()
{
  Punto punto1;
  punto1.x=5;
  punto1.y=10;

  Punto punto2;
  punto2.x=10;
  punto2.y=20;

    float distancia = GetDistancia (punto1, punto2);
    cout << distancia << '\n';
    /*assert ( 1.0 == GetDistanciaAlOrigen ({0,1}));
    assert ( 0 == GetDistanciaAlOrigen ({0,0}) );
    assert ( 0 == GetDistancia ({8,4},{8,4}) );
    assert ( true == IsIgual ({8,4},{8,4}) );
    assert ( false == IsIgual ({8,4},{8,0}) );*/

    system("PAUSE()");
    return 0;
}

//Definiciones de las funciones

float GetDistanciaAlOrigen (Punto punto1)
{
  float distanciaorigen;
  distanciaorigen = sqrt (pow(punto1.x,2)+pow(punto1.y,2));
  
  return distanciaorigen;

}

float GetDistancia (Punto p1, Punto p2)
{
  float distancia;
  distancia = sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
  return distancia;

}

bool IsIgual (Punto punto1, Punto punto2)
{
    return punto1.x==punto2.x and punto1.y==punto2.y ; //? true : false

}