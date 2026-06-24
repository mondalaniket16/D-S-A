/*
Problem Statement: Given N cards arranged in a row, 
each card has an associated score denoted by the cardScore array. Choose exactly k cards. In each step, 
a card can be chosen either from the beginning or the end of the row. 
The score is the sum of the scores of the chosen cards.

Examples
Input :cardScore = [1, 2, 3, 4, 5, 6] , k = 3
Output : 15
Explanation :Choosing the rightmost cards will maximize your total score. 
So optimal cards chosen are the rightmost three cards 4 , 5 , 6.
Th score is 4 + 5 + 6 => 15.


Input :cardScore = [5, 4, 1, 8, 7, 1, 3 ] , k = 3
Output :12
Explanation : In first step we will choose card from beginning with score of 5.
In second step we will choose the card from beginning again with score of 4.
In third step we will choose the card from end with score of 3.
The total score is 5 + 4 + 3 => 12

*/
#include<bits/stdc++.h>
using namespace std;

int optimal(int*arr, int n, int k)
{
    int count=0;
    int l=0,r=n-1;
    int sum=0;
    while(count<k)
    {
        if(arr[l]>arr[r])   
        {
            // count<<arr[l];
            sum+=arr[l];
            l++;
            count++;
        }
        else
        {
            // cout<<arr[r];
            sum+=arr[r];
            r--;
            count++;
        }
    }
    return sum;
}

int extremeBruteForce(int*arr, int n, int k)        // O(N^2)
{
    int count=0;
    int i=0,j=0;
    int sum=0;
    int maxsum=0;
    while(count<k+1)
    {
        sum=0;
        int t=0;
        for(i=0;i<k-count;i++)
        {
            sum+=arr[i];
        }
        for(j=0;j<count;j++)
        {
            sum+=arr[n-1-j];
        }
        maxsum = max(maxsum,sum);
        count++;
    }
    return maxsum;
}

int bruteForce(int*arr, int n, int k)       // O(2N)
{
    int maxSum=0,lSum=0,rSum=0;
    int j=n-1;
    for(int i=0;i<=k-1;i++)  lSum+=arr[i];
    maxSum = lSum;
    for(int i=k-1;i>=0;i--)
    {
        lSum-=arr[i];
        rSum+=arr[j];
        j--;
        maxSum = max(maxSum,lSum+rSum);
    }
    return maxSum;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)    cin>>arr[i];
    int k;
    cin>>k;
    // cout<<optimal(arr,n,k);
    cout<<bruteForce(arr,n,k);
}