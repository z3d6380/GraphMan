// Project 3 - GraphMan
// File: TestEdge.cpp - Tests the edge class and its methods
// Written By: Luis Moraguez
// COP4415.02
// Last Modified - 12/4/2021
//

#include "Edge.h"

int main() {

    // Declare and Initialize Edge and Vertex objects
    Edge testEdge1;
    Vertex testVertex1("Src");
    Vertex testVertex2("Dst");

    // Getters and Setters Tests
    cout << endl << "/// RUNNING TESTS ///" << endl;
    testEdge1.testBuilder("Name Getter Test - ", testEdge1.getName() == "TE");
    testEdge1.testBuilder("Source Getter Test - ", testEdge1.getSource() == nullptr);
    testEdge1.testBuilder("Destination Getter Test - ", testEdge1.getDestination() == nullptr);
    testEdge1.testBuilder("Weight Getter Test - ", testEdge1.getWeight() == 0);
    cout << endl;
    testEdge1.setName("e1");
    testEdge1.setSource(&testVertex1);
    testEdge1.setDestination(&testVertex2);
    testEdge1.setWeight(4);
    testEdge1.testBuilder("Name Setter Test - ", testEdge1.getName() == "e1");
    testEdge1.testBuilder("Source Setter Test - ", testEdge1.getSource() == &testVertex1);
    testEdge1.testBuilder("Destination Setter Test - ", testEdge1.getDestination() == &testVertex2);
    testEdge1.testBuilder("Weight Setter Test - ", testEdge1.getWeight() == 4);

    // Testing Printing Method(s)
    cout << endl << "Testing Printing Methods" << endl;
    cout << testEdge1;
    testEdge1.printEdge();


    return 0;
}
