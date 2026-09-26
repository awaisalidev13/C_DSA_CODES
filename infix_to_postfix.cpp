#include <iostream>
#include <stack>
using namespace std;





int pres(char c)
{
    if(c == '+' || c == '-')
    {
        return 1;
    }
    else if(c == '*' || c == '/')
    {
        return 2;
    }
    else
    {
        return 0;
    }
}


void infix_to_postfix(string str)
{
    string res = "";
    stack<char> s;
    for(int i=0 ; i<str.length() ; i++)
    {
    
        if(str[i] >= 'A' && str[i] <= 'Z')
        {
            res += str[i];
        }
        if(str[i] == '(')
        {
            s.push(str[i]);
        }
        if(str[i] == ')')
        {
            while(s.top() != '(')
            {
                res += s.top();
                s.pop();
            }
            s.pop();
        }
        if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
        {
            s.push(str[i]);
        }
    }
    while(!s.empty())
    {
        res += s.top();
        s.pop();
    }

    cout << "Postfix expression: " << res << endl;
}


int main()
{
    string str;
    cout << "Enter the infix expression: ";
    cin >> str;
    infix_to_postfix(str);
    return 0;
  
}