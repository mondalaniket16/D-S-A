#include<bits/stdc++.h>
using namespace std;
int p;  //stack pointer global variable
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

int Push(int*st,int data)
{
    p++;
    st[p]=data;
    return p;
}

int Pop(int*st)
{
    int a=st[p];
    p--;
    return a;
}

int top(int*st)
{
    return st[p];
}

void print(int*st)
{
    while(p!=-1)
    {
        cout<<st[p]<<", ";
        p--;
    }
    cout<<"\n";
}

bool palindromeCheckUsingStack(int*st,Node*head)        // T: O(N)      S: O(N)
{
    Node* temp=head;
    while(temp!=NULL)
    {
        if(temp->data!=top(st)) return false;
        Pop(st);
        temp=temp->next;
    }
    return true;
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

int main()
{
    p=-1;
    int n;
    cin>>n;
    int arr[n];
    int st[n];      //stack
    for(int i=0;i<n;i++)    
    {
        cin>>arr[i];
        Push(st,arr[i]);
    }
    // print(st);
    Node* head = convert2LinkedList(arr,n);
    // printLL(head);
    cout<<palindromeCheckUsingStack(st,head);
    // Pop(st);
}