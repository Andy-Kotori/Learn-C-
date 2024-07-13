#include<bits/stdc++.h>
#include <iostream>
using namespace std;
void s(int x, int y);

int main(){
   int a,b;
   cin>>a;
   cin>>b;
   s(a, b);
   cout<<a<<" "<<b<<endl;
   return 0;
}
void s(int x,int y){
      int temp;
      temp=y;
      cout<<temp<<endl;
      y=x;
      x=temp;
   }