#include "Graph.hpp"
using namespace std;

int main(){
    int numVertices;
    int numEdges;
    cout << "Enter number of vertices: ";
    cin >> numVertices;
    cout << "Enter number of edges: ";
    cin >> numEdges;

    Graph g(numVertices);
    g.loadGraph(numVertices, numEdges);
    g.print();
    cout << "\nBFS List: ";
    g.BFSL(0);
    g.resetVisited();
    cout << "\nBFS Matrix: ";
    g.BFSM(0);
    g.resetVisited();

    return 0;
}