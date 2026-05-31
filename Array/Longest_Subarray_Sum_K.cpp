/*
Given an array nums of size n and an integer k, find the length of the longest sub-array that sums to k. 
If no such sub-array exists, return 0.

Example 1:
Input:
 nums = [10, 5, 2, 7, 1, 9], k = 15  
Output:
 4  
Explanation:
 The longest sub-array with a sum equal to 15 is [5, 2, 7, 1], which has a length of 4. 
 This sub-array starts at index 1 and ends at index 4, and the sum of its elements (5 + 2 + 7 + 1) equals 15. 
 Therefore, the length of this sub-array is 4.

Example 2:
Input:
 nums = [-3, 2, 1], k = 6  
Output:
 0  
Explanation:
 There is no sub-array in the array that sums to 6. Therefore, the output is 0.

*/

#include<bits/stdc++.h>
using namespace std;
class Main
{
    public:
    void bruteForce(int*arr, int n, int k)      // O(N^2)       O(1)
    {
        int sum=0;
        int maxLen=0;
        for(int i=0;i<n-1;i++)
        {
            int c=0;
            sum=arr[i];
            c++;
            for(int j=i+1;j<n;j++)
            {
                sum+=arr[j];
                c++;
                if(sum==k)
                {
                    if(c>maxLen)   maxLen=c;
                }
            }
    
        }
        cout<<"Longest substring: "<<maxLen;
    }

    void optimal(int *arr, int n, int k)
    {
        int i=0;
        int j=0;
        int sum=0;
        int maxLen=0;
        int c=0;
        sum=arr[i];
        while(j<n || i<n && i<=j)
        {
            if(sum<=k)
            {
                j++;
                sum+=arr[j];            // till sum<target increase j, and add it to sum
                c=j-i+1;                // length of sub-arry = right-lower+1
                if(sum==k)
                {
                    maxLen=max(c,maxLen);       // store the max length of sub-array
                }
            }
            else        // if sum is greater than the target reduce from left side untill sum = target
            {
                sum=sum-arr[i];
                i++;
            }
        }
        cout<<"Longest Subarray: "<<maxLen;
    }
};
int main()
{
    Main ob;
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)    
    {
        cin>>arr[i];
    }
    int k;
    cin>>k;
    //ob.optimal(arr,n,k);
    ob.bruteForce(arr,n,k);
    return 0;
}