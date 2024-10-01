#ifndef LINKSTACK_H
#define LINKSTACK_H

#include<iostream>
using namespace std;

class outofBound{};

template<class elemType>
class linkStack;

template<class elemType>
class node{
    friend class linkStack<elemType>;

    private:
    elemType data;
    node* next;

    public:
    node(){
        next=NULL;
    }
    node(const elemType& e, node* N=NULL){
        data=e;
        next=N;
    }
};

template<class elemType>
class linkStack{
    private:
    node<elemType>* Top;

    public:
    linkStack(){
        Top=NULL;
    }
    bool isEmpty(){
        return (Top==NULL);
    }
    bool isFUll(){
        return false;
    }
    elemType top();
    void push(const elemType& e);
    void pop();
    ~linkStack();
};

#endif