#include<bits/stdc++.h>
using namespace std;
class RightRotate
{
    public:
    void rotate(int *arr, int n, int k)
    {
        int temp[n];
        for(int i=0;i<n;i++)
        {
            temp[(i+k)%n]=arr[i];
        }
       
        cout<<"Rotated array: "<<endl;
        for(int i=0;i<n;i++)
        {
            cout<<temp[i]<<", ";
            arr[i]=temp[i];
        }
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
}