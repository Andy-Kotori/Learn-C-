#include "BTree.h"

template<class elemType>
void BTree<elemType>::createTree(const elemType& flag){
    seqQueue<Node<elemType>*> que(30);
    elemType e, el, er;
    Node<elemType> *p, *pl, *pr;
    stopFlag=flag;
    cout<<"input the root:"<<endl;
    cin>>e;
    if (e==stopFlag){return;}
    p=new Node<elemType>(e);
    root=p;
    que.enQueue(p);
    while (!que.isEmpty())
    {
        p=que.front();
        que.deQueue();
        cout<<"input the left child and the right child of "<<p->data<<endl;
        cin>>el>>er;
        if (el!=stopFlag)
        {
            pl=new Node<elemType>(el);
            que.enQueue(pl);
            p->left=pl;
        }
        if (er!=stopFlag)
        {
            pr=new Node<elemType>(er);
            que.enQueue(pr);
            p->right=pr;
        }
    }
}

template<class elemType>
int BTree<elemType>::Size(){
    return Size(root);
}

template<class elemType>
int BTree<elemType>::Size(Node<elemType>* t){
    if (!t){return 0;}
    return 1+Size(t->left)+Size(t->right);
}

template<class elemType>
int BTree<elemType>::Height(){
    return Height(root);
}

template<class elemType>
int BTree<elemType>::Height(Node<elemType>* t){
    if (!t){return 0;}
    int hl, hr;
    hl=Height(t->left);
    hr=Height(t->right);
    if (hl>=hr){
        return 1+hl;
    } else {
        return 1+hr;
    }
}

template<class elemType>
void BTree<elemType>::DelTree(){
    DelTree(root);
    root=NULL;
}

template<class elemType>
void BTree<elemType>::DelTree(Node<elemType>* t){
    if (!t){return;}
    DelTree(t->left);
    DelTree(t->right);
    delete[] t;
}

template<class elemType>
void BTree<elemType>::PreOrder(){
    PreOrder(root);
    cout<<endl;
}

template<class elemType>
void BTree<elemType>::PreOrder(Node<elemType>* t){
    if (!t){return;}
    cout<<t->data<<" ";
    PreOrder(t->left);
    PreOrder(t->right);
}

template<class elemType>
void BTree<elemType>::PreOrder_2(){
    if (!root){return;}
    Node<elemType>* p;
    seqStack<Node<elemType>*> s(30);
    s.push(root);
    while(!s.isEmpty()){
        p=s.top();
        cout<<p->data<<" ";
        s.pop();
        if (p->right){
            s.push(p->right);
        }
        if (p->left){
            s.push(p->left);
        }
    }
    cout<<endl;
}

template<class elemType>
void BTree<elemType>::InOrder(){
    InOrder(root);
    cout<<endl;
}

template<class elemType>
void BTree<elemType>::InOrder(Node<elemType>* t){
    if (!t){return;}
    InOrder(t->left);
    cout<<t->data<<" ";
    InOrder(t->right);
}

template<class elemType>
void BTree<elemType>::InOrder_2(){
    if (!root){return;}
    seqStack<Node<elemType>*> s1(30);
    seqStack<int> s2(30);
    Node<elemType>* p=root;
    s1.push(root);
    const int zero=0;
    const int one=1;
    s2.push(zero);
    int flag;
    while (!s1.isEmpty()){
        p=s1.top();
        flag=s2.top();
        s1.pop();
        s2.pop();
        if (flag==0){
            s1.push(p);
            s2.push(one);
            if (p->left){
                s1.push(p->left);
                s2.push(zero);
            }
        }
        if (flag==1){
            cout<<p->data<<" ";
            if (p->right){
                s1.push(p->right);
                s2.push(zero);
            }
        }
    }
    cout<<endl;
}

template<class elemType>
void BTree<elemType>::PostOrder(){
    PostOrder(root);
    cout<<endl;
}

template<class elemType>
void BTree<elemType>::PostOrder(Node<elemType>* t){
    if (!t){return;}
    PostOrder(t->left);
    PostOrder(t->right);
    cout<<t->data<<" ";
}

template<class elemType>
void BTree<elemType>::PostOrder_2(){
    if (!root){return;}
    seqStack<Node<elemType>*> s1(30);
    seqStack<int> s2(30);
    const int zero=0;
    const int one=1;
    const int two=2;
    Node<elemType>* p=root;
    s1.push(root);
    s2.push(zero);
    int flag;
    while (!s1.isEmpty()){
        p=s1.top();
        flag=s2.top();
        s2.pop();
        if (flag==0){
            s2.push(one);
            if (p->left){
                s1.push(p->left);
                s2.push(zero);
            }
        }
        else if (flag==1){
            s2.push(two);
            if (p->right){
                s1.push(p->right);
                s2.push(zero);
            }
        }
        else if (flag==2){
            cout<<p->data<<" ";
            s1.pop();
        }
    }
    cout<<endl;
}

