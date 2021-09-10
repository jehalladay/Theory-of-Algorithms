/*
Project 1 - MST and Shortest Path

We will be writing a program that takes a file, distances.txt, as input and 
outputs the minimum spanning tree if 3 arguments are given
outputs the shortest path between two nodes if 4 arguments are given
outputs both if 5 arguments are given

*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;


int main(int argc, char* argv[]) {
    //check for correct number of arguments
    if (argc < 3 && argc > 5) { 
        cout << "Incorrect number of arguments" << endl;
        return 1;
    }

    // open file   
    ifstream file;
    file.open(argv[1]);
    if (!file) {
        cout << "File not found" << endl;
        return 1;
    } 




}