/*

Given a string, S. Find the length of the longest substring without repeating characters.

Example 1:
Input:
 S = "abcddabac"  
Output:
 4  
Explanation:
 The longest substring with distinct characters is "abcd", which has a length of 4.

Example 2:
Input:
 S = "aaabbbccc"  
Output:
 2  
Explanation:
 The longest substrings with distinct characters are "ab" and "bc", both having a length of 2.
*/

#include<bits/stdc++.h>
using namespace std;

int longestSubstringBruteForce(string st, int n)        // O(N^2)
{
    int len=0;
    int max=0;
    for(int i=0;i<n;i++)
    {
        string s="";
        for(int j=i;j<n;j++)
        {
            if(s.find(st[j])==-1)
            {
                s=s+st[j];
                // s = st.substr(i,j+1); // function to create substrings from strings st.substr() 
                // cout<<s<<endl;
            }
            else
            {
                len=s.length();
                break;
            }
        }
        if(len>max) max=len;
    }   
    return max;
}

int longestSubstringOptimal(string st, int n)
{
    int i=0;
    int j=0;
    int max=0;
    int len=0;
    map<char,int> hash;
    while(j<n)
    {
        
        if(hash.find(st[j])!=hash.end()) // if element is present in hash
        {
            if(hash[st[j]]>=i)       // check exisitng index is less than i or not
            {
                i=hash[st[j]]+1;        // place i after the previous index of the element
            }
        }
        len=j-i+1;
        hash[st[j]]=j;      // update the index of the element to new index j
        j++;
        if(len>max) max=len;
    }
    return max;
}

int main()
{
    string st;
    cin>>st;
    cout<<st<<endl;
    int n = st.length();
    // cout<<longestSubstringBruteForce(st,n);
    cout<<longestSubstringOptimal(st,n);
}