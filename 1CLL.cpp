#include<iostream>
using namespace std;
class Node
{
    public:
    Node*next;
    int data;
    Node()
    {
        next=NULL;
        data=0;
    }
    Node(int a)
    {
        next=NULL;
        data=a;
    }
};
class CLL
{
    public:
    Node*front,*rear;
    CLL()
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
};
void CLL::create()
{
    int n;
    cout<<"enter nthe number of nodes=";
    cin>>n;
    int x;
    cout<<"enter data=";
    cin>>x;
    Node*p=new Node(x);
    p->next=p;
    front=rear=p;
    for(int i=1;i<n;i++)
    {
        cout<<"enter data=";
        cin>>x;
        p->next=new Node(x);
        p=p->next;
    }
    rear=p;
    rear->next=front;
}
void CLL::show()
{
    if(front==NULL)return;
    Node*p=front;
    do{
        cout<<p->data<<" ";
        p=p->next;
    }while(p!=front);
}
void CLL::addatbeg(int x)
{
    if(front==NULL){
        Node*p=new Node(x);
        front=rear=p;
        p->next=p;
        return;
    }
    Node*q=new Node(x);
    q->next=front;
    front=q;
    rear->next=front;
}
void CLL::addatend(int x)
{
    Node*p=new Node(x);
    if(front==NULL){
        front=rear=p;
        return;
    }
    rear->next=p;
    rear=rear->next;
    rear->next=front;
}
int CLL::count()
{
    int cnt=0;
    if(front==NULL)return 0; 
    Node*p=front;
    do{
        p=p->next;
        cnt++;
    }while(p!=front);
    return cnt;
}
void CLL::addatpos(int pos,int x)
{
    int n=count();
    if(pos<0 || pos>n+1)return;
    if(pos==0 ){addatbeg(x);return;}
    if(pos==n+1){addatend(x);return;}
    
    Node*p=front;
    for(int i=1;i<pos-1;i++)
    {
        p=p->next;
    }
    Node*q=new Node(x);
    q->next=p->next;
    p->next=q;
    return;
}
void CLL::delatbeg()
{
    if(front==NULL)return;
    if(front->next==NULL){
        delete front;
        front =rear=NULL;
    }
    Node*p=front;
    front=front->next;
    rear->next=front;
    delete p;
}
void CLL::delatend()
{
    if(front==NULL)return;
    if(front->next==NULL){
        delete front;
        front =rear=NULL;
        return;
    }
    Node*p=front;
    while(p->next!=rear)
    {
        p=p->next;
    }
    delete rear;
    rear=p;
    rear->next=front;
}
void CLL::delatpos(int pos)
{   
    Node*p=front;
    int n=count();
    if(pos<0 || pos>n-1)return;
    if(pos==0){delatbeg();return;}
    if(pos==n-1){delatend();return;}
    else
    {
        for(int i=1;i<pos-1;i++)
        {
            p=p->next;
        }
        Node*q=p->next;
        p->next=q->next;
        delete q;
    }
}
int main()
{
    CLL D1;
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
    D1.show();
}