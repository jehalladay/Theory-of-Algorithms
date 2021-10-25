/*
    Project 3 - Hashtable and Heapsort
    James Halladay
    Theory of Algorithms
    10/9/2021


    Here we create the header file for the hashtable class.
    The hashtable will use chaining to resolve collisions.
*/
#pragma once

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string> 
#include <vector>  

using namespace std;

void hashtest1();
void hashtest2();


struct element {
    string entry;
    int key, frequency;
};

class Hashtable {
    private:
        // Internal attributes

        vector<vector<element>> _table;
        int _size, _capacity, _hasher, _compresser;
        double _load_factor, _max_load_factor;

        // Internal methods

        void calculate_load_factor();
        void insert(element e);
        void resize();
        int hash1(string entry);
        int compress1(int raw_key);
    
    public:
        // constructors

        Hashtable();
        Hashtable(int capacity);
        Hashtable(double max_load_factor, int capacity);

        // destructors
        
        ~Hashtable();

        // getters

        int get_size();
        double get_load_factor();
        double get_max_load_factor();
        int get_capacity();
        element find(string entry);

        // setters

        void set_max_load_factor(double max_load_factor);
        void set_capacity(int capacity);

        // mutators

        void insert(string entry);
        void remove(string entry);
        element pop(string entry);
        element pop();

        // hash functions

        int hash(string entry);

        // other functions

        void print_table();
        void test();
};

