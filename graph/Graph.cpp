// Project 3 - GraphMan
// File: Graph.cpp - Implements the graph class and its methods
// Written By: Luis Moraguez
// COP4415.02
// Last Modified - 12/4/2021
//

#include "Graph.h"

// Default Constructor
Graph::Graph() {}

// Constructor with istream parameter
Graph::Graph(std::istream& iss) {
    // Variables
    string line;

    // Get first line of file to set number of vertices
    std::getline(iss, line);
    numVertices = atoi(line.c_str());

    // Initialize Adjacency Matrix
    adj.reserve(numVertices);
    vector<int> row;
    row.reserve(numVertices);
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            row.push_back(0);
        }
        adj.push_back(row);
        row.clear();
    }

    // add vertex to vector of vertices in graph
    for (int i = 0; i < numVertices; i++) {
        std::getline(iss, line);
        Vertex vertex(trim(line));
        addVertex(vertex);
    }

    // add edge to edges (in graph) while not EOF
    while (std::getline(iss, line)) {
        char ch;
        std::istringstream sstream(line);
        int i = 0;
        string src;
        string dst;
        uint16_t wgt = 0;
        while (sstream >> std::skipws >> ch) {

            if (i == 0) {
                src = ch;
            }
            else if (i == 2) {
                dst = ch;
            }
            else if (i == 4) {
                wgt = ch - '0';

                Vertex* srcV = getVertexByName(src);
                Vertex* dstV = getVertexByName(dst);
                Edge edge(src+dst,srcV,dstV,wgt);
                addEdge(edge);
                i = 0;
            }
            i++;
        }
    }

}

// Edges Getters and Setters
vector<Edge>& Graph::getEdges() {
    return edges;
}

vector<Edge> const& Graph::getEdges() const {
    return edges;
}

void Graph::addEdge(Edge& e) {
    edges.push_back(e);
    numEdges++;
    adj[getVertexIndex(this->vertices, e.getSource()->getName())][getVertexIndex(this->vertices, e.getDestination()->getName())] = e.getWeight();
}

// Vertices Getters and Setters
vector<Vertex>& Graph::getVertices() {
    return vertices;
}

vector<Vertex> const& Graph::getVertices() const {
    return vertices;
}

Vertex* Graph::getVertexByName(string const& vertex) {
    for (auto i = vertices.begin(); i != vertices.end(); ++i) {
        if (vertex == i->getName()) {
            return &(*i);
        }
    }
    return nullptr;
}

Vertex const* Graph::getVertexByName(string const& vertex) const {
    for (auto i = vertices.begin(); i != vertices.end(); ++i) {
        if (vertex == i->getName()) {
            return &(*i);
        }
    }
    return nullptr;
}

void Graph::addVertex(Vertex& v) {
    vertices.push_back(v);
}

int Graph::getVertexIndex(vector<Vertex>& v, string Key) {
    int i = 0;
    while (i < v.size() && v[i].getName() != Key) {
        i++;
    }
    // found
    if (i < v.size()) {
        return i;
    }
        // not found
    else {
        return -1;
    }
}

int Graph::getVertexIndex(vector<Vertex>& v, string Key) const {
    int i = 0;
    while (i < v.size() && v[i].getName() != Key) {
        i++;
    }
    // found
    if (i < v.size()) {
        return i;
    }
    // not found
    else {
        return -1;
    }
}

// Search/Traversal Methods
// Breadth-first search
void Graph::BFS(string& vertexName) {
    // Index of vertex in vertices
    int index = getVertexIndex(vertices, vertexName);
    // Used for tracking when node is visited
    vector<bool> visited(adj.size(), false);

    // create queue for BFS
    queue<int> queue;

    // mark the current node as visited and enqueue it
    visited[index] = true;
    queue.push(index);

    // iterate through adjacency matrix
    int vis;
    while(!queue.empty()) {
        vis = queue.front();

        // Dequeue a vertex from queue and print it
        vertexName = vertices[queue.front()].getName();
        cout << vertexName << " ";
        queue.pop();

        // Get all the adjacent vertices of the dequeued
        // vertex. If adjacent has not been visited, mark and queue it
        for (int i = 0; i < adj[vis].size(); i++) {
            if (adj[vis][i] > 0 && (!visited[i])) {
                queue.push(i);
                visited[i] = true;
            }
        }
    }
    cout << endl;
}

