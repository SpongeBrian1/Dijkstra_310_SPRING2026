#include "Edge.h"

Edge::Edge(){
    this->startVert = -1;
    this->endVert = -1;
    this->weight = -1;
}

Edge::Edge(int start, int end, int w){
    this->startVert = start;
    this->endVert = end;
    this->weight = w;
}

int Edge::getStartVert(){
    return this->startVert;
}

int Edge::getEndVert(){
    return this->endVert;
}

int Edge::getWeight(){
    return this->weight;
}

void Edge::setWeight(int newWeight){
    this->weight = newWeight;
}
