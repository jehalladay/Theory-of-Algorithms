/* 
    Project 3 - Hashtable and Heapsort
    James Halladay
    Theory of Algorithms
    10/9/2021

    This program will render a program that expect a command line
        argument being an input text file and an output text file name. 
    The program will read the data in the input file (strings) and write
        to the output file the sorted contents of the input

    We will scan the file and store the words in 
        the hashtable while recording their frequencies.
    
    After the file is finished, we will input the words and their frequencies 
        into the heap. 
    
    The heap is a maxheap, so once the heap is full, the we will remove the root 
        node until it is empty into a vector. 
    
    The input file is sorted through this process and then is written to the output file specified
        by the second command line argument.
*/

#include <iostream>
#include <string>
#include <fstream>

#include "hash.h"
#include "heap.h"
#include "utility.h"

using namespace std;

const string MODIFY_DATE = "10-24-21";
const string FILE_NAME = "A Scandal In Bohemia.txt";


void arg_check(int argc, char* argv[]);
void maintest();
void write_file(string file_name, vector<element>& sorted);


int main(int argc, char* argv[]) {

    arg_check(argc, argv);
    maintest();
    Hashtable ht = read_file(argv[1], .65);
    vector<element> sorted = Heap().heap_sort(ht);
    write_file(argv[2], sorted);

    return 0;
}

void arg_check(int argc, char* argv[]) {
    if (argc < 2 || argc > 3) { 
        cout << "Incorrect number of arguments" << endl;
        throw;
    }

    cout << "argc: " << argc << endl;
    for(int i = 0; i < argc; i++) {
        cout << "argv[" << i << "]: " << argv[i] << endl;
    }
}

void write_file(string file_name, vector<element>& sorted) {
    ofstream outfile;
    outfile.open(file_name);
    for(int i = 0; i < (int)sorted.size(); i++) {
        outfile << sorted[i].entry << "\t\t" << sorted[i].frequency << endl;
    }
    outfile.close();
}


void maintest() {
    cout << endl << "Hello, World! from inside assign3.cpp"  << "\tLast Modified: " << MODIFY_DATE << endl;
}
