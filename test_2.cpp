#include<iostream>
using namespace std;
int main(){
    int* a;
    cout<<a<<endl;
    int* c=NULL;
    int b=3;
    a=&b;
    c=a;
    cout<<a<<" "<<&b<<" "<<c<<" "<<*c<<endl;
    return 0;
}





// #include<bits/stdc++.h>

// enum DAY { MON=1, TUE, WED, THU, FRI, SAT, SUN };
// int main(){
// int x, y, z;
// x = 10;
// y = 20;
// z = 30;
// DAY yesterday, today, tomorrow;
// yesterday = MON;
// today = TUE;
// tomorrow = WED;
// printf("%d %d %d \n", yesterday, today, tomorrow);
// }

// 构造、析构、拷贝构造
// #include<bits/stdc++.h>
// using namespace std;
// class Line{
//     private:
//     int* ptr;
//     public:
//     void getter(){
//         cout<<ptr<<endl;
//     }
//     int ptrgetter(){
//         return *ptr;
//     }
//     Line(int len){
//         ptr=new int;
//         *ptr=len;
//         cout<<"create"<<endl;
//     }
//     Line(const Line& obj){
//         ptr=new int;
//         *ptr=*obj.ptr;
//         cout<<"copy create"<<endl;
//     }
//     ~Line(){
//         delete ptr;
//         cout<<"deleted"<<endl;
//     }
// };
// int main(){
//     int a;
//     cin>>a;
//     Line line1=a;
//     line1.getter();
//     cout<<line1.ptrgetter()<<endl;
//     Line line2=line1;
//     cout<<line2.ptrgetter()<<endl;
//     return 0;
// }

// // 类与指针与静态成员与this指针
// #include<bits/stdc++.h>
// using namespace std;
// class myclass{
//     private:
//     int data;
//     public:
//     static int counter;
//     void setter(int data){
//         this->data=data;
//         counter++;
//     }
//     void initial(){
//         data=1;
//     }
//     int getter() const{
//         return data;
//     }
//     static int getcounter(){
//         return counter;
//     }
//     void compare(myclass myclass){
//         cout<<this->getter()-myclass.getter()<<endl;
//     }
// };
// void processptr(myclass* ptr){
//     cout<<"Here: "<<ptr->getter()<<endl;//指针做函数参数
// }
// int myclass::counter=0;
// int main(){
//     myclass obj;
//     myclass* ptr=&obj;
//     ptr->initial();
//     cout<<ptr->getter()<<endl;
//     int a,b;
//     cin>>a>>b;
//     cout<<"before "<<myclass::getcounter()<<endl;
//     ptr->setter(a);
//     myclass obj2;
//     obj2.setter(b);
//     obj.compare(obj2);
//     cout<<"after "<<myclass::getcounter()<<endl;
//     cout<<ptr->getter()<<endl;
//     processptr(&obj);
//     return 0;
// }

// 向量vector
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int a;
//     cin>>a;
//     vector<int> myvector(a);
//     int b=0;
//     for (int i=0;i<a;i++){
//         b+=i;
//         myvector[i]=b+i;
//         cout<<myvector[i]<<endl;
//     }
//     cout<<b<<endl;
//     vector<int> vec2 = {1, 2, 3, 4};
//     myvector.push_back(2);
//     return 0;
// }

// 列表
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int N;
//     cin>>N;
//     int n[40][40];
//     for (int i=0;i<=N-1;i++){
//         for (int j=0;j<=N-1;j++){
//             n[i][j]=0;
//         }
//     }
//     n[0][(N+1)/2-1]=1;
//     int x=0;
//     int y=(N+1)/2-1;
//     for (int i=2;i<=N*N;i++){
//         // for (int i=0;i<=N-1;i++){
//         //     for (int j=0;j<=N-1;j++){
//         //         cout<<n[i][j]<<" ";
//         //     }
//         // cout<<endl;
//         // }
//         // cout<<x<<y;
//         if (x==0 && y!=N-1){
//             x=N-1,y++;
//             n[x][y]=i;
//         }
//         else if (x!=0 && y==N-1){
//             x=x-1,y=0;
//             n[x][y]=i;
//         }
//         else if (x==0 && y==N-1){
//             x++;
//             n[x][y]=i;
//         }
//         else if (x!=0 && y!=N-1){
//             if (n[x-1][y+1]==0){
//                 x=x-1,y=y+1;
//                 n[x][y]=i;
//             }
//             else{
//                 x++;
//                 n[x][y]=i;
//             }
//         }
//     }
//     for (int i=0;i<=N-1;i++){
//         for (int j=0;j<=N-1;j++){
//             cout<<n[i][j]<<" ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }

// 一些调用函数、操作、质数判断
// #include<bits/stdc++.h>
// using namespace std;
// int judge1(int x);
// int judge2(int x);
// int main(){
//     int a,b;
//     cin>>a>>b;
//     for (int j=a;j<=b;j++){
//         if (j==2){
//             cout<<2<<endl;
//         }
//         else{
//             if ((j%2==1) && (j<=9989899)){
//                 if (judge2(j)==1){
//                     if (judge1(j)==1){
//                         cout<<j<<endl;
//                     }
//                 }
//             }
//         }
//     }
//     return 0;
// }
// int judge1(int x){  
//     if (x <= 1) {   
//         return 0;
//     }  
//     int a = 0;  
//     for (int i = 2; i <= floor(sqrt(x)); i++){
//         if (x % i == 0){  
//             a++;  
//             break;
//         }  
//     }  
//     if (a == 0){  
//         return 1;
//     }  
//     else{  
//         return 0;
//     }  
// }
// int judge2(int x){
//     string str=to_string(x);
//     string str2="";
//     int len=str.size();
//     for (int i=1;i<=len;i++){
//         str2+=str[len-i];
//     }
//     if (str2==str){
//         return 1;
//     }
//     else{
//         return 0;
//     }
// }

// 一些字符串操作
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int a;
//     cin>>a;
//     if (a>=0){
//         string str=to_string(a);
//         string str2="";
//         int len=str.size();
//         for (int i=1;i<=len;i++){
//             str2+=str[len-i];
//         }
//         int ans=stoi(str2);
//         cout<<ans<<endl;
//     }
//     else{
//         a=-a;
//         string str=to_string(a);
//         string str2="";
//         int len=str.size();
//         for (int i=1;i<=len;i++){
//             str2+=str[len-i];
//         }
//         int ans=stoi(str2);
//         cout<<-ans<<endl;
//     }
//     return 0;
// }

//一些字符串操作
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int a=12345678;
//     string b;
//     b=to_string(a);
//     char c=b[3];
//     cout<<c<<endl;
//     return 0;
// }

// 空指针函数
// void f(int x);
// int h,m;
// int main(){
//     int s,v;
//     cin>>s>>v;
//     int t;
//     t=ceil((double) s/(double) v)+10;
//     if (t<=480){
//         int tt=480-t;
//         // cout<<tt<<endl;
//         h=floor(tt/60);
//         m=tt%60;
//     }
//     if (t>480){
//         int tt=24*60+480-t;
//         // cout<<tt<<endl;
//         h=floor(tt/60);
//         m=tt%60;
//     }
//     f(h);
//     cout<<":";
//     f(m);
//     cout<<endl;
//     return 0;
// }
// void f(int x){
//     if (x<10){
//         cout<<"0"<<x;
//     }
//     if (x>=10){
//         cout<<x;
//     }
// }

// 取小数点
// int main(){
//     float a;
//     int b;
//     cin>>a>>b;
//     cout<<setprecision(3)<<fixed<<a/b<<endl<<b*2;
//     return 0;
// }