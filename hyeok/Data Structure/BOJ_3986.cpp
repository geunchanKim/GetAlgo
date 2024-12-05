#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int n;
    int count = 0;

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        stack<char> s;
        string command;
        cin >> command;
        for(int j = 0; j < command.length(); j++)
        {
            if(s.empty())
            {
                s.push(command[j]);
            }
            else
            {
                if(s.top() == command[j])
                {
                    s.pop();
                }
                else
                {
                    s.push(command[j]);
                }
            }
        }
        if(s.empty())
        {
            count++;
        }
    }
    cout << count << endl;
}