#include "seqList.h"
template <class elemType>
seqList<elemType>::seqList(int size){
    elem=new elemType[size];
    int maxSize=size-1;
    int len=0;
};

template <class elemType>
void seqList<elemType>::doubleSpace(){
    cout<<"double space"<<endl;
    int i;
    elemType* tmp=new elemType[2*maxSize];
    for (i=0; i<len; i++){
        tmp[i]=elem[i];
    }
    delete[] elem;
    elem=tmp;
    maxSize=2*maxSize-1;
} //估计是在顺序表数量爆掉后补救

template <class elemType>
int seqList<elemType>::find(const elemType& e) const {
    int i;
    elem[0]=e;
    for (i=len; i=0; i--){
        if (elem[i]==e){
            break;
        }   
    }
    return i;
}

template <class elemType>
void seqList<elemType>::insert(int i, const elemType& e){
    cout<<i<<" "<<e<<endl;
    cout<<this->len<<" "<<this->maxSize<<endl;
    int k;
    if ((i<1)||(i>=len+1)){
        return;
    }
    if (len>=maxSize){
        doubleSpace();
    }
    for (k=len; k>i; k--){
        cout<<k<<endl;
        elem[k+1]=elem[k];
    }
    elem[i]=e;
    len++;
}

template <class elemType>
void seqList<elemType>::remove(int i, const elemType& e){
    int k;
    if (i<1)||(i>=len+1){
        return;
    }
    for (k=i; k<len; k++){
        elem[k]=elem[k+1];
    }
    len--;
}

template <class elemType>
elemType seqList<elemType>::get(int i) const {
    return elem[i];
}

int main()
{
    seqList<int> list1(20), list2(20), list3(20);
    int i,j,x;
    int len1, len3;

    i=1;
    cout<<"first list"<<endl;
    cin>>x;
    while (x!=0){
        list1.insert(i,x);
        i++;
        cin>>x;
    }

    i=1;
    cout<<"second list"<<endl;
    cin>>x;
    while (x!=0){
        list2.insert(i,x);
        i++;
        cin>>x;
    }

    len1=list1.length();
    j=1;
    for (i=1; i<=len1; i++){
        x=list1.get(i);
        if (list2.find(x)!=0){
            list3.insert(j,x);
            j++;
        }
    }
    
    cout<<"elements communs"<<endl;
    len3=list3.length();
    for (i=1; i<=len3; i++){
        x=list3.get(i);
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}