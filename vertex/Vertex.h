// Project 3 - GraphMan
// File: Vertex.h - Prototypes the vertex class and its methods
// Written By: Luis Moraguez
// COP4415.02
// Last Modified - 12/3/2021
//

#ifndef GRAPHMAN_VERTEX_H
#define GRAPHMAN_VERTEX_H

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "../edge/Edge.h"

using std::string; using std::vector;
using std::cout; using std::cerr; using std::endl;

class Edge;

class Vertex {
private:
    string name;
    vector<Edge*> edges;

public:
    // Default Constructor
    Vertex();

    // Constructor with one parameter
    Vertex(string const&);

    // Constructor with two parameters
    Vertex(string const&, vector<Edge*>);

    // Destructor
    ~Vertex();

    // Name Getter and Setter
    string getName() const;
    void setName(const string &name);

    // Edges Getter and Setter
    vector<Edge*>& getEdges(); // mutator
    vector<Edge*> const& getEdges() const; // inspector
    void setEdges(vector<Edge*> const& edges);
    void addEdge(Edge* const& edge);

    // Overloaded operator<< for when statically allocated
    friend std::ostream &operator<< (std::ostream&, Vertex&);

    // Overloaded operator<< for when dynamically allocated
    friend std::ostream &operator<< (std::ostream&, Vertex*);

// Printing Method(s)
    void printVertex();

// Debugging
#ifndef NDEBUG
    void testBuilder(string const&, bool const&) const;
#endif
};

#endif //GRAPHMAN_VERTEX_H
