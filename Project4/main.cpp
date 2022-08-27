/*
    Project 4 - A* Search
    James Halladay
    Theory of Algorithms
    10/9/2021


    This is the driver for the A* Search algorithm. The implementation is in
        graph.cpp and the header is in graph.h.
*/


#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

#include "graph.h"

using namespace std;

Graph read_file(string file_name);
void arg_check(int argc, char* argv[]);

int main(int argc, char* argv[]) {
    arg_check(argc, argv);
    
    int start_node = stoi(argv[1]), end_node = stoi(argv[2]);
    Graph G, djk, astar;
    G = read_file("Adjacency matrix.txt");

    cout << "First, we check for the shortest path from vertex " << start_node << " to vertex " << end_node << " using the A* Search algorithm." << endl;
    astar = G.AStarSearch(start_node, end_node);
    astar.print_edges(cout);
    cout << endl;

    cout << "Next, we check for the shortest path from vertex " << start_node << " to vertex " << end_node << " using Dijkstra's algorithm to verify our results." << endl;
    djk = G.ShortestPath(start_node, end_node);
    djk.print_edges(cout);
    

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


/*
    function will read in file containing an adjacency matrix of the graph
    and will create a graph object.

    The adjacency matrix is presented row by row. The first row will be counted
    to determine the number of vertices in the graph. Each new item will trigger
    a G.add_vertex() call

    input: String filename
    output: Graph
*/
Graph read_file(string filename) {
    ifstream file;
    Graph G;

    file.open(filename);

    if(!file.is_open()) {
        cout << "Error opening file" << endl;
        throw "Error opening file";
    }

    int num_vertices = 0;
    string line;
    getline(file, line);

    if(line.length() == 0) {
        throw "Error: Empty first line";
    }

    stringstream ss(line);
    string item;

    while(getline(ss, item, ',')) {
        if(item == "" || item == " ") {
            continue;
        }
        G.add_vertex();
        if(stoi(item) != 0) {
            G.add_edge(0, num_vertices, stoi(item));
        }
        num_vertices++;
    }

    for(int i = 1; i < num_vertices; i++) {
        int j = 0;
        string line = "", item = "";
        getline(file, line);
        stringstream ss(line);
        while(getline(ss, item, ',')) {
            if(item == "" || item == " ") {
                continue;
            }
            if(j < i || j >= num_vertices) {
                j++;
                continue;
            }
            if(stoi(item) != 0) {
                G.add_edge(i, j, stoi(item));
            }
            j++;
            string item = "";
        }
    }

    return G;
}