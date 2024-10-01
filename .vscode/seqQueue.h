#ifndef SEQQUEUE_H
#define SEQQUEUE_H

#include<iostream>
using namespace std;


template<class elemType>
class seqQueue{
    private:
    elemType* array;
    int Front, Rear;
    int maxSize;
    void doubleSpace();

    public:
    seqQueue(int size);
    bool isEmpty();
    bool isFull();
    elemType front();
    void enQueue(const elemType& e);
    void deQueue();
    int length() const;
    ~seqQueue();

};

#endif