template<class elemType>
void BTree<elemType>::LevelOrder(){
    if (!root){return;}
    seqQueue<Node<elemType>*> que(30);
    que.enQueue(root);
    Node<elemType>* p;
    while (!que.isEmpty()){
        p=que.front();
        cout<<p->data<<" ";
        que.deQueue();
        if (p->left){
            que.enQueue(p->left);
        }
        if (p->right){
            que.enQueue(p->right);
        }
    }
    cout<<endl;
}

template<class elemType>
Node<elemType>* BTree<elemType>::TreadMid(){
    Node<elemType> *first, *p, *pre;
    seqStack<Node<elemType>*> s1(30);
    seqStack<int> s2(30);
    const int zero=0;
    const int one=1;
    pre=NULL;
    first=NULL;
    if (!root){return NULL;}
    s1.push(root);
    s2.push(zero);
    int flag;
    while (!s1.isEmpty()){
        // cout<<"flag top"<<endl;
        flag=s2.top();
        s2.pop();
        // cout<<"p top"<<endl;
        p=s1.top();
        if (flag==0){
            s2.push(one);
            if (p->left){
                s1.push(p->left);
                s2.push(zero);
            }
        }
        if (flag==1){
            s1.pop();
            if (!first){first=p;}
            if (p->right){
                s1.push(p->right);
                s2.push(zero);
            }
            if (!p->left){
                p->leftFlag=1;
                p->left=pre;
            }
            if ((pre) && (!pre->right)){
                pre->rightFlag=1;
                pre->right=p;
            }
            pre=p;
        }
    }
    p->rightFlag=1;
    cout<<p->data<<" "<<"next NULL"<<endl;
    // cout<<"first: "<<first->data<<endl;
    return first;
}

template<class elemType>
void BTree<elemType>::ThreadMidVisit(Node<elemType>* first){
    if (!first){return;}
    Node<elemType>* p;
    p=first;
    // cout<<p->data<<endl;
    // int i=5;
    while (p){
        cout<<p->data<<" ";
        // cout<<"rightflag: "<<p->rightFlag<<" ";
        if (p->rightFlag==0){
            // cout<<"have a right child ";
            p=p->right;
            while ((p->left) && (p->leftFlag==0)){
                p=p->left;
            }
        }
        else if (p->rightFlag==1){
            p=p->right;
            // cout<<"use flag to right ";
        }
        // else {cout<<"else ";}
        // i--;
        // if (i==0){break;}
    }
    cout<<endl;
}

template<class elemType>
void BTree<elemType>::ThreadMidPreVIsit(){
    if (!root){return;}
    Node<elemType>* p;
    p=root;
    // int i=10;
    while (p){
        cout<<p->data<<" ";
        // cout<<"the leftFlag of whom is "<<p->leftFlag<<" ";
        if (p->leftFlag==0){
            p=p->left;
        }
        else{
            while ((p) && (p->rightFlag==1)){
                p=p->right;
            }
            if (!p){return;}
            p=p->right;
        }
        // i--;
        // if (i==0){break;}
    }
    cout<<endl;
}

template<class elemType>
Node<elemType>* BTree<elemType>::buildTree(elemType pre[], elemType min[], int pl, int pr, int ml, int mr){
    Node<elemType> *p, *leftRoot, *rightRoot;
    int i, pos, num;
    int lpl, lpr, lml, lmr;
    int rpl, rpr, rml, rmr;
    p=new Node<elemType>(pre[pl]);
    if (!root){
        root=p;
    }
    if (pl>pr){return NULL;}
    for (i=ml; i<=mr; i++){
        if (min[i]==pre[pl]){
            break;
        }
    }
    pos=i;
    num=pos-ml;
    lml=ml;
    lmr=pos-1;
    rml=pos+1;
    rmr=mr;
    lpl=pl+1;
    lpr=pl+num;
    rpl=pl+num+1;
    rpr=pr;
    leftRoot=buildTree(pre, min, lpl, lpr, lml, lmr);
    rightRoot=buildTree(pre, min, rpl, rpr, rml, rmr);
    p->left=leftRoot;
    p->right=rightRoot;
    return p;
}

// int main(){
//     BTree<int> tree;
//     tree.createTree(0);
//     cout<<tree.Size()<<endl;
//     cout<<tree.Height()<<endl;
//     tree.PreOrder_2();
//     tree.InOrder_2();
//     tree.PostOrder_2();
//     tree.LevelOrder();
//     Node<int>* first;
//     first=tree.TreadMid();
//     tree.ThreadMidVisit(first);
//     tree.ThreadMidPreVIsit();
//     BTree<char> tree2;
//     char pre[9]={'B','L','S','C','F','D','G','I','H'};
//     char min[9]={'L','S','B','F','C','I','G','H','D'};
//     tree2.buildTree(pre, min, 0, 8, 0, 8);
//     cout<<tree2.Size()<<endl;
//     tree2.PostOrder();
//     return 0;
// }