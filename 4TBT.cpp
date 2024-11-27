#include<iostream>
using namespace std;
class Node
{
    public:
    int lbit,rbit;
    Node*left;
    int child;
    Node*right;
    int data;
    Node()
    {
        data=0;
        left=right=NULL;
        lbit=rbit=0;
        child=-1;
    }
    Node(int a)
    {
        data=a;
        left=right=NULL;
        lbit=rbit=0;
        child=-1;
    }
};
class TBT
{
    public:
    Node*root;
    TBT()
    {
        root=new Node(0);;
        root->left=root->right=root;
        root->lbit=root->rbit=1;
    }
    void create();
    Node*preorder_succ(Node*T);
    void create_rec(Node*,int);
    void preorder(Node*);
    Node*getroot(){return root;}
    void preorder();
    Node*in_succ(Node*T);
    void inorder();
    void postorder();
    Node* post_succ(Node*T);
};

void TBT::create_rec(Node*p,int child)
{
    int x;
    cout<<"enter data= ";
    cin>>x;
    if(x==0)return ;
    Node*T=new Node(x);
    if(child==0)
    {
        T->left=p->left;
        T->child=0;
        T->right=p;
        p->left=T;
        p->lbit=1;
        
    }
    else if (child==1)
    {
        T->right=p->right;
        T->child=1;
        T->left=p;
        p->rbit=1;
        p->right=T;
        
    }
    cout<<"enter left data=\n ";
    create_rec(T,0);
    cout<<"enter right data= \n";
    create_rec(T,1);
}
void TBT::create()
{
    create_rec(root,0);
}
void TBT::preorder(Node*T)
{
    if(T==NULL)return;
    cout<<T->data<<" ";
    if(T->lbit==1)
    {
        preorder(T->left);
    }
    if(T->rbit==1)
    {
        preorder(T->right);
    }
}
Node*TBT::preorder_succ(Node*T)
{
    if(T->lbit==1)
    {
        T=T->left;
        return T;
    }
    else{
        while(T->rbit==0)
        {
            T=T->right;
        }
        T=T->right;
    }
    return T;
}
void TBT::preorder()
{
    Node*T=root->left;
    while(T!=root)
    {
        cout<<T->data<<" ";
        T=preorder_succ(T);
    }
}
Node*TBT::in_succ(Node*T)
{
    if(T->rbit==0)
    {
        T=T->right;
        return T;
    }
    else{
        T=T->right;
        while(T->lbit==1)
        {
            T=T->left;
        }
        return T;
    }
    return T;
}
void TBT::inorder()
{
    Node*T=root->left;
    while(T->lbit==1)
    {
        T=T->left;
    }
    while(T!=root)
    {
        cout<<T->data<<" ";
        T=in_succ(T);
    }
}
Node* TBT::post_succ(Node*T)
{
    // right child
    if(T->child==1)
    {
        while(T->lbit==1)
        {
            T=T->left;
        }
        T=T->left;
        return T;
    }
    //left child
    if(T->child==0)
    {
        while(T->rbit==1)
        {
            T=T->right;
        }
        T=T->right;
    }
    //father 
    //check if the after is the leaf node
    if(T->rbit==0|| T==root)return T;
    T=T->right;
    while(T->lbit==1 || T->rbit==1){
        if(T->lbit==1)T=T->left;
        else if (T->rbit==1)T=T->right;
    }
    return T;
}
void TBT::postorder()
{
    Node*T=root->left;
    while(T->lbit==1 || T->rbit==1)
    {
        if(T->lbit==1)T=T->left;
        else if (T->rbit==1)T=T->right;
    }
    while(T!=root)
    {
        cout<<T->data<<" ";
        T=post_succ(T);
    }
}
int main()
{
    TBT tbt;
    tbt.create();
    Node*T=tbt.getroot();
    //tbt.preorder(tbt.getroot()->left);
    tbt.postorder();
}