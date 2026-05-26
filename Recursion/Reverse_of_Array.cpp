#include<bits/stdc++.h>
using namespace std;
class Reverse
{
    public:
    void print(int *p, int i)  // i is initialized with n-1
    {
        if(i<0)
            return;
        cout<<*(p+i)<<", "; // *(p+i) is the data/value present in that location
        print(p, i-1);  // with every recursion call, i is dec-- by 1 untill i=0
    }
};
int main()
{
    Reverse ob;
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"Reverse display of array: ";
    ob.print(arr,n-1);  // arr is a pointer that points to the start of the array
}