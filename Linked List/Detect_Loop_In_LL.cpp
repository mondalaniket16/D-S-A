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

Node* create(int*arr, int n)
{
    Node* head = new Node(arr[0]);
    Node* temp = head;
    for(int i=1; i<n-1 ; i++)
    {
        Node* newNode = new Node(arr[i]);
        temp->next=newNode;
        temp=temp->next;
    }
    
    Node* newNode = new Node(arr[4]);
    temp->next=newNode;
    newNode->next=head;       // code to create loop

    return head; 
}

bool findLoop(Node* head)
{
    map<Node*, int> visited;
    Node* temp=head;
    while(temp!=NULL)
    {
        if(visited.find(temp)!=visited.end())
        {
            return true;
        }
        visited[temp]=1;
        temp=temp->next;
    }
    return false;
}

bool findLoopTHA(Node* head)
{
    Node* slow=head;
    Node* fast=head;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=(fast->next)->next;
        if(slow==fast)  return true;
    }
    return false;
}

Node* returnFirstNode(Node* head)      // using map O(N)    O(N)
{
    map<Node*,int> visited;
    Node* temp =head;
    while(temp!=NULL)
    {
        if(visited.find(temp)!=visited.end())
        return temp;
        visited[temp]=1;
        temp=temp->next;
    }
    return NULL;
}

Node* returnFirstNodeTHA(Node* head)        // Tortoise Hare Algorithm      O(N^2)  O(1)
{
    Node* slow = head;
    Node* fast = head;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=(fast->next)->next;
        if(slow==fast)
        {
            slow=head;
            while(slow!=fast)
            {
                slow=slow->next;
                fast=fast->next;
            }
            return slow;        // starting node
        }
    }
    return NULL;        // no loop exist
}

int lengthOfLoop(Node* head)
{
    Node* slow = head;
    Node* fast = head;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=(fast->next)->next;
        if(slow==fast)
        {
            int c=0; 
            while(true)
            {
                c++;
                fast=(fast->next);
                if(slow==fast)
                break;
            }
            return c;
        }
        
    }
    return 0;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)    cin>>arr[i];
    Node* head = create(arr,n);  
    cout<<lengthOfLoop(head);
}