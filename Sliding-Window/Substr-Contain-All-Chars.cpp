/*
 Given a string s , consisting only of characters 'a' , 'b' , 'c'.
 Find the number of substrings that contain at least one occurrence of all these characters 'a','b','c'.

Examples
Input : s = "abcba"
Output :  5
Explanation : The substrings containing at least one occurrence of the characters 'a' , 'b' , 'c' are "abc" , "abcb" , "abcba" , "bcba" , "cba".

Input : s = "ccabcc"
Output : 8
Explanation : The substrings containing at least one occurrence of the characters 'a' , 'b' , 'c' are "ccab" , "ccabc" , "ccabcc" , "cab" , "cabc" , "cabcc" , "abc" , "abcc".
*/

#include<bits/stdc++.h>
using namespace std;
 
int bruteForce(string st, int n)
{ 
    int lastSeen[3]={-1,-1,-1};
    int l=0,r=0;
    int count=0;
    while(r<n)
    {
        lastSeen[st[r]-'a']=r;
        count += 1 + min(lastSeen[0],min(lastSeen[1],lastSeen[2]));
        r++;
    }
    return count;
}

int main()
{
    string st;
    cin>>st;
    int n = st.length();
    cout<<bruteForce(st, n);
}