#pragma once
#include <iostream> 
#include <vector>

template<class Key>
class MetodosOrdenacion {
    public:
        virtual std::vector<Key> Ordenar(std::vector<Key> secuencia1, int tamano1) = 0;
        
};

template<class Key>
void Imprimir(std::vector<Key> secuencia1, int tamano1) {
    for (int i = 0; i < tamano1; i++) {
        std::cout << secuencia1[i] << " ";
    }
    std::cout << std::endl;

}

template<class Key>
void Imprimir_secuencia(std::vector<Key> secuencia1, int inicio, int final) {
    std::cout << "[ ";
    for (int i = inicio; i < final+1; i++) {
        std::cout << secuencia1[i] << " ";
    }
    std::cout <<  "]" << std::endl;

}


