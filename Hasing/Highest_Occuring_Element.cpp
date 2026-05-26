#include<bits/stdc++.h>
using namespace std;
class HighestOccurence
{
    public:
    void Hash(int *arr, int n)
    {
        unordered_map<int ,int> hash;
        for(int i=0;i<n;i++)
        {
            hash[arr[i]]++;
        }

        /* cout<<"Hash array: "<<endl;
        for(auto i:hash)    cout<<i.first<<"->"<<i.second; */

        int maxCount=0;
        int maxElement=0;
        for(auto i:hash)
        {
            if(i.second>maxCount)    
            {
                maxCount=i.second;
                maxElement=i.first;
            }
        }
        cout<<"Highest Occurence: "<<maxElement<<endl;
     
    }
};

int main()
{
    HighestOccurence ob;
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)    cin>>arr[i];
    ob.Hash(arr, n);
}