/*

Quick Sort is a Divide and Conquer Algorithm.
 It picks an element as pivot and partitions the given array around the picked pivot.
 Smaller elements on left and greater elements on right.
 
 - Time Complexity: O(N log N) on average and O(N^2) in the worst case (when the smallest or largest element is always chosen as the pivot).
 - Space Complexity: O(log N) on average and O(N) in the worst case (when the smallest or largest element is always chosen as the pivot).
 - Stable: No, Quick Sort is not a stable sorting algorithm.
 - In-place: Yes, Quick Sort is an in-place sorting algorithm as it does not require any additional data structures for sorting.
 - Not adaptive: Quick Sort does not take advantage of any existing order in the input data, so it is not an adaptive sorting algorithm.
 - Efficienct and Simple, especially for large datasets.

*/

#include<bits/stdc++.h>
using namespace std;
class QuickSort
{
    public:

    int partition(int *arr, int low, int high)
    {
        int pivot=arr[low];   // we take the first element as pivot
        int i=low;
        int j=high;
        while(i<j)   // till j doesn't cross i
        {
            while(arr[i]<=pivot && i<=high-1)   // i searches for an element greater than pivot
                i++;
            while(arr[j]>pivot && j>=low+1)     // j searches for an element smaller than or equal to pivot
                j--;
            if(i<j)                            // if i and j haven't crossed, then swap the elements at i and j
                swap(arr[i],arr[j]);
        }
        swap(arr[j],arr[low]);   // put the pivot in correct position
        return j; // partition index
    }

    void qs(int *arr, int low, int high)
    {
        if(low<high)
        {
            int partitionIndex=partition(arr,low,high);  // returns the partition index
            qs(arr,low,partitionIndex-1);                // left half
            qs(arr,partitionIndex+1,high);               // right half
        }
        else
            return;
    }
};

int main()
{
    QuickSort ob;
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)    cin>>arr[i];
    cout<<"Sorted Array: "<<endl;
    ob.qs(arr,0,n-1);
    for(int i=0;i<n;i++)    cout<<arr[i]<<", ";
}