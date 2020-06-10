/*
Axel Javier López
TP3 : IsBisiesto
Demostrar el uso de operadores booleanos y expresiones complejas.
9.1. Objetivos
• Demostrar el uso de operadores booleanos y expresiones complejas.
9.2. Temas
• Expresiones.
• Operadores booleanos: and, or, y not.
• Operador resto: %.
• Asociatividad de Operadores: ID ó DI.
• Precedencia de Operadores.
• Orden de evaluación de Operandos.
• Efecto de lado de una expresión.
9.3. Problema
Dado un año, determinar si es bisiesto.
9.4. Restricciones
• Desarrollar la lógica en una función.
Tareas
• El nombre de la función debe ser IsBisiesto.
• Aplicar operadores booleanos
• No aplicar el operador condicional.
• No aplicar if ni switch.
*/

#include <iostream>
#include <cassert>

using namespace std;

bool IsBisiesto (int);

int main ()
{
    assert (IsBisiesto (2000)); // prueba con divisible por 400 
    assert (not IsBisiesto (1900)); // prueba con divisible solo por 100 
    assert (not IsBisiesto (205)); // prueba con menor que 1582
    
    system("PAUSE()");
    return 0;
}

// m: year > 1582; p: year%4 == 0; q: year%100 == 0; r: year%400 == 0;

bool IsBisiesto (int year)
    {
        return year > 1582 and (year%4 == 0) and ((year%100 != 0) or year%400 == 0); // m ^ (p ^ (-q v r))
    }

    /* La definición de la función lógica podría cambiar siguiendo
       las propiedades de los conectores lógicos de la siguiente manera:
       
       m ^ (p ^ (-q v r)) = m ^ (p ^ (r v -q)) = (p ^ (r v -q)) ^ m = (p ^ (r v -q)) ^ m CONMUTATIVIDAD

       m ^ (p ^ (-q v r)) = (m ^ p) ^ (-q v r)  ASOCIATIVIDAD
    */

      