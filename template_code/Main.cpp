#include "Edge.h"
#include "Graph.h"
#include <iostream>

int main(){

    // start of the initial pipeline that loads the test case file stream from std::cin

    int numOfVertices = 0;
    int numOfEdges = 0;

    if(!std::cin.eof()){
        std::cin >> numOfVertices;
        std::cin >> numOfEdges;
    }
    else{
        std::cout<<"Input not found!"<<std::endl;
        return 1;
    }

    // Here is where you load up the Graph object
    Edge* edges = new Edge[numOfEdges];
    int edgeCount = 0;

    while(!std::cin.eof() && edgeCount < numOfEdges){
        int startVertice;
        int endVertice;
        int weight;
        std::cin >> startVertice;
        std::cin >> endVertice;
        std::cin >> weight;
        edges[edgeCount] = Edge(startVertice, endVertice, weight);
        edgeCount++;
    }

    Graph* g = new Graph();
    g->loadGraph(numOfVertices, numOfEdges, edges, edgeCount);

    // And here is where you start working on the three tasks
    g->printAdjMatrix();

    int oddNodes[MAX_V];
    int oddCount = g->getOddDegreeNodes(oddNodes);
    g->printOddDegreeNodes(oddNodes, oddCount);

    for (int i = 0; i < oddCount; i++){
        g->dijkstra(oddNodes[i]);
    }

    delete[] edges;
    delete g;
    return 0;
}