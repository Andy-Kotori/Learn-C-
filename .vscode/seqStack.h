#ifndef SEQSTACK_H
#define SEQSTACK_H

#include<iostream>
using namespace std;

class illegalSize{};

template <class elemType>
class seqStack{
    private:
    elemType* array;
    int maxSize;
    int Top;
    void doubleSpace();

    public:
    seqStack(int size);
    bool isEmpty() const{
        return (Top==-1);
    }
    bool isFull() const{
        return (Top==maxSize-1);
    }
    elemType top() const;
    void push(const elemType& e);
    void pop();
    ~seqStack(){
        delete[] array;
    }
};

#endif