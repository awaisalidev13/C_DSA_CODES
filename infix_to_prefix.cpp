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

string reverse(string str)
{
    string res = "";

    for(int i = str.length() - 1 ; i>=0 ; i--)
    {
        res+= str[i];
    }

    return res;
}

void rep_brack(string &str)
{
    for(int i=0 ; i<str.length() ; i++)
    {
        if(str[i] == '(')
        {
            str[i] = ')';
        }
        else if(str[i] == ')')
        {
            str[i] = '(';
        }
    }

}
string infix_to_postfix(string str)
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
            while(!s.empty() && s.top() != '(')
            {
                res += s.top();
                s.pop();
            }
            s.pop();
        }
        if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
        {
            while(!s.empty() && (pres(s.top()) >= pres(str[i])))
            {
                res += s.top();
                s.pop();

            }
            
            s.push(str[i]);
        }
    }
    while(!s.empty())
    {
        res += s.top();
        s.pop();
    }

    return res;
}



void infix_to_prefix(string str)
{
    string eq = reverse(str);
    rep_brack(eq);
    string res = infix_to_postfix(eq);
    
    cout << "Prefix result = " << reverse(res) << endl;
}









int main()
{
    cout << "Enter a string : ";
    string str;
    cin >> str;

    infix_to_prefix(str);
    return 0;
}