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

int main ()
{
    bool IsBisiesto (unsigned);

    assert (IsBisiesto (2000));
    assert (not IsBisiesto (1900));
    assert (not IsBisiesto (205));

    bool IsBisiesto (unsigned year)
    {
        return year > 1582 and (year%4 == 0) and ( (year%100 != 0) or year%400 == 0);
    }

    return 0;
}


