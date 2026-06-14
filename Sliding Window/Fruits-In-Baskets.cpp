/*
There is only one row of fruit trees on the farm, oriented left to right. 
An integer array called fruits represents the trees, 
where fruits[i] denotes the kind of fruit produced by the ith tree.
The goal is to gather as many fruit as possible, adhering to the owner's stringent rules :

Rule 1: There are two baskets available, and each basket can only contain one kind of fruit. 
The quantity of fruit each basket can contain is unlimited.

Rule 2: Start at any tree, but as you proceed to the right, select exactly one fruit from each tree, 
including the starting tree. One of the baskets must hold the harvested fruits.

Rule #: Once reaching a tree with fruit that cannot fit into any basket, stop.

Return the maximum number of fruits that can be picked.

Examples
Input :fruits = [1, 2, 1]
Output : 3
Explanation : We will start from first tree.
The first tree produces the fruit of kind '1' and we will put that in the first basket.
The second tree produces the fruit of kind '2' and we will put that in the second basket.
The third tree produces the fruit of kind '1' and we have first basket that is already holding fruit of kind '1'. So we will put it in first basket.
Hence we were able to collect total of 3 fruits.


Input : fruits = [1, 2, 3, 2, 2]
Output : 4
Explanation : we will start from second tree.
The first basket contains fruits from second , fourth and fifth.
The second basket will contain fruit from third tree.
Hence we collected total of 4 fruits.
*/

#include<bits/stdc++.h>
using namespace std;

int maxFruitBruteForce(int*arr, int n)  // O(N^2) - max length subarry with atmost 2 distinct fruits
{
    int c;
    int maxFruit=0;
    for(int j=0;j<n;j++)
    {
        c=0;
        unordered_map<int,int> basket;
        for(int i=j;i<n;i++)
        {
            if(basket.find(arr[i])==basket.end() && basket.size()<2)
            {
                basket[arr[i]]=1;
                c++;
            }
            else if(basket.find(arr[i])!=basket.end())
            {
                basket[arr[i]]++;
                c++;
            }
            else if(basket.find(arr[i])==basket.end() && basket.size()==2)
            {
                break;
            }   
        }
        basket.clear();
        maxFruit = max(maxFruit,c);
    }
    return maxFruit;
    
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)    cin>>arr[i];
    cout<<maxFruitBruteForce(arr,n);
}