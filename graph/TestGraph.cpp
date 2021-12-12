// Project 3 - GraphMan
// File: TestGraph.cpp - Tests the graph class and its methods
// Written By: Luis Moraguez
// COP4415.02
// Last Modified - 12/4/2021
//

#include "Graph.h"

int main() {

    // Di-graph string
    string digraph =
R"(3
a
b
c
a,b,5
a,c,1
c,b,3)";

    std::istringstream iss(digraph);

    // Declare and Initialize Graph
    Graph testGraph(iss);

    // Getters and Setters Tests
    cout << endl << "/// RUNNING TESTS ///" << endl;
    testGraph.testBuilder("Number of Vertices Getter Test - ", testGraph.getNumVertices() == testGraph.getVertices().size());
    testGraph.testBuilder("Number of Edges Getter Test - ", testGraph.getNumEdges() == testGraph.getEdges().size());

    // Testing Printing Method(s)
    cout << endl << "Testing Printing Methods" << endl;
    testGraph.printGraph();




    return 0;
}
