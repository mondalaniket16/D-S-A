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

Node* middleOFLL(Node* head)
{
    Node* temp=head;
    int n=0;
    while (temp!=NULL)
    {
        temp=temp->next;
        n++;
    }

    temp=head;
    int count=0;
    while(temp!=NULL)
    {
        if(count==(n)/2)
            return temp;
        temp=temp->next;
        count++;
    }
    
}

Node* TortoiseHareAlgo(Node* head)
{
    Node* slow = head;
    Node* fast = head;
    while(fast!=NULL && fast->next!=NULL) // by the time fast pointer reaches the end of the LL 
    {
        slow=slow->next;         // the slow pointer will reach the middle of LL
        fast=(fast->next)->next;
    } 
    return slow;
}

Node* create(int* arr, int n)
{
    Node* head = new Node(arr[0]);
    Node* temp = head;
    for(int i=1;i<n;i++)
    {
        Node* newNode = new Node(arr[i]);
        temp->next=newNode;
        temp=temp->next;
    }
    return head;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)    cin>>arr[i];
    Node* head = create(arr,n);
    Node* pos = TortoiseHareAlgo(head);
    cout<<pos->data;
}