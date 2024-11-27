#include<iostream>
using namespace std;
class Node
{
    public:
    Node*next;
    Node*prev;
    int data;
    Node()
    {
        next=prev=NULL;
        data=0;
    }
    Node(int a)
    {
        next=prev=NULL;
        data=a;
    }
};
class DCLL
{
    public:
    Node*front,*rear;
    DCLL()
    {
        front=rear=NULL;
    }
    void create();
    void show();
    void addatbeg(int);
    void addatend(int);
    void addatpos(int,int);
    void delatbeg();
    void delatend();
    void delatpos(int);
    int count();
    void rev_show();
};
void DCLL::create()
{
    int n;
    cout<<"enter nthe number of nodes=";
    cin>>n;
    if(n==0){
        return;
    }
    int x;
    cout<<"enter data=";
    cin>>x;
    Node*p=new Node(x);
    p->next=p;
    p->prev=p;
    front=rear=p;
    for(int i=1;i<n;i++)
    {
        cout<<"enter data=";
        cin>>x;
        p->next=new Node(x);
        p->next->prev=p;
        p=p->next;
    }
    rear=p;
    front->prev=rear;
    rear->next=front;
}
void DCLL::show()
{
    Node*p=front;
    do{
        cout<<p->data<<" ";
        p=p->next;
    }while(p!=front);
    cout<<endl;
    
}
void DCLL::rev_show()
{
    Node*p=rear;
    do{
        cout<<p->data<<" ";
        p=p->prev;
    }while(p!=rear);
    cout<<endl;
    
}
void DCLL::addatbeg(int x)
{
    Node*p=new Node(x);
    if(front==NULL){
        front=rear=p;
        p->next=p;
        p->prev=p;
        return;
    }
    p->next=front;
    front->prev=p;
    front=p;
    rear->next=front;
    front->prev=rear;
}
void DCLL::addatend(int x)
{
    Node*p=new Node(x);
    if(front==NULL){
        front=rear=p;
        front->prev=rear;
        rear->next=front;
        return;
    }
    rear->next=p;
    p->prev=rear;
    rear=p;
    rear->next=front;
    front->prev=rear;
}
int DCLL::count()
{
    int cnt=0;
    Node*p=front;
    do{
        p=p->next;
        cnt++;
    }while(p!=front);
    return cnt;
}
void DCLL::addatpos(int pos,int x)
{
    int n=count();
    if(pos<1 || pos>n+1)return;
    if(pos==1 ){addatbeg(x);return;}
    if(pos==n+1){addatend(x);return;}
    
    Node*p=front;
    for(int i=1;i<pos-1;i++)
    {
        p=p->next;
    }
    Node*q=new Node(x);
    q->next=p->next;
    p->next=q;
    q->next->prev=q;
    q->prev=p;
    return;
}
void DCLL::delatbeg()
{
    if(front==NULL)return;
    if(front->next==NULL){
        delete front;
        front =rear=NULL;
        return;
    }
    Node*p=front;
    front=front->next;
    delete p;
    front->prev=rear;
    rear->next=front;
}
void DCLL::delatend()
{
    if(front==NULL)return;
    if(front->next==NULL){
        delatbeg();
    }
    Node*p=rear->prev;
    Node*q=rear;
    p->next=front;
    front->prev=p;
    rear=p;
    delete q;
}
void DCLL::delatpos(int pos)
{   
    Node*p=front;
    int n=count();
    if(pos<1 || pos>n)return;
    if(pos==1){delatbeg();return;}
    if(pos==n){delatend();return;}
    else
    {
        for(int i=1;i<pos-1;i++)
        {
            p=p->next;
        }
        Node*q=p->next;
        p->next=q->next;
        q->next->prev=p;
        delete q;
    }
}
int main()
{
    DCLL D1;
    D1.create();
    D1.addatend(1);
    D1.addatend(2);
    D1.addatend(3);
    D1.addatend(4);
    D1.addatbeg(0);
    D1.addatend(9);
    D1.addatpos(5,1);
    D1.show();
    cout<<endl;
    D1.delatbeg();
    D1.delatend();
    D1.delatpos(4);    
    D1.show();cout<<endl;
    D1.rev_show();
}