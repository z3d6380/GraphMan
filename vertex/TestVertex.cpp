// Project 3 - GraphMan
// File: TestVertex.cpp - Tests the vertex class and its methods
// Written By: Luis Moraguez
// COP4415.02
// Last Modified - 12/4/2021
//

#include "Vertex.h"

int main() {

    // Declare and Initialize Vertex and Edge objects
    Edge testEdge1("e1", "a", "dst", 5);
    Vertex* testVertex1 = testEdge1.getSource();
    Vertex* testVertex2 = testEdge1.getDestination();
    Vertex testVertex3("c");
    Edge testEdge3("e3", testVertex1, &testVertex3, 2);
    //testVertex1->addEdge(&testEdge3);

    // Getters and Setters Tests
    cout << endl << "/// RUNNING TESTS ///" << endl;
    testVertex1->testBuilder("Name Getter Test - ", testVertex1->getName() == "a");
    testVertex1->testBuilder("Edges Getter Test - ", !testVertex1->getEdges().empty());
    cout << endl;
    testVertex2->setName("b");
    Edge testEdge2("e2", testVertex2, testVertex1, 1);
    //vector<Edge*> edgesTest;
    //edgesTest.push_back(&testEdge2);
    //testVertex2->setEdges(edgesTest);
    testVertex2->testBuilder("Name Setter Test - ", testVertex2->getName() == "b");
    testVertex2->testBuilder("Edges Setter Test - ", !testVertex2->getEdges().empty());

    // Testing Printing Method(s)
    cout << endl << "Testing Printing Methods" << endl;
    cout << testVertex1;
    testVertex2->printVertex();
    testVertex3.printVertex();

    return 0;
}