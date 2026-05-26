/*
Bubble Sort PUSHES THE LARGEST ELEMENT TO THE LAST by ADJACENT SWAPPING the elements if they are in wrong order.
* A sorted array starts to appear from the end(back)
* No. of iterations reduces by 1 after each step
- Time complexity: O(N^2) in best, average case
- Best case O(N) if already sorted no need for swapping
- Space complexity: O(1) as it is an in-place sorting algorithm.
- Stable: Yes, it maintains the relative order of equal elements.
- Not adaptive: It does not take advantage of any existing order in the input.
- Not suitable for large datasets due to its O(n^2) time complexity.

*/

#include<bits/stdc++.h>
using namespace std;    
class BubbleSort
{
    public:
    void sort(int*arr, int n)
    {
        int flg=0;
        for(int i=0;i<n-1;i++)
        {
            for(int j=0;j<=n-i-1;j++)
            {
                if(arr[j]>arr[j+1])
                {
                    swap(arr[j],arr[j+1]);
                    flg=1;
                }
            }
            if(flg==0) break;
        }
        for(int i=0;i<n;i++)
        {
            cout<<arr[i]<<", ";
        }
    }
};
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)    cin>>arr[i];
    cout<<"After Swapping: "<<endl;
    BubbleSort ob;
    ob.sort(arr,n);
}