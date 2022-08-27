#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
// #include <math.h>
// #include "linked_list.h"
#include "graph.h"

using namespace std;

const edge null_edge = {-1, -1, 0};

Graph::Graph() {
    degree = 0;
    edges = 0;
    start = 0;
    edge_list.push_back(null_edge);
    edge_list.push_back(null_edge);
}


Graph::Graph(int number_of_vertices, int start_position) {
    vector<color> colorList;
    vector<edge> edgeList;
    vector<vector<int>> matrix;
    int total_edges = (number_of_vertices * (number_of_vertices - 1) / 2);

    for(int i = 0; i < number_of_vertices; i++) {
        vector<int> row;
        for(int j = 0; j < number_of_vertices; j++) {
            row.push_back(0);
        }
        matrix.push_back(row);
        colorList.push_back(White);
    }

    for(int i = 0; i < total_edges; i++) {
        edgeList.push_back(null_edge);
    }

    colors = colorList;
    edge_list = edgeList;
    adjacency_matrix = matrix;
    
    degree = number_of_vertices;
    edges = 0;
    start = start_position;
}


void Graph::add_vertex() {
    degree++;
    
    if(degree == 1) {
        // Instantiate a matrix if this is the first node of the graph
        vector<vector<int>> matrix;
        vector<color> colorList;
        vector<int> row;
        
        row.push_back(0);
        matrix.push_back(row);
        colorList.push_back(White);

        colors = colorList;
        adjacency_matrix = matrix;
    } else {
        // Add a new row to the matrix for the new node
        // adjacency_matrix.push_back(vector<int>(degree, 0));
        vector<int> row;
        for(int i = 0; i < degree; i++) {
            row.push_back(0);
        }
        adjacency_matrix.push_back(row);

        for(int i = 0; i < degree - 1; i++) {
            adjacency_matrix[i].push_back(0);
        }

        colors.push_back(White);

        // here we make the edgelist's size match the degree of the graph. 
        // An undirected, simple graph can have (degree * (degree - 1) / 2) edges.
        // while a graph with less than 2 vertices have 0 edges.
        if(degree == 2) {
            int total_edges = (degree * (degree - 1) / 2);
            vector<edge> edgeList = edge_list;
            
            for(int i = edge_list.size(); i < total_edges; i++) {
                edgeList.push_back(null_edge);
            }
            
            edge_list = edgeList;
        } else {
            int needed_edges = (degree * (degree - 1) / 2) - edge_list.size();
            for(int i = 0; i < needed_edges; i++) {
                edge_list.push_back(null_edge);
            }
        }
    }    
}



void Graph::add_edge(int to, int from, int weight) {
    int end = start + degree - 1;
    edge e;

    if(start <= from && end >= from && start <= to && end >= to) {
        if(adjacency_matrix[from - start][to - start] == 0 && adjacency_matrix[to - start][from - start] == 0) {

            adjacency_matrix[from - start][to - start] = weight;
            adjacency_matrix[to - start][from - start] = weight;

            e.to = to - start;
            e.from = from - start;
            e.weight = weight;
            
            edge_list[edges] = e;
            // cout << "Edge added: " << edge_list[edges].to << " " << edge_list[edges].from << " " << edge_list[edges].weight << endl;
            edges++;
        } else {
            cout << "Cannot add edge where edge already exists" << endl;
            throw;
        }
    } else {
        cout << "Cannot add edge to vertice that does not exist" << endl;
        throw;
    }
}


void Graph::print_edges(ostream &ofs) {
    int to = 0, from = 0;
    ofs << "#:\tFrom:\tTo:\tWeight:" << endl << endl;
    for(int i = 0; i < edges; i++) {
        to = edge_list[i].to;
        from =edge_list[i].from;
        ofs << i+1 << ":\t" 
            << from << ", " << "\t"
            << to   << ", " << "\t" 
            << "Weight = " << edge_list[i].weight << endl;
    }
}


Graph Graph::MST(int first) {
    int V_1 = first, V_2;
    Graph mst(degree, start);
    Queue Q;
    edge e;


    colors[V_1] = Gray;

    e.to = first;
    e.from = ' ';
    e.weight = -1;
    Q.enQueue(e);

    while(!Q.empty()) {
        e = Q.deQueue();
        V_1 = e.to - start;

        if(colors[V_1] != Black) {
            if(e.weight != -1) {
                mst.add_edge(e.to, e.from, e.weight);
            }

            for(V_2 = 0; V_2 < degree; V_2++) {
                if(adjacency_matrix[V_2][V_1] != 0 && colors[V_2] != Black) {
                    colors[V_2] = Gray;
                    e.to = V_2 + start;
                    e.from = V_1 + start;
                    e.weight = adjacency_matrix[V_2][V_1];
                    Q.enQueue(e);
                }
            }
        }

        colors[V_1] = Black;
    }

    // reset colors to white
    for(int i = 0; i < degree; i++) {
        colors[i] = White;
    }

    return mst;
}

