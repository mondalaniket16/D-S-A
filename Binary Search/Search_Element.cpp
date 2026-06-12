

#include<bits/stdc++.h>
using namespace std;
class Main
{
    public:
    bool search(int*arr, int n,int k)
    {
        int low=0,high=n-1;
        int mid=(low+high)/2;
        while(low<high)
        {
            if(k>arr[mid])
            {
                low=mid+1;
            }
            else if(k<arr[mid])
            {
                high=mid;
            }
            else if(k==arr[mid])
            {
                return true;
            }
        }
        return false;
    }

    bool recursion(int*arr,int n,int k,int low,int high)
    {
        if(low<high)
        {
            int mid=(low+high)/2;
            if(k>arr[mid])
            {
                recursion(arr,n,k,mid+1,high);
            }
            else if(k<arr[mid])
            {
                recursion(arr,n,k,low,mid-1);
            }
            else if(k==arr[mid])    return true;
            else                    return false;
        }
        else return false;
    }
};

int main()
{
    Main ob;
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)    cin>>arr[i];
    int k;
    cin>>k;
    cout<<ob.search(arr,n,k);
    // cout<<ob.recursion(arr,n,k,0,n-1);
    return 0;
}