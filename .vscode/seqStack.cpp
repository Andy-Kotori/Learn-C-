#ifndef SEQSTACK_CPP
#define SEQSTACK_CPP

#include "seqStack.h"

template<class elemType>
seqStack<elemType>::seqStack(int size){
    array=new elemType[size];
    Top=-1;
    if (!array){
        throw illegalSize();
    }
    maxSize=size;
}

template<class elemType>
elemType seqStack<elemType>::top() const{
    if (isEmpty()){
        cout<<"top OOB"<<endl;
        throw outofBound();
    }
    return array[Top];
}

template<class elemType>
void seqStack<elemType>::push(const elemType& e){
    if (isFull()){
        doubleSpace();
    }
    array[Top+1]=e;
    Top++;
}

template<class elemType>
void seqStack<elemType>::pop(){
    if (isEmpty()){
        cout<<"pop OOB"<<endl;
        throw outofBound();
    }
    Top--;
}

template<class elemType>
void seqStack<elemType>::doubleSpace(){
    elemType* tmp=new elemType[2*maxSize];
    for (int i=0; i<=Top; i++){
        tmp[i]=array[i];
    }
    delete[] array;
    array=tmp;
    maxSize=2*maxSize;
}

// int main() {  
//     seqStack<char> s(20);  
//     char ctemp;  
//     cout << "Input the elements, press enter to end: "<<endl;  
//     ctemp = cin.get();  
//     while (ctemp != '\n') {
//         s.push(ctemp);  
//         ctemp = cin.get(); 
//     }
//     cout<<"start output"<<endl;
//     while(!s.isEmpty()){
//         ctemp=s.top();
//         s.pop();
//         cout<<ctemp;
//     }

//     return 0;  
// }

#endif