Graph Graph::Dijkstra(int first) {
    Graph DJK(degree, start);
    int V_1 = first, V_2;
    vector<int> dist, Q;
    vector<vector<edge>> paths;
    edge e;

    for(int i = 0; i < degree; i++) {
        vector<edge> path;
        paths.push_back(path);
        dist.push_back(2147483647);
        if(i != V_1) {
            Q.push_back(i);
        }
    }

    dist[V_1] = 0;

    for(int i = 0; i < degree; i++) {
        colors[V_1] = Black;
        for(V_2 = 0; V_2 < degree; V_2++) {
            if(adjacency_matrix[V_1][V_2] != 0 && dist[V_2] > dist[V_1] + adjacency_matrix[V_1][V_2]) {
                dist[V_2] = dist[V_1] + adjacency_matrix[V_1][V_2];
                
                e.from = V_1;
                e.to = V_2;
                e.weight = adjacency_matrix[V_1][V_2];

                // now we update the path
                vector<edge> path;
                for(int i = 0; i < (int)paths[V_1].size(); i++) {
                    path.push_back(paths[V_1][i]);
                }
                path.push_back(e);
                paths[V_2] = path;
            }
        }

        // find the vertex with the least distance
        if (Q.size() > 0) {
            int min_vertex = Q[0], index = 0;
            for(int i = 1; i < (int)Q.size(); i++) {
                if(dist[Q[i]] < dist[min_vertex] && colors[Q[i]] != Black) {
                    min_vertex = Q[i];
                    index = i;
                }
            }

            V_1 = min_vertex;
            Q.erase(Q.begin() + index);
        }
    }

    // now we need to add the edges to the graph
    DJK.add_edge(paths[0][0].to, paths[0][0].from, paths[0][0].weight);
    for(int i = 0; i < degree; i++) {
        for(int j = 0; j < (int)paths[i].size(); j++) {
            if(DJK.adjacency_matrix[paths[i][j].to][paths[i][j].from] == 0) {
                DJK.add_edge(paths[i][j].to, paths[i][j].from, paths[i][j].weight);
            }
        }
    }

    // reset colors to white
    for(int i = 0; i < degree; i++) {
        colors[i] = White;
    }

    return DJK;
}

Graph Graph::ShortestPath(int first, int last) {
    Graph DJK(degree, start), Path(degree, start);
    int V_1 = first, V_2;
    vector<int> dist, Q;
    vector<vector<edge>> paths;
    edge e;

    for(int i = 0; i < degree; i++) {
        vector<edge> path;
        paths.push_back(path);
        dist.push_back(2147483647);
        if(i != V_1) {
            Q.push_back(i);
        }
    }

    dist[V_1] = 0;

    for(int i = 0; i < degree; i++) {
        colors[V_1] = Black;
        for(V_2 = 0; V_2 < degree; V_2++) {
            if(adjacency_matrix[V_1][V_2] != 0 && dist[V_2] > dist[V_1] + adjacency_matrix[V_1][V_2]) {
                dist[V_2] = dist[V_1] + adjacency_matrix[V_1][V_2];
                
                e.from = V_1;
                e.to = V_2;
                e.weight = adjacency_matrix[V_1][V_2];

                // now we update the path
                vector<edge> path;
                for(int i = 0; i < (int)paths[V_1].size(); i++) {
                    path.push_back(paths[V_1][i]);
                }
                path.push_back(e);
                paths[V_2] = path;
            }
        }

        // find the vertex with the least distance
        if (Q.size() > 0) {
            int min_vertex = Q[0], index = 0;
            for(int i = 1; i < (int)Q.size(); i++) {
                if(dist[Q[i]] < dist[min_vertex] && colors[Q[i]] != Black) {
                    min_vertex = Q[i];
                    index = i;
                }
            }

            V_1 = min_vertex;
            Q.erase(Q.begin() + index);
        }
    }

    // now we need to add the edges from paths[last] to the Path graph
    for(int i = 0; i < (int)paths[last].size(); i++) {
        Path.add_edge(paths[last][i].to, paths[last][i].from, paths[last][i].weight);
    }

    // reset colors to white
    for(int i = 0; i < degree; i++) {
        colors[i] = White;
    }

    return Path;
}

int Graph::h(int steps, int degree) {
    int x = sqrt(degree) + 1; // assumed number of hops to get to end
    Graph G(degree, start);
    int y = 0;
    if(steps < x) {
        for(int i = 0; i < x - steps; i++) {
            if(i < edges) {
                G.add_edge(edge_list[i].to, edge_list[i].from, edge_list[i].weight);
            }
        }

        // y = G.total_weight();
    }
    
    return y;
}

