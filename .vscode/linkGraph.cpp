#include "linkGraph.h"
#include "seqStack.h"
#include "seqSTack.cpp"
#include "seqQueue.h"
#include "seqQueue.cpp"

template<class verType, class edgeType>
linkGraph<verType,edgeType>::linkGraph(bool direct){
    this->directed=direct;
    verts=0; edges=0;
    maxVertex=DefaultNumVertex;
    verList=new verNode<verType, edgeType>[maxVertex];
}

template<class verType, class edgeType>
linkGraph<verType, edgeType>::~linkGraph(){
    int i;
    edgeNode<edgeType>* p;
    for (i=0; i<verts; i++){
        while (verList[i].adj){
            p=verList[i].adj;
            verList[i].adj=p->link;
            delete[] p;
        }
    }
    delete[] verList;
}

template<class verType, class edgeType>
void linkGraph<verType, edgeType>::insertEdge(verType vertex1, verType vertex2, edgeType edge){
    int i,j;
    for (i=0; i<verts; i++){
        if (verList[i].data==vertex1){
            break;
        }
    }
    for (j=0; j<verts; j++){
        if (verList[j].data==vertex2){
            break;
        }
    }
    if (i==j){return;}
    if ((i==verts) || (j==verts)){return;}
    edgeNode<edgeType>* tmp=new edgeNode<edgeType>;
    tmp->dest=j;
    tmp->weight=edge;
    tmp->link=verList[i].adj;
    verList[i].adj=tmp;
    if (!directed){
        edgeNode<edgeType>* tmp=new edgeNode<edgeType>;
        tmp->dest=i;
        tmp->weight=edge;
        tmp->link=verList[j].adj;
        verList[j].adj=tmp;
    }
}

template<class verType, class edgeType>
void linkGraph<verType, edgeType>::removeVertex(verType vertex){
    int i, j;
    int count=0;
    edgeNode<edgeType> *p, *q;
    for (i=0; i<verts; i++){
        if (verList[i].data==vertex){
            break;
        }
    }
    if (i==verts){return;}
    p=verList[i].adj;
    while (p){
        verList[i].adj=p->link;
        delete[] p;
        count++;
        p=verList[i].adj;
    }
    for (j=0; j<verts; j++){
        p=verList[j].adj;
        q=NULL;
        while (p){
            if (p->dest==i){break;}
            q=p;
            p=p->link;
        }
        if (!p){continue;}
        if (!q){
            verList[j].adj=p->link;
            delete[] p;
        } else {
            q->link=p->link;
            delete[] p;
        }
        count++;
    }
    for (j=0; j<verts; j++){
        p=verList[j].adj;
        while(p){
            if (p->dest>i){
                p->dest--;
            }
            p=p->link;
        }
    }
    if (directed){
        edges=edges-count;
    } else {
        edges=edges-count/2;
    }
    for (j=i; j<verts-1; j++){
        verList[j]=verList[j+1];
    }
    verts--;
}

template<class verType, class edgeType>
void linkGraph<verType, edgeType>::DFS() const{
    int i;
    bool* visited
    visited=new bool[verts];
    for (i=0; i<verts; i++){
        visited[i]=false;
    }
    for (i=0; i<verts; i++){
        if (!visited[i]){
            DFS(i, visited)
        }
    }
    cout<<endl;
}

template<class verType, class edgeType>
void linkGraph<verType, edgeType>::DFS(int start, bool visited[]) const{
    edgeNode<edgeType>* p;
    cout<<verList[start].data<<'\t';
    visited[start]=true;
    p=verList[start].adj;
    while (p){
        if (!visited[p->dest]){
            DFS(p->dest, visited);
        }
        p=p->link;
    }
}

template<class verType, class edgeType>
void linkGraph<verType, edgeType>::DFS_2() const{
    int i;
    int a;
    seqStack<int> s(maxVertex);
    edgeNode* p
    bool* visited;
    visited=new bool[verts];
    for (i=0; i<verts; i++){
        visited[i]=false;
    }
    for (i=0; i<verts; i++){
        s.push(i)
        while (!s.isEmpty()){
            a=s.top();
            s.pop();
            if (visited[a]){continue;}
            cout<<verList[a].data<<'\t';
            visited[a]=true;
            p=verList[a].adj;
            while (p){
                if (!visited[p->dest]){
                    s.push(p->dest);
                }
                p=p->link;
            }
        }
    }
    cout<<endl;
}

template<class verType, class edgeType>
void linkGraph<verType, edgeType>::BFS() const{
    int i, start;
    edgeNode<edgeType>* p;
    seqQueue<int> que(maxVertex);
    bool* visited=new bool[verts];
    for (i=0; i<verts; i++){
        visited[i]=false;
    }
    for (i=0; i<verts; i++){
        if (visited[i]){continue;}
        que.enQueue(i);
        while (!que.isEmpty()){
            start=que.front();
            p=verList[start].adj;
            cout<<verList[start].data<<'\t';
            visited[start]=true;
            que.deQueue();
            while (p){
                if (!visited[p->dest]){
                    que.enQueue(p->dest);
                }
                p=p->link;
            }
        }
    }
    cout<<endl;
}

template<class verType, class edgeType>
bool linkGraph<verType, edgeType>::connected() const{
    int i, start;
    edgeNode<edgeType>* p;
    seqQueue<int> que(maxVertex);
    bool* visited=new bool[verts];
    int count=0;
    start=0;
    for (i=0; i<verts; i++){
        visited[i]=false;
    }
    que.enQueue(start);
    while (!que.isEmpty()){
        i=que.front();
        que.deQueue();
        visited[i]=true;
        count++;
        p=verList[i].adj;
        while (!p){
            if (!visited[p->dest]){
                que.enQueue(p->dest);
            }
            p=p->link;
        }
    }
    if (count==verts){
        return true;
    } else {
        return false;
    }
}