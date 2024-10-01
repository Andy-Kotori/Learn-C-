#include "Graph.h"
#include "Graph.cpp"
using namespace std;

template<class verType, class edgeType>
void Graph<verType, edgeType>::Floyd() const{
    int i, j, k;
    edgeType** A;
    int** pre;
    A=new edgeType*[verts];
    pre=new int*[verts];
    for (i=0; i<verts; i++){
        A[i]=new edgeType[verts];
        pre[i]=new int[verts];
    }
    for (i=0; i<verts; i++){
        for (j=0; j<verts; j++){
            A[i][j]=edgeMatrix[i][j];
            if (A[i][j]!=noEdge && i!=j){
                pre[i][j]=i;
            } else {
                pre[i][j]=-1;
            }
        }
    }
    for (k=0; k<verts; k++){
        for (i=0; i<verts; i++){
            if (i==k){continue;}
            for (j=0; j<verts; j++){
                if ((j==i) || (j==k)){continue;}
                if (A[i][k]+A[k][j]<A[i][j]){
                    A[i][j]=A[i][k]+A[k][j];
                    pre[i][j]=k;
                }
            }
        }
    }
}