// Depth-first search
void Graph::DFS(string& vertexName) {
    // Index of vertex in vertices
    int index = getVertexIndex(vertices, vertexName);
    // Used for tracking when node is visited
    vector<bool> visited(adj.size(), false);

    // create stack for DFS
    stack<int> stack;

    // mark the current node as visited and stack it
    visited[index] = true;
    stack.push(index);

    // iterate through adjacency matrix
    int vis;
    while(!stack.empty()) {
        vis = stack.top();

        // Pop a vertex from stack and print it
        vertexName = vertices[stack.top()].getName();
        cout << vertexName << " ";
        stack.pop();

        // Get all the adjacent vertices of the popped
        // vertex. If adjacent has not been visited, mark and stack it
        for (int i = 0; i < adj[vis].size(); i++) {
            if (adj[vis][i] > 0 && (!visited[i])) {
                stack.push(i);
                visited[i] = true;
            }
        }
    }
    cout << endl;
}

// numEdges and numVertices Getters
int Graph::getNumVertices() const {
    return numVertices;
}

int Graph::getNumEdges() const {
    return numEdges;
}

// Text cleaning functions
// Remove whitespace characters from start of record (in place)
void Graph::ltrim(string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));
}

// Remove whitespace characters from end of record (in place)
void Graph::rtrim(string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), s.end());
}

// Remove whitespace characters from both ends of record (in place)
string Graph::trim(string &s) {
    ltrim(s);
    rtrim(s);
    return s;
}

// Printing Method(s)
// Overloaded operator<< for when statically allocated
std::ostream &operator<<(std::ostream& out, Graph& graph) {
    for (int i = 0; i < graph.getVertices().size(); i++) {
        out << "------------\n| Vertex: "<< graph.getVertices()[i].getName() << "|\n------------" << endl;
        int noMatchCount = 0;
        for (int j = 0; j < graph.getEdges().size(); j++) {
            if (graph.getEdges()[j].getSource() == &(graph.getVertices()[i])) {
                out << graph.getEdges()[j];
            } else {
                noMatchCount++;
                if (noMatchCount == graph.getEdges().size()) {
                    out << "|    --    |" << endl;
                }
            }
        }
        out << "------------" << endl;
    }
    return out;
}

// Overloaded operator<< for when dynamically allocated
std::ostream &operator<<(std::ostream& out, Graph* graph) {
    for (int i = 0; i < graph->getVertices().size(); i++) {
        out << "------------\n| Vertex: "<< graph->getVertices()[i].getName() << "|\n------------" << endl;
        int noMatchCount = 0;
        for (int j = 0; j < graph->getEdges().size(); j++) {
            if (graph->getEdges()[j].getSource() == &(graph->getVertices()[i])) {
                out << graph->getEdges()[j];
            } else {
                noMatchCount++;
                if (noMatchCount == graph->getEdges().size()) {
                    out << "|    --    |" << endl;
                }
            }
        }
        out << "------------" << endl;
    }
    return out;
}

void Graph::printGraph() {
    cout << *this;
}

void Graph::printAdjacencyList() {
    cout << "Matrix Form:" << endl;
    for (int i = 0; i < numVertices; i++){
        for (int j = 0; j < numVertices; j++) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl << "List Form:" << endl;
    for (int i = 0; i < numVertices; i++){
        cout << vertices[i].getName() << "->";
        for (int j = 0; j < numVertices; j++) {
            if (adj[i][j] > 0) {
                cout << vertices[j].getName() << " ";
            }
        }
        cout << endl;
    }
}

// Debugging
#ifndef NDEBUG
void Graph::testBuilder(string const& test, bool const& hasPassed) const {
    cout << test << "has " << (hasPassed ? "Passed" : "Failed") << endl;
}
#endif



