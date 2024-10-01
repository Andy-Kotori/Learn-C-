#include "linkList.h"

template <class elemType>
linkList<elemType>::linkList(){
    head=new node<elemType>;
}

template <class elemType>
bool linkList<elemType>::isEmpty() const{
    if (head->next==NULL){
        return true;
    }
    return false;
}

template <class elemType>
int linkList<elemType>::length() const{
    int i=0;
    node<elemType>* p=this->head;
    while (p->next){
        i++;
        p=p->next;
    }
    return i;
}

template <class elemType>
void linkList<elemType>::insert(int i, const elemType& e){
    if (i<1){
        return;
    } //向下越界
    int j=0;
    node<elemType>* p=this->head;
    while (p && j<i-1){
        j++;
        p=p->next;
    }
    if (!p){
        return;
    } //向上越界
    p->next=new node<elemType>(e, p->next);
}

template <class elemType>
void linkList<elemType>::remove(int i, elemType& e){
    if (i<1){
        return;
    }
    node<elemType>* p=this->head;
    int j=0
    while (p && j<i-1){
        j++;
        p=p->next;
    }
    if (!p){
        return;
    }
    node<elemType>* q=p->next;
    p->next=q->next;
    delete[] q;
}

template <class elemType>
elemType linkList<elemType>::get(int i) const{
    if (i<1){
        throw outofBound();
    }
    int j=0;
    node<elemType>* p=this->head;
    while (p && j<i){
        j++;
        p=p->next;
    }
    if (!p){
        throw outofBound();
    }
    return p->data;
}

template <class elemType>
int linkList<elemType>::find(const elemType& e) const{
    int j=1;
    node<elemType>* p=head->next;
    while (p && (p->data!=e)){
        j++;
        p=p->next;
    }
    if (!p){
        return 0;
    }
    else{
        return j;
    }
}

template <class elemType>
void linkList<elemType>::clear(){
    node<elemType> *p, *q;
    p=head->next;
    head->next=NULL;
    while (p){
        q=p->next;
        delete[] p;
        p=q;
    }
}

template<class elemType>
void linkList<elemType>::insertlist(const elemType a[], int n){
    node<elemType>* tmp;
    for (int i=0; i<n; i++){
        tmp=new node<elemType>;
        tmp->next=head->next;
        tmp->data=a[i];
        head->next=tmp;
    }
}

template<class elemType>
void linkList<elemType>::reverse(){
    node<elemType>* p;
    node<elemType>* q;
    p=head->next;
    q=p->next;
    p->next=NULL;
    p=q;
    while(p){
        q=p->next;
        p->next=head->next;
        head->next=p;
        p=q;
    }
}

template<class elemType>
linkList<elemType>::~linkList(){}

int main(){
    cout<<"start"<<endl;
    int a[5]={1,2,3,4,5};
    linkList<int> list1;
    list1.insertlist(a, 5);
    for (int i=1; i<=5; i++){
        cout<<list1.get(i)<<" ";
    }
    cout<<endl;
    list1.reverse();
    for (int i=1; i<=5; i++){
        cout<<list1.get(i)<<" ";
    }
    cout<<list1.find(3)<<endl;

}