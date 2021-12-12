// Project 3 - GraphMan
// File: main.cpp - Main file
// Written By: Luis Moraguez
// COP4415.02
// Last Modified - 12/5/2021
//

#include <fstream>
#include "graph/Graph.h"

// Global Function Prototypes for Menu
void menu(Graph&);
void choices();

// Global Variable for menu choice
uint16_t choice = 0;
string vertexName;

int main(int argc, char* argv[]) {

    // Program must be called with path to graph input file, otherwise exit.
    if (argc != 2) {
        cerr << "Usage Error: expected graph input file as execution parameter" << endl;
        exit(EXIT_FAILURE);
    }

    // Create ifstream from file provided as execution parameter
    std::ifstream input_file(argv[1]);

    // Check that input file exists, if not, exit with error
    if (!input_file) {
        cerr << "Input file not found." << endl;
        exit(EXIT_FAILURE);
    }

    // Check that input file was opened, if not, exit with error
    if (!input_file.is_open()) {
        cerr << "Unable to open file - '" << argv[1] << "'" << endl;
        exit(EXIT_FAILURE);
    }


    // Declare Graph
    Graph graph(input_file);

    // Load Program Menu
    menu(graph);

    return 0;
}

void menu(Graph& graph) {
    while (choice != 6) {
        choices();

        // Placeholder for possible local variables

        switch(choice) {
            case 1:
                // Shortest path between two nodes

                choice = 0;
                break;
            case 2:
                // Print adjacency list
                graph.printAdjacencyList();
                choice = 0;
                break;
            case 3:
                // Breadth-first search
                cout << endl << "/// Breadth-First Traversal ///" << endl << "Enter name of vertex to start at: ";
                std::cin >> vertexName;
                graph.BFS(vertexName);
                vertexName = "";
                choice = 0;
                break;
            case 4:
                // Depth-first search
                cout << endl << "/// Depth-First Traversal ///" << endl << "Enter name of vertex to start at: ";
                std::cin >> vertexName;
                graph.DFS(vertexName);
                vertexName = "";
                choice = 0;
                break;
            case 5:
                // Depth-first search where the node edges are ordered depending on the increasing degree of the destination node

                choice = 0;
                break;
            case 6:
                // Print graph
                graph.printGraph();
                choice = 0;
                break;
            case 7:
                // Exit
                return;
        }
    }
}

void choices() {
    std::cout << std::endl << "\tWelcome to GraphMan";
    std::cout << std::endl << "\t-------------------" << std::endl;
    std::cout << "Please select one of the following tasks:" << std::endl;
    std::cout << "  [1] Shortest path between two nodes" << std::endl;
    std::cout << "  [2] Print adjacency list" << std::endl;
    std::cout << "  [3] Breadth-first search" << std::endl;
    std::cout << "  [4] Depth-first search" << std::endl;
    std::cout << "  [5] Depth-first search (node edges are ordered depending on the increasing degree of the destination node)" << std::endl;
    std::cout << "  [6] Print Graph" << std::endl;
    std::cout << "  [7] Exit" << std::endl << std::endl;
    std::cout << "  Enter your selection: ";
    std::cin >> choice;
}


