#pragma once
#include <iostream> 
#include <vector>
#include "MetodosOrdenacion.h"

#include <algorithm> // swap()

#define traza
//#define traza2

template<class Key>
class ShellSort: public MetodosOrdenacion<Key> {
    public:
        std::vector<Key> Ordenar(std::vector<Key> secuencia1, int tamano1);
        std::vector<Key> deltaSort (std::vector<Key> secuencia1, int tamano1, int delta);


};


template<class Key>
std::vector<Key> ShellSort<Key>::Ordenar(std::vector<Key> secuencia1, int tamano1) {

    int delta = tamano1;
    while (delta > 1) {
        delta = delta / 2;
        #ifdef traza
        std::cout << "**** {Delta = " << delta << "} ****" << std::endl;
        #endif
        secuencia1 = deltaSort(secuencia1, tamano1, delta);
    }
    return secuencia1;
}

template<class Key>
std::vector<Key> ShellSort<Key>::deltaSort (std::vector<Key> secuencia1, int tamano1, int delta) {

    Key x;
    int j;
    for (int i = delta; i < tamano1; i++) {
        x = secuencia1[i];
        j = i;
        while ((j >= delta) && (x < secuencia1[j - delta])) {

            #ifdef traza
            std::cout << "[" << x << " < " << secuencia1[j - delta] << "] OK" << std::endl;
            #endif
            secuencia1[j] = secuencia1[j - delta];

            #ifdef traza
            Imprimir(secuencia1, tamano1);
            #endif
            
            j = j - delta;
        }
        secuencia1[j] = x;
    }
    return secuencia1;
    #ifdef traza
    Imprimir(secuencia1, tamano1);
    #endif
}
