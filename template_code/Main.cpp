#include "Edge.h"
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
        return NULL;
    }

    while(!std::cin.eof()){
        int startVertice;
        int endVertice;
        int weight;
        std::cin >> startVertice;
        std::cin >> endVertice;
        std::cin >> weight;
        Edge* newEdge = new Edge(startVertice, endVertice);
        newEdge->setWeight(weight);
        // Here is where you load up the Graph object
        Graph* g = new Graph();
        g->loadGraph(numOfVertices, numOfEdges, edges, edgeCount);

        g->printAdjMatrix();

        int oddNodes[MAX_V];
        int oddcount = g->getOddDegreeNodes(oddNodes);
        g->printOddDegreeNodes(oddNodes, oddCount);

        for (int i = 0; i < oddCount; i++){
            g->dijkstra(oddNodes[i]);
        }

        delete[] edges;
        delete g;
    }

    // And here is where you start working on the three tasks
    return 0;
}