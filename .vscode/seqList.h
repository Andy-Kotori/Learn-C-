#ifndef SEQLIST_H
#define SEQLIST_H

#include<bits/stdc++.h>
#define initSize 100
using namespace std;

class illegalSize{};
class outofBound{};

template <class elemType>
class seqList{
    private:
    elemType* elem;
    int len; //list length
    int maxSize; //max list length
    void doubleSpace();

    public:
    seqList(int size);
    bool isEmpty() const {
        return (this->len==0);
    }
    bool isFull() const {
        return (this->len==maxSize);
    }
    int length() const {
        return this->len;
    }
    elemType get(int i) const;  //返回第i个元素的值
    int find(const elemType& e) const;  //返回元素e的位置
    void insert(int i, const elemType& e);  //插入e
    void remove(int i, const elemType& e);  //移除i处的e
    void clear(){
        this->len=0;
    } //清除数据表
    ~seqList(){
        delete[] elem;
    } //析构
};

#endif