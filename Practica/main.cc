#include <iostream>
#include "Sort.h"
#define traza


using Key = int; // Establecemos Key como tipo long

int main() {

	int tamano = 0, opcion = 0, opcion_valores = 0;
	Key element;

	std::cout << "Indique el tamaño de la secuencia (N): ";
	std::cin >> tamano;

	while (!ValoresCorrectos(tamano)) {
		std::cout << "el tamaño introducido no es correcto. Vuelve a intentarlo: ";
		std::cin >> tamano;
	}

	Sort<Key> sort1(tamano);

	std::cout << "1 - Selección. 2 - QuickSort. 3 - ShellSort. 4 - HeapSort. 5 - RadixSort." << std::endl;
	std::cout << "Introduce el tipo de algoritmo deseado: ";
	std::cin >> opcion;

	while (!sort1.SetOrdenacion(opcion)) {
		std::cout << "Opción incorrecta. Vuelva a intentarlo: ";
		std::cin >> opcion;
	}

	

	std::cout << "Si desea introducir los valores manualmente pulse 1, sino pulse cualquier otro número (automático): ";
	std::cin >> opcion_valores;

	sort1.Insercion(opcion_valores);
	std::cout << "HAS INTRODUCIDO: "; 
	sort1.Print();

	sort1.Ordenar();
	return 0;

}