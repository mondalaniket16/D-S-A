/*
For maximum number of non-overlapping intervals, the optimal greedy strategy is:
Always select the interval that finishes earliest.
This is the classic Activity Selection Problem.

[1,3] [2,4] [3,5] [6,7] [5,9]

[1,3] → [3,5] → [6,7]

3

Sorting: O(n log n)
Greedy traversal: O(n)
Overall: O(n log n)
Extra space: O(1) excluding sorting space.

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