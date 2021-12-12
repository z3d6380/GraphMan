// Project 3 - GraphMan
// File: Vertex.cpp - Implements the vertex class and its methods
// Written By: Luis Moraguez
// COP4415.02
// Last Modified - 12/3/2021
//

#include "Vertex.h"

// Default Constructor
Vertex::Vertex() {
    this->name = "Test";
}

// Constructor with one parameter
Vertex::Vertex(string const& name) {
    this->name = name;
}

// Constructor with two parameters
Vertex::Vertex(string const& name, vector<Edge*> edges) {
    this->name = name;
    this->edges = edges;
}

// Destructor
Vertex::~Vertex() = default;

// Name Getter and Setter
string Vertex::getName() const {
    return name;
}

void Vertex::setName(string const& name) {
    this->name = name;
}

// Edges Getter and Setter
vector<Edge*>& Vertex::getEdges() {
    return edges;
}

vector<Edge*> const& Vertex::getEdges() const {
    return edges;
}

void Vertex::setEdges(vector<Edge*> const& edges) {
    this->edges = edges;
}

void Vertex::addEdge(Edge* const& edge) {
    edges.push_back(edge);
}

// Overloaded operator<< for when statically allocated
std::ostream &operator<<(std::ostream& out, Vertex& vertex) {
    out << "---------" << endl
        << "|   " << vertex.getName() << "   |" << endl
        << "---------" << endl;

    auto start = vertex.getEdges().cbegin();
    auto end = vertex.getEdges().cend();
    for (auto i = start; i != end; ++i) {
        //out edge with overloaded operator<< in edge class
        out << *i;
    }

    out << "---------" << endl << endl;
    return out;
}

// Overloaded operator<< for when dynamically allocated
std::ostream &operator<<(std::ostream& out, Vertex* vertex) {
    out << "---------" << endl
        << "|   " << vertex->getName() << "   |" << endl
        << "---------" << endl;

    auto start = vertex->getEdges().cbegin();
    auto end = vertex->getEdges().cend();
    for (auto i = start; i != end; ++i) {
        //out edge with overloaded operator<< in edge class
        out << *i;
    }

    out << "---------" << endl << endl;
    return out;
}

// Printing Method(s)
void Vertex::printVertex() {
    cout << *this;
}

// Debugging
#ifndef NDEBUG
void Vertex::testBuilder(string const& test, bool const& hasPassed) const {
    cout << test << "has" << (hasPassed ? "Passed" : "Failed") << endl;
}
#endif