/*López, Axel Javier
AED 2020
Curso K1051
*/

using namespace std;
#include <array>
#include <iostream>
#include <cmath>
#include <cstdint>
#include <cstring>
#include <fstream>

//Declaración Punto

struct Punto {double x, y;};

//Declaracion Color

struct Color {uint8_t R, G, B;};

//Declaración Nodo Punto

struct Node{
    Punto p;
    Node* next;
};

//Declaración Polígono (lista enlazada)

struct Poligono {
    Node* FirstNode = nullptr;
    Color c;
};

//Declaración Nodo Polígono

struct NodePol{
    Poligono poligono;
    NodePol* nextNodePol;
};

//Declaración lista de Polígonos (lista enlazada)

struct ListaPol{
    NodePol* firstPol = nullptr;
};

void AddFirstVertice (Poligono& pol, const Punto& punto);
void AddFinalVertice (Poligono& pol, const Punto& punto);
void MostrarPoligono (const Poligono& pol);
void MostrarPunto (const Node* nodo);
void MostrarColor (const Poligono& pol);
void MostrarPuntos (const Poligono& pol);
void AddPoligono (const Poligono& pol, ListaPol& listapol);
void MostrarListaPol (const ListaPol& listapol);
float GetPerimetro (const Poligono& pol);
float GetDistancia (const Punto& p1, const Punto& p2);