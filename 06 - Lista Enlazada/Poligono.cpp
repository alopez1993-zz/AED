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
#include "Poligono.h"


void AddFirstVertice (Poligono& pol, const Punto& punto){ 
    
    auto n = new Node; //Reservo nodo en Heap
   
    n->p.x = punto.x; //Asigno dato (punto) al nodo
    n->p.y = punto.y;
    n->next = pol.FirstNode; //Nuevo nodo apunta donde apunta el primer puntero
    pol.FirstNode = n; // Primero puntero apunta a nuevo nodo   
  

}

void AddFinalVertice (Poligono& pol, const Punto& punto){
    
    auto n = new Node;
    n->p.x = punto.x; //Asigno dato (punto) al nodo
    n->p.y = punto.y;
    n->next = nullptr;

    Node* aux = pol.FirstNode;
    if (aux != nullptr)
    {
        while (aux->next != nullptr)
        {
            aux = aux->next;
        }
        aux->next = n;
    }
    else pol.FirstNode = n;
}

void MostrarPoligono (const Poligono& pol){

   MostrarColor (pol);  
   MostrarPuntos (pol);
}

void MostrarColor (const Poligono& pol)
{
    cout << "\nColor:(" <<
        static_cast<int>(pol.c.R) << ',' << 
        static_cast<int>(pol.c.G) << ',' << 
        static_cast<int>(pol.c.B) << ")\n";
}

void MostrarPuntos (const Poligono& pol){

    cout << "Puntos:";
    Node* aux = pol.FirstNode;

        while (aux != nullptr)
        {
            MostrarPunto(aux);
            aux = aux->next;
        }
    cout << '\n';
}

void MostrarPunto (const Node* nodo){

    cout << '(' << (*nodo).p.x << ',' << (*nodo).p.y << ')';
}

void AddPoligono (const Poligono& pol, ListaPol& listapol){

    auto n = new NodePol; //Creo nuevo nodo (Poligono) en Heap
    n->poligono = pol;
    n->nextNodePol = nullptr; 
    
    auto aux = listapol.firstPol; //Nuevo nodo (Poligono) apunta donde apunta el primer puntero
    if (aux != nullptr)
    {
        while (aux->nextNodePol != nullptr)
        {
            aux = aux->nextNodePol; //Apunta al que apunta el siguente nodo (Poligono)
        }
        aux->nextNodePol = n; //Hace apuntar el último nodo hacia el nuevo
    }
    else listapol.firstPol = n; //Puntero de lista apunta hacia el nuevo nodo (primer Poligono)
}

void MostrarListaPol (const ListaPol& listapol){

    cout << "Poligonos:\n";
    NodePol* aux = listapol.firstPol;

        while (aux != nullptr)
        {
            MostrarPoligono (aux->poligono);
            aux = aux->nextNodePol;
        }
    
}

float GetPerimetro (const Poligono& pol){

float resultado = 0;
Punto puntoaux;
Node* aux;

puntoaux.x = pol.FirstNode->p.x;
puntoaux.y = pol.FirstNode->p.y;

aux = pol.FirstNode;

while (aux->next != nullptr){
    resultado = resultado + GetDistancia(puntoaux, aux->p);
    aux = aux->next;
    puntoaux.x = aux->p.x;
    puntoaux.y = aux->p.y;
    }

    resultado = resultado + GetDistancia(aux->p, pol.FirstNode->p); 
    cout << resultado << '\n';
    return resultado;
}

float GetDistancia (const Punto& p1, const Punto& p2)
{
  float distancia;
  distancia = sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
  return distancia;

}