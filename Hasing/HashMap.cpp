/* 
* Map is a data structure that stores key-value pairs. STL CPP
* It uses a hash function to compute an index into an array of buckets or slots, 
  from which the desired value can be found.
* Map alsways stores in sorted order of keys.
* Time Complexity: O(N) for building the hash map, O(1) for lookups on average.

Input: [1, 2, 2, 3, 5]

1->2
2->2
3->1
5->1

*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    //Pre-Fetch
    map<int,int> hash;
    for(int i=0;i<n;i++)
    {
        hash[arr[i]]++;
    }

    for(auto i:hash)
    {
        cout<<i.first<<"->"<<i.second<<endl;
    }
}