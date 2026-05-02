#include "Graph.h"
#include <iostream>
#include <climits>

// Constructor for the adjacency matrix and vertex array
Graph::Graph() {
    this-> = 0;
    this->m = 0;
    for (int i = 0; i < MAX_V; i++) {
        vertices[i].setIndex(i);
        vertices[i].setDegree(0);
        for (int j = 0; j < MAX_V; j++) {
            adjMatrix[i][j] = 0;
        }
    }
}

//populate the adjMatrix and vertex degrees
void Graph::loadGraph(int numVerts, int numEdges, Edge* edges, int edgeCount) {
    this->n = numVerts;
    this->m = numEdges;

    // Initialise vertex indices
    for (int i = 1; i <= n; i++) {
        vertices[i].setIndex(i);
        vertices[i].setDegree(0);
    }

    // Fill adjacency matrix
    for (int k = 0; k < edgeCount; k++) {
        int u = edges[k].getStartVert();
        int v = edges[k].getEndVert();
        int w = edges[k].getWeight();
        adjMatrix[u][v] = w;
        adjMatrix[v][u] = w;
        // Degree: each endpoint gains 1
        vertices[u].incrementDegree();
        vertices[v].incrementDegree();
    }
}

// print part 1
void Graph::printAdjMatrix() {
    std::cout << "The adjacency matrix of G is:" << std::endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            // trailing space after every element, include last
            std::cout << adjMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    // blank line after the matrix
    std::cout << std::endl; 
}

// 
int Graph::getOddDegreeNodes(int oddNodes[]) {
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (vertices[i].getDegree() % 2 != 0) {
            oddNodes[count++] = i;
        }
    }
    // Vertices are already visited 1..n in ascending order, so no sort needed.
    return count;
}

// print part 2
void Graph::printOddDegreeNodes(int oddNodes[], int count) {
    std::cout << "The nodes with odd degrees in G are:" << std::endl;
    std::cout << "O = { ";
    for (int i = 0; i < count; i++) {
        std::cout << oddNodes[i];
        if (i < count - 1) std::cout << " ";
    }
    std::cout << " }" << std::endl;
    // Blank line after odd-degree section
    std::cout << std::endl;
}

// find the nearest unvisited node
int Graph::minDistVertex(int dist[], bool visited[]) {
    int minVal = INT_MAX;
    int minIdx = -1;
    for (int v = 1; v <= n; v++) {
        if (!visited[v] && dist[v] <= minVal) {
            minVal = dist[v];
            minIdx = v;
        }
    }
    return minIdx;
}

// print part 3
void Graph::dijkstra(int source) {
    // dist[v]    = current shortest distance from source to v
    // visited[v] = true once v is finalised (added to the SPT)
    int  dist[MAX_V];
    bool visited[MAX_V];

    for (int i = 1; i <= n; i++) {
        dist[i]    = INT_MAX;
        visited[i] = false;
    }
    dist[source] = 0;

    // Relax n vertices
    for (int iter = 0; iter < n; iter++) {
        // Pick the unvisited vertex with the smallest tentative distance
        int u = minDistVertex(dist, visited);
        if (u == -1) break; // remaining vertices are unreachable
        visited[u] = true;

        // Relax all neighbours of u
        for (int v = 1; v <= n; v++) {
            int w = adjMatrix[u][v];
            if (w != 0 && !visited[v] && dist[u] != INT_MAX) {
                int newDist = dist[u] + w;
                if (newDist < dist[v]) {
                    dist[v] = newDist;
                }
            }
        }
    }

    // Print results
    std::cout << "The shortest path lengths from Node " << source
              << " to all other nodes are:" << std::endl;
    for (int i = 1; i <= n; i++) {
        std::cout << "  " << i << ": " << dist[i] << std::endl;
    }
    // blank line after each Dijkstra block
    std::cout << std::endl; 
}
