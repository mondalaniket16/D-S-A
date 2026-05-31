/*
Given an array that contains only 1 and 0 return the count of maximum consecutive ones in the array..

Examples
Example 1:
Input: prices = {1, 1, 0, 1, 1, 1}
Output: 3
Explanation: There are two consecutive 1’s and three consecutive 1’s in the array out of which maximum is 3.

Example 2:
Input: prices = {1, 0, 1, 1, 0, 1} 
Output: 2
Explanation: There are two consecutive 1's in the array. 
*/

#include<bits/stdc++.h>
using namespace std;
class Main
{
    public:
    void function(int *arr, int n)
    {
        int max=0;
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]==1)
            {
                count++;
                if(count>max)   max=count;
            }
            else
            {
                count=0;
            }
        }
        cout<<"Max no. of 1's: "<<max;
    }
};
int main()
{
    Main ob;
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)    cin>>arr[i];
    ob.function(arr,n);
    return 0;
}
