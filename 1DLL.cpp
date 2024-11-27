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
class DLL
{
    public:
    Node*head;
    DLL()
    {
        head=NULL;
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
void DLL ::create()
{
     int n;
    cout<<"Enter number of nodes=";
    cin>>n;
    if(n <= 0) {
    cout << "Invalid number of nodes!" << endl;
    return;
    }
    int x;
    cout<<"enter data=";
    cin>>x;
    Node*p=new Node(x);
    head=p;
    for(int i=1;i<n;i++)
    {
        cout<<"enter data=";
        cin>>x;
        p->next=new Node(x);
        p->next->prev=p;
        p=p->next;
    }
}
int  DLL::count()
{
    int cnt=0;
    Node*p=head;
    while(p!=NULL)
    {
        p=p->next;
        cnt++;
    }
    return cnt;
}
void DLL::show()
{
    Node*p=head;
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }cout<<endl;
}
void DLL::addatbeg(int x)
{
    Node*q=new Node(x);
    if(head==NULL){head=q;return;}
    q->next=head;
    head->prev=q;
    head=q;
}
void DLL::addatend(int x)
{
    Node*q=new Node(x);
    if(head==NULL){head=q;return;}
    Node*p=head;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->next=q;
    q->prev=p;
}
void DLL::addatpos(int pos,int x)
{
    int n=count();
    if(pos<0 || pos>n)return;
    if(pos==0){addatbeg(x);return;}
    if(pos==n){addatend(x);return;}
    else{
        Node*p=head;
        for(int i=1;i<pos;i++)
        {
            p=p->next;
        }
        Node*q=new Node(x);
        q->next=p->next;
        p->next->prev=q;
        q->prev=p;
        p->next=q;
    }
}
void DLL::delatbeg()
{
    if(head == NULL) return;
    if(head->next==NULL){delete head;head=NULL;return;}
    Node*p=head;
    head=head->next;
    head->prev=NULL;
    delete p;
}
void DLL::delatend()
{
    Node*p=head;Node*q=head;
    if(head==NULL)return;
    if(head->next==NULL){delete head;head=NULL;}
    while(p->next!=NULL)
    {
        q=p;
        p=p->next;
    }
    q->next=NULL;
    delete p;
}
void DLL::delatpos(int pos)
{
    int n=count();
    if(pos<0 || pos>=n){
        return;
    }
    if(pos==0){delatbeg();return;}
    if(pos==n-1){delatend();return;}
    else{
        Node*p=head;
        for(int i=1;i<pos;i++)
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
    DLL D1;
    //D1.create();
    //D1.show();
    D1.addatend(1);
    D1.addatend(2);
    D1.addatend(3);
    D1.addatend(4);
    D1.addatbeg(0);
    D1.addatend(9);
    D1.addatpos(5,1);
    D1.show();
    D1.delatbeg();
    D1.delatend();
    D1.delatpos(4);    
    D1.show();
}