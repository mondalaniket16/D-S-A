#include <climits>
#include<bits/stdc++.h>
using namespace std;
class SortedCheck
{
    public:
    bool check(int *arr, int n)
    {
        for(int i=0;i<n-1;i++)
        {
            if(arr[i]>arr[i+1])
                return false;
        }
        return true;

    }
};
int main()
{
    SortedCheck ob;
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)    cin>>arr[i];
    if(ob.check(arr,n))     cout<<"Sorted";
    else                    cout<<"Not Sorted";
}