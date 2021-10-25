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
#include <chrono>
#include <vector>

#include "hash.h"
#include "heap.h"
#include "utility.h"

using namespace std;
using namespace std::chrono;

const string MODIFY_DATE = "10-24-21";
const string FILE_NAME = "A Scandal In Bohemia.txt";

void arg_check(int argc, char* argv[]);
void maintest();
void print_top_words(vector<element>&);
void print_bottom_words(vector<element>&);
void look_up_word(Hashtable&, string);
void experiment(double max_load_factor);


/*
    Function drives the programs execution cycle.

    Menu will print to console and require console input to move the program forward
        options:
            0) Exit
            1) Print top 150 most frequent words
            2) Print bottom 150 most frequent words
            3) Look up a word
            4) Run experiment

    after an option is executed, the menu will tell user to press enter to continue
        this sends the the user back to the menu
*/
int main() {
    double max_load_factor = .65;
    Hashtable ht = read_file(FILE_NAME, max_load_factor);
    vector<element> sorted = Heap().heap_sort(read_file(FILE_NAME, .65));
    int option = -1;
    string input = "";


    while(option != 0) {
        cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
        cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
        cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
        cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;

        cout << "Menu" << endl;
        cout << "0) Exit" << endl;
        cout << "1) Print top 150 most frequent words" << endl;
        cout << "2) Print bottom 150 most frequent words" << endl;
        cout << "3) Look up a word" << endl;
        cout << "4) Run experiment" << endl;
        cout << "Enter option: ";

        getline(cin, input);
        option = stoi(input);

        switch(option) {
            case 0:
                cout << "Exiting..." << endl;
                return 0;
            case 1:
                print_top_words(sorted);
                break;
            case 2:
                print_bottom_words(sorted);
                break;
            case 3:
                // now we ask user for a word to look up
                cout << "Enter word to look up: ";
                getline(cin, input);
                look_up_word(ht, input);
                break;
            case 4:
                // now we ask user for a max load factor percentage
                cout << "Enter max load factor: ";
                getline(cin, input);
                max_load_factor = stod(input);
                experiment(max_load_factor);
                break;
            default:
                cout << "Invalid option" << endl;
                break;
        }

        cout << "Press enter to continue..." << endl;
        getline(cin, input);
    }

    return 0;
}


void print_top_words(vector<element> &words) {
    for(int i = 0; i < 150 && i < (int)words.size(); i++) {
        cout << i + 1 << ": " << words[i].entry << "\t\t" << words[i].frequency << endl; 
    }
}


void print_bottom_words(vector<element> &words) {
    for(int i = (int)words.size() - 1; i >= (int)words.size() - 150 && i >= 0; i--) {
        cout << i + 1 << ": " << words[i].entry << "\t\t" << words[i].frequency << endl; 
    }
}


void look_up_word(Hashtable &ht, string word) {
    element item = ht.find(word);
    if(item.frequency != -1) {
        cout << "The word " << word << " was found " << item.frequency << " times." << endl;
    } else {
        cout << "The word " << word << " was not found." << endl;
    }
}


void experiment(double max_load_factor) {
    // record run time
    auto start = high_resolution_clock::now();

    Hashtable ht = read_file(FILE_NAME, max_load_factor);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);

    cout << "\t\tHashtable Size:\t\t\t"        << ht.get_size()                  << endl;
    cout << "\t\tHashtable Capacity:\t\t"      << ht.get_capacity()              << endl;
    cout << "\t\tHashtable Load Factor:\t\t"   << ht.get_load_factor()           << endl;
    cout << "\t\tHashtable Max Load Factor:\t" << ht.get_max_load_factor()       << endl;
    cout << "\t\tHashtable Run-Time:\t\t" << duration.count() << " milliseconds" << endl;
}


void maintest() {
    cout << endl << "Hello, World! from inside main.cpp"  << "\tLast Modified: " << MODIFY_DATE << endl;
}
