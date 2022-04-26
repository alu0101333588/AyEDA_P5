#pragma once
#include <iostream> 
#include <vector>
#include "MetodosOrdenacion.h"
#include <string>

#include <algorithm> // swap()

#define traza
//#define traza2

template<class Key>
class InsercionSort: public MetodosOrdenacion<Key> {
    public:
        std::vector<Key> Ordenar(std::vector<Key> secuencia1, int tamano1);
        std::vector<Key> Insertar(std::vector<Key> secuencia1, int i, Key valor, int tamano1);


};


template<class Key>
std::vector<Key> InsercionSort<Key>::Ordenar(std::vector<Key> secuencia1, int tamano1) {
      
    // Modificación clase: MENOR A MAYOR - EMPEZANDO POR LA DERECHA    
    //for (int i = 0; i < tamano1; i++) {
    for (int i = tamano1; i > -1; i = i - 1) {
        //Imprimir(secuencia1, tamano1);
        secuencia1 = Insertar(secuencia1, i, secuencia1[i], tamano1);

    }
    return secuencia1;
}


template<class Key>
std::vector<Key> InsercionSort<Key>::Insertar(std::vector<Key> secuencia1, int i, Key valor, int tamano1) {

    Key centinela = valor;
    int j = i - 1;

    while (valor < centinela) {
        secuencia1[j+1] = centinela;
        j++; // j--
        centinela = secuencia1[j];
    }
    secuencia1[j+1] = valor;


    

    while (x < secuencia1[j]) {
        secuencia[j+1] = secuencia1[j];
        j--;
    }
    secuencia[j+1] = valor;

    for (int k = tamano1; k >= i; i = i -1) {
        int j = k;
        valor = secuencia1[k];
        centinela = valor;
        j--;
    }
    secuencia1[j] = valor;
} 
    
    Imprimir(secuencia1, i);

    return secuencia1;



}