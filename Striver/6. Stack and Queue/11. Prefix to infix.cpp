#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/')
        return true;
    return false;
}

string prefixToInfix(string prefix)
{
    stack<string> s;
    int length = prefix.size();
    for (int i = length - 1; i >= 0; i--)
    {
        if (isOperator(prefix[i]))
        {
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
            string temp = "(" + op1 + prefix[i] + op2 + ")";
            s.push(temp);
        }
        else
        {
            s.push(string(1, prefix[i]));
            /*
            : This part creates a string containing a single character.
            1: This specifies the length of the string (which is 1 in this case).
            prefix[i]: This accesses the character at index i in the prefix string.
            s.push(...): This pushes the created string (which is the single character operand) onto the stack s.*/
        }
    }
    return s.top();
}
