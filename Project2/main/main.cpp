/*
Project 1 - MST and Shortest Path

We will be writing a program that takes a file, distances.txt, as input and 
outputs the minimum spanning tree if 2 arguments are given
outputs the shortest path between two nodes if 3 arguments are given
outputs both if 4 arguments are given

A file is expected as input in the first argument.
The data in the file is expected to be in the following format:
    city, ST[coord1, coord2]weight
    dist1, dist2, ... , distn

    where city is the name of the city, ST is the state abbreviation,
    coord1, coord2 are the coordinates of the city, 
    and 0 - n distances from the city to other cities
    for n cities.

We will discard the coordinates and the weights, keeping only the city, state, and distances.

This will form the basis of our graph.

The second argument expects the name of a city.
If only 2 arguments:
    The program will output the minimum spanning tree for the graph.
if 3 arguments:
    The program will output the shortest path between the two cities given by arg 2 and arg 3.
if 4 arguments:
    The program will output first the minimum spanning tree and then the shortest path
*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

#include "linked_list.h"
#include "graph.h"

using namespace std;



int city_to_index(string city, List<string> cities);
List<string> read_file(string source, Graph &G);
void arg_check(int argc, char* argv[]);

int main(int argc, char* argv[]) {
    arg_check(argc, argv);

    Graph G, MST;
    string city1 = argv[2], city2;
    List<string> cities = read_file(argv[1], G);

    // we only use city2 if calculating shortest path
    if(argc > 3) {   
        city2 = argv[3];
    }

    MST = G.MST(city_to_index(city1, cities));

    cout << "Minimum Spanning Tree: " << MST.total_weight() << endl;
    MST.print_edges(cout, cities);

    return 0;
}


void arg_check(int argc, char* argv[]) {

    //check for correct number of arguments, used for debugging
    if (argc < 3 || argc > 5) { 
        cout << "Incorrect number of arguments" << endl;
        throw;
    }

    cout << "argc: " << argc << endl;
    for(int i = 0; i < argc; i++) {
        cout << "argv[" << i << "]: " << argv[i] << endl;
    }
}


// A utility function to find the index of a city when 
// given the city name and the list of cities.
int city_to_index(string city, List<string> cities) {
    for (int i = 0; i < cities.length(); i++) {
        if (cities[i] == city) {
            return i;
        }
    }

    return -1;
}


List<string> read_file(string source, Graph &G) {
    List<string> cities;
    string town = "", state;
    int dist, id = 0;
    ifstream file;
    file.open(source);

    
    if (!file) {
        cout << "File not found" << endl;
        throw;
    }

    cout << "reading file" << endl;

    // throw away all contents of the file preceeding the first city, Youngstown, OH.
    while(town != "Youngstown,") {
        file >> town;

    }

    file >> state;

    // read in file, stopping after we reach the end of the cities
    while(town != "*") {
        int i;

        // Check if the city is composed of multiple words
        while(state[2] != '[') {
            town += " " + state;
            file >> state;
        }

        // erase all garbage in the state field, leaving only the state abbreviation
        state.erase(2, 100);
        town += " " + state;
        cities.push(town);
        G.add_vertex();

        // here we will read the distances between cities as edges between nodes
        for (i = 0; i < id; i++) {
            file >> dist;
            G.add_edge(i, id, dist);
        }

        // read in the next city
        file >> town >> state;
        id++;

    }

    return cities;
}