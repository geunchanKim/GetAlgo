#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;
    queue<int> q;
    string command;

    for(int i = 0; i < n; i++)
    {
        cin >> command;

        if(command == "push")
        {
            int num;
            cin >> num;
            q.push(num);
        }
        else if(command == "pop")
        {
            if(q.empty())
            { cout << -1 << "\n";}
            else
            {
                cout << q.front() << "\n";
                q.pop();
            }
        }
        else if(command == "size")
        {
            cout << q.size() << "\n";
        }
        else if(command == "empty")
        {
            cout << q.empty() << "\n";
        }
        else if(command == "front")
        {
            if(q.empty())
            { cout << -1 << "\n";}
            else
            {
                cout << q.front() << "\n";
            }
        }
        else if(command == "back")
        {
            if(q.empty())
            { cout << -1 << "\n";}
            else
            {
                cout << q.back() << "\n";
            }
        }
    }
}