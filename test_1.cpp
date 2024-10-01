#include<bits/stdc++.h>
using namespace std;
// create, append, find, delete
template <class elemType>
class arr{
   private:
   elemType* a;
   int maxsize, count;
   public:
   arr(int size){
      a=new elemType[size];
      maxsize=size;
      count=0;
   }
   void append(const elemType& x){
      if (count<maxsize){
         a[count]=x;
         count++;
      }
   }
   void find(const elemType& x) const{
      int i;
      for (i=0; i<count; i++){
         if (a[i]==x){
            break;
         }
      }
      if (i==count){
         cout<<"n'existe pas";
      }
      else{
         cout<<"existe";
      }
   }
   ~arr(){
      delete[] a;
   }
};
int main(){
   int size=49;
   arr<int> obj1(size);
   int num=100;
   for (int i=1; i<=size; i++){
      obj1.append(2*i);
   }
   obj1.find(num);
   return 0;
}