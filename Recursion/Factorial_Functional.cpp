#include<bits/stdc++.h>
using namespace std;
class factorial
{
    public:
    int fact(int n)
    {
        if(n==0)
            return 1;
        return n*fact(n-1);    
    }
};
int main()
{
    int n;
    cin>>n;
    factorial ob;
    cout<<"The factorial of "<<n<<" is "<<ob.fact(n);
}