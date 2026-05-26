#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;

    Node(int data1)
    {
        data = data1;
        next=NULL;
    }
};

Node* create(int*arr,int n)
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

void deleteNthFromLast(Node* head, int n, int k)
{
    Node* temp=head;
    int c=0;
    while(temp!=NULL)
    {
        if(c==n-k-1)
        {
            temp->next=(temp->next)->next;
            break;
        }
        temp=temp->next;
        c++;
    }
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

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)    cin>>arr[i];
    Node* head = create(arr,n);
    int k;
    cin>>k;
    deleteNthFromLast(head,n,k);
    print(head);

}
