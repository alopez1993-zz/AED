# Tipo de Dato PUNTO
## 14.1.1. Objetivos
• Demostrar capacidad de construcción de tipos compuestos basados en tipos
existentes atómicos.
## 14.1.2. Temas
• Tipos.
• Definición de conjunto de valores con struct.
• Definición de conjunto de operaciones con funciones y pasaje de argumentos
por referencia (i.e., variable).
## 14.1.3. Problema
Desarrollar el tipo de dato Punto que representa un punto en el plano
con coordenadas cartesianas. Las operaciones son: IsIgual, GetDistancia, y
GetDistanciaAlOrigen.
## 14.1.4. Restricciones
• Las pruebas deben realizarse con assert, sin usar cin ni cout.
## 14.1.5. Tareas
1. Especificar matemáticamente el tipo en Punto.md:
a. Especificar el conjunto de operaciones.
b. Especificar el conjunto de valores.
2. Diseñar y codificar las pruebas en main.
3. Declarar los prototipos de las operaciones arriba de main.
4. Declarar Punto antes de los prototipos las operaciones.
5. Compilar: Luego de finalizar tareas anteriores, estamos en condiciones de
compilar. Deberíamos obtener error de linkeo (i.e., vinculación) pero no de
compilación.
6. Codificar las definiciones de las operaciones, debajo de main.
7. Probar: Luego de las definiciones, deberíamos poder realizar el proceso de
traducción completo (i.e., compilación y linkeo) sin errores. Una vez obtenido
el programa ejecutable, deberíamos poder ejecutarlo sin errores.