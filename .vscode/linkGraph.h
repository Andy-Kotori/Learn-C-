#ifndef LINKGRAPH_H
#define LINKGRAPH_H

#define DefaultNumVertex 20

#include<iostream>
using namespace std;

class outofBound{};
template<class edgeType>
struct edgeNode{
    int dest;
    edgeType weight;
    edgeNode* link;
    edgeNode(int d, edgeType w, edgeNode* l){
        dest=d;
        weight=w;
        link=l;
    }
};

template<class verType, class edgeType>
struct verNode{
    verType data;
    edgeNode<edgeType>* adj;
};

struct EulerNode{
    int NodeNum;
    EulerNode* next;
    EulerNode(int ver){
        NodeNum=ver;
        next=NULL;
    }
};

template <class verType, class edgeType>
class linkGraph{
    private:
    bool directed;
    int verts, edges;
    int maxVertex;
    verNode<verType, edgeType>* verList;
    void DFS(int start, bool visited[]) const;
    verNode<verType, edgeType>* clone() const;
    void EulerCircuit(int start, EulerNode *&beg, EulerNode *&end);

    public:
    linkGraph(bool direct);
    ~linkGraph();
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
    void DFS() const;
    void DFS_2() const;
    void BFS() const;
    bool connected() const;
    void Prim() const;
    void Dijikstra(verType start) const;
    void EulerCircuit(verType start);
};




#endif