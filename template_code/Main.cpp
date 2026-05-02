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

    while(!std::cin.eof()){
        int startVertice;
        int endVertice;
        int weight;
        int edgeCount = 0;
        std::cin >> startVertice;
        std::cin >> endVertice;
        std::cin >> weight;
        Edge* newEdge = new Edge(startVertice, endVertice, weight);
        newEdge->setWeight(weight);
        // Here is where you load up the Graph object
        Graph* g = new Graph();
        g->loadGraph(numOfVertices, numOfEdges, newEdge, edgeCount);

        g->printAdjMatrix();

        int oddNodes[MAX_V];
        int oddCount = g->getOddDegreeNodes(oddNodes);
        g->printOddDegreeNodes(oddNodes, oddCount);

        for (int i = 0; i < oddCount; i++){
            g->dijkstra(oddNodes[i]);
        }

        delete newEdge;
        delete g;
    }

    // And here is where you start working on the three tasks
    return 0;
};