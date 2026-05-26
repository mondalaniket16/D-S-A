#include<bits/stdc++.h>
using namespace std;
class recursion
{
    public:
    void f(int i, int n)
    {
        if(i>n)
            return;
        f(i+1,n);
        cout<<i<<", ";
    }
};

int main()
{
    recursion ob;
    int n;
    cin>>n;
    ob.f(1,n);
}