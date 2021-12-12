cmake_minimum_required(VERSION 3.16)
project(GraphMan)

set(CMAKE_CXX_STANDARD 17)

add_executable(GraphMan main.cpp vertex/Vertex.cpp vertex/Vertex.h edge/Edge.cpp edge/Edge.h graph/Graph.cpp graph/Graph.h)
add_executable(TestVertex vertex/TestVertex.cpp vertex/Vertex.cpp vertex/Vertex.h edge/Edge.cpp edge/Edge.h)
add_executable(TestEdge edge/TestEdge.cpp vertex/Vertex.cpp vertex/Vertex.h edge/Edge.cpp edge/Edge.h)
add_executable(TestGraph graph/TestGraph.cpp vertex/Vertex.cpp vertex/Vertex.h edge/Edge.cpp edge/Edge.h graph/Graph.cpp graph/Graph.h)
