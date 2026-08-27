/*
Vector is a sequence container that represents a dynamic array.
Vectors can grow or shrink in size automatically as you add or remove elements.
*/

#include<bits/stdc++.h>
using namespace std;
void print(vector<int> v)
{
    for(auto i:v)
    {
        cout<<i<<" ";   // traverse through the vector
    }
    cout<<"\n";
}
int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);

    int arr[]={3,4,5};
    int n=3;
    v.insert(v.end(),arr,arr+n);  // add an array to a vector
    print(v);
    
    vector<int> vec(5,100);   // create a vector of size n, containing same element
    print(vec);

    vector<int> a(5);   // create a vector containing all 0 
    print(a);

    vector<int> vct(vec);  // copy a vector to another
    print(vct);

    vector<pair<int,int>> duel = {{10,20},{30,40},{50,60}};  // vector containing pair of elements
    for(auto i:duel)
    {
        cout<<i.first<<" "<<i.second<<endl;
    }

    for(vector<int>::iterator it=v.begin(); it!=v.end(); it++) // another way to iterate an vector
    {
        cout<<*(it)<<" ";
    }
}