/*
 Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

Examples
Input : nums = [1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0] , k = 3
Output : 10
Explanation : The maximum number of consecutive 1's are obtained only if we flip the 0's 
present at position 3, 4, 5 (0 base indexing).
The array after flipping becomes [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0].
The number of consecutive 1's is 10.


Input : nums = [0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1] , k = 3
Output : 9
Explanation : The underlines 1's are obtained by flipping 0's in the new array.
[1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1].
The number of consecutive 1's is 9.

*/

#include<bits/stdc++.h>
using namespace std;

int maxOnesBruteForce(int *arr, int n, int k)
{
    int j=0;
    int len=0;
    int max=len;
    for(int i=0;i<n;i++)
    {
        int c=0;                // store count of zeros
        for(j=i;j<n;j++)
        {
            if(arr[j]==0)
            {
                c++;        
            }   
            if(c>k)         // if no. of zeros in the subarray > k : invalid subarray
            {   
                break;      // no. of zeros < = k so that they can be flipped into 1
            }
            len=j-i+1;              
            if(len>max) max=len;
        }
    }
    return max;
}

int maxOnesOptimal(int *arr, int n, int k)
{
    int i=0;
    int j=0;
    int c=0;
    int max=0;
    int len=0;
    while(j<n)
    {
        if(arr[j]==0)
        {
            c++;
        }
        if(c<=k)
        {
            len=j-i+1;
            if(len>max) max=len;
        }
        else
        {
            i=j;
            c=0;
        }
        j++;
    }
    return max;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)    cin>>arr[i];
    int k;
    cin>>k;
    // cout<<maxOnesBruteForce(arr,n,k);
    cout<<maxOnesOptimal(arr,n,k);
}