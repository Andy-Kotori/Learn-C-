#ifndef BTREE_H
#define BTREE_H

#include<iostream>
#include "seqStack.h"
#include "seqQueue.h"
#include "seqSTack.cpp"
#include "seqQueue.cpp"
using namespace std;

template<class elemType>
class BTree;

template<class elemType>
class Node{
    friend class BTree<elemType>;
    private:
    elemType data;
    Node *left, *right;
    int leftFlag=0, rightFlag=0;

    public:
    Node(){
        left=right=NULL;
        leftFlag=rightFlag=0;
    }
    Node(const elemType& e, Node* L=NULL, Node* R=NULL){
        data=e;
        left=L;
        right=R;
    }
};

template<class elemType>
class BTree{
    private:
    Node<elemType>* root;
    elemType stopFlag;
    int Size(Node<elemType>* t);
    int Height(Node<elemType>* t);
    void DelTree(Node<elemType>* t);
    void PreOrder(Node<elemType>* t);
    void InOrder(Node<elemType>* t);
    void PostOrder(Node<elemType>* t);

    public:
    BTree(){root=NULL;}
    void createTree(const elemType& flag);
    bool isEmpty(){return (root==NULL);}
    Node<elemType>* GetRoot(){return root;}
    int Size();
    int Height();
    void DelTree();
    void PreOrder();
    void PreOrder_2();
    void InOrder();
    void InOrder_2();
    void PostOrder();
    void PostOrder_2();
    void LevelOrder();
    Node<elemType>* TreadMid();
    void ThreadMidVisit(Node<elemType> *first);
    void ThreadMidPreVIsit();
    Node<elemType>* buildTree(elemType pre[], elemType min[], int pl, int pr, int ml, int mr);
};

#endif