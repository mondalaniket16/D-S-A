/*

*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<pair<int,int>> arr;
    int start[n];
    int finish[n];
    for(int i=0; i<n; i++) cin>>start[i];
    for(int i=0; i<n ;i++) cin>>finish[i];
    for(int i=0; i<n ;i++)
    {
        arr.push_back({start[i],finish[i]});
    }

    sort(arr.begin(), arr.end(), [](pair<int,int> a, pair<int,int> b){ return a.second < b.second; });

    int count = 0;
    int lastFinish = 0;
    for(auto it :arr)   
    {
        if(it.first >= lastFinish)
        {
            count++;
            lastFinish = it.second;
            cout<<it.first<<","<<it.second<<endl;
        }
    }
    cout<<count;
}