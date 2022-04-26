#pragma once
#include <iostream> 
#include <vector>
#include "MetodosOrdenacion.h"

#define traza
//#define traza2

template<class Key>
class Seleccion: public MetodosOrdenacion<Key> {
    public:
        std::vector<Key> Ordenar(std::vector<Key> secuencia1, int tamano1);
};


template<class Key>
std::vector<Key> Seleccion<Key>::Ordenar(std::vector<Key> secuencia1, int tamano1) {

    Key x;
    int min = 0;

    for (int i = 0; i < tamano1 - 1; i++) {
        
        min = i;

        for (int j = i+1; j < tamano1; j++) {
            if (secuencia1[j] < secuencia1[min]) {
                min = j;
            }

        }

        #ifdef traza
        std::cout << "**** (" << i << "," << min << ") [" << secuencia1[i] << " < " << secuencia1[min] << "] ****" << std::endl;
        Imprimir(secuencia1, tamano1);
        #endif

        x = secuencia1[min];
        secuencia1[min] = secuencia1[i];
        secuencia1[i] = x;
    }
    return secuencia1;

}