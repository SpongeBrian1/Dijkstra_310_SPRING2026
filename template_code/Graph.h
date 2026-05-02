#ifndef GRAPH_H
#define GRAPH_H

#include "Vertex.h"
#include "Edge.h"
#include <climits>
#define MAX_V 2100

class Graph{
private:
    int adjMatrix[MAX_V][MAX_V]; // This is the adjacency matrix
    Vertex vertices[MAX_V]; //vertex array
    int n; //num of vertices
    int m; //num of edges
    int minDistVertex(int dist[], bool visited[]);

public:
    Graph();

    void loadGraph(int numVerts, int numEdges, Edge* edges, int edgeCount);

    void printAdjMatrix();

    int getOddDegreeNodes(int oddNodesp[]);

    void printOddDegreeNodes(int oddNodes[], int count);

    void dijkstra(int source);
}


#endif