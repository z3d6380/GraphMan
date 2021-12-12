// Project 3 - GraphMan
// File: Edge.h - Prototypes the edge class and its methods
// Written By: Luis Moraguez
// COP4415.02
// Last Modified - 12/4/2021
//

#ifndef GRAPHMAN_EDGE_H
#define GRAPHMAN_EDGE_H

#pragma once
#include <iostream>
#include <string>
#include "../vertex/Vertex.h"

using std::string; using std::cout;
using std::cerr; using std::endl;

class Vertex;

class Edge {
private:
    string name;
    Vertex *source;
    Vertex *destination;
    uint16_t weight;

public:
    // Default Constructor
    Edge();

    // Constructor with parameters (pointers to vertex given)
    Edge(string const&, Vertex*, Vertex*, uint16_t);

    // Constructor with parameters (names of vertices given to be created)
    Edge(string const&, string const&, string const&, uint16_t);

    // Destructor
    ~Edge();

    // Name Getter and Setter
    string getName() const;
    void setName(string const& name);

    // Source Getter and Setter
    Vertex* getSource() const;
    void setSource(Vertex* source);

    // Destination Getter and Setter
    Vertex* getDestination() const;
    void setDestination(Vertex* destination);

    // Weight Getter and Setter
    uint16_t getWeight() const;
    void setWeight(uint16_t const& weight);

    // Overloaded operator<< for when statically allocated
    friend std::ostream &operator<< (std::ostream&, Edge&);

    // Overloaded operator<< for when dynamically allocated
    friend std::ostream &operator<< (std::ostream&, Edge*);

// Printing Method(s)
    void printEdge();

// Debugging
#ifndef NDEBUG
    void testBuilder(string const&, bool const&) const;
#endif
};


#endif //GRAPHMAN_EDGE_H
