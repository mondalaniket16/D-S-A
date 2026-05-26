#include<bits/stdc++.h>
using namespace std;
class factorial
{
    public:
    int fact(int f, int i)
    {
        if(i==0)
            return 1;
        if(i==1)
            return f;
        return fact(f*i,i-1);
    }
};
int main()
{
    factorial ob;
    int n;
    cin>>n;
    cout<<"The Factorial of "<<n<<" is: "<<ob.fact(1,n);
}