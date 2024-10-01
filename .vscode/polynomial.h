#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include<iostream>
using namespace std;

struct Type{
    int coef; //系数
    int exp; //幂指数
};

template<class elemType>
struct Node{
    elemType data;
    Node* next;
};

template<class elemType>
struct Polynomial{
    private:
    Node<elemType>* head;
    elemType stop_flag;
    public:
    Polynomial(const elemType& stop); //读取结束标志并初始化
    void getPoly(); //读入
    void addPoly(const Polynomial& L1, const Polynomial& L2);
    void disPoly() const;
    void length() const;
    // void clear();
    // ~Polynomial(){
    //     clear();
    //     delete[] head;
    // }
};

#endif