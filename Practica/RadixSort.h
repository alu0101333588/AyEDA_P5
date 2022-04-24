#pragma once
#include <iostream> 
#include <vector>
#include "MetodosOrdenacion.h"
#include <string>

#include <algorithm> // swap()

#define traza
//#define traza2

template<class Key>
class RadixSort: public MetodosOrdenacion<Key> {
    public:
        std::vector<Key> Ordenar(std::vector<Key> secuencia1, int tamano1);


};


template<class Key>
std::vector<Key> RadixSort<Key>::Ordenar(std::vector<Key> secuencia1, int tamano1) {

    //std::cout << "ENTRADA" << std::endl;

    //int i, j, d, m = 1;
    std::vector<Key> oVector;
    int longitud = std::to_string(secuencia1[0]).length();
    

    for (int i = longitud-1; i > -1; i = i - 1) { 
        oVector = secuencia1;
        int k = 0;
        while (k < tamano1) {
            int comparacion = 9;
            int posicion = 0;
            
            for (int j = k; j < tamano1; j++) {
                std::string elemento = std::to_string(oVector[j]);
                char num2 = elemento[i];
                int num1 = num2 - '0'; 

                if (num1 < comparacion) {
                    comparacion = num1; 
                }
            }

            int q = k;

            for (int j = q; j < tamano1; j++) {
                int posicion_clave = 0;
                for (int l = j; l < tamano1; l++) {
                    std::string elemento = std::to_string(oVector[l]);
                    char num2 = elemento[i];
                    int num1 = num2 - '0'; 
                    if (num1 == comparacion) {
                        if (oVector[j] <= oVector[comparacion]) { 
                            posicion_clave = l;
                        }    
                    }  
                }
                std::swap(oVector[k], oVector[posicion_clave]);
                k++;
            }
        }

        #ifdef traza
        Imprimir(oVector, tamano1);
        #endif
    }

    //std::cout << "Peaje1" << std::endl;

    return secuencia1;
}


