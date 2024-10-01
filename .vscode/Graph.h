#ifndef GRAPH_H
#define GRAPH_H

#define DefaultNumVertex 20

#include<iostream>
using namespace std;

class outofBound{};
template<class verType, class edgeType>
class Graph{
    private:
    int verts, edges;
    int maxVertex;
    verType* verList;
    edgeType** edgeMatrix;
    edgeType noEdge;
    bool directed;

    public:
    Graph(bool direct, edgeType noEdge);
    ~Graph();
    int numberOfVertex() const {return verts;}
    int numberOfEdge() const {return edges;}
    int getVertex(verType vertex) const;
    bool existEdge(verType vertex1, verType vertex2) const;
    void insertVertex(verType vertex);
    void insertEdge(verType vertex1, verType vertex2, edgeType edge);
    void removeVertex(verType vertex);
    void removeEdge(verType vertex1, verType vertex2);
    int getFirstNeighbor(verType vertex) const;
    int getNextNeighbor(verType vertex1, verType vertex2) const;
    void disp() const;
    void Floyd() const;
    void topoSort() const;
    void keyActivity(verType start, verType end) const;
};

#endif