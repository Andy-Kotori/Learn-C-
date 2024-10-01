#ifndef LINKQUEUE_H
#define LINKQUEUE_H

#include<iostream>
using namespace std;

class outofBound{};
class illegalSize{};

template<class elemType>
class linkQueue;

template<class elemType>
class Node{
    friend class linkQueue<elemType>;
    private:
    elemType data;
    Node* next;

    public:
    Node(){
        next=NULL;
    }
    Node(const elemType& e, Node* N){
        data=e;
        next=N;
    }
};

template<class elemType>
class linkQueue{
    private:
    Node<elemType>* Front;
    Node<elemType>* Rear;

    public:
    linkQueue(){
        Front=NULL;
        Rear=NULL;
    }
    bool isEmpty(){
        return !Front;
    }
    bool isFull(){
        return false;
    }
    elemType front() const{
        if (isEmpty()){
            throw class outofBound();
        }
        else{
            return Front->data;
        }
    }
    void enQueue(const elemType& e){
        if (!Rear){
            Node<elemType>* tmp=new Node<elemType>;
            tmp->data=e;
            Front=tmp;
            Rear=tmp;
        }
        else{
        Node<elemType>* tmp=new Node<elemType>;
        tmp->data;
        Rear->next=tmp;
        Rear=tmp;
        }
    }
    void deQueue(){
        if (isEmpty()){
            throw outofBound();
        }
        Node<elemType>* tmp=Front;
        Front=Front->next;
        delete[] tmp;
        if (!Front){
            Rear=NULL;
        }
    }
    int length(){
        if (isEmpty()){
            return 0;
        }
        int count=1;
        Node<elemType>* p=Front;
        while (p){
            p=p->next;
            count++;
        }
        return count;
    }
    ~linkQueue(){
        Node<elemType>* p=Front;
        while (Front){
            Front=Front->next;
            delete[] p;
            p=Front;
        }
        Rear=NULL;
    }
};

#endif