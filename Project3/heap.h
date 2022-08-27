/*
    Project 3 - Hashtable and Heapsort
    James Halladay
    Theory of Algorithms  
    10/9/2021


    Here we create the header file for the heap class.
*/
#pragma once

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>

#include "hash.h"

using namespace std;   


/*
    Class is a Max Heap.
*/
class Heap {
    private:
        vector<element> _heap;
        int size;
        void heap_up(int);
        void heap_down(int);
    public:
        Heap();
        ~Heap();
        void insert(element);
        element pop_root();
        vector<element> heap_sort(Hashtable);
};


void heaptest();