Graph Graph::AStarSearch(int first, int last) {
    // a heuristic for an undirected graph
    
    Graph DJK(degree, start), Path(degree, start);
    int V_1 = first, V_2;
    vector<int> dist, Q;
    vector<vector<edge>> paths;
    edge e;

    for(int i = 0; i < degree; i++) {
        vector<edge> path;
        paths.push_back(path);
        dist.push_back(2147483647);
        if(i != V_1) {
            Q.push_back(i);
        }
    }

    dist[V_1] = 0;

    for(int i = 0; i < degree; i++) {
        colors[V_1] = Black;
        for(V_2 = 0; V_2 < degree; V_2++) {
            if(adjacency_matrix[V_1][V_2] != 0 && dist[V_2] > dist[V_1] + adjacency_matrix[V_1][V_2]) {
                dist[V_2] = dist[V_1] + adjacency_matrix[V_1][V_2];
                
                e.from = V_1;
                e.to = V_2;
                e.weight = adjacency_matrix[V_1][V_2];

                // now we update the path
                vector<edge> path;
                for(int i = 0; i < (int)paths[V_1].size(); i++) {
                    path.push_back(paths[V_1][i]);
                }
                path.push_back(e);
                paths[V_2] = path;
            }
        }


        // find the vertex with the least distance
        if (Q.size() > 0) {
            int min_vertex = Q[0] , index = 0;
            for(int i = 1; i < (int)Q.size(); i++) {
                if(dist[Q[i]] + h(paths[Q[i]].size(), degree) < dist[min_vertex]  + h(paths[Q[min_vertex]].size(), degree) && colors[Q[i]] != Black) {
                    min_vertex = Q[i];
                    index = i;
                }
            }

            V_1 = min_vertex;
            if(V_1 == last) {
                break;
            }
            Q.erase(Q.begin() + index);
        }
    }

    // now we need to add the edges from paths[last] to the Path graph
    for(int i = 0; i < (int)paths[last].size(); i++) {
        Path.add_edge(paths[last][i].to, paths[last][i].from, paths[last][i].weight);
    }

    // reset colors to white
    for(int i = 0; i < degree; i++) {
        colors[i] = White;
    }

    return Path;
}

/*
    Method gives the first N edges in the graph
        inside a new graph

    Input: int n
    Output: Graph
*/
Graph Graph::firstNEdges(int n) {
    Graph Edges(degree, start);
    if(n > edges) {
        cout << "Error: n is greater than the number of edges in the graph" << endl;
        throw "Error: n is greater than the number of edges in the graph";
    }

    // we go in reverse in case the method is called on the graph it produces later
    for(int i = n - 1; i >= 0; i--) {
        Edges.add_edge(edge_list[i].from, edge_list[i].to, edge_list[i].weight);
    }

    return Edges;
}


int Graph::get_edges() {
    return edges;
}


int Graph::get_degree() {
    return degree;
}


int Graph::total_weight() {
    int sum = 0;

    for(int i = 0; i < edges; i++) {
        sum += edge_list[i].weight;
    }

    return sum;
}


Queue::Queue() {    
    head = new element;
    tail = new element;

    head->link = tail;
    tail->link = NULL;

    head->vertex = ' ';
    tail->vertex = ' ';

    head->priority = 0;
    tail->priority = 9999999;

    _length = 0;
}


int Queue::length() {
    return _length;
}


bool Queue::empty() {
    return head->link == tail;
}


void Queue::enQueue(edge e) {
    element *new_element, *prior, *next;
    bool found = false, keep = true;

    new_element = new element;
    new_element->priority = e.weight;
    new_element->vertex = e.to;
    new_element->data = e;

    next = head->link;
    prior = head;

    // First we make sure the vertext the edge leads 
    // to is not in the queue. if it is in queue
    // delete if priority is lower than new edge
    // else we leave it in there and forget the new edge

    while(next != tail && !found) {
        if(next->vertex == new_element->vertex) {
            found = true;
            if(next->priority > new_element->priority) {
                prior->link = next->link;
                _length--;
                delete next;
            } else {
                // if priority of existing edge 
                // in queue is higher than new one
                // we do not keep the new edge
                keep = false;
            }
        }

        if(!found) {
            prior = next;
            next = next->link;
        }
    }

    if(keep) {
        next = head->link;
        prior = head;

        while(next != tail && next->priority <= new_element->priority) {
            prior = next;
            next = next->link;
        }

        prior->link = new_element;
        new_element->link = next;
        _length++;
    }
}


edge Queue::deQueue() {
    element *c;
    edge e;

    if(empty()) {
        cout << "Cannot dequeue from an empty queue" << endl;
        throw;
    }

    c = head->link;
    e = c->data;
    head->link = c->link;
    delete c;

    return e;
}