/*
* 01-Adición
* "El usuario ingresará dos enteros y se mostrará por pantalla la suma de los mismos"
* López, Axel Javier 
* 20200430
*/

#include <iostream>

int main(){
    std::cout << "A SUMAR!\n";
int a;
std::cout << "Ingresa un numero entero\n"; 
std::cin >> a;
int b;
std::cout << "Ingresa otro numero entero\n";
std::cin >> b;
std::cout << "Los enteros suman:\n";
std::cout << a + b;

    system("PAUSE()");
    return 0;
}