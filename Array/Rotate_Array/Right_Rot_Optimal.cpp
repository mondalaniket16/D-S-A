

#include<bits/stdc++.h>
using namespace std;
class RightRotate
{
    public:
    void reverse(int *arr,int i, int n)
    {
        for(int j=n-1; i<j ;i++,j--)
        {
            swap(arr[i],arr[j]);
        }
    }
    void rotate(int *arr, int n, int k)
    {
        reverse(arr,0,n);   // reverse the whole array
        reverse(arr,0,k);   // reverse first k elements
        reverse(arr,k,n);   // reverse next n-k elements
    }
};
int main()
{
    RightRotate ob;
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)    cin>>arr[i];
    int k;
    cin>>k;
    ob.rotate(arr,n,k%n);
    cout<<"Rotating array right by "<<k<<" places: ";
    for(int i=0;i<n;i++)    cout<<arr[i]<<", ";
}