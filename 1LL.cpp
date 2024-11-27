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
class SLL
{
    Node*head;
    public:
    SLL()
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
void SLL::create()
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
        p=p->next;
    }
}
void SLL::show()
{
    Node*p=head;
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
}
void SLL:: addatbeg(int x)
{
    Node*p=new Node(x);
    p->next=head;
    head=p;
}
void SLL:: addatend(int x)
{
    Node*q=new Node(x);
    Node*p=head;
    if(p==NULL){head=q;return;}
    while(p!=NULL && p->next!=NULL)
    {
        p=p->next;
    }
    p->next=q;
}
int  SLL::count()
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
void SLL::addatpos(int x,int pos){
    int n=count();
    if(pos>n || pos<0 )return;
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
        p->next=q;
    }
}
void SLL::delatbeg(){
    if(head==NULL)return;
    Node*p=head;
    head=head->next;
    delete p;
    return;
}
void SLL::delatend(){
    if(head==NULL)return;
    Node*q,*p=head;
    if(head->next==NULL){delete head; head=NULL;return;}
    while(p->next!=NULL)
    {
        q=p;
        p=p->next;
    }
    q->next= NULL;
    delete p;
}
void SLL::delatpos(int pos){
    int n=count();
    if(pos<0 || pos>=n)return ;
    if(pos==n-1){delatend();return;}
    if(pos==0){delatbeg();return;}
    Node*p=head;
    for(int i=1;i<pos-1;i++)
    {
        p=p->next;
    }
    Node*q=p->next;
    p->next=q->next;
    delete q;
    return;
}
int main()
{
    SLL S1;
    S1.create();
    S1.addatbeg(1);
    S1.addatend(9);
    S1.addatpos(5,1);
    S1.show();cout<<endl;
    S1.delatbeg();
    S1.delatend();
    S1.delatpos(4);    S1.show();

}