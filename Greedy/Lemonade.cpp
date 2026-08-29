/*
At a lemonade stand, each lemonade costs $5. Customers are standing in a queue to buy from you 
and order one at a time (in the order specified by bills). 
Each customer will only buy one lemonade and pay with either a $5, $10, or $20 bill. 
You must provide the correct change to each customer so that the net transaction is that the customer pays $5.
Note that you do not have any change in hand at first.

Given an integer array bills where bills[i] is the bill the ith customer pays, 
return true if you can provide every customer with the correct change, or false otherwise.

Example 1:
Input: bills = [5,5,5,10,20]
Output: true
Explanation: 
From the first 3 customers, we collect three $5 bills in order.
From the fourth customer, we collect a $10 bill and give back a $5.
From the fifth customer, we give a $10 bill and a $5 bill.
Since all customers got correct change, we output true.

Example 2:
Input: bills = [5,5,10,10,20]
Output: false
Explanation: 
From the first two customers in order, we collect two $5 bills.
For the next two customers in order, we collect a $10 bill and give back a $5 bill.
For the last customer, we can not give the change of $15 back because we only have two $10 bills.
Since not every customer received the correct change, the answer is false.
*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int bills[n];
    map<int,int> change = {{5,0},{10,0},{20,0}};
    int flg=1;
    int count=0;
    for(int i=0; i<n; i++)cin>>bills[i];
    for(int i=0; i<n; i++)
    {
        if(bills[i]==5) 
        {
            change[5]++;
            count++;
        }
        else if(bills[i]==10)
        {
            if(change[5]>0)
            {
                change[10]++;
                change[5]--;
                count++;
            }
            else
            {
                flg=0;
                cout<<false<<endl;
                break;
            }
        }
        else if(bills[i]==20)
        {
            if(change[10]>0 && change[5]>0)
            {
                change[20]++;
                change[10]--;
                change[5]--;
                count++;
            }
            else if (5*change[5]>=15)
            {
                change[5]-=3;
                change[20]++;
                count++;
            }
            else
            {
                flg=0;
                cout<<false<<endl;
                break;
            }
        }
    }
    if(flg==1) cout<<true<<endl;
    cout<<"Total customers served = "<<count;
}