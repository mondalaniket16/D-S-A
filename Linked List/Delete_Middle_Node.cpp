#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;

    Node(int data1)
    {
        data=data1;
        next=NULL;
    }
};

Node* create(int*arr,int n)
{
    Node* head=new Node(arr[0]);
    Node* temp = head;
    for(int i=1;i<n;i++)
    {
        Node* newNode = new Node(arr[i]);
        temp->next=newNode;
        temp=temp->next;
    }
    return head;
}

void print(Node* head)
{
    Node* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<", ";
        temp=temp->next;
    }
    cout<<endl;
}

Node* deleteMiddle(Node* head)
{
    int n=0;
    Node* temp = head;
    while(temp!=NULL)
    {
        n++;
        temp=temp->next;
    }
    int c=0;
    temp=head;
    
    while(temp!=NULL)
    {
        c++;
        if(c==(n/2))
        {
            temp->next=(temp->next)->next;
        }
        temp=temp->next;
    }
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)  cin>>arr[i];
    Node* head = create(arr,n);
    deleteMiddle(head);
    print(head);
}