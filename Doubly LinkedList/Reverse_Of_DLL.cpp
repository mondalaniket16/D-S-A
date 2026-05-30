#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int data1)
    {
        data=data1;
        next=NULL;
        prev=NULL;
    }
};

Node* create(int*arr, int n)
{
    Node* head=new Node(arr[0]);
    Node* prev=head;
    for(int i=1;i<n;i++)
    {
        Node* newNode = new Node(arr[i]);
        newNode->prev=prev;
        prev->next=newNode;
        prev=prev->next;
    }
    return head;
}

void print(Node* head)
{
    cout<<"Linked List: ";
    Node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<", ";
        temp=temp->next;
    }
    cout<<"\n ";
}

Node* reverse(Node* head)
{
    if(head==NULL || head->next==NULL)      return NULL;
    Node* temp=head;
    Node* last=NULL;
    while(temp!=NULL)
    {
        last=temp->prev;
        temp->prev=temp->next;
        temp->next=last;
        temp=temp->prev;
    }
    return last->prev;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)    cin>>arr[i];
    Node* head = create(arr,n);
    head=reverse(head);
    print(head);
}