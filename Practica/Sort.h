#pragma once
#include <iostream> 
#include <fstream>

#include <vector>

#include <random> // rand()
#include <ctime> // time()

#include "Seleccion.h"
#include "QuickSort.h"
#include "ShellSort.h"
#include "HeapSort.h"
#include "RadixSort.h"

#define traza


template<class Key> class MetodosOrdenacion;
template<class Key> class Sort {
    public:
        Sort(int tamano);
        ~Sort() = default;
        
        void Insercion(int opcion); // 1 - Manual | * - Automática

        void Print(); 
        int GetTamano() const {return tamano_; }

        void Ordenar();
 
        bool SetOrdenacion(int opcion); // Establece el algoritmo de ordenación
    
    private:
        int tamano_; // Tamaño tabla
        std::vector<Key> Secuencia_;
        MetodosOrdenacion<Key> *Ordenacion_;        
    
};

bool ValoresCorrectos(int numero) {
    if (numero <= 0) {
        return false;
    }
    return true;
}


template<class Key>
Sort<Key>::Sort(int tamano) {
    tamano_ = tamano;
    Secuencia_.resize(tamano);
}



template<class Key>
void Sort<Key>::Ordenar() {

    std::vector<Key> vector1;
    vector1 = Ordenacion_->Ordenar(Secuencia_, tamano_);
    #ifndef traza
    std::cout << "Secuencia final: ";
    #endif
    Imprimir(vector1, tamano_);

}

template<class Key>
bool Sort<Key>::SetOrdenacion(int opcion) {
    
    switch (opcion) {
    case 1:
        Ordenacion_ = new Seleccion<Key>();
        break;
    case 2:
        ///mOrdenacion_ = new QuickSort<Key>();
        break;
    case 3:
        //mOrdenacion_ = new ShellSort<Key>();
        break;
    case 4:
        //mOrdenacion_ = new HeapSort<Key>();
        break;
    case 5:
        //mOrdenacion_ = new RadixSort<Key>();
        break;

    default:
        return false; // Retorno de error
        break;
    }

    return true; // Retorno de éxito

}

template<class Key>
void Sort<Key>::Insercion(int opcion) {

    int max = 9999, min = 1000;
    
    if (opcion == 1) { // Manual
        for (int i = 0; i < tamano_; i++) {
            std::cout << "Posición " << i << ": ";
            std::cin >> Secuencia_[i];
        }            
        std::cout << "________________" << std::endl;

    } else {
        srand(time(NULL));
        for (int i = 0; i < tamano_; i++) {
            Secuencia_[i] = rand() % (max - min - 1) + min; 
        }
    }
}

template<class Key>
void Sort<Key>::Print() {
    for (int i = 0; i < tamano_; i++) {
        std::cout << Secuencia_[i] << " ";
    }
    std::cout << std::endl << "###############" << std::endl;

}