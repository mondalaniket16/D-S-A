/*

'pair' is a structural container template that links two values together into a single unit. 
These two values can be of the same or completely different data types.

*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
    pair<int,int> data1 = {1,2};
    cout<<data1.first<<endl;
    cout<<data1.second<<endl;

    pair<int,string> data2 = {10,"Messi"};
    cout<<data2.first<<endl;
    cout<<data2.second<<endl;

    pair<int,pair<int,int>> data3 = {1,{2,3}};
    cout<<data3.first<<endl;
    cout<<data3.second.first<<endl;
    cout<<data3.second.second<<endl;

    pair<int,int> arr[] = {{10,20},{30,40},{50,60}};
    int n=3;
    for(int i=0; i<n; i++)
    {
        cout<<arr[i].first<<" "<<arr[i].second<<endl;
    }
}