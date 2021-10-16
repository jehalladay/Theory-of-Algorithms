/*
    Project 3 - Hashtable and Heapsort
    James Halladay
    Theory of Algorithms
    10/9/2021

    Here we create the implementation file for the hashtable class.
    defaults for the hashtable:
        chaining: linear
        capacity = 1000
        max load factor = .80

*/ 

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>

#include "hash.h"

using namespace std;

const string MODIFY_DATE = "10-11-21";



/*
    Function for testing that the hash file is compiling and linking correctly.
*/
void hashtest1() {
    cout << "Hello, World! from hash.cpp   " << "\t\tLast Modified: " << MODIFY_DATE << endl;
}


/*
    Function for testing functions and methods in hash.cpp.
    
        Basic: only tests that they are working as intended.
*/
void hashtest2() {
    auto hashtest_2 = []() {
        cout << "Testing Hashtable: constructor 3" << endl;

        Hashtable ht;
        ht.test();

        cout << "Testing Hashtable: destructor" << endl;
    };
    hashtest_2();
    cout << "Finished hash.cpp tests" << endl;
}


/*
    Class contructor that sets default values for maximum load factor and capacity
*/
Hashtable::Hashtable() {
    vector<vector<element>> table;

    for(int i = 0; i < 1000; i++) {
        vector<element> temp;
        table.push_back(temp);
    }

    _table = table; 
    _size = 0;
    _hasher = 1;
    _compresser = 1;
    _capacity = 1000;
    _max_load_factor = .80;
    calculate_load_factor();

    cout << "\tConstructor 1: Hashtable created" << endl;
}

/*
    Class contructor that allows the user to specify the capacity
*/
Hashtable::Hashtable(int capacity) {
    vector<vector<element>> table;

    for(int i = 0; i < capacity; i++) {
        vector<element> temp;
        table.push_back(temp);
    }

    _table = table; 
    _size = 0;
    _hasher = 1;
    _compresser = 1;
    _capacity = capacity;
    _max_load_factor = .80;
    calculate_load_factor();

    cout << "\tConstructor 2: Hashtable created" << endl;
}


/*
    Class contructor that allows the user to specify max load factor and capacity
*/
Hashtable::Hashtable(double max_load_factor, int capacity) {
    vector<vector<element>> table;

    for(int i = 0; i < capacity; i++) {
        vector<element> temp;
        table.push_back(temp);
    }

    _table = table; 
    _size = 0;
    _hasher = 1;
    _compresser = 1;
    _capacity = capacity;
    _max_load_factor = max_load_factor;
    calculate_load_factor();

    cout << "\tConstructor 3: Hashtable created" << endl;
}


/*
    Class destructor

        Has no contents as no pointers are used and no memory is allocated
*/
Hashtable::~Hashtable() {
    cout << "\tDestructor: Hashtable destroyed" << endl;
}


void Hashtable::calculate_load_factor() {
    // Calculate the load factor of the hashtable
    _load_factor = (_size * 1.0) / _capacity;

    if(_load_factor > _max_load_factor) {
        cout << "\t\tHashtable: load factor is greater than max load factor" << endl;
        resize();
    }
}


/*
    Method resizes the hashtable to double the old capacity

        Internal Use:
            Creates a new hashtable
            Insert all entries from old table into new table
            Calculate load factor
*/
void Hashtable::resize() {
    vector<vector<element>> old_table = _table;
    vector<vector<element>> table;
    int old_capacity = _capacity;

    _capacity *= 2;

    for(int i = 0; i < _capacity; i++) {
        vector<element> temp;
        table.push_back(temp);
    }

    _table = table;

    // Copy the elements from the old hashtable to the new one

    for(int i = 0; i < old_capacity; i++) {
        for(int j = 0; j < (int)old_table[i].size(); j++) {
            insert(old_table[i][j]);
        }  
    }

    calculate_load_factor();
}


