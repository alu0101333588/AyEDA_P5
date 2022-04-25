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
      
    int longitud = std::to_string(secuencia1[0]).length();
    int fase = 1;
    

    for (int i = longitud-1; i > -1; i = i - 1) { 
        std::vector<std::vector<Key>> oVector;
        oVector.resize(10);

        for (int j = 0; j < tamano1; j++) {
            std::string elemento = std::to_string(secuencia1[j]);
            char num2 = elemento[i];
            int num1 = num2 - '0'; 

            oVector[num1].push_back(secuencia1[j]);
            
        }


        #ifdef traza
        std::cout << "[FASE " << fase << "]" << std::endl;
        for (int h = 0; h < 10; h++) {
            int tamano2 = oVector[h].size();
            for (int l = 0; l < tamano2; l++) {
                std::cout << oVector[h][l] << " ";
            }
        }   
        std::cout << std::endl;
        fase++;
        #endif
    }

    //std::cout << "Peaje1" << std::endl;

    return secuencia1;
}


