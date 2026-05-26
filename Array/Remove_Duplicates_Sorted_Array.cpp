#include<bits/stdc++.h>
using namespace std;
class RemoveDuplicates
{
    public:

    void remove(int *arr, int n)
    { 
        vector<int> temp;
        for(int i=0;i<n;i++)
        {
            temp.push_back(arr[i]);
            int j=i;
            while(j<n)
            {
                if(arr[j]==arr[j+1])
                {
                    i++;
                    j++;
                }
                else
                    break;
            }
        }
        for(auto i:temp)
        {
            cout<<i<<", ";
        }
    } 

    void remove_using_vector(int *arr, int n)
    {
        vector<int> temp;
        temp.push_back(arr[0]);
        int j=0;
        while(j<n-1)
        {
            if(arr[j]==arr[j+1])
            {
                j++;
            }
            else
            {
                temp.push_back(arr[j+1]);
                j++;
            }
        }
        for(auto i:temp)
        {
            cout<<i<<", ";
        }
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
