#pragma once
#include <iostream> 
#include <vector>
#include "MetodosOrdenacion.h"

#include <algorithm> // swap()

#define traza
//#define traza2

template<class Key>
class QuickSort: public MetodosOrdenacion<Key> {
    public:
        std::vector<Key> Ordenar(std::vector<Key> secuencia1, int tamano1);
        std::vector<Key> Qsort (std::vector<Key> secuencia1, int ini, int fin, int tamano1);


};


template<class Key>
std::vector<Key> QuickSort<Key>::Ordenar(std::vector<Key> secuencia1, int tamano1) {
    return Qsort(secuencia1, 0, tamano1 - 1, tamano1);
}


template<class Key>
std::vector<Key> QuickSort<Key>::Qsort (std::vector<Key> secuencia1, int ini, int fin, int tamano1) {
    int i = ini, f = fin;
    Key p = secuencia1[(i+f)/2];

    #ifdef traza
    std::cout << "**(Pivote: " << p << ")**" << std::endl;
    #endif

    while (i <= f) {
        while (secuencia1[i] < p){
            #ifdef traza2
            //std::cout << "[" << secuencia1[i] << " < " << p << "] OK" << std::endl;
            //Imprimir(secuencia1, tamano1);
            Imprimir_secuencia(secuencia1, i, f);
            #endif
            
            i++;
        }

        #ifdef traza2
        std::cout << "[" << secuencia1[i] << " < " << p << "] X" << std::endl;
        Imprimir(secuencia1, tamano1);
        #endif

        while (secuencia1[f] > p) {
            #ifdef traza2
            //std::cout << "[" << secuencia1[f] << " > " << p << "] OK" << std::endl;
            //Imprimir(secuencia1, tamano1);
            Imprimir_secuencia(secuencia1, i, f);
            #endif
            f--;
        }

        #ifdef traza2
        std::cout << "[" << secuencia1[f] << " > " << p << "] X" << std::endl;
        Imprimir(secuencia1, tamano1);
        #endif

        if (i <= f) {
            std::swap(secuencia1[i], secuencia1[f]);

            #ifdef traza2
            std::cout << "[" << i << " <= " << f << "] OK. Intercambio(" << secuencia1[i] << ", " << secuencia1[f] << ")" << std::endl;
            Imprimir(secuencia1, tamano1);
            //Imprimir_secuencia(secuencia1, i, f);
            #endif

            i++;
            f--;
        }
    }

    if (ini < f) {

        #ifdef traza2
        std::cout << "Compara, inic(" << ini << "). f(" << f << ") OK" << std::endl;
        Imprimir(secuencia1, tamano1);
        //Imprimir_secuencia(secuencia1, i, f);
        #endif
        secuencia1 = Qsort(secuencia1, ini, f, tamano1);
    }

    if (i < fin) {

        #ifdef traza2
        std::cout << "Comparara, i(" << i << "). fin(" << fin << ") OK" << std::endl;
        Imprimir(secuencia1, tamano1);
        //Imprimir_secuencia(secuencia1, i, f);
        #endif
        secuencia1 = Qsort(secuencia1, i, fin, tamano1);
    }

    //std::cout << "PREFINAL: ";
    Imprimir(secuencia1, tamano1);

    return secuencia1;
}