#ifndef BSEARCHTREE_H
#define BSEARCHTREE_H

#include<iostream>
#include "seqQueue.h"
#include "seqQueue.cpp"

using namespace std;

template<class elemType>
class binarySearchTree;

template<class elemType>
class Node{
    friend class binarySearchTree<elemType>;
    private:
    elemType data;
    Node* left, *right;
    int factor;

    public:
    Node(){left=right=NULL;}
    Node(const elemType& x, Node* l=NULL, Node* r=NULL){
        data=x;
        left=l;
        right=r;
    }
};

template<class elemType>
class binarySearchTree{
    private:
    Node<elemType>* root;
    bool search(const elemType& x, Node<elemType>* t) const;
    void insert(const elemType& x, Node<elemType>*& t);
    void remove(const elemType& x, Node<elemType>*& t); 

    public:
    binarySearchTree(){root=NULL;}
    bool search(const elemType& x) const;
    void insert(const elemType& x);
    void remove(const elemType& x);
    void levelTravese() const;
};

#endif