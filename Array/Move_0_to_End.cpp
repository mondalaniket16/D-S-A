#include<bits/stdc++.h>
using namespace std;
class MoveZeroes
{
    public:
    void zeroes(int *arr, int n)
    {
        /* int c=0;                 // Brute Force   O(N^2)  O(1)
        for(int i=0;i<n-1;i++)
        {
            if(arr[i]==0)
            {
                c++;
                int j=i;
                int k=j+1;
                while(j<n-1)
                {
                    if(arr[k]!=0)
                    {
                        arr[j]=arr[k];
                        j++;
                        k++;
                    }
                    else
                    {
                        c++;
                        k++;
                    }
                }
            }
        }
        for(int i=n-1;i>=0;i--)
        {
            if(c==0)    break;
            arr[i]=0;
            c--;
        } */


        int j=-1;
        for(int i=0;i<n;i++)  // find index of first 0
        {
            if(arr[i]==0)
            {
                j=i;
                break;
            }
        }
        if(j==-1) // if no zero found
        {
            cout<<"Array contains no 0's"<<endl;
            return;
        }
        
        for(int i=j+1;i<n;i++) // i gets incremented anyway but j is incremented only when swap occurs and it points to the next 0
        {
            if(arr[i]!=0) // if element is non zero then only swap
            {
                swap(arr[i],arr[j]);
                j++;  // j always point to a 0 element
            }
        }
    }
};
int main()
{
    MoveZeroes ob;
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)    cin>>arr[i];
    ob.zeroes(arr,n);
    cout<<"Modified array: ";
    for(int i=0;i<n;i++)    cout<<arr[i]<<", ";
}