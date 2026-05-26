/* 
* Map is a data structure that stores key-value pairs. STL CPP
* It uses a hash function to compute an index into an array of buckets or slots, 
  from which the desired value can be found.
* Map alsways stores in sorted order of keys.
* Time Complexity: O(N) for building the hash map, O(1) for lookups on average.

Input: "ababc"

a->2
b->2    
c->1

*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    //Pre-Fetch
    map<char,int> hash;
    for(int i=0;i<s.length();i++)
    {
        hash[s[i]]++;
    }

    for(auto i:hash)
    {
        cout<<i.first<<"->"<<i.second<<endl;
    }
}