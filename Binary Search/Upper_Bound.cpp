/*
The upper bound algorithm finds the first or the smallest index in a sorted array 
where the value at that index is greater than the given key i.e. x.
The upper bound is the smallest index, ind, where arr[ind] > x.

Examples
Example 1:
Input Format: N = 4, arr[] = {1,2,2,3}, x = 2
Result: 3
Explanation: Index 3 is the smallest index such that arr[3] > x.

Example 2:
Input Format: N = 6, arr[] = {3,5,8,9,15,19}, x = 9
Result: 4
Explanation: Index 4 is the smallest index such that arr[4] > x.

*/

#include<bits/stdc++.h>
using namespace std;
class Main
{
    public:
    int lowerBound(int*arr, int n, int k)
    {
        int low=0,high=n-1;
        int lb=n;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(arr[mid]>k)
            {
                high=mid-1;
                lb=mid;
            }
            else
            {
                low=mid+1;
            }
            
        }
        return lb;
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
    cout<<ob.lowerBound(arr,n,k);
    return 0;
}