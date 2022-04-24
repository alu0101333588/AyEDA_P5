#pragma once
#include <iostream> 
#include <vector>
#include "MetodosOrdenacion.h"

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

    int i, j, d, m = 1;
    std::vector<std::vector<Key>> oVector;

    for (j = 1; j <= tamano1, j++) {
        for (i = 0; i <= 9; i++) {
            
        }
    }


    

    return secuencia1;
}


int i, j, d, m=1;
    slist *temp, *head[10], *tail[10];

    for (j=1; j<=t; j++) 
    { 
        // Initialize the queues, 0 to 9
        for (i=0; i<=9; i++)
        {
            head[i] = NULL;
            tail[i] = NULL;
        }

        // Process the list L
        while ( L != NULL ) 
        {
            // Get the decimal digit with place value m
            d = static_cast<int>(L->val/m)%10;
            
            // Make temp point to the current list item
            temp = L;

            // Make L point to the next list item
            L = L->next;

            // Disconnect the current list item, making it self-contained
            temp->next = NULL;

            if (head[d]!= NULL)
            {   // The queue for digit d is not empty

                // Add the list item to the end of the queue for digit d
                tail[d]->next = temp;

                // Make tail[d] point to the new tail item of queue d
                tail[d] = temp;
            }
            else
            {   // The queue for digit d is empty
                head[d] = temp;  // Point to the new head
                tail[d] = temp;  // Point to the new tail
            }
        } // while

        // Find the index, d, of the first non-empty queue
        d=0;
        while (head[d]==NULL)
            d++;

        // Point to the first item of the first non-empty queue
        L = head[d];

        // Point to the last item of the first non-empty queue
        temp = tail[d];

        // Append the items of the remaining non-empty queues
        // to the tail of list L.
        d++;
        while (d<10)
        {
            if (head[d]!=NULL)
            {
                // Append the items of non-empty queue d to list L
                temp->next = head[d];

                // Point to the new tail of list L
                temp = tail[d];
            }

            d++;
        } // while

        // Prepare to process the next more significant digit
        m = m*10;
    } // for

    return L;
}