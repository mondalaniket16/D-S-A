/* Union of Two Sorted Arrays
 Union of two sorted arrays is the set of distinct elements present in either of the two arrays.
 Example:

 Input: arr1[] = {1, 2, 4, 5, 6}
        arr2[] = {2, 3, 5, 7}

 Output: {1, 2, 3, 4, 5, 6, 7}
 Time Complexity: O(n+m) where n and m are the sizes of the two arrays. 
 Auxiliary Space: O(n+m) in worst case when there are no common elements in the two arrays. O(1) if we ignore the space required for storing the result.

*/

#include<bits/stdc++.h>
using namespace std;
class Union
{
    public:
    void modify_using_set(int *arr1, int *arr2, int n, int m)  // O(n+m) ; O(n+m)
    {
        set<int> s;
        for(int i=0;i<n;i++)    s.insert(arr1[i]);
        for(int i=0;i<m;i++)    s.insert(arr2[i]);
        cout<<"New array after Union: ";
        for(auto i:s)   cout<<i<<", ";
    }

    void modify_using_2pointer(int *arr1, int *arr2, int n, int m) // O(n+m) ; O(n+m)
    {
        int i=0;
        int j=0;
        vector<int> temp;
        while(i<n && j<m)
        {
            if(arr1[i]<arr2[j] && find(temp.begin(), temp.end(), arr1[i])==temp.end())
            {
                temp.push_back(arr1[i]);
                i++;
            }
            else if(arr1[i]>arr2[j] && find(temp.begin(), temp.end(), arr2[j])==temp.end())
            {
                temp.push_back(arr2[j]);
                j++;
            }
            else
            {
                if(find(temp.begin(), temp.end(), arr1[i])==temp.end())
                {
                    temp.push_back(arr1[i]);
                }
                i++;
                j++;
            }
        }
        while(i<n)
        {
            if(find(temp.begin(), temp.end(), arr1[i])==temp.end())
            {
                temp.push_back(arr1[i]);
                i++;
            }
        }
        while(j<m)
        {
            if(find(temp.begin(), temp.end(), arr2[j])==temp.end())
            {
                temp.push_back(arr2[j]);
                j++;
            }
        }
        cout<<"New array after Union: ";
        for(int i=0;i<temp.size();i++)      cout<<temp[i]<<", ";
    }

    void modify(int *arr1, int *arr2, int n, int m)
    {
        set<int> s;
        for(int i=0;i<n-1;i++)
        {
            if(arr1[i]<arr1[i+1])
            {
                s.insert(arr1[i]);
            }
        }
        s.insert(arr1[n-1]);

        for(int j=0;j<m-1;j++)
        {
            if(arr2[j]<arr2[j+2])
            {
                s.insert(arr2[j]);
            }
        }
        s.insert(arr2[m-1]);
        cout<<"New array after Union: ";
        for(auto i:s)   cout<<i<<", ";
    }
};
int main()
{
    Union ob;
    int n,m;
    cin>>n;
    cin>>m;
    int arr1[n];
    int arr2[m];
    for(int i=0;i<n;i++)    cin>>arr1[i];
    for(int i=0;i<m;i++)    cin>>arr2[i];
    ob.modify_using_2pointer(arr1,arr2,n,m);
    return 0;
}