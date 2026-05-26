/*
    Prime number: A number that has only two factors, 1 and itself.
    Time complexity: O(sqrt(n)) because we are checking for factors only till sqrt(n)
*/

#include<bits/stdc++.h> 
using namespace std;
class prime
{
    public:
    bool isprime(int x)
    {
        int c=0;
        if(x<=1)
        {
            return false;
        }
        for(int i=1;i*i<=x;i++)
        {
            if(x%i==0)
            {
                c++;
                if(x/i!=1)
                {
                    c++;
                }
            }
        }
        if(c==2)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    prime ob;
    int n;
    cin>>n;
    if(ob.isprime(n))
    {
        cout<<n<<" is a prime number.";
    }
    else
    {
        cout<<n<<" is not a prime number.";
    }
}