#ifndef EDGE_H
#define EDGE_H

class Edge{
    private:
        int startVert;
        int endVert;
        int weight;
    public:
        Edge();
        Edge(int start, int end, int w);
        int getWeight();
        int getStartVert();
        int getEndVert();
        void setWeight(int newWeight);
};


#endif