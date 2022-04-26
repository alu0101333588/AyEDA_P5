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

    for (int i = (tamano1/2) - 1; i >= 0; i--) {
        Imprimir_secuencia(secuencia1, i, tamano1);
        secuencia1 = Baja(secuencia1, tamano1, i);
    }

    for (int i = tamano1 -1 ; i > 0; i--) {
        Imprimir_secuencia(secuencia1, i, tamano1);
        std::swap(secuencia1[0], secuencia1[i]);
        secuencia1 = Baja(secuencia1, i, 0);
    }

    return secuencia1;
}

template<class Key>
std::vector<Key> HeapSort<Key>::Baja (std::vector<Key> secuencia1, int tamano1, int i) {
    
    int h1, h2, h;
    /*#ifndef antiguo
    h1 = 2*i + 1;
    h2 = h1 + 2;
    h = i;

    if (h1 < tamano1 && secuencia1[h1] > secuencia1[h]) {
        h = h1;
    } 

    if (h2 < tamano1 && secuencia1[h2] > secuencia1[h]) {
        h = h2;
    } 

    if (h != i) {
        std::swap(secuencia1[i], secuencia1[h]);
        secuencia1 = Baja(secuencia1, tamano1, h);
    }
    #endif*/


    //while (h1 <= tamano1) {
    while (2*i <= tamano1){
        h1 = 2 * i; // +1
        h2 = h1 + 1; // +2

        //h1 = 2*i;
        //h2 = h1+1;

        if (h1 == tamano1) {
            h = h1;
        } else if (secuencia1[h1] > secuencia1[h2]) {
            h = h1;
        } else {
            h = h2;
        }

        if (secuencia1[h] <= secuencia1[i]){
            
            #ifdef traza
            Imprimir(secuencia1, tamano1);
            #endif

            break;

        } else {
            std::swap(secuencia1[i], secuencia1[h]);
            #ifdef traza
            Imprimir(secuencia1, tamano1);
            #endif
            i = h;
        }
    }

    return secuencia1;

}
