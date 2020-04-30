/*
* 01-Adición
* "El usuario ingresará dos enteros y se mostrará por pantalla la suma de los mismos"
* López, Axel Javier 
* 20200430
*/

#include <iostream>

int main(){
int a;
std::cout << "Ingresá un numero entero\n"; 
std::cin >> a;
int b;
std::cout << "Ingresá otro numero entero\n";
std::cin >> b;
std::cout << "Los enteros suman:";
std::cout << a + b;
    system("PAUSE()");
    return 0;
}