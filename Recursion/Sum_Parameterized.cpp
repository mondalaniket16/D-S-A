#include<bits/stdc++.h>
using namespace std;
class sum
{
    public:
    int f(int sum, int n)
    {
        if(n==0)
            return sum;
        return f(sum+n,n-1);
    }
};
int main()
{
    int n;
    cin>>n;
    sum ob;
    cout<<ob.f(0,n);
}