// Project 3 - GraphMan
// File: Edge.cpp - Implements the edge class and its methods
// Written By: Luis Moraguez
// COP4415.02
// Last Modified - 12/4/2021
//

#include "Edge.h"

// Default Constructor
Edge::Edge() {
    this->name = "TE";
    this->source = nullptr;
    this->destination = nullptr;
    this->weight = 0;
}

// Constructor with parameters (pointers to vertex given)
Edge::Edge(string const& name, Vertex* source, Vertex* destination, uint16_t weight) {
    this->name = name;
    this->source = source;
        this->source->addEdge(this);
    this->destination = destination;
    this->weight = weight;
}

// Constructor with parameters (names of vertices given to be created)
Edge::Edge(string const& name, string const& source, string const& destination, uint16_t weight) {
    this->name = name;
    this->source = new Vertex(source);
        this->source->addEdge(this);
    this->destination = new Vertex(destination);
    this->weight = weight;
}

// Destructor
Edge::~Edge() = default;

// Name Getter and Setter
string Edge::getName() const {
    return name;
}

void Edge::setName(string const& name) {
    this->name = name;
}

// Source Getter and Setter
Vertex* Edge::getSource() const {
    return source;
}

void Edge::setSource(Vertex* source) {
    this->source = source;
}

// Destination Getter and Setter
Vertex* Edge::getDestination() const {
    return destination;
}

void Edge::setDestination(Vertex* destination) {
    this->destination = destination;
}

// Weight Getter and Setter
uint16_t Edge::getWeight() const {
    return weight;
}

void Edge::setWeight(uint16_t const& weight) {
    this->weight = weight;
}

// Overloaded operator<< for when statically allocated
std::ostream &operator<<(std::ostream& out, Edge& edge) {
    out << "| " << edge.name << "," << edge.source->getName() << "," << edge.destination->getName() << "," << edge.weight << " |" << endl;
    return out;
}

// Overloaded operator<< for when dynamically allocated or by pointer
std::ostream &operator<<(std::ostream& out, Edge* edge) {
    out << "| " << edge->name << "," << edge->source->getName() << "," << edge->destination->getName() << "," << edge->weight << " |" << endl;
    return out;
}

// Printing Method(s)
void Edge::printEdge() {
    cout << *this;
}

// Debugging
#ifndef NDEBUG
void Edge::testBuilder(string const& test, bool const& hasPassed) const {
    cout << test << "has " << (hasPassed ? "Passed" : "Failed") << endl;
}
#endif













