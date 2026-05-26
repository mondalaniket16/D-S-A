#include<bits/stdc++.h>
using namespace std;
class RemoveDuplicates
{
    public:
    void remove(int *arr, int n)
    {
        vector<int> temp;
        temp.push_back(arr[0]);
        for(int i=1;i<n;i++)
        {
            if(find(temp.begin(),temp.end(),arr[i])==temp.end())  // if element not found find() returns vector.end()
            {
                temp.push_back(arr[i]);
            }
        }
        for(auto i:temp)    cout<<i<<", ";
    }
};

int main()
{
    RemoveDuplicates ob;
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)    cin>>arr[i];
    cout<<"Array after removing duplicates: ";
    ob.remove(arr,n);
}