#include <bits/stdc++.h>
using namespace std;
struct Node
{
    char c;
    int f;
    Node*l,*r;
    Node(char c,int f):c(c),f(f),l(0),r(0){}
};
struct cmp
{
    bool operator()(Node*a,Node*b)
    {
        return a->f>b->f;
    }
};
void print(Node*r,string s)
{
    if(!r)return; 
    if(!r->l&&!r->r)
        cout<<r->c<<" "<<s<<"\n"; 
    print(r->l,s+"0"); 
    print(r->r,s+"1");
}
int main()
{
    priority_queue<Node*,vector<Node*>,cmp> pq;
    for(auto p:vector<pair<char,int>>{{'A',5},{'B',9},{'C',12},{'D',13},{'E',16},{'F',45}})
    pq.push(new Node(p.first,p.second));
    while(pq.size()>1)
    {
        Node*x=pq.top();
        pq.pop();
        Node*y=pq.top();
        pq.pop();
        Node*z=new Node('#',x->f+y->f);
        z->l=x;
        z->r=y;
        pq.push(z);
    }
    print(pq.top(),"");
     cout<<"\n\n24BPS1087";
}
