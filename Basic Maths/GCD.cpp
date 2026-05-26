/* GCD or Greatest Common Divisor of two numbers is the largest positive integer 
*  that divides both the numbers without a remainder.

*  Time complexity: O(min(a,b)) because gcd won't be greater than min(a,b)
*/

#include<iostream>

using namespace std;
class gcd
{
    public:
    int calc(int a, int b)
    {
        int temp=1;
        int gcd=1;
        int c=min(a, b);
        while(temp<=c)
        {
            if(a%temp==0 && b%temp==0)
            {
                    gcd=temp;
            }
            temp++;
        }
        return gcd;
    }
};

int main()
{
    gcd ob;
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;
    cout << "GCD of " << a << " and " << b << " is: " << ob.calc(a, b) << endl;
    return 0;
}
