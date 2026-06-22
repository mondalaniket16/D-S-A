/*
Given a binary array nums and an integer goal, 
return the number of non-empty subarrays with a sum goal.

A subarray is a contiguous part of the array.

Example 1:
Input: nums = [1,0,1,0,1], goal = 2
Output: 4
Explanation: The 4 subarrays are bolded and underlined below:
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]

Example 2:
Input: nums = [0,0,0,0,0], goal = 0
Output: 15
*/

#include<bits/stdc++.h>
using namespace std;

int binarySum(int *arr, int n, int k)
{
    if(k<0) return 0;
    int l=0,r=0;
    int sum=0;
    int count=0;
    while(r<n)
    {
        sum = sum + arr[r];
        if(sum > k)
        {
            while(sum > k)
            {
                sum = sum - arr[l];
                l++;
            }
        }
        if(sum <= k)    count+=(r-l+1);
        r++;
    }
    return count;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)    cin>>arr[i];
    int k;
    cin>>k;
    int c2 = binarySum(arr,n,k);
    int c1 = binarySum(arr,n,k-1);
    cout<<c2-c1;
}