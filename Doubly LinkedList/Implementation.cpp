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

void reversePrint(Node* tail)
{
    cout<<"Reverse Linked List: ";
    Node* temp=tail;
    while(temp!=NULL)
    {
        cout<<temp->data<<", ";
        temp=temp->prev;
    }
    cout<<"\n ";
}

Node* insertAtEnd(Node* head, int data)
{
    Node* temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    Node* newNode = new Node(data);
    temp->next=newNode;
    newNode->prev=temp;
}

Node* insertAtEndUsingTail(Node* tail,int data)
{
    Node* temp=tail;
    Node* newNode= new Node(data);
    tail->next=newNode;
    newNode->prev=tail;
    return newNode;
}

Node* insertAtBeginning(Node* head,int data)
{
    Node* newNode=new Node(data);
    head->prev=newNode;
    newNode->next=head;
    return newNode;
}

Node* insertInBetween(Node* head, int data, int position)
{
    int count=0;
    Node* temp=head;
    Node* newNode=new Node(data);
    while(temp!=NULL)
    {
        if(count==position-1)       // position is of last or middle node
        {
            newNode->next=temp->next;
            temp->next=newNode;
            newNode->prev=temp;
        }
        else if(count==position && temp->prev==NULL)     // if position is of first node
        {
            newNode->next=temp;
            temp->prev=newNode;
            return newNode; // new head;
        }
        count++;
        temp=temp->next;
    }
    return head;
}

Node* deleteFromBackUsingTail(Node* tail)
{
    tail=tail->prev;
    tail->next=NULL;
    return tail;
}

Node* deleteFromBack(Node* head)
{
    Node* temp=head;
    while(temp!=NULL)
    {
        if(temp->next==NULL)
        {
            temp=temp->prev;
            temp->next=NULL;
            break;
        }
        temp=temp->next;
    }
    return temp;
}

Node* deleteFromBeginning(Node*head)
{
    head=head->next;
    head->prev=NULL;
    return head;
}

Node* deleteInBetween(Node* head,int pos)
{
    Node* temp=head;
    int count=0;
    while(temp!=NULL)
    {
        if(count==pos && temp->next==NULL)   // if position is of last node
        {
            (temp->prev)->next=NULL;
            temp->prev=NULL;
            break;
        }
        else if(count==pos && temp->prev==NULL)         //if position is of first node
        {
            (temp->next)->prev=NULL;
            head=temp->next;
            temp->next=NULL;
            return head;  // new head;            
        }
        else if(count==pos)         // if positon other than first or last node
        {
            (temp->prev)->next=temp->next;
            (temp->next)->prev=temp->prev;
            temp->next=NULL;
            temp->prev=NULL;
            break;
        }
        count++;
        temp=temp->next;
    }
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)    cin>>arr[i];
    Node* head = create(arr,n);
    Node* temp=head;
    while(temp->next!=NULL) temp=temp->next;
    Node* tail=temp;
    int data;
    cin>>data;
    int pos;
    cin>>pos;
    // insertAtEnd(head,data);
    // tail=insertAtEndUsingTail(tail,data);
    // head=insertAtBeginning(head,data);
    head=insertInBetween(head,data,pos);
    // tail=deleteFromBack(tail);
    // tail=deleteFromBack(head);
    // head=deleteFromBeginning(head);
    // head=deleteInBetween(head,pos);
    // reversePrint(tail);
    print(head);
    return 0;
}