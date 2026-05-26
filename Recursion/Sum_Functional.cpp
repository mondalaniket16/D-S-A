#include<bits/stdc++.h>
using namespace std;
class sum
{
    public:
    int f(int n)
    {
        if(n==0)
            return 0;
        return n+f(n-1);  // functional call is made before the addition, so it will add n to the sum of first n-1 natural numbers and return it
    }
};

int main()
{
    int n;
    cin>>n;
    sum ob;
    cout<<ob.f(n);
}