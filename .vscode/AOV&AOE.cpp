#include "Graph.h"
#include "Graph.cpp"
#include "seqStack.h"
#define MAXSTACK 99
using namespace std;

template<class verType, class edgeType>
void Graph<verType, edgeType>::topoSort() const{
    int* inDegree;
    seqStack<int> s(MAXSTACK);
    int i, j;
    inDegree=new int[verts];
    for (j=0; j<verts; j++){
        inDegree[j]=0;
        for (i=0; i<verts; i++){
            if (i!=j && edgeMatrix[i][j]!=noEdge){
                inDegree[j]++;
            }
        }
        if (inDegree[j]==0){
            s.push(j);
        }
    }
    while (!s.isEmpty()){
        i=s.top();
        s.pop();
        cout<<i<<" ";
        for (j=0; j<verts; j++){
            if (j!=i && edgeMatrix[i][j]!=noEdge){
                inDegree[j]--;
                if (inDegree[j]==0){
                    s.push(j);
                }
            }
        }
    }
    cout<<endl;
}

template<class edgeType>
struct keyEdge{
    int u, v;
    edgeType weight;
    edgeType early, last;
};

template<class verType, class edgeType>
void Graph<verType, edgeType>::keyActivity(verType start, verType end) const{
    int* inDegree;
    edgeType* verEarly, verLast;
    keyEdge<edgeType>* edgeEL;
    seqStack<int> s1(MAXSTACK);
    seqStack<int> s2(MAXSTACK);
    int i, j, k;
    int u, v;
    int intStart, intEnd;
    inDegree=new int[verts];
    verEarly=new edgeType[verts];
    verLast=new edgeType[verts];
    edgeEL=new keyEdge<edgeType>[edges];
    intStart=intEnd=-1;
    for (i=0; i<verts; i++){
        if (verList[i]==start){intStart=i;}
        if (verList[i]==end){intEnd=i;}
    }
    for (j=0; j<verts; j++){
        inDegree[j]=0;
        for (i=0; i<verts; i++){
            if (j!=i && edgeMatrix[i][j]!=noEdge){
                inDegree[j]++;
            }
        }
    }
    for (i=0; i<verts; i++){
        verEarly[i]=0;
    }
    verEarly[intStart]=0;
    s1.push(intStart);
    s2.push(intStart);
    i=intStart;
    while (i!=intEnd){
        for (j=0; j<verts; j++){
            if (i!=j && edgeMatrix[i][j]!=noEdge){
                inDegree[j]--;
                if (inDegree[j]==0){
                    s1.push(j);
                }
                if (verEarly[j]<verEarly[i]+edgeMatrix[i][j]){
                    verEarly[j]=verEarly[i]+edgeMatrix[i][j];
                }
            }
        }
        i=s1.top();
        s1.pop();
        s2.push(i);
    }
    for (i=0; i<verts; i++){
        verLast[i]=verEarly[intEnd];
    }
    while (!s2.isEmpty()){
        j=s2.top();
        s2.pop();
        for (i=0; i<verts; i++){
            if (i!=j && edgeMatrix[i][j]!=noEdge){
                if (verLast[i]>verLast[j]-edgeMatrix[i][j]){
                    verLast[i]=verLast[j]-edgeMatrix[i][j];
                }
            }
        }
    }
    k=0;
    for (i=0; i<verts; i++){
        for (j=0; j<verts; j++){
            if (i!=j && edgeMatrix[i][j]!=noEdge){
                edgeEL[k].u=i;
                edgeEL[k].v=j;
                edgeEL[k].weight=edgeMatrix[i][j];
                edgeEL[k].early=verEarly[i];
                edgeEL[k].last=verLast[j]-edgeMatrix[i][j];
                k++;
            }
        }
    }
    cout<<"AOE:"<<endl;
    for (k=0; k<edges; k++){
        if (edgeEL[k].early==edgeEL[k].last){
            u=edgeEL[k].u;
            v=edgeEL[k].v;
            cout<<verList[u]<<"->"<<verList[v]<<endl;
            cout<<"early: "<<edgeEL[k].early<<"  "
                <<"last: "<<edgeEL[k].last;
            cout<<endl<<endl;
        }
    }
}