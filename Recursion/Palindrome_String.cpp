#include<bits/stdc++.h>
using namespace std;
class PalString
{
    public:
/*    bool check(string st, int n)
    {
        int l=0;
        int r=n-1;
        while(l<r)
        {
            if(st[l]!=st[r])
                return false;
            l++;
            r--;
        }
        return true;
    } */

    bool pal_check(string st, int l, int r)
    {
        if(l>r)
            return false;
        if(st[l]!=st[r])  // if st[l]!=st[r] it means it's not palindrome
            return false;
        else
        {
            if(l<=r)
                return true;  // st[l]=st[r] and l is < or = r in case of even and odd length strings respectively.
        }
        pal_check(st,l++,r--);
    }

};
int main()
{
    int l,r,n;
    PalString ob;
    string st;
    cin>>st;
    n=st.length();
    if(ob.pal_check(st,0,n-1))
        cout<<"Palindrome";
    else
        cout<<"Not Palindrome";
}

