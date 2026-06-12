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
    string s="";
    int len=0;
    int max=0;
    while(i<n && j<n && i<=j)
    {
     
        if(s.find(st[j])!=-1) // is st[j] present in the substring
        {
            i++;
            s=s.substr(i,j-i);
        }
        else
        {
            s=s+st[j];
        }
        cout<<s<<endl;
        len=j-i+1;
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