/*
You are given an array nums consisting of positive integers.
Nice Subarray: the bitwise AND of every pair of elements that are in different positions in the subarray equal to 0.
Return the length of the longest nice subarray.
A subarray is a contiguous part of an array.
Note that subarrays of length 1 are always considered nice.

Example 1:
Input: nums = [1,3,8,48,10]
Output: 3
Explanation: The longest nice subarray is [3,8,48]. This subarray satisfies the conditions:
- 3 AND 8 = 0.
- 3 AND 48 = 0.
- 8 AND 48 = 0.
It can be proven that no longer nice subarray can be obtained, so we return 3.

Example 2:
Input: nums = [3,1,5,11,13]
Output: 1
Explanation: The length of the longest nice subarray is 1. Any subarray of length 1 can be chosen.
*/

#include<bits/stdc++.h>
using namespace std;

int bruteForce(int* arr, int n) // basically non-overlapping elements
{
    int l=0,r=0,i=0,j=0;
    int maxLen=0;
    while(r<n)
    {
        int result=0;
        for(i=l; i<r; i++)
        {
            for(j=i+1; j<=r; j++)
            {
                result = arr[i] & arr[j];
                if(result!=0) break;
            }
            if(result!=0)   l++;
        }
        if(result == 0) maxLen=max(maxLen,r-l+1);
        r++;
    }
    return maxLen;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)    cin>>arr[i];
    cout<<bruteForce(arr,n);
}