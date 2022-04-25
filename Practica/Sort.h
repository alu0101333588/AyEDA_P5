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
        
        bool Insercion(int opcion); // 1 - Manual | * - Automática

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
    #ifdef traza
    std::cout << "<><><><> SECUENCIA FINAL <><><><>: ";
    #endif
    Imprimir(vector1, tamano_);

}

template<class Key>
bool Sort<Key>::SetOrdenacion(int opcion) {
    
    switch (opcion) {
    case 1:
        Ordenacion_ = new Seleccion<Key>;
        break;
    case 2:
        Ordenacion_ = new QuickSort<Key>;
        break;
    case 3:
        Ordenacion_ = new ShellSort<Key>;
        break;
    case 4:
        Ordenacion_ = new HeapSort<Key>;
        break;
    case 5:
        Ordenacion_ = new RadixSort<Key>;
        break;

    default:
        return false; // Retorno de error
        break;
    }

    return true; // Retorno de éxito

}

template<class Key>
bool Sort<Key>::Insercion(int opcion) {

    int max = 9999, min = 1000;
    
    if (opcion == 1) { // Manual
        for (int i = 0; i < tamano_; i++) {
            std::cout << "Posición " << i << ": ";
            std::cin >> Secuencia_[i];
        }            
        std::cout << "________________" << std::endl;
        return true;

    } else if (opcion == 2){
        std::string nfichero = "";
        std::cout << "INTRODUZCA EL NOMBRE DEL FICHERO: ";
        std::cin >> nfichero;

        std::ifstream lectura1(nfichero);
        while(!lectura1.eof()) {
            //std::string linea = " ";
            //getline(lectura1, linea);

            for (int i = 0; i < tamano_; i++) {
                lectura1 >> Secuencia_[i];
            }
            return true;
        }

    } else if (opcion == 3) {
        srand(time(NULL));
        for (int i = 0; i < tamano_; i++) {
            Secuencia_[i] = rand() % (max - min - 1) + min; 
        }
        return true;
    }

    return false;
}

template<class Key>
void Sort<Key>::Print() {
    for (int i = 0; i < tamano_; i++) {
        std::cout << Secuencia_[i] << " ";
    }
    std::cout << std::endl << "############### (" << Secuencia_.size() << ")" << std::endl;

}