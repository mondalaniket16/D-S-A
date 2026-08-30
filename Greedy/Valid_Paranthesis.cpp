/*
Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.

The following rules define a valid string:

Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' 
or a single left parenthesis '(' or an empty string "".
 

Example 1:
Input: s = "()"
Output: true

Example 2:
Input: s = "(*)"
Output: true

Example 3:
Input: s = "(*))"
Output: true
*/

#include<bits/stdc++.h>
using namespace std;

bool checkValidString(string s) 
{
    int n=s.length();
    vector<char> stack;
    int top = -1;
    for(int i=0; i<n; i++)
    {
        if(s[i]=='(')   
        {
            top++; 
            cout<<top<<" ";
            stack.push_back('(');
        }
        if(s[i]==')' && top !=-1)   
        {
            if(stack[top]=='*')
            {
                while(stack[top]=='*')
                {
                    stack.pop_back();
                    top--;
                }
            }
            stack.pop_back();
            top--;
            cout<<top<<" ";
        }
        if(s[i]=='*')
        {
            top++;
            stack.push_back('*');
            cout<<top<<" ";
        }
    }
    if(top==-1) return true;
    else if(stack[top]=='*')     return true;
    else        return false;
}

int main()
{
    string s;
    cin>>s;
    cout<<checkValidString(s);
}