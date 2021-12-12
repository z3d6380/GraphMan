// Project 3 - GraphMan
// File: Graph.h - Prototypes the graph class and its methods
// Written By: Luis Moraguez
// COP4415.02
// Last Modified - 12/4/2021
//

#ifndef GRAPHMAN_GRAPH_H
#define GRAPHMAN_GRAPH_H

#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include "../edge/Edge.h"
#include "../vertex/Vertex.h"

using std::string; using std::vector; using std::queue; using std::stack;
using std::cout; using std::cerr; using std::endl;

class Graph {
private:
    vector<Edge> edges;
    vector<Vertex> vertices;

    // Variables
    int numEdges = 0;
    int numVertices = 0; // default

    // AdjacencyMatrix
    vector<vector<int>> adj;


public:
    // Default Constructor
    Graph();

    // Constructor with istream parameter
    Graph(std::istream&);

    // Edges Getter and Setter
    vector<Edge>& getEdges(); // mutator
    vector<Edge> const& getEdges() const; // inspector
    void addEdge(Edge&);


    // Vertices Getter and Setter
    vector<Vertex>& getVertices(); //mutator
    vector<Vertex> const& getVertices() const; // inspector
    Vertex* getVertexByName(string const&); //mutator
    Vertex const* getVertexByName(string const&) const; //inspector
    void addVertex(Vertex&);
    int getVertexIndex(vector<Vertex>&, string);
    int getVertexIndex(vector<Vertex>&, string) const;

    // numEdges and numVertices Getters
    int getNumEdges() const;
    int getNumVertices() const;

// Search/Traversal Methods
    // Breadth-first search
    void BFS(string&);
    // Depth-first search
    void DFS(string&);

    // Text cleaning functions
    void ltrim(string&);
    void rtrim(string&);
    string trim(string&);

    // Printing Method(s)
    // Overloaded operator<< for when statically allocated
    friend std::ostream &operator<< (std::ostream&, Graph&);

    // Overloaded operator<< for when dynamically allocated
    friend std::ostream &operator<< (std::ostream&, Graph*);

    void printGraph();
    void printAdjacencyList();

// Debugging
#ifndef NDEBUG
    void testBuilder(string const&, bool const&) const;
#endif
};


#endif //GRAPHMAN_GRAPH_H
