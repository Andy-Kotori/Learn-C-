#ifndef SEQQUEUE_CPP
#define SEQQUEUE_CPP


#include "seqQueue.h"

template<class elemType>
seqQueue<elemType>::seqQueue(int size){
    array=new elemType[size];
    if (!array){
        throw illegalSize();
    }
    Front=Rear=0;
    maxSize=size;
}

template<class elemType>
bool seqQueue<elemType>::isEmpty(){
    return Front==Rear;
}

template<class elemType>
bool seqQueue<elemType>::isFull(){
    return (Rear+1)%maxSize==Front;
}

template<class elemType>
elemType seqQueue<elemType>::front(){
    if (isEmpty()){
        throw outofBound();
    }
    return array[Front];
} 

template<class elemType>
void seqQueue<elemType>::enQueue(const elemType& e){
    if (isFull()){
        doubleSpace();
    }
    array[Rear]=e;
    Rear=(Rear+1)%maxSize;
}

template<class elemType>
void seqQueue<elemType>::deQueue(){
    if (isEmpty()){
        throw outofBound();
    }
    Front=(Front+1)%maxSize;
}

template<class elemType>
void seqQueue<elemType>::doubleSpace(){
    elemType* tmp=new elemType[2*maxSize];
    int len=length();
    for (int i=Front; i<Front+len; i++){
        tmp[i]=array[i];
    }
    delete[] array;
    array=tmp;
    maxSize=2*maxSize;
    Front=Front;
    Rear=Front+len;
}

template<class elemType>
int seqQueue<elemType>::length() const{
    return (Rear+maxSize-Front)%maxSize;
}

template<class elemType>
seqQueue<elemType>::~seqQueue(){}

#endif