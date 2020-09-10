/*
Axel Javier Lopez
09092020
Tipo de Dato: Poligono
*/

#include <iostream>
#include <cassert>
#include <array>
#include <string>
#include <fstream>

using namespace std;

    //Declaraciones de variables
    struct Color {uint8_t R, G, B;};
   
    const Color red = {255,0,0};
    const Color green = {0,255,0};
    const Color blue = {0,0,255};
       
    //using Proporcion = array <double,3>;
    
    //Prototipos de las operaciones
    Color SumarColor (Color, Color);
    Color RestarColor (Color, Color);
    Color mezcla (Color, Color);
    Color GetComplementario (Color);
    //Proporcion ProporcionMezcla (Color, Color);
    //CrearSvgConTextoEscritoEnAltoContraste (string nombrearchivo, string mensaje, Color colormensaje; )
    bool IsIgual (Color, Color);

    Color yellow = SumarColor (red, green); //const Color yellow = {255,255,0};
    Color cyan = SumarColor (blue, green); //const Color cyan = {0,255,255};
    Color magenta = SumarColor (red, green);  //const Color magenta = {255,0,255};
    Color white = SumarColor (yellow, blue); //const Color white = {255,255,255};
    Color black = SumarColor (red, red);  //const Color black = {0,0,0};

int main ()
{
    
    assert ( 255 == SumarColor ( white, red ).R);
    assert ( 50 == SumarColor ( {30,0,0} , {20,0,0} ).R);
    assert ( 0 == RestarColor ( black, blue).B);
    assert ( 77 == RestarColor ({0,100,0}, {0,23,0}).G );
    assert ( 70 == mezcla ({0,120,0}, {0,20,0}).G );
    assert ( 127 == mezcla (blue, yellow).R );
    assert ( 92 == mezcla ({156,0,0}, {28,0,0}).R );
    assert ( 130 == GetComplementario ({125,6,26}).R);
    assert ( 249 == GetComplementario ({125,6,26}).G);
    assert ( 229 == GetComplementario ({125,6,26}).B);
    assert ( IsIgual ({125,6,26}, {125,6,26}));

    system("PAUSE()");
    return 0;
}


    Color SumarColor (Color color1, Color color2) // devuelve color sumando canal por canal
    {
        Color colorsuma;

        color1.R + color2.R > 255? colorsuma.R = 255 :
        colorsuma.R = color1.R + color2.R;

        color1.G + color2.G > 255? colorsuma.G = 255:
        colorsuma.G = color1.G + color2.G;

        color1.B + color2.B > 255? colorsuma.B = 255 :
        colorsuma.B = color1.B + color2.B ;
        
        return colorsuma;
    }

    Color RestarColor (Color color1, Color color2) // devuelve color restando canal por canal
    {
        Color colorresta;

        color1.R - color2.R < 0?   :
        colorresta.R = color1.R - color2.R;

        color1.G - color2.G < 0? colorresta.G = 0 :
        colorresta.G = color1.G - color2.G;

        color1.B - color2.B < 0? colorresta.B = 0 :
        colorresta.B = color1.B - color2.B;
        
        return colorresta;
    }
    
    Color mezcla (Color color1, Color color2) //devuelve la mezcla (suma y promedia canales)
    {
        
        Color colormezcla;

        colormezcla.R = (color1.R + color2.R)/2;
        colormezcla.G = (color1.G + color2.G)/2;
        colormezcla.B = (color1.B + color2.B)/2;

        return colormezcla;
    }

    Color GetComplementario (Color color1) //devuelve el color complementario
    {
        Color colorcomplementario;
        colorcomplementario.R = 255 - color1.R;
        colorcomplementario.G = 255 - color1.G;
        colorcomplementario.B = 255 - color1.B;

        return colorcomplementario;
    }
    
    bool IsIgual (Color color1, Color color2)
    {
        return color1.R == color2.R and color1.G == color2.G and color1.B == color2.B;
        
    }
    /*CrearSvgConTextoEscritoEnAltoContraste (string nombrearchivo, string mensaje, Color colormensaje)
    {
        ofstream archivo;
        archivo.open ("'nombrearchivo'.svg", ios::out);
        string texto;
        texto = '<svg xmlns="http://www.w3.org/2000/svg">
                <rect x="0" y="0" height="30" width="120"
                style="fill: #ff0000"/>
                <text x="5" y="18" style="fill:
                rgb(0,255,255)">
                ¡Hola, Mundo!
                </text>
                </svg>'
        <<texto
        
        archivo.close();
    }*/

    
    


    