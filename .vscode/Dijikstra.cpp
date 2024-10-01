#include "linkGraph.cpp"
#include "linkGraph.h"

using namespace std;

template <class edgeType> struct DijikstraNode {
    int source;
    int dist;
    bool selected;
};

template <class verType, class edgeType> void linkGraph<verType, edgeType>::Dijikstra(verType start) const {
    DijikstraNode<edgeType> *Dlist;
    int i, j, startInt;
    int cnt;
    int min;
    int dist;
    int noEdge = 9999;
    edgeNode<edgeType> *p;
    for (i = 0; i < verts; i++) {
        if (verList[i] == start) {
            break;
        }
    }
    if (i == verts) {
        return;
    }
    startInt = i;
    Dlist = new DijikstraNode<edgeType>[verts];
    for (i = 0; i < verts; i++) {
        Dlist[i].source = -1;
        Dlist[i].dist = noEdge;
        Dlist[i].selected = false;
    }
    min = startInt;
    cnt = 1;
    Dlist[startInt].source = startInt;
    Dlist[startInt].dist = 0;
    Dlist[startInt].selected = true;
    while (cnt < verts) {
        p = verList[min].adj;
        while (p) {
            if (Dlist[p->dest].selected == false) {
                if (Dlist[min].dist + p->weight < Dlist[p->dest].dist) {
                    Dlist[p->dest].dist = Dlist[min].dist + p->weight;
                    Dlist[p->dest].source = min;
                }
            }
            p = p->link;
        }
        min = -1;
        dist = noEdge;
        for (i = 0; i < verts; i++) {
            if (Dlist[i].selected == true) {
                continue;
            }
            if (Dlist[i].dist < dist) {
                min = i;
                dist = Dlist[i].dist;
            }
        }
        cnt++;
        Dlist[min] = true;
    }
}