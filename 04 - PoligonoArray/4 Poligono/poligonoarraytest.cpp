// Tests Poligono
#include "poligonoarray.h"
#include <cassert>

int main ()
{
    Poligono pol;
    pol.p =  3;
    pol.puntospol = {-6,3,{0,0},{5,2},{-3,4}};
    pol.colorpol = {255,0,0};

    Punto origen;

    RemoveVertice (pol); //Ejemplo visto en clase. Remueve realmente el último punto?
    AddVertice (pol, {-3,4}); //Vuelve a agregarle el punto que le sacó RemoveVertice (En realidad no lo remueve?)
    SetVertice (pol, {3,-2}, 1);
    SetColorPol (pol, {255,40,25});

    assert (4 == pol.puntospol.at(3).y );
    assert (-6 == (GetVertice (pol, 0)).x );
    assert (-2 == (GetVertice (pol, 1)).y );
    assert (25 == (GetColorPol (pol)).B );
    assert (4 == GetCantidadLados (pol));
    assert (3 == pol.p); 
    assert (29 == PerimetroPol (pol) );

    system("PAUSE()");
    return 0;
}