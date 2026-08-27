/*
The weight of N items and their corresponding values are given. 
We have to put these items in a knapsack of weight W such that 
the total value obtained is maximized.

Example 1:
Input:
 val = [60, 100, 120], wt = [10, 20, 30], capacity = 50  
Output:
 240.000000  
Explanation:
  
- Take item 0 (w = 10, v = 60)  
- Take item 1 (w = 20, v = 100)  
- Take 2⁄3 of item 2 (w = 20, v = 80)  
Total value = 60 + 100 + 80 = 240
*/

#include<bits/stdc++.h>
using namespace std;
struct Item
{
    int weight;
    int value;
};

int main()
{
    int n;
    cin>>n;
    int capacity;
    cin>>capacity;
    Item arr[n];   // array of items
    for(int i=0; i<n; i++)  
    {
        cin>>arr[i].weight; 
    }
    for(int i=0; i<n; i++)
    {
        cin>>arr[i].value;
    }
    int w=capacity;
    float p = 0.0;
    for(int i=0; i<n; i++)
    {
        if(arr[i].weight <= w)
        {
            w=w-arr[i].weight;
            p+=arr[i].value;
        }
        else
        {
            p = p + (w*arr[i].value/arr[i].weight);
            break;
        }
    }
    cout<<p;
}
