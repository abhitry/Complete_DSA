#include<iostream>
using namespace std;
class Node {
    public:
    Node*left,*right;int data;
    Node()
    {
        left=right=NULL;
        data =0;
    }
    Node(int a)
    {
        left=right=NULL;
        data =a;
    }
};
class BT{
    Node*root;
    public:
    BT(){
        root=NULL;
    }
    void create();
    Node*create_rec();
    void preorder(Node*);
     void preorder();
    Node*getroot(){return root;}
    void inorder(Node*T);
    void inorder();
    void postorder(Node*T);
    void postorder();
    void deleteNode();
    Node* del_rec(Node*T,int x);

};
void BT::create()
{
    root=create_rec();
}
Node* BT::create_rec()
{
    int x;
    cout<<"enter data or 0 to stop";
    cin>>x;
    if(x==0)return NULL;
    Node*T=new Node(x);
    T->left=create_rec();
    T->right=create_rec();
    return T;
}
void BT::preorder(Node*T)
{
    if(T==NULL)return;
    cout<<T->data;
    preorder(T->left);
    preorder(T->right);
}
void BT::preorder()
{
    Node*T=root;
    stack<Node*>stk;
    while(T!=NULL){
        cout<<T->data<<" ";
        stk.push(T);
        T=T->left;
    }
    while(!stk.empty())
    {
        Node*T=stk.top();
        stk.pop();
        T=T->right;
        while(T!=NULL)
        {
            stk.push(T);
            cout<<T->data<<" ";
            T=T->left;
        }
    }
}
void BT::inorder(Node*T)
{
    if(T==NULL)return;
    inorder(T->left);
    cout<<T->data<< " ";
    inorder(T->right);
}
void BT::inorder()
{
    Node*T=root;
    stack<Node*>stk;
    while(T!=NULL)
    {   
        stk.push(T);
        T=T->left;
    }
    while(!stk.empty())
    {
        Node*T=stk.top();stk.pop();
        cout<<T->data<<" ";
        T=T->right;
        while(T!=NULL)
        {
            stk.push(T);
            T=T->left;
        }
    }
}
void BT::postorder(Node*T)
{
    if(T==NULL)return;
    postorder(T->left);
    postorder(T->right);
    cout<<T->data<<" ";
}
class SuperNode
{public:
    Node*add;
    int flag;
    SuperNode()
    {
        add=NULL;
        flag=0;
    }
    SuperNode(Node*T)
    {
        add=T;
        flag=0;
    }
};
void BT::postorder()
{
    Node*T=root;
    stack<SuperNode>stk;
    SuperNode super;
    while(T!=NULL)
    {
        super.add=T;
        super.flag=0;
        stk.push(super);
        T=T->left;
    }
    while(!stk.empty())
    {
        SuperNode super=stk.top();
        stk.pop();
        Node*T=super.add;
        if(super.flag==1)
        {
            cout<<T->data<<" ";
        }
        else{
            super.flag=1;
            stk.push(super);
            T=T->right;
            while(T!=NULL)
            {
                super.add=T;
                super.flag=0;
                stk.push(super);
                T=T->left;
            }
        }
    }
}
Node* findleaf(Node*T)
{
    if (T == NULL) return NULL;
    while(T->left!=NULL || T->right!=NULL)
    {
        if(T->left!=NULL)T=T->left;
        else if(T->right!=NULL)T=T->right;
    }
    return T;
}
Node* BT::del_rec(Node*T,int x)
{
    if(T==NULL)
    {
        return NULL;
    }
    if(x!=T->data)
    {
        T->left =del_rec(T->left,x);    
        T->right=del_rec(T->right,x);
        return T;
    }
    if(T->left==NULL && T->right==NULL)
    {
        delete T;
        return NULL;
    }
    Node*leaf=findleaf(T);
    T->data=leaf->data;
    if(T->left!=NULL)
        T->left=del_rec(T->left,leaf->data);
    else if(T->right!=NULL)
        T->right=del_rec(T->right,leaf->data);
    return T;
}

void BT:: deleteNode()
{
    int x;
    cout<<"enter number to be deleted=";
    cin>>x;
    root=del_rec(root,x);
}

int main()
{
    BT bt;
    bt.create();
    Node*T=bt.getroot();
    bt.preorder(T);cout<<endl;
    bt.deleteNode();
    bt.preorder();cout<<endl;
    
}