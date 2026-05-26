#include<bits/stdc++.h>
using namespace std;
class MergeArrays
{
    public:
    void merge(int *arr1, int *arr2, int *arr3, int n1, int n2)
    {
        int i=0;
        int j=0;
        int k=0;
        while(i<n1 && j<n2)
        {
            if(arr1[i]<=arr2[j])
                arr3[k++]=arr1[i++];

            else
                arr3[k++]=arr2[j++];
        }
        
        while(j<n2)
            arr3[k++]=arr2[j++];

        while(i<n1)
            arr3[k++]=arr1[i++];
    }
};
int main()
{
    MergeArrays ob;

    int n1;
    cout<<"\n Enter length of 1st array: "<<endl;
    cin>>n1;
    int arr1[n1];
    for(int i=0;i<n1;i++)    cin>>arr1[i];

    cout<<"\n Enter length of 1st array: "<<endl;
    int n2;
    cin>>n2;
    int arr2[n2];
    for(int i=0;i<n2;i++)   cin>>arr2[i];

    int arr3[n1+n2]={};

    ob.merge(arr1, arr2, arr3, n1, n2);
    cout<<"\n Merged Arrays: "<<endl;
    for(int i=0;i<n1+n2;i++)    cout<<arr3[i]<<", ";
}