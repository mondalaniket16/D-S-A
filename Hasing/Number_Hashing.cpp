#include<bits/stdc++.h>
using namespace std;
class hashing
{
    public:
    void preCheck(int *arr,int n, int max)
    {
        int hash[max+1]={};
        /* for(int i=0;i<=max;i++)
        {
            for(int j=0;j<n;j++)
            {                       Time Complexity: O(N^2)
                if(i==arr[j])
                    hash[i]++;
            }
        } */

        for(int i=0;i<n;i++)
        {
            hash[arr[i]]++;          // O(N)
        }
        cout<<"\n Hash array: "<<endl;
        for(int i=0;i<=max;i++)
        {
            cout<<hash[i]<<", ";
        }
    }
};
int main()
{
    hashing ob;
    int n;
    cin>>n;
    int arr[n];
    int max=INT_MIN;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        if(arr[i]>max)
            max=arr[i];
    }
    cout<<"Original array: "<<endl;
    for(int i=0;i<n;i++)    cout<<arr[i]<<", ";
    ob.preCheck(arr,n,max);

}