/*
    Method hashes an input string and returns it's key
        An internal attribute controls which hash and compression methods are used

    input: string entry
    output: int
*/
int Hashtable::hash(string entry) {
    // This function will send the entry into the proper hash function
    // and then send the generated key into the proper compression function

    int key = -1;

    switch (_hasher)
    {
    case 1:
        key = hash1(entry);
        break;
    }

    switch (_compresser)
    {
    case 1:
        key = compress1(key);
        break;
    }

    if(key < 0) {
        cout << "\tHashtable: hash function failed" << endl;
        throw key;
    }

    return key;
}


/*
    Method hashes an input string and returns a raw key

    input: string entry
    output: int
*/
int Hashtable::hash1(string entry) {
    int key = 0;

    for(int i = 0; i < (int)entry.length(); i++) {
        key = (key << 4) + (int)entry[i];
    }

    return key;
}


/*
    Method compresses a raw key into a positive key less than the maximum capacity of the hashtable
*/
int Hashtable::compress1(int raw_key) {
    return abs(raw_key % _capacity);
}


/*
    Method inserts an element into the hashtable
    
        Internal Use:
            Inserts an element into the hashtable
            Does not increment size
            Used to transfer elements from one hashtable to another

    input element e
*/
void Hashtable::insert(element e) {
    e.key = hash(e.entry);
    _table[e.key].push_back(e);
}


/*
    Method returns the current size of the hashtable
*/
int Hashtable::get_size() {
    return _size;
}


/*
    Method returns the capacity of the hashtable
*/
int Hashtable::get_capacity() {
    return _capacity;
}


/*
    Method returns the current load factor of the hashtable
*/
double Hashtable::get_load_factor() {
    return _load_factor;
}


/*
    Method returns the maximum load factor of the hashtable
*/
double Hashtable::get_max_load_factor() {
    return _max_load_factor;
}


/*
    Method searches the hashtable for the input string and returns an element struct
        If the entry is not found, the element is returned with a frequency of -1
    
    input: string entry
    output: element = {entry, key, frequency}
*/
element Hashtable::find(string entry) {
    element e = {entry, hash(entry), -1};

    for(int i = 0; i < (int)_table[e.key].size(); i++) {
        if(_table[e.key][i].entry == entry) {
            return _table[e.key][i];
        }
    }

    return e;
}



/*
    Method allows the user to set the maximum load factor of the hashtable.
*/
void Hashtable::set_max_load_factor(double max_load_factor) {
    _max_load_factor = max_load_factor;
    calculate_load_factor();
}


/*
    Method allows the user to set the capacity of the hashtable
*/
void Hashtable::set_capacity(int capacity) {
    _capacity = capacity;
    calculate_load_factor();
}


/*
    Method removes an element from the hashtable

    input: string entry
*/
void Hashtable::remove(string entry) {
    element e = find(entry);

    if(e.frequency != -1) {
        for(int i = 0; i < (int)_table[e.key].size(); i++) {
            if(_table[e.key][i].entry == entry) {
                _table[e.key].erase(_table[e.key].begin() + i);
                _size--;
            }
        }
    }
}


// need to make these two methods
// element Hashtable::pop(string entry);
// element Hashtable::pop();



/*
    Method inserts an element into the hashtable

        For External Use:
            Takes a string
            Assigns it a hash
            Checks table for string
                If string is found, increments frequency
                If string is not found, inserts string into table and increments size
            Checks load factor

    input: string entry
*/
void Hashtable::insert(string entry) {
    element e = {entry, hash(entry), 1};

    if(_table[e.key].size() == 0) {
        _table[e.key].push_back(e);
        _size++;
    } else {
        bool found = false;
        for(int i = 0; i < (int)_table[e.key].size() && !found; i++) {
            if(_table[e.key][i].entry == e.entry) {
                _table[e.key][i].frequency++;
                found = true;
            }
        }

        if(!found) {
            _table[e.key].push_back(e);
            _size++;
        }
    }

    calculate_load_factor();
}



/*
    Method for initialization testing
*/
void Hashtable::test() {
    cout << "\tHashtable test function called" << endl;
}
