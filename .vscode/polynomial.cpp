#include "polynomial.h"

template <class elemType>
void getStop(elemType& stopFlag){
    int c,e;
    cout<<"give stopFlag:";
    cin>>c>>e;
    stopFlag.coef=c;
    stopFlag.exp=e;
}

template <class elemType>
Polynomial<elemType>::Polynomial(const elemType& stop){
    head=new Node<elemType>;
    stop_flag.coef=stop.coef;
    stop_flag.exp=stop.exp;
}

template <class elemType>
void Polynomial<elemType>::getPoly(){
    cout<<"start getting"<<endl;
    Node<elemType> *tmp, *p;
    p=head;
    elemType e;
    cout<<"input coefs and exps:"<<endl;
    cin>>e.coef>>e.exp;
    while ((e.coef!=stop_flag.coef) && (e.exp!=stop_flag.exp)){
        tmp=new Node<elemType>;
        tmp->next=NULL;
        tmp->data.coef=e.coef;
        tmp->data.exp=e.exp;
        p->next=tmp;
        p=tmp;
        cin>>e.coef>>e.exp;
    }
}

template <class elemType>
void Polynomial<elemType>::disPoly() const{
    cout<<"start displaying"<<endl;
    Node<elemType>* p;
    p=head->next;
    while (p){
        cout<<p->data.coef<<" "<<p->data.exp<<endl;
        p=p->next;   
    }
}

template <class elemType>
void Polynomial<elemType>::length() const{
    int i=0;
    Node<elemType>* p=head;
    while (p->next){
        p=p->next;
        i++
    }
    return i;
}

template <class elemType>
void Polynomial<elemType>::addPoly(const Polynomial& L1, const Polynomial& L2){
    Node<elemType> *p1, *p2, *p, *tmp;
    p=this->head;
    p1=L1.head->next;
    p2=L2.head->next;
    while (true){
        if (!p1 && !p2){
            break;
        }
        if (p1 && p2){
        if (p1->data.exp==p2->data.exp){
            if (p1->data.coef+p2->data.coef==0){
                p1=p1->next;
                p2=p2->next;
            }
            tmp=new Node<elemType>;
            tmp->next=NULL;
            tmp->data.coef=p1->data.coef+p2->data.coef;
            tmp->data.exp=p1->data.exp;
            p->next=tmp;
            p=tmp;
            p1=p1->next;
            p2=p2->next;
        }
        else if (p1->data.exp<p2->data.exp){
            tmp=new Node<elemType>;
            tmp->next=NULL;
            tmp->data.coef=p1->data.coef;
            tmp->data.exp=p1->data.exp;
            p->next=tmp;
            p=tmp;
            p1=p1->next;
        }
        else if (p1->data.exp>p2->data.exp){
            tmp=new Node<elemType>;
            tmp->next=NULL;
            tmp->data.coef=p2->data.coef;
            tmp->data.exp=p2->data.exp;
            p->next=tmp;
            p=tmp;
            p2=p2->next;
        }
        }
        else if (p1 && !p2){
            tmp=new Node<elemType>;
            tmp->next=NULL;
            tmp->data.coef=p1->data.coef;
            tmp->data.exp=p1->data.exp;
            p->next=tmp;
            p=tmp;
            p1=p1->next;
        }
        else if (!p1 && p2){
            tmp=new Node<elemType>;
            tmp->next=NULL;
            tmp->data.coef=p2->data.coef;
            tmp->data.exp=p2->data.exp;
            p->next=tmp;
            p=tmp;
            p2=p2->next;
        }
        cout<<"one time after"<<endl;
        disPoly();
    }
}

int main(){
    Type stop_Flag;
    getStop<Type>(stop_Flag);
    // cout<<stopFlag.coef<<stopFlag.exp<<endl;
    Polynomial<Type> L1(stop_Flag), L2(stop_Flag), L3(stop_Flag);
    L1.getPoly();
    L2.getPoly();
    L1.disPoly();
    L2.disPoly();
    cout<<"start adding"<<endl;
    L3.addPoly(L1, L2);
    L3.disPoly();

    return 0;
}