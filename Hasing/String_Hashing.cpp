/*
a-a=0
b-a=1
c-a=2  Based on ASCII value

Time Complexity: 0(N)

*/

#include<bits/stdc++.h>
using namespace std;
class hashing
{
    public:
    void preCheck(string st, int n)
    {
        int hash[256]={};
        /*
        for(int i=0;i<26;i++)
        {                           Time Complexity: O(N^2)
            for(int j=0;j<n;j++)
            {
                if(i==(st[j]-'a'))
                    hash[i]++;
            }
        }
        */
       for(int i=0;i<n;i++)
       {
            hash[st[i]]++;  //s[i] gives a character - it's ASCII value is considered for the index
       }
        cout<<"Hash array: "<<endl;
        for(int i=0;i<256;i++)   cout<<hash[i]<<", ";
    }
};
int main()
{
    hashing ob;
    int n;
    string st;
    cin>>st;
    n=st.size();
    ob.preCheck(st,n);
}