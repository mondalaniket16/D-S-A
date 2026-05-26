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

Node* create(int* arr, int n)
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

Node* Reverse(Node* head)  //Time complexity: O(N)    Space Complexity: O(1)
{
    Node* temp=head;
    Node* prev=NULL;
    while(temp!=NULL)
    {
        Node* front = temp->next;   //      prev --> temp --> front   
        temp->next=prev;            //      prev <-- temp   front
        prev=temp;                  //      prev <-- prev = temp    front
        temp=front;                 //      prev <-- prev <-- temp    front
    }
    return prev;
}

Node* ReverseUsingRecursion(Node* prev, Node* temp, Node* front)
{
    if(temp!=NULL)  return prev;
    temp->next=prev;
    ReverseUsingRecursion(temp,front,temp->next);
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)    cin>>arr[i];
    Node* head = create(arr,n);
    head=ReverseUsingRecursion(NULL,head,head->next);
    cout<<"Reversed Linked List: \n";
    Node* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<", ";
        temp=temp->next;
    }
}