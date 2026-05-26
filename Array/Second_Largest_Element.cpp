#include <climits>
#include<bits/stdc++.h>
using namespace std;
class SecondLargestElement
{
    public:
    void find(int *arr, int n)
    {
        int max=arr[0];
        int second=INT_MIN;
        for(int i=0;i<n;i++)
        {
            if(arr[i]>max)  max=arr[i];
        }
        for(int i=0;i<n;i++)
        {
            if(arr[i]>second && arr[i]<max) second=arr[i];
        }
        cout<<"Second Largest Element: "<<second<<endl;
    }
};
int main()
{
    SecondLargestElement ob;
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)    cin>>arr[i];
    ob.find(arr,n);
}