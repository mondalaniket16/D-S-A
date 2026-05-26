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

Node* create(int *arr, int n)
{
    Node* head = new Node(arr[0]);
    Node* temp=head;
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

void seprateOddEven(Node* head)
{
    Node* odd = head;
    Node* even = head->next;
    Node* head2 = head->next;
    while(odd!=NULL && odd->next!=NULL || even!=NULL && even->next!=NULL)  // next of NULL throws an error
    {
        odd->next=even->next;
        odd=even->next;
        even->next=odd->next;
        even=odd->next;
    }
/*     cout<<"Even part: ";
    print(head2);
    cout<<"Odd part: ";             // to show in different LL
    print(head);  */

    
    odd->next=head2;          // to show in a single LL
    print(head); 
    
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)  cin>>arr[i];
    Node* head = create(arr,n);
    seprateOddEven(head);
}