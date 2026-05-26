#include<bits/stdc++.h>
using namespace std;
class fibonacci
{
    public:
    void print(int i, int n, int a, int b)
    {
        if(i>n)
            return;
        if(n==1)
        {
            cout<<"0";
            return;
        }
        if(n==2)
        {
            cout<<"0, 1";
            return;
        }
        cout<<a<<", ";
        print(i+1,n,b,a+b);
    }
};
int main()
{
    int n;
    cin>>n;
    fibonacci ob;
    cout<<"The first "<<n<<" terms of Fibonacci Series are: ";
    ob.print(1,n,0,1);
}