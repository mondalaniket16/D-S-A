#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;

    Node()  
    {
        data=0;
        next=NULL;
    }

    Node(int data1)     
    {
        data=data1;
        next=NULL;
    }
};

Node* convert2LinkedList(int *arr, int n)  
{
    Node* head = new Node(arr[0]);
    Node* temp = head;
    for(int i=1;i<n;i++)
    {
        Node* newNode = new Node(arr[i]);
        temp->next=newNode;
        temp=newNode;
    }
    return head;   
}

void printLL(Node* head)
{
    Node* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<", ";
        temp=temp->next;  // current node will point to the next node
    }
    cout<<"\n";
}

Node* findMiddle(Node* head)
{
    Node* slow=head;
    Node* fast=head;
    while(fast->next!=NULL && fast->next->next!=NULL)       // for odd and even respectively
    {
        slow=slow->next;
        fast=fast->next->next;      //tortoise hare algorithm
    }
    return slow;
}

Node* reverseLL(Node* newHead)
{
    Node* temp=newHead;
    Node* back=NULL;
    while(temp!=NULL)
    {
        Node* front=temp->next;
        temp->next=back;
        back=temp;
        temp=front;
    }
    return back;
}

bool palindromeCheck(Node* head)
{
    Node* mid = findMiddle(head);
    Node* newHead = reverseLL(mid);
    Node* first = head;
    Node* second = newHead;
    while(second->next!=NULL)
    {
        if(first->data!=second->data)   return false;
        first=first->next;
        second=second->next;
    }
    return true;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    int st[n];      //stack
    for(int i=0;i<n;i++)    
    {
        cin>>arr[i];
    }
    Node* head = convert2LinkedList(arr,n);
    cout<<palindromeCheck(head);
    
}