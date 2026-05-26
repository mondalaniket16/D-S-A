/* 

Selection sort is an in-place comparison based sorting algorithm. SELECTS THE MINIMUM
- Finds(selects) the Minimum element from the unsorted part and puts it at the beginning(sorted part).
- Time complexity: O(n^2) in all cases.
- Space complexity: O(1) as it is an in-place sorting algorithm.
- Stable: No, it does not maintain the relative order of equal elements.
- Not adaptive: It does not take advantage of any existing order in the input.
- Not suitable for large datasets due to its O(n^2) time complexity.

Example:
Input: [64, 25, 12, 22, 11]
Output: [11, 12, 22, 25, 64]

*/

#include<bits/stdc++.h>
using namespace std;
class Selection_Sort
{
    public:
    void sort(int *arr, int n)
    {
        for(int i=0;i<=n-2;i++)
        {
            int min=i;                // min!=0(not fixed). It should change in every step.
            for(int j=i+1;j<=n-1;j++)
            {
                if(arr[j]<arr[min])
                    min=j;            // Finding index of the min. value in the un-sorted part.
            }
            swap(arr[i],arr[min]);
        }
        for(int i=0;i<n;i++)
            cout<<arr[i]<<", ";
    }
};

int main()
{
    Selection_Sort ob;
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"Original array:"<<endl;
    for(int i=0;i<n;i++)
            cout<<arr[i]<<", ";

    cout<<"\n The sorted array: "<<endl;
    ob.sort(arr,n);
    return 0;
}