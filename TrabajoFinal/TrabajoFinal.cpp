/* López, Axel Javier
AED 2020
Curso K1051
*/

#include <iostream>
#include <cmath>
#include <fstream>
#include "TrabajoFinal.h"


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
   MostrarPerimetro (pol);
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
    return resultado;
}

float GetDistancia (const Punto& p1, const Punto& p2)
{
  float distancia;
  distancia = sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
  return distancia;

}

void MostrarPerimetro (const Poligono& pol){
    float Perimetro;
    Perimetro = GetPerimetro (pol);
    cout << "Perimetro:" << '(' << Perimetro << ')' << "\n\n";
}

bool ParsearPoligonos (ifstream& in, ListaPol& listapol){
    Poligono pol;
    bool parsePol = false; //Avisa si se parseó al menos un Polígono
    while (ParsearPoligono (in, pol))
    {
        parsePol = true;
        AddPoligono (pol, listapol);
        pol.FirstNode = nullptr; // RESETEO LA LISTA DE NODOS DEL POL
    }
    return parsePol;
}

bool ParsearPoligono (ifstream& in, Poligono& pol)
{
    if (not ParsearColor (in, pol)) return false;
    if (not ParsearPuntos (in, pol)) return false;
    return bool {in};
}

bool ParsearColor (ifstream& in, Poligono& pol)
{
    int entero;

    in >> entero;
    pol.c.R = entero;

    {char caracter = '%'; in >> caracter; if (',' != caracter) return false;} // Parsear Coma ()
    
    in >> entero;
    pol.c.G = entero;

    {char caracter = '%'; in >> caracter; if (',' != caracter) return false;} // Parsear Coma ()
    
    in >> entero;
    pol.c.B = entero;
  
    return bool {in};

}

bool ParsearPuntos (ifstream& in, Poligono& pol)
{
    while ( in.get() != ';') // así lee de caracter en caracter y puede identificar el ";"
    {
        char coma;
        Punto punto;
        in >> punto.x;
        in >> coma; 
        in >> punto.y;
        AddFinalVertice (pol, punto);
    }
    
    return bool {in};
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

void FiltrarPoligonos (ListaPol& listapol, const int& cond){

auto auxPol = new NodePol;
auto auxAntPol = new NodePol;
//auto auxLibera = new NodePol;

auxPol = listapol.firstPol; //auxPol apunta al primer nodo (Polígono)

while (not CumpleCondicionPerimetro(auxPol->poligono, cond)) //Nodos (Polígonos) consecutivos no cumplen
{
    //auxLibera = listapol.firstPol; //auxAntPol apunta al primer nodo (Polígono) que no cumple la condición
    listapol.firstPol = auxPol->nextNodePol; //Lista saltea un Nodo (Polígono)
    auxPol = auxPol->nextNodePol; //auxPol saltea un Nodo (Polígono)
    //LiberarPoligono (auxLibera); //Libera reserva de memoria del primer nodo (Poligono)
}
 
auxPol = auxPol->nextNodePol; //auxPol apunta al segundo nodo (Poligono)
auxAntPol = listapol.firstPol; //auxAntPol apunta al primer nodo (Poligono)

while (auxPol != nullptr)
    {
        if (not CumpleCondicionPerimetro(auxPol->poligono, cond)) {
            auxAntPol->nextNodePol = auxPol->nextNodePol; //Primero nodo "se saltea" el siguiente
        }
        else auxAntPol = auxAntPol->nextNodePol;//auxAntPol apunta al siguiente nodo (Poligono)
        
        auxPol = auxPol->nextNodePol; //auxPol apunta al segundo nodo (Poligono)
    }

}

bool CumpleCondicionPerimetro(const Poligono& pol, const int& cond){
    return (GetPerimetro (pol) > cond);
}

void EnviarPoligonosFiltrados (ListaPol& listapol, const int& cond, ofstream& out){
    FiltrarPoligonos (listapol, cond);
    EnviarPoligonos (listapol, out);
}

void EnviarPoligonos (ListaPol& listapol, ofstream& out){
    
    auto aux = new NodePol; //Inicializo un puntero auxiliar hacia un Nodo (Polígono)
    aux = listapol.firstPol; //Auxiliar apunta al primer Nodo (Polígono)
    while (aux != nullptr )
    {
        EnviarPoligono (aux->poligono, out); //Envío Poligono
        aux = aux->nextNodePol; //Apunto al siguiente Nodo (Polígono)
    }
}

void EnviarPoligono (Poligono& pol, ofstream& out){
    out << "Poligono:\n";
    EnviarColor (pol.c, out);
    EnviarPuntos (pol.FirstNode, out);
    EnviarPerimetro (pol, out);
}

void EnviarColor (Color& color, ofstream& out){
    out << "Color:" << '(' << static_cast<int>(color.R) << ',' << static_cast<int>(color.G) << ','<< static_cast<int>(color.B)<< ")\n";
}

void EnviarPuntos (Node* nodo, ofstream& out){
    
    out << "Puntos:";
    auto aux = new Node; //Inicializo un puntero auxiliar hacia un Nodo (Punto)
    aux = nodo; //Auxiliar apunta al primer Nodo (Polígono)
    while (aux != nullptr ) //Recorro nodo (Punto) por nodo (Punto) y envío a "out" hasta encontrar el último.
    {
        out <<'('<< aux->p.x <<','<< aux->p.y<< ") ";
        aux = aux->next; //Apunto al próximo nodo (Punto)
    }
    out << '\n';
}

void EnviarPerimetro (const Poligono& pol, ofstream& out){
    float Perimetro;
    Perimetro = GetPerimetro (pol);
    out << "Perimetro:" << '(' << Perimetro << ')' << "\n\n";
}

void FlujoPoligonos (){
    ifstream poligonosin ("poligonos.txt");
    ofstream poligonosout ("poligonosout.txt"); 
    ListaPol listapol; //Lista en la que gurdaremos los polígonos a filtrar
    if (ParsearPoligonos (poligonosin, listapol))
    {
        MostrarListaPol (listapol);
        int cond = 4; //Cota inferior (Perímetro) de filtrado
        EnviarPoligonosFiltrados (listapol, cond, poligonosout);
    }
}

