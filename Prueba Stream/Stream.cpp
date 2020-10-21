#include <fstream>
#include <array>
#include <string>

using namespace std;

    struct Color {uint8_t R, G, B;};     
    struct Punto {double x, y;};
    struct Poligono { unsigned p; array<Punto, 50> puntospol; Color colorpol;}; //p marca la cantidad de puntos que tiene el polígono
    //n marca la cantidad máxima posible de puntos
    bool ExtraerPoligono (Poligono&, ifstream&);
    bool ExtraerPuntos (Poligono&, ifstream&);
    bool ExtraerColor (Poligono&, ifstream&);
    void AddVertice (Poligono&, Punto); // Nueva version. La de la tarea de Poligonos anterior no servia, ya que solo agregaba al final.   
    void EnviarPoligono (Poligono&, ofstream&);
    void EnviarColor (Poligono&, ofstream&);
    void EnviarPuntos (Poligono&, ofstream&);    



int main ()
{
    // Archivo fuente y archivo de salida

    ifstream poligonosin ("poligonos.txt");
    ofstream poligonosout;
    poligonosout.open ("poligonosout.txt",ios::out); //si el archivo no existe lo crea y si no existe lo reemplaza.
 
    Poligono pol;
    pol.p = 0; // seteo en 0 la primer posicion para agregar

   
    while (ExtraerPoligono (pol, poligonosin)) //mientras se haya exraído un polígono, mandar al archivo de salida
    { 
        EnviarPoligono (pol, poligonosout);
    } 
    system("PAUSE()");
    return 0;
}

// Funciones de extracción

bool ExtraerPoligono (Poligono& pol, ifstream& in)
{
    ExtraerColor (pol, in);
    ExtraerPuntos (pol, in);
    pol.p = 0;
    return bool {in};
}

bool ExtraerColor (Poligono& pol, ifstream& in)
{
    char coma;
    in >> pol.colorpol.R;
    in >> coma;
    in >> pol.colorpol.G;
    in >> coma;
    in >> pol.colorpol.B;
    return bool {in};

}

bool ExtraerPuntos (Poligono& pol, ifstream& in)
{
    while ( in.get() != ';') // así lee de caracter en caracter y puede identificar el ";"
    {
        char coma;
        Punto punto;
        in >> punto.x;
        in >> coma;
        in >> punto.y;
        AddVertice (pol, punto);
    }
    
    return bool {in};
}

void AddVertice (Poligono& pol, Punto punto) // Nueva version. La de la tarea de Poligonos anterior no servia, ya que solo agregaba al final.
    {
        pol.puntospol.at (pol.p).x = punto.x;
        pol.puntospol.at (pol.p).x = punto.y;
        pol.p = pol.p++ ; // mueve una posicion la direccion del array a agregar el proximo punto.
    }

// Funciones de envío

void EnviarPoligono (Poligono& pol, ofstream& out)
{
    EnviarColor (pol, out);
    EnviarPuntos (pol, out);
}

void EnviarColor (Poligono& pol, ofstream& out)
{
    out << '(' << pol.colorpol.R << ',' << pol.colorpol.G << ','<< pol.colorpol.B<< ") ";
}

void EnviarPuntos (Poligono& pol, ofstream& out)
{
    for (int i = 0; i != pol.p+1; i++) // así lee de caracter en caracter y puede identificar el ";"
    {
        out <<'('<< pol.puntospol.at(i).x <<','<< pol.puntospol.at(i).y<< ")\n";
    }
}
