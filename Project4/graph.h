/*
Here we create the header file for the graph class.
    the implementation is in graph.cpp and uses a priority queue 
    to store the edges when constructing the MST. When producing
    a graph's MST, since the MST is a subgraph of the original graph,
    we store it in its own graph object.
*/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>

 
// #include "linked_list.h"

using namespace std;

struct edge {
    int to;
    int from;
    int weight;
};

struct vertex {
    int degree;
};

enum color {
    White,
    Gray,
    Black
};

class Graph {
    private:
        int start;
        int degree;
        int edges;
        vector<vector<int>> adjacency_matrix;
        vector<color> colors;                          
        vector<edge> edge_list;
        vector<vertex> vertex_list;
        int h(int size, int degree);
    public:
        Graph();
        Graph(int number_of_vertices, int start_position);

        void add_vertex(); 
        void add_edge(int to, int from, int weight);
        void print_edges(ostream &ofs);
        int get_edges();
        int get_degree();
        int total_weight();

        Graph MST(int first);
        Graph Dijkstra(int first);
        Graph ShortestPath(int first, int second);
        Graph AStarSearch(int first, int second);
        Graph firstNEdges(int edges);

        // overloaded operators
};


struct element {
    int priority;
    char vertex;
    element *link;
    edge data;
};


// priority queue, it was simpler to call queue 
class Queue {
    private:
        element *head, *tail;
        int _length;
    public:
        Queue();

        int length();
        bool empty();
        void enQueue(edge e);
        edge deQueue();
};

