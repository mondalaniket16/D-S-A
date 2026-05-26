#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;

    Node()  // default constructor
    {
        data=0;
        next=NULL;
    }

    Node(int data1)     // parameterized constructor
    {
        data=data1;
        next=NULL;
    }
};

Node* convert2LinkedList(int *arr, int n)  // function whose return type is Node pointer
{
    Node* head = new Node(arr[0]);
    Node* temp = head;
    for(int i=1;i<n;i++)
    {
        Node* newNode = new Node(arr[i]);
        temp->next=newNode;
        temp=newNode;
    }
    return head;    // very important to return head; It's the starting point of the linked list.
}

void print(Node* head)
{
    Node* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<", ";
        temp=temp->next;  // current node will point to the next node
    }
}

int lengthOfLL(Node* head)
{
    int count=0;
    Node* temp = head;
    while(temp!=NULL)
    {
        temp=temp->next;  
        count++;
    }
    return count;
}

bool find(Node* head, int x)
{
    Node* temp = head;
    while(temp!=NULL)
    {
        if(temp->data==x)
            return true;
        temp=temp->next;  

    }
    return false;
}

Node* insertAtEnd(Node* head, int data)
{
    Node* temp = head;
    Node* newNode = new Node(data);
    while(temp!=NULL)
    {
        if(temp->next==NULL)  //last element of linked list
        {
            temp->next=newNode;  // make the next to last element to point to new node
            break;
        }
        temp=temp->next;  

    }
}

Node* insertInMiddle(Node* head, int data, int position)
{
    Node* temp = head;
    Node* newNode = new Node(data);
    int count=0;
    while(temp!=NULL)
    {
        if(count==position-1)
        {
            newNode->next=temp->next;
            temp->next=newNode;
        }
        temp=temp->next;
        count++;
    }
}

Node* insertAtStart(Node* head, int data)
{
    Node* temp=head;
    Node* newNode = new Node(data);
    newNode->next=temp;
    temp=newNode;
    return temp;
}

Node* deleteFromEnd(Node* head)
{
    Node* temp = head;
    while(temp!=NULL)
    {
        if((temp->next)->next==NULL)
        {
            temp->next=NULL;
            break;
        }
        temp=temp->next;
    }
    return head;
}

Node* deleteFromMiddle(Node* head, int position)
{
    Node* temp = head;
    int count=0;
    while(temp!=NULL)
    {
        if(count=position-1);
        {
            temp->next=(temp->next)->next;
            break;
        }
        temp=temp->next;
    }
}

Node* deleteFromFront(Node* head)
{
    Node* temp = head;
    head=temp->next;
    return head;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)    cin>>arr[i];
    Node* head = convert2LinkedList(arr,n);  // contains the head of the linked list
    head=deleteFromFront(head);
    print(head);
    
}