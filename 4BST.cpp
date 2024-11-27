#include<iostream>
using namespace std;
class Node
{
    public:
    Node*left,*right;
    int data;
    Node()
    {
        left=right=NULL;
        data=0;
    }
    Node(int a)
    {
        left=right=NULL;
        data=a;
    }
};
class BST
{
    Node*root;
    public:
    BST(){root=NULL;}
    public:
    Node*getroot(){return root;}
    void create();
    Node*create_rec( Node*,int);
    void inorder(Node*T);
    void insert_nonrec(int x);
    void deletenode(int x);
    Node* del_rec(Node*T,int x);

};
void BST:: create(){
    int x;
    while(1)
    {
        cout<<"enter data or 0 to stop";
        cin>>x;
        if(x==0)break;
        //root=create_rec(root,x);
        insert_nonrec(x);
    }
}
Node* BST::create_rec(Node*T,int x)
{
    if(T==NULL)return new Node(x);
    if(x<T->data){
        T->left=create_rec(T->left,x);
        return T;
    }
    if(x>T->data)
    {
        T->right=create_rec(T->right,x);
        return T;
    }
    return T;
}
void BST::insert_nonrec(int x)
{
    Node*T=root;
    if(T==NULL){
        root=new Node(x);
        return;
    }
    Node*p;
    while(T!=NULL)
    {
        p=T;
        if(x<T->data)
        {
            T=T->left;
        }
        else if (x>T->data)
        {
            T=T->right;
        }
        else{return;}
    }
    if(x<p->data)
    {
        p->left=new Node(x);
    }
    else {
        p->right=new Node(x);
    }

}

void BST::inorder(Node*T)
{
    if(T==NULL)return;
    inorder(T->left);
    cout<<T->data<<" ";
    inorder(T->right);
}
void BST:: deletenode(int x)
{
    root=del_rec(root,x);
}
Node* findmin(Node*T)
{
    if(T==NULL)return T;
    while(T->left!=NULL)
    {
        T=T->left;
    }
    return T;
}
Node* BST::del_rec(Node*T,int x)
{
    if(T==NULL)
    {
        return NULL;
    }
    if(x<T->data)
    {
        T->left=del_rec(T->left,x);
        return T;
    }
    else if (x>T->data)
    {
        T->right=del_rec(T->right,x);
        return T;
    }
    if(T->left==NULL && T->right==NULL)
    {
        delete T;
        return NULL;
    }
    if(T->left==NULL)
    {
        Node*p=T->right;
        delete T;
        return p;
    }
    if(T->right==NULL)
    {
        Node*p=T->left;
        delete T;
        return p;
    }
    Node*p=findmin(T->right);
    T->data=p->data;
    T->right=del_rec(T->right,p->data);
    return T;
}

int main()
{
    BST bst;
    bst.create();
    bst.inorder(bst.getroot());
    bst.deletenode(5);
    cout<<endl;
    bst.inorder(bst.getroot());
}