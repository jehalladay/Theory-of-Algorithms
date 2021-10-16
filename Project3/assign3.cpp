/* 
    Project 3 - Hashtable and Heapsort
    James Halladay
    Theory of Algorithms
    10/9/2021

    This program will be the driver for the hashtable and heapsort
        classes.

    We will scan the file "A Scandal In Bohemia.txt" and store the words in 
        the hashtable while recording their frequencies.
    
    After the file is finished, we will input the words and their frequencies 
        into the heap. 
    
    The heap is a maxheap, so once the heap is full, the we will remove the root 
        node until it is empty into a vector. 
    
    We will then print the top 150 words and their frequencies as well as the 
        bottom 150 words and their frequencies.
*/

#include <iostream>
#include <string>
#include <fstream>

#include "hash.h"
#include "heap.h"

using namespace std;

const string MODIFY_DATE = "10-10-21";
const string FILE_NAME = "A Scandal In Bohemia.txt";


void arg_check(int argc, char* argv[]);
void maintest();


int main(int argc, char* argv[]) {

    arg_check(argc, argv);
    maintest();

    return 0;
}

void arg_check(int argc, char* argv[]) {

    //check for correct number of arguments, used for debugging
    // if (argc < 3 || argc > 5) { 
    //     cout << "Incorrect number of arguments" << endl;
    //     throw;
    // }

    cout << "argc: " << argc << endl;
    for(int i = 0; i < argc; i++) {
        cout << "argv[" << i << "]: " << argv[i] << endl;
    }
}

void maintest() {
    cout << endl << "Hello, World! from inside assign3.cpp"  << "\tLast Modified: " << MODIFY_DATE << endl;
}
