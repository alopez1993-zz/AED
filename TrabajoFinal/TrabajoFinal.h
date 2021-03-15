/*López, Axel Javier
AED 2020
Curso K1051
*/

#include <array>
#include <cstdint>
#include <cstring>
#include <cmath>
#include <iostream>

using namespace std;

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

void FlujoPoligonos ();
void AddFirstVertice (Poligono& pol, const Punto& punto);
void AddFinalVertice (Poligono& pol, const Punto& punto);
void MostrarPoligono (const Poligono& pol);
void MostrarPunto (const Node* nodo);
void MostrarColor (const Poligono& pol);
void MostrarPuntos (const Poligono& pol);
bool ParsearPoligonos (ifstream& in, ListaPol& listapol);
bool ParsearPoligono (ifstream& in, Poligono& pol);
bool ParsearColor (ifstream& in, Poligono& pol);
bool ParsearPuntos (ifstream& in, Poligono& pol);
bool ParsearPunto (ifstream& in, Punto& punto);
bool ParsearPuntoComa (ifstream& in);
void AddPoligono (const Poligono& pol, ListaPol& listapol);
void MostrarListaPol (const ListaPol& listapol);
float GetPerimetro (const Poligono& pol);
void FiltrarPoligonos (ListaPol& listapol, const int& cond);
bool CumpleCondicionPerimetro (const Poligono& pol, const int& cond);
void DesenlazarNodoPol(ListaPol& listapol, NodePol* nodePol);
void EnviarPoligonosFiltrados (ListaPol& listapol, const int& cond, ofstream& out);
void EnviarPoligonos (ListaPol& listapol, ofstream& out);
void EnviarPoligono (Poligono& pol, ofstream& out);
void EnviarColor (Color& color, ofstream& out);
void EnviarPuntos (Node* nodo, ofstream& out);
float GetDistancia (const Punto& p1, const Punto& p2);
void EnviarPerimetro (const Poligono& pol, ofstream& out);
void LiberarPoligono (NodePol*& nodePol);
void MostrarPerimetro (const Poligono& pol);





