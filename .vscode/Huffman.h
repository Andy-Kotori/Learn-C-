#ifndef HUFFMAN_H
#define HUFFMAN_H

#include<iostream>
#include "seqStack.h"
#include "seqStack.cpp"
using namespace std;

template<class elemType>
struct HuffmanNode{
    elemType data;
    double weight;
    int parent;
    int left, right;
};

template<class elemType>
int minIndex(HuffmanNode<elemType> Bt[], int k, int m){
    int i, min, minWeight=9999;
    for (i=m-1; i>k; i--){
        if (Bt[i].weight<minWeight){
            min=i;
            minWeight=Bt[i].weight;
        }
    }
    return min;
}

template<class elemType>
HuffmanNode<elemType>* BestBinaryTree(elemType a[], double w[], int n){
    HuffmanNode<elemType>* BBTree;
    int first_min, second_min;
    int m, i, j;
    m=2*n;
    BBTree=new HuffmanNode<elemType>[m];
    for (j=0; j<n; j++){
        i=m-1-j;
        BBTree[i].data=a[j];
        BBTree[i].weight=w[j];
        BBTree[i].parent=0;
    }
    i=n-1;
    while (i!=0){
        first_min=minIndex(BBTree, i, m);
        BBTree[first_min].parent=i;
        second_min=minIndex(BBTree, i, m);
        BBTree[second_min].parent=i;
        BBTree[i].parent=0;
        BBTree[i].left=first_min;
        BBTree[i].right=second_min;
        i--;
    }
    return BBTree;
}

template<class elemType>
char** HuffmanCode(HuffmanNode<elemType> BBTree[], int n){
    seqStack<char> s(n+1);
    char** HFCode;
    int parent, child, i, j;
    int m=2*n;
    const char zero='0';
    const char one='1';
    HFCode=new char*[n+1];
    for (i=0; i<n; i++){
        HFCode[i]=new char[n+1];
    }
    if (n==0){return HFCode;}
    if (n==1){
        HFCode[0][0]=zero;
        HFCode[0][1]='\0';
        return HFCode;
    }
    for (i=m-1; i>=n; i--){
        child=i;
        parent=BBTree[child].parent;
        while (parent!=0){
            if (BBTree[parent].left==child){
                s.push(zero);
            } else{
                s.push(one);
            }
            child=parent;
            parent=BBTree[child].parent;
        }
    j=0
    while (!s.isEmpty()){
        HFCode[i-m+1][j]=s.top();
        s.pop();
        j++;
    }
    HFCode[i-m+1][j]='\0';
    }
    return HFCode;
}

#endif