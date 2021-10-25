/*
    Project 3 - Hashtable and Heapsort
    James Halladay
    Theory of Algorithms
    10/9/2021

    Here we create the implementation file for the heap class.
    The heap is a max heap and will be equipped with the operations:
        insert
        pop_root
        heap_up
        heap_down
        heap_sort
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

#include "heap.h"

using namespace std;

const string MODIFY_DATE = "10-24-21";



// Constructor for Max Heap
Heap::Heap() {
    size = 0;
}

// Destructor for Max Heap
Heap::~Heap() { }



// Mutators

/*
    Method inserts an element into the heap.

    input: element e
*/
void Heap::insert(element e) {
    _heap.push_back(e);
    size++;
    heap_up(size - 1);
}


void Heap::heap_up(int i) {
    int parent = (i - 1) / 2;
    element temp;
    if (i != 0) {
        if(_heap[parent].frequency < _heap[i].frequency) {
            temp = _heap[parent];
            _heap[parent] = _heap[i];
            _heap[i] = temp;

            heap_up(parent);
        }
    }
}


void Heap::heap_down(int i) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i;
    element temp;

    if (left < size && _heap[left].frequency > _heap[largest].frequency) {
        largest = left;
    }
    
    if (right < size && _heap[right].frequency > _heap[largest].frequency) {
        largest = right;
    }

    if (largest != i) {
        temp = _heap[i];
        _heap[i] = _heap[largest];
        _heap[largest] = temp;

        heap_down(largest);
    }
}


element Heap::pop_root() {
    element root = _heap[0];
    _heap[0] = _heap[size - 1];
    _heap.pop_back();
    size--;
    heap_down(0);
    return root;
}

vector<element> Heap::heap_sort(Hashtable ht) {
    vector<element> sorted;

    while(ht.get_size() != 0) {
        element e = ht.pop();
        insert(e);
    }


    while (size > 0) {
        sorted.push_back(pop_root());
    }
    return sorted;
}


void heaptest() {
    cout << "Hello, World! from heap.cpp   " << "\t\tLast Modified: " << MODIFY_DATE << endl;
}
