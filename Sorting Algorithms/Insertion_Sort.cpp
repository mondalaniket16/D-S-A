/*
 Insertion Sort iterates through the input array and at each iteration,
  It removes one element, 
  Finds the location it belongs to in the sorted list,
  And inserts it there. 
  It repeats until no input elements remain.
 - Time complexity: O(n^2) in worst and average case, O(n) in best case when the array is already sorted.
 - Space complexity: O(1) as it is an in-place sorting algorithm.
 - Stable: Yes, it maintains the relative order of equal elements.
 - Adaptive: Yes, it takes advantage of existing order in the input. It performs better on partially sorted arrays.

*/

#include<bits/stdc++.h>
using namespace std;
class InsertionSort
{
    public:
    void sort(int *arr, int n)
    {
        
        for(int i=0;i<n;i++)
        {
           int j=i;
           while(j>0 && arr[j]<arr[j-1])  // Compare the current element with the previous one and swap if necessary. If !true, it doesn't enter the loop.
           {
                swap(arr[j],arr[j-1]);
                j--;
           } 
        }
        for(int i=0;i<n;i++)    cout<<arr[i]<<", ";
    }
};

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)    cin>>arr[i];
    InsertionSort ob;
    cout<<"After sorting "<<endl;
    ob.sort(arr,n);
}