/*
TP3: Uso de los tipos de variables en C++
Axel Javier López
*/

#include <iostream>
#include <string>
using namespace std;

int main () 
{
 string nombre = "Axel Javier Lopez"; 
 cout << "El nombre del alumno es: " << nombre << "\n\n";

 unsigned edad = 27;
 cout << "Edad: " << edad << "\n\n";

 long dni = 37424190;
 cout << "DNI: " << dni << "\n\n";

 char curso [6] = "K1051";
 cout << "Curso: " << curso << "\n\n";
 
 bool asistencia = false;
 double promedio = 8;
 cout << "Promedio: " << promedio << "\n\n";
 if (promedio >= 6 and asistencia == true)
    {
      cout << "Ha aprobado la materia\n\n";
      if (promedio >= 8)
        {
          cout << "Ha promocionado. No debe dar final\n";
        }
      else
        {
        }
    } 
 else
    {
     if (asistencia == false)
        {
         cout << "Debe recursar por no cumplir porcentaje de asistencias\n";
        }
       else
       {
         cout << "Debe recursar";
       }
    }
 cout << "\n";

 system("PAUSE()");
 return 0;

}