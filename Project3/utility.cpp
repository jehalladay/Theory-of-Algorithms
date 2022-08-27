/*
    Project 3 - Hashtable and Heapsort
    James Halladay
    Theory of Algorithms
    10/10/2021

    Here we create the implementation file for our utility functions.
*/ 

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>

#include "hash.h"
#include "heap.h"
#include "utility.h"

using namespace std;

const string MODIFY_DATE = "10-11-21";


/*
    Function reads the input file and stores the data in a vector of elements for testing purposes.

    input: string file_name
    output: vector<elements>
*/
vector<element> readfile(string file_name)
{
    vector<element> elements;
    Hashtable hash_table(20000);
    ifstream file;
    file.open(file_name);
    string line = "", clean_line = "";
    element word;

    if(!file.is_open()) {
        cout << "\tFile not found: " << file_name << endl;
        throw file_name;
    }


    // first we get past all the comments by project gutenberg
    while(line != "Menendez") {
        file >> line;
    }

    // Gutenberg is the first unique word to show up after the contents of the novel, 
    //      so we stop reading the file here.
    while(line != "Gutenberg") {
        file >> line;
        clean_line = scrub(line);
        if(clean_line != "") {
            hash_table.insert(clean_line); 
        }
    }

    cout << "\t\tHashtable Size:\t\t\t"        << hash_table.get_size()            << endl;
    cout << "\t\tHashtable Capacity:\t\t"      << hash_table.get_capacity()        << endl;
    cout << "\t\tHashtable Load Factor:\t\t"   << hash_table.get_load_factor()     << endl;
    cout << "\t\tHashtable Max Load Factor:\t" << hash_table.get_max_load_factor() << endl;

    file.close();

    return elements;
}


/*
    Function reads the input file and stores the data in a hashtable
        that records the frequency of each word.

        default version

    input: string file_name
    output: Hashtable
*/
Hashtable read_file(string file_name)
{
    Hashtable hash_table(2500);
    ifstream file;
    file.open(file_name);
    string line = "", clean_line = "";
    element word;

    if(!file.is_open()) {
        cout << "\tFile not found: " << file_name << endl;
        throw file_name;
    }


    // first we get past all the comments by project gutenberg
    while(line != "Menendez") {
        file >> line;
    }

    // Gutenberg is the first unique word to show up after the contents of the novel, 
    //      so we stop reading the file here.
    while(line != "Gutenberg") {
        file >> line;
        clean_line = scrub(line);
        if(clean_line != "") {
            hash_table.insert(clean_line); 
        }
    }

    file.close();

    return hash_table;
}


/*
    Function reads the input file and stores the data in a hashtable
        that records the frequency of each word.

        variable load factor version

    input: string file_name, double max_load_factor
    output: Hashtable
*/
Hashtable read_file(string file_name, double max_load_factor) {
    Hashtable hash_table(max_load_factor, 2500);
    ifstream file;
    file.open(file_name);
    string line = "", clean_line = "";
    element word;

    if(!file.is_open()) {
        cout << "\tFile not found: " << file_name << endl;
        throw file_name;
    }


    // first we get past all the comments by project gutenberg
    while(line != "Menendez") {
        file >> line;
    }

    // Gutenberg is the first unique word to show up after the contents of the novel, 
    //      so we stop reading the file here.
    while(line != "Gutenberg") {
        file >> line;
        clean_line = scrub(line);
        if(clean_line != "") {
            hash_table.insert(clean_line); 
        }
    }

    file.close();

    return hash_table;
}


/*
    Function takes a string and returns a string with all non-alphanumeric characters removed.

    input: string word
    output: string
*/
string scrub(string word) {
    string scrubbed = "";

    for(int i = 0; i < (int)word.length(); i++) {
        if(!ispunct(word[i]) && !isdigit(word[i])) {
            scrubbed += (char)tolower(word[i]);
        }
    }

    return scrubbed;
}


/*
    Function for testing that the utility file is compiling and linking correctly.
*/
void utilitytest1() {
    cout << "Hello, World! from utility.cpp" << "\t\tLast Modified: " << MODIFY_DATE << endl;
}


/*
    Function for testing all the functions in utility.cpp.
    
        Basic: only tests that they are working as intended.
*/
void utilitytest2() {
    vector<element> elements;
    string word = "He1l123lo, W''\"\"orld123123123125555@;';./.,;!@^*^(^%&&$#{}|}]\\`~!";
    bool found = false;


    cout << "Testing readfile function: wrong input file" << endl;
    try {
        elements = readfile("test.txt");
    } catch(string e) {}


    cout << "Testing readfile function: correct input file" << endl;
    elements = readfile("A Scandal In Bohemia.txt");


    cout << "Testing scrub function: " << word << endl;
    cout << "\t" << scrub(word) << endl;


    cout << "Testing scrub function: readfile internal usage" << endl;
    for(int i = 0; i < (int)elements.size() && !found; i++) {
        for(int j = 0; j < (int)elements[i].entry.length(); j++) {
            if(ispunct(elements[i].entry[j]) || isdigit(elements[i].entry[j])) {
                found = true;
            }
        }
    }

    if(found) {
        cout << "\tScrub Failed" << endl;
    } else {
        cout << "\tScrub Passed" << endl;
    }

    cout << "Finished utility.cpp tests" << endl;
}
