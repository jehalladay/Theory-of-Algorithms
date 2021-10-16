/* 
    Project 3 - Hashtable and Heapsort
    James Halladay
    Theory of Algorithms
    10/9/2021

    This program will test the various functions and methods
    used to create this project
*/

#include <iostream>
#include <string>
#include <fstream>

#include "hash.h"
#include "heap.h"
#include "utility.h"

using namespace std;

const string MODIFY_DATE = "10-11-21";


// Here we will place function prototypes that execute the tests
void init_test1();
void init_test2();


/*
    Our program runs tests in three phases:

        1: Tests to see if all files are linking and compiling properly
        2: Runs the individual tests for each file to test the functions they contain
        3: Runs tests on functions and methods as they work together in this file's test function
*/
int main() {
    init_test1();
    heaptest();
    hashtest1();
    utilitytest1();

    cout << endl << "Testing hash.cpp" << endl;
    hashtest2();
    cout << endl << "Testing utility.cpp" << endl;
    utilitytest2();
    
    cout << endl << "Testing test.cpp" << endl;
    init_test2();

    cout << endl << "Ending execution of test.cpp" << endl;
    return 0;
}


/*
    Function is for testing that test.cpp is linking and compiling properly
*/
void init_test1() {
    cout << endl << "Hello, World! from test.cpp   "  << "\t\tLast Modified: " << MODIFY_DATE << endl;
}


/*
    Function is for testing that the functions in hash.cpp, heap.cpp, and utility.cpp
        are working and interacting properly

        Basic: only tests that functions and methods are working as intended
*/
void init_test2() {
    Hashtable hash_table = read_file("A Scandal In Bohemia.txt", .5);

    cout << "Testing Hashtable and read_file:" << endl;

    cout << "\t\tHashtable Size:\t\t\t"        << hash_table.get_size()            << endl;
    cout << "\t\tHashtable Capacity:\t\t"      << hash_table.get_capacity()        << endl;
    cout << "\t\tHashtable Load Factor:\t\t"   << hash_table.get_load_factor()     << endl;
    cout << "\t\tHashtable Max Load Factor:\t" << hash_table.get_max_load_factor() << endl;


    hash_table = read_file("A Scandal In Bohemia.txt", .7);
    cout << "Testing Hashtable and read_file:" << endl;

    cout << "\t\tHashtable Size:\t\t\t"        << hash_table.get_size()            << endl;
    cout << "\t\tHashtable Capacity:\t\t"      << hash_table.get_capacity()        << endl;
    cout << "\t\tHashtable Load Factor:\t\t"   << hash_table.get_load_factor()     << endl;
    cout << "\t\tHashtable Max Load Factor:\t" << hash_table.get_max_load_factor() << endl;


    hash_table = read_file("A Scandal In Bohemia.txt", .8);
    cout << "Testing Hashtable and read_file:" << endl;

    cout << "\t\tHashtable Size:\t\t\t"        << hash_table.get_size()            << endl;
    cout << "\t\tHashtable Capacity:\t\t"      << hash_table.get_capacity()        << endl;
    cout << "\t\tHashtable Load Factor:\t\t"   << hash_table.get_load_factor()     << endl;
    cout << "\t\tHashtable Max Load Factor:\t" << hash_table.get_max_load_factor() << endl;

    cout << "Finished test.cpp tests" << endl;
}