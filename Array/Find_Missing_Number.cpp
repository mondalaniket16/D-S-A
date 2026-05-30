/*
Given an array arr[] of size n-1 with distinct integers in the range of [1, n]. 
This array represents a permutation of the integers from 1 to n with one element missing. 
Find the missing element in the array.

Examples: 

Input: arr[] = [8, 2, 4, 5, 3, 7, 1]
Output: 6
Explanation: All the numbers from 1 to 8 are present except 6.

Input: arr[] = [1, 2, 3, 5]
Output: 4
Explanation: Here the size of the array is 4, so the range will be [1, 5]. The missing number between 1 to 5 is 4
*/

#include<bits/stdc++.h>
using namespace std;
class Main
{
    public:
    void bruteForce(int *arr, int n)        // O(N^2)   O(1)
    {
        for(int i=1;i<=n+1;i++)
        {
            int flg=1;
            for(int j=0;j<n;j++)
            {
                if(arr[j]==i)   
                {
                    flg=1;
                    break;
                }
                else   flg=0;
            }
            if(flg==0)
            {
                cout<<"Missing digit is: "<<i<<endl;
                return;
            }
        }
    }

    void UsingMap(int *arr,int n)       //O(N)      O(N)
    {
        unordered_map<int,int> mpp;
        for(int i=0;i<n;i++)
        {
            mpp[arr[i]]=1;
        }
        for(int i=1;i<=n;i++)
        {
            if(mpp[i]==0)
            {
                cout<<i;
                return;
            }
        }
    }

    void UsingXtraArray(int *arr,int n)     //O(N)      O(N)
    {
        int a[n+2]={};
        for(int i=0;i<n;i++)
        {
            a[arr[i]]++;
        }
        for(int i=1;i<=n+1;i++)
        {
            if(a[i]==0)   cout<<"Missing number is: <<i";
        }
        return;
    }

    void SumOfN(int*arr,int n)      //O(N)      O(1)
    {
        int a=(n+1)*(n+2)/2;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
        }
        cout<<"Missing term: "<<a-sum;
    }
};
int main()
{
    Main ob;
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)    cin>>arr[i];
    ob.SumOfN(arr,n);
    return 0;
}