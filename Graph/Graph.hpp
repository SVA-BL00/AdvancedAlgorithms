#ifndef GRAPH_HPP
#define GRAPH_HPP
#include <iostream>
#include <list>
#include <time.h>

class Graph {
public:
    Graph(int);

    ~Graph() {
        delete[] adjList;
        for (int i = 0; i < numVertices; i++) {
            delete[] adjMatrix[i];
        }
        delete[] adjMatrix;
        delete[] visited;
    }

    void addEdge(int, int);
    void print();
    void loadGraph(int, int);
    void resetVisited();
    void BFSL(int);
    void BFSM(int);

private:
    int numVertices, numEdges;
    std::list<int>* adjList;
    bool** adjMatrix;
    bool *visited;
};

#endif