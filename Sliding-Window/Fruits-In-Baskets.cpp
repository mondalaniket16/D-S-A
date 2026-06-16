/*
There is only one row of fruit trees on the farm, oriented left to right. 
An integer fruitsay called fruits represents the trees, 
where fruits[i] denotes the kind of fruit produced by the ith tree.
The goal is to gather as many fruit as possible, adhering to the owner's stringent rules :

Rule 1: There are two baskets available, and each basket can only contain one kind of fruit. 
The quantity of fruit each basket can contain is unlimited.

Rule 2: Start at any tree, but as you proceed to the right, select exactly one fruit from each tree, 
including the starting tree. One of the baskets must fruits[l] the harvested fruits.

Rule #: Once reaching a tree with fruit that cannot fit into any basket, stop.

Return the maximum number of fruits that can be picked.

Examples
Input :fruits = [1, 2, 1]
Output : 3
Explanation : We will start from first tree.
The first tree produces the fruit of kind '1' and we will put that in the first basket.
The second tree produces the fruit of kind '2' and we will put that in the second basket.
The third tree produces the fruit of kind '1' and we have first basket that is already fruits[l]ing fruit of kind '1'. So we will put it in first basket.
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

int maxFruitBruteForce(int*fruits, int n)     // O(N^2) max length subfruitsy with atmost 2 distinct fruits
{
    int maxLen=0;
    for(int i=0;i<n;i++)
    {
        set<int> basket;        // set is s data structure that stores distinct elements
        for(int j=i;j<n;j++)
        {
            basket.insert(fruits[j]);
            if(basket.size()<=2) maxLen = max(maxLen,j-i+1);
            else break;
        }
    }
    return maxLen;
}

int maxFruitOptimal(int* fruits, int n) // O(2N)   time taken for erase() and size() are ignored
{
    unordered_map<int,int> basket;  // SC: O(3) map contains atmost 3 elements 
    int l=0,r=0;
    int maxLen=0;
    while(r<n)
    {
        basket[fruits[r]]++;
        if(basket.size()>2)
        {
            while(basket.size()!=2)
            {
                basket[fruits[l]]--;
                if(basket[fruits[l]]==0)    basket.erase(fruits[l]);
                l++;
            }
        }
        if(basket.size()<=2)    maxLen = max(maxLen,r-l+1);
        r++;
    }
    return maxLen;
}

int main()
{
    int n;
    cin>>n;
    int fruits[n];
    for(int i=0;i<n;i++)    cin>>fruits[i];
    // cout<<maxFruitBruteForce(fruits,n);
    // cout<<maxFruitBruteForce(fruits,n);
    cout<<maxFruitOptimal(fruits,n);

}