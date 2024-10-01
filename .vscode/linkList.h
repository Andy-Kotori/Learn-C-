#ifndef LINKLIST_H
#define LINKLIST_H

#include<iostream>
using namespace std;

class outofBound{};

template <class elemType>
class linkList;

template <class elemType>
class node{
    friend class linkList<elemType>;

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

template <class elemType>
class linkList{
    private:
    node<elemType>* head;

    public:
    linkList();
    bool isEmpty() const;
    bool isFull() const {
        return false;
    }
    int length() const;
    elemType get(int i) const;
    int find(const elemType& e) const;
    void insert(int i, const elemType& e);
    void insertlist(const elemType a[], int n);
    void output() const;
    void remove(int i, elemType& e);
    void reverse();
    void clear();
    ~linkList();
};

#endif