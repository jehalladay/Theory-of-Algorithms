#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

#include "linked_list.h"

using namespace std;

// const int MaxVertices = 26;
// const int MaxEdges = (MaxVertices*(MaxVertices - 1) / 2);

struct edge {
    int to;
    int from;
    int weight;
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
        // int adjacency_matrix[MaxVertices][MaxVertices];     // convert to dynamic array
        List<List<int>> adjacency_matrix;
        // color colors[MaxVertices];                          // convert to dynamic array
        List<color> colors;                          
        // edge edge_list[MaxEdges];                           // convert to dynamic array
        List<edge> edge_list;
    public:
        Graph(int number_of_vertices, int start_position);
        Graph();

        void add_vertex(); 
        void add_edge(int to, int from, int weight);
        void print_edges(ostream &ofs);
        int get_edges();
        int get_degree();
        int total_weight();

        Graph MST(int first);

        // overloaded operators
        friend istream& operator >>(istream &ins, Graph &graph);
        friend ostream& operator <<(ostream &ofs, Graph &graph);
        
};


struct element {
    int priority;
    char vertex;
    element *link;
    edge data;
};


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

