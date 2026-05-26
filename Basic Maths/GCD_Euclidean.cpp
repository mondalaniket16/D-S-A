/*
    Euclidean Algorithm states that gcd(a,b)=acd(a-b,b) given a>b and we can apply this recusively untill one becomes 0, then the other will be gcd of the two

    also: gcd(a,b)=gcd(a%b,b)

    Time complexity: O(log(min(a,b)))
*/

#include<bits/stdc++.h>
using namespace std;
class gcd
{
    public:
    int calc(int a, int b)
    {
        while(a>=0 && b>0)
        {
            if(a>b)
                a%=b;
            else
                b%=a;
        }
        if(a==0)
            return b;
        else
            return a;
    }
};
int main()
{
    gcd ob;
    int a,b;
    cin>>a>>b;
    cout<<"GCD of "<<a<<" and "<<b<<" is: "<<ob.calc(a,b);
    return 0;
}