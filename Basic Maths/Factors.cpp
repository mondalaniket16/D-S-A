/*
    Factors of a entered number
    Ex: 36

    1*36=36
    2*18=36
    3*12=36
    4*9=36
    6*6=36
    So, factors of 36 are: 1, 2, 3, 4, 6, 9, 12, 18, 36 and we found them in 6 iterations only. 
    If we had used i<=x, then we would have found the factors in 36 iterations.

    Time complexity: O(sqrt(n)) because we are checking for factors only till sqrt(n)
*/

#include<bits/stdc++.h>
using namespace std;
class factors
{
    public:
    void print(int x)
    {
        vector<int> l;
        cout<<"Factors of "<<x<<" are: ";
        for(int i=1;i*i<=x;i++)  // i<=sqrt(x) makes 0(sqrt(x)) time complexity
        {
            if(x%i==0)
            {
                l.push_back(i);
                if(x/i!=i)
                {
                    l.push_back(x/i);
                }
            }
        }
        sort(l.begin(), l.end());
        for(int i=0;i<l.size();i++)
        {
            cout<<l[i]<<", ";
        }
    }
};

int main()
{
    factors ob;
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    ob.print(n);
    return 0;
}