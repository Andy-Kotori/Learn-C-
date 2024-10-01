#include "linkStack.h"

template<class elemType>
elemType linkStack<elemType>::top(){
    if (!Top){
        throw outofBound();
    }
    return Top->data;
}

template<class elemType>
void linkStack<elemType>::push(const elemType& e){
    node<elemType>* tmp=new node<elemType>;
    tmp->data=e;
    tmp->next=Top;
    Top=tmp;
}

template<class elemType>
void linkStack<elemType>::pop(){
    node<elemType>* tmp;
    if (!Top){
        throw outofBound();
    }
    tmp=Top;
    Top=Top->next;
    delete[] tmp;
}

template<class elemType>
linkStack<elemType>::~linkStack(){
    node<elemType>* tmp;
    while (Top){
        tmp=Top;
        Top=Top->next;
        delete[] tmp;
    }
}


//括号匹配
// int main(){
//     linkStack<char> s;
//     char str[20];
//     int i=0;
//     char ch;
//     cout<<"input string:"<<endl;
//     cin.getline(str,20,'\n');
//     cout<<"str: "<<str<<endl;

//     ch=str[i++];
//     while (ch!='\0'){
//         switch (ch){
//         case '(':
//         s.push(ch);
//         break;
//         case ')':
//         if (s.isEmpty()){
//             cout<<"lack of ("<<endl;
//             return 1;
//         }
//         else{
//             s.pop();
//             break;
//         }
//         }
//         ch=str[i++];
//     }

//     if (!s.isEmpty()){
//         cout<<"unexpected ("<<endl;
//     }
//     else{
//         cout<<"parfait"<<endl;
//     }

//     return 0;
// }


// int flag(const char& e){
//     if ((e=='+') || (e=='-')){
//         return 1;
//     }
//     if ((e=='*') || (e=='/')){
//         return 2;
//     }
//     if ((e==')') || (e=='(')){
//         return 3;
//     }
//     if ((e>='0') && (e<='9')){
//         return 0;
//     }
// }

//企图表达式计算的残骸

// int main(){
//     linkStack<char*> strop;
//     linkStack<char*> strsym;
//     char str[30];
//     int op1, op2, op;
//     char ch, ch0;
//     cout<<"input string:"<<endl;
//     cin.getline(str,30,'\n');
//     cout<<"str: "<<str<<endl;
//     int i=0;
//     ch0='+';
//     ch=str[i++];
//     while (ch!='\0'){
//         switch (flag(ch))
//         {
//         case 0:
//             if (flag(ch0)!=0){
//                 char* tmp=new char[10];
//                 tmp[0]=ch;
//                 strop.push(tmp);
//             }
//             else if (flag(ch0==0)){
//                 int tmp=

//             }
            
//             break;
        
//         default:
//             break;
//         }
//     }

//     return 0;
// }