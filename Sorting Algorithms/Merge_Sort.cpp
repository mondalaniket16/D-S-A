/*

Merge Sort is a divide and conquer algorithm. 
  Sorts an array by recursively dividing it into smaller subarrays 
  sorting those subarrays and merging them back together in the correct order.

- Time Complexity: O(n log n) in all cases (best, average, worst)
- Space Complexity: O(n) due to the temporary array used for merging  
- Stability: Merge Sort is a stable sorting algorithm, meaning that it preserves the relative order of equal elements.
- In-place: Merge Sort is not an in-place sorting algorithm, as it requires additional space for the temporary array used during the merging process.
- Suitable for large datasets:  especially when the data is stored on external storage (like disk) minimizes the number of comparisons and movements required.

*/

#include<bits/stdc++.h>
using namespace std;
class MergeSort
{
    public:

    void merge(int *arr, int low, int mid, int high)
    {
        int i=low;
        int j=mid+1;
        vector<int> temp;
        while(i<=mid && j<=high)
        {
            if(arr[i]<=arr[j])
            {
                temp.push_back(arr[i]);
                i++;
            }
            else
            {
                temp.push_back(arr[j]);
                j++;
            }
        }
        while(i<=mid)
        {
            temp.push_back(arr[i]);
            i++;
        }
        while(j<=high)
        {
            temp.push_back(arr[j]);
            j++;
        }
        
        for(int i=low;i<=high;i++)
            arr[i]=temp[i-low];
    }

    void mergeSort(int *arr, int low, int high)
    {
        if(low>=high)   return;
        int mid=(low+high)/2;
        mergeSort(arr, low, mid);   // left half
        mergeSort(arr, mid+1, high);  // right half
        merge(arr, low, mid, high);
    }
};

int main()
{
    MergeSort ob;
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)    cin>>arr[i];
    cout<<"Sorted array: "<<endl;
    ob.mergeSort(arr,0,n-1);
    for(int i=0;i<n;i++)    cout<<arr[i]<<", ";
}