#include<bits/stdc++.h>
using namespace std;
class fibonacci  // f(N) = f(N-1) + f(N-2)
{
    public:
    int print(int n)
    {
        if(n<=1);
            return n;
        int last=print(n-1);
        int slast=print(n-2);
        return last+slast;
    }

};
int main()
{
    int n;
    cin>>n;
    fibonacci ob;
    cout<<"The "<<n<<"th Fibonacci number is: "<<ob.print(n);
}


/* Recursion Tree
                
                f(4) 
             __/   \__
            /         \
        f(3)           f(2)    
       /    \         /    \
    f(2)    f(1)   f(1)    F(0)
   /    \
f(1)    F(0)


*/