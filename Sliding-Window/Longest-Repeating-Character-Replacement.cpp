/*
Given an integer k and a string s, any character in the string can be selected 
and changed to any other uppercase character. 
This operation can be performed up to k times. 
After completing these steps, return the length of the longest substring that contains the same letter.

Input: s = "BAABAABBBAAA", k = 2  
Output: 6  
Explanation: We can change the B at index 0 and 3 (0-based indexing) to A. 
The new string becomes "AAAAAABBBAAA". The substring "AAAAAA" is the longest substring 
with the same letter, and its length is 6. 


Input: s = "AABABBA", k = 1  
Output: 4  
Explanation: We can change one character to get the new string "AABBBBA". 
The substring "BBBB" is the longest with the same character. 
There are other ways to achieve this result as well.
*/

#include<bits/stdc++.h>
using namespace std;

int bruteForce(string st, int k)
{
    int i,r,maxLen=0;
    int maxFreq=0;
    int count=0;
    int n = st.length();
    for(int i=0;i<n;i++)
    {
        unordered_map<char,int> hash;
        for(r=i;r<n;r++)
        {
            hash[st[r]]++;
            maxFreq = max( maxFreq, hash[st[r]]);
            count = (r-i+1) - maxFreq;
            if( count<=k)
            {
                maxLen = max( maxLen, r-i+1);
            }
            else
            {
                break;
            }
        }
    }
    return  maxLen;
}

int optimal(string st, int k)
{
    int n = st.length();
    int l=0,r=0,maxLen=0,maxFreq=0;
    int count=0;
    unordered_map<char,int> hash;
    while(r<n)
    {
        hash[st[r]]++;
        maxFreq = max(maxFreq, hash[st[r]]);
        count = (r-l+1) - maxFreq;
        if(count <= k)
        {
            maxLen = max( maxLen, r-l+1);
        }
        else
        {
            hash[st[l]]--;
            l++;
            // while(count>k)
            // {
            //     hash[st[l]]--;
            //     maxFreq = max(maxFreq, hash[st[l]]);
            //     count = (r-l+1) - maxFreq;
            //     l++;
            // }
        }
        r++;
    }
    return maxLen;
    
}

int main()
{
    string st;
    cin>>st;
    int k;
    cin>>k;
    cout<<optimal(st,k);
}