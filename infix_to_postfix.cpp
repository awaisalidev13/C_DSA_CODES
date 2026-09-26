#include <iostream>
#include <stack>

using namespace std;

int main()
{
    string str;
    cout << "Enter the infix expression: ";
    cin >> str;

    stack<char> s;
    for(int i=0 ; i<str.length() ; i++)
    {
    
        if(str[i] >= 'A' && str[i] <= 'Z')
        {
            cout << str[i];
        }
        
    }
    
}