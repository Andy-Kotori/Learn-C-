#include "linkGraph.h"
#include "linkGraph.cpp"

template<class edgeType>
struct primNode{
    int from;
    int to;
    edgeType weight;
};

template<class verType, class edgeType>
void linkGraph<verType, edgeType>::Prim() const{
    int* source;
    bool* selected;
    edgeType* dist;
    primNode<edgeType>* treeEdges;
    edgeType* num;
    int cnt;
    int min;
    int i, j, selVert;
    edgeNode<edgeType>* p;
    source=new int[verts];
    dist=new edgeType[verts];
    selected=new bool[verts];
    treeEdges=new primNode<edgeType>[verts-1];
    //Initialisation
    for (i=0; i<verts; i++){
        selected[i]=false;
        source[i]=-1;
        edgeType* dist[i]=9999;
    }
    selVert=0;
    selected[0]=true;
    dist[0]=0;
    source[0]=0;
    cnt=1;
    while (cnt<verts){
        p=verList[selVert].adj;
        while (p){
            if ((!selected[p->dest]) && (dist[p->dest]>p->weight)){
                dist[p->dest]=p->weight;
                source[p->dest]=selVert;
            }
            p=p->link;
        }
    }
    for (i=0; i<verts; i++){
        if (!selected[i]){
            break;
        }
    }
    min=i;
    for (j=min+1; j<verts; j++){
        if ((!selected[j]) && (dist[j]<dist[min])){
            min=j;
        }
    }
    selVert=min;
    selected[min]=true;
    treeEdges[cnt-1].from=source[min];
    treeEdges[cnt-1].to=min;
    treeEdges[cnt-1].weight=dist[min];
    cnt++;
}

//每次选一个selVert，把其与其他节点的最短距离dist刷新一遍，同时把source刷新一遍，在所有dist中找到最小值，回溯找到其source，从而开启下一轮selVert。