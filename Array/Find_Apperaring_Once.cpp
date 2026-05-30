/*
Given a non-empty array of integers arr, every element appears twice except for one. Find that single one.

Example 1:
Input Format: arr[] = {2,2,1}
Result: 1
Explanation: In this array, only the element 1 appear once and so it is the answer.

Example 2:
Input Format: arr[] = {4,1,2,1,2}
Result: 4
Explanation: In this array, only element 4 appear once and the other elements appear twice. So, 4 is the answer.
*/

#include<bits/stdc++.h>
using namespace std;
class Main
{
    public:
    void UsingMap(int *arr,int n)           //O(N)      O(N)
    {
        unordered_map<int,int> mpp;
        for(int i=0;i<n;i++)
        {
            mpp[arr[i]]++;
        }
        for(auto i: mpp)
        {
            if(i.second==1)
            {
                cout<<i.first;
                return;
            }
        }
    }

    void optimum(vector<int>&v, int n)
    {

        int xorr=0;
        for(auto i:v)
        {
            xorr=xorr^i;
        }      
        cout<<xorr;
        return;
    }
    
};
int main()
{
    Main ob;
    int n;
    cin>>n;
    int arr[n];
    vector<int> v={4,1,2,1,2};
    ob.optimum(v,n);
    return 0;
}