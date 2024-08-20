#include "Graph.hpp"

Graph::Graph(int V) {
        numVertices = V;
        numEdges = 0;
        visited = new bool[V];
        adjList = new std::list<int>[V];
        adjMatrix = new bool*[V];
        for (int i = 0; i < V; i++) {
            adjMatrix[i] = new bool[V];
            for (int j = 0; j < V; j++) {
                adjMatrix[i][j] = false;
            }
        }
}

void Graph::print() {
    for (int i = 0; i < numVertices; i++) {
        std::cout << "Vertex " << i << ": ";
        for (auto j : adjList[i]) {
            std::cout << "-> " << j;
        }
        std::cout << std::endl;
    }
    std::cout << "\nAdjacency Matrix:" << std::endl;
    for (int i = 0; i < numVertices; i++) {
        std::cout << "Vertex " << i << ": ";
        for (int j = 0; j < numVertices; j++) {
            std::cout << adjMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void Graph::addEdge(int u, int v) {
    adjList[u].push_back(v);
    adjList[v].push_back(u);
    adjMatrix[u][v] = true;
    adjMatrix[v][u] = true;
}

void Graph::loadGraph(int numVertices, int numEdges) {
    srand(time(NULL));
    for (int i = 0; i < numEdges;) {
        int u = rand() % numVertices;
        int v = rand() % numVertices;
        if (u != v && adjMatrix[u][v] == false) {
            addEdge(u, v);
            i++;
        }
    }
}

void Graph::resetVisited(){
    for (int i = 0; i < numVertices; i++) {
        visited[i] = false;
    }
}

void Graph::BFSL(int v) {
    visited[v] = true;
    std::list<int> Q;
    Q.push_back(v);
    while (!Q.empty()) {
        int currentV = Q.front();
        std::cout << currentV << " ";
        Q.pop_front();
        for (auto i : adjList[currentV]) {
            if (!visited[i]) {
                visited[i] = true;
                Q.push_back(i);
            }
        }
    }
}

void Graph::BFSM(int v) {
    visited[v] = true;
    std::list<int> Q;
    Q.push_back(v);
    while (!Q.empty()) {
        int currentV = Q.front();
        std::cout << currentV << " ";
        Q.pop_front();
        for (int i = 0; i < numVertices; i++) {
            if (adjMatrix[currentV][i] && !visited[i]) {
                visited[i] = true;
                Q.push_back(i);
            }
        }
    }
}