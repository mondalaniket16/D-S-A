/* A single recursive function can replace a single loop 
   For nested foor loop we need a recursive function wihtin another recursive function 
*/

#include<bits/stdc++.h>
using namespace std;
class RecursionBubbleSort
{
    public:
    /* void bubbleSort(int *arr,int n)
    {
        for(int i=0;i<n-1;i++)
        {
            for(int j=0;j<n-1-i;j++)
            {
                if(arr[j]>arr[j+1])
                    swap(arr[j],arr[j+1]);
            }
        }
    } */

    void bubbleSort(int *arr, int i, int n)
    {
        if(i<0) return;
        bubbleSort(arr,i-1,n);       
        swapFunction(arr,n-i+1);
    }

    void swapFunction(int *arr,int j)
    {
        if(j<0) return;
        if(arr[j]>arr[j+1])
            swap(arr[j],arr[j+1]);
        swapFunction(arr,j-1);
    }
};

int main()
{
    RecursionBubbleSort ob;
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)    cin>>arr[i];
    cout<<"Sorted array: "<<endl;
    ob.bubbleSort(arr, n-2, n);
    for(int i=0;i<n;i++)    cout<<arr[i]<<", ";
}
