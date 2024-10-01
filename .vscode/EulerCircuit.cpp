#include "linkGraph.h"
#include "linkGraph.cpp"


template<class verType, class edgeType>
verNode<verType, edgeType>* linkGraph<verType, edgeType>::clone() const{
    verNode* tmp=new verNode[verts];
    edgeType* p;
    for (int i=0; i<this->verts; i++){
        tmp[i]=verList[i];
        p=verList[i].adj;
        // tmp[i].adj=new edgeNode(p->dest, p->weight, NULL);
        // q=tmp[i].adj;
        // p=p->next;
        while (p){
            tmp[i].adj=new edgeNode(p->dest, p->weight, tmp[i].adj);
            p=p->link;
        }
    }
    return tmp;
}

template<class verType, class edgeType>
void linkGraph<verType, edgeType>::EulerCircuit(int start, EulerNode *&beg, EulerNode *&end){
    int nextNode;
    beg=end=new EulerNode(start);
    while (verList[start].adj!=NULL){
        nextNode=verList[start].adj->dest;
        removeEdge(start, nextNode);
        removeEdge(nextNode, start);
        start=nextNode;
        end->next=new EulerNode(start);
        end=end->next;
    }
}

template<class verType, class edgeType>
void linkGraph<verType, edgeType>::EulerCircuit(verType start){
    EulerNode *beg, *end, *p, *q, *tb, *te;
    int numofDegree;
    edgeNode* r;
    verNode* tmp;
    if (this->edges==0){
        cout<<"no EulerCircuit"<<endl;
        return;
    }
    for (i=0; i<verts; i++){
        numofDegree=0;
        r=verList[i].adj;
        while (r){
            numofDegree++;
            r=r->link;
        }
        if (numofDegree%2){
            cout<<"no EulerCircuit"<<endl;
            return;
        }
    }
    for (i=0; i<verts; i++){
        if (verList[i]==start){
            break;
        }
    }
    if (i==verts){return;}
    tmp=clone();
    EulerCircuit(i, beg, end);
    while (true){
        p=beg;
        while (p){
            if (verList[p->next->NodeNum].adj!=NULL){
                break;
            } else {
                p=p->next;
            }
        }
        if (p->next==NULL){break;}
        q=p->next;
        EulerCircuit(q->NodeNum, tb, te);
        te->next=q->next;
        p->next=tb;
        delete p;
    }
    delete[] verList;
    verList=tmp;
    cout<<"EulerCircuit:"<<endl;
    while (beg!=NULL){
        cout<<verList[beg->NodeNum].data<<" ";
        p=beg;
        beg=beg->next;
        delete p;
    }
    cout<<endl;
}
