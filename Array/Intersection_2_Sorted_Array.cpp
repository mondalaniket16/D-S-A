/* 
    Given two sorted arrays, find their intersection. The intersection of two arrays is a list that contains the common elements between the two arrays. The common elements should be in the same order as they appear in the original arrays.
    
    Example:
    Input: arr1[] = {1, 2, 4, 5, 6}
            arr2[] = {2, 3, 5, 7}
    
    Output: {2, 5}
*/

#include<bits/stdc++.h>
using namespace std;
class Intersection
{
    public:
    void modify(int *arr1, int *arr2, int n, int m)
    {
        int i=0;
        int j=0;
        vector<int> temp;
        while(i<n && j<m)
        {
            if(arr1[i]==arr2[j])
            {
                temp.push_back(arr1[i]);
                i++;
                j++;
            }
            else if(arr1[i]<arr2[j])
            {
                i++;
            }
            else
            {
                j++;
            }
        }
        while(i<n)
        {
            if(find(temp.begin(),temp.end(),arr1[i])!=temp.end())
            {
                temp.push_back(arr1[i]);
            }
            problem 404
            i++;
        }
        while(j<m)
        {
            if(find(temp.begin(),temp.end(),arr2[j])!=temp.end())
            {
                temp.push_back(arr2[j]);
            }
            j++;
        }
        cout<<"Array after intersection: ";
        for(auto i:temp)      cout<<i<<", ";
    }
};
int main()
{
    Intersection ob;
    int n,m;
    cin>>n;
    cin>>m;
    int arr1[n];
    int arr2[m];
    for(int i=0;i<n;i++)    cin>>arr1[i];
    for(int j=0;j<m;j++)    cin>>arr2[j];
    ob.modify(arr1, arr2, n, m);
    return 0;
}