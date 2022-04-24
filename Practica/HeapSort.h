#pragma once
#include <iostream> 
#include <vector>
#include "MetodosOrdenacion.h"

#include <algorithm> // swap()

#define traza
//#define traza2

template<class Key>
class HeapSort: public MetodosOrdenacion<Key> {
    public:
        std::vector<Key> Ordenar(std::vector<Key> secuencia1, int tamano1);
        std::vector<Key> Baja (std::vector<Key> secuencia1, int tamano1, int i);


};


template<class Key>
std::vector<Key> HeapSort<Key>::Ordenar(std::vector<Key> secuencia1, int tamano1) {

    for (int i = tamano1/2; i > 0; i--) {
        secuencia1 = Baja(secuencia1, tamano1, i);
    }

    for (int i = n; i > 1; i--) {
        std::swap(secuencia1[1], secuencia[i]);
        secuencia1 = Baja(secuencia1, i-1, 1);
    }

    return secuencia1;
}

template<class Key>
std::vector<Key> HeapSort<Key>::Baja (std::vector<Key> secuencia1, int tamano1, int i) {

    int h1, h2, h;

    while (2*i <= tamano1) {
        h1 = 2 * i;
        h2 = h1 + 1;

        if (h1 == tamano1) {
            h = h1:
        } else if (secuencia1[h1] > secuencia1[h2]) {
            h = h1;

        } else {
            h = h2;
        }

        if (secuencia1[h] <= secuencia1[i]){

        } else {
            std::swap(secuencia1[i], secuencia1[h]);
            i = h;
        }
    }

    return secuencia1;

}
