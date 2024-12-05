#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
    string command;
    cin >> command;
    stack<char> s;

    int answer = 0, tmp = 1;
    for(int i = 0; i < command.length(); i++)
    {
        if(command[i] == '(')
        {
            tmp *= 2;
            s.push('(');
        }
        else if(command[i] == ')')
        {
            if(s.empty() || s.top() != '(')
            {
                answer = 0;
                break;
            }
            if(command[i - 1] == '(')
            {
                answer += tmp;
                tmp /= 2;
                s.pop();
            }
            else
            {
                tmp /= 2;
                s.pop();
            }
        }
        else if(command[i] == '[')
        {
            tmp *= 3;
            s.push('[');
        }
        else if(command[i] == ']')
        {
            if(s.empty() || s.top() != '[')
            {
                answer = 0;
                break;
            }
            if(command[i - 1] == '[')
            {
                answer += tmp;
                tmp /= 3;
                s.pop();
            }
            else
            {
                tmp /= 3;
                s.pop();
            }
        }
    }

    if(!s.empty())
        answer = 0;
    cout << answer << "\n";
}