#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;

    priority_queue<int> q;
    for(int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        if(n != 0)
        {
            q.push(n);
        }
        else
        {
            if(q.empty())
            {
                cout << 0 << '\n';
            }
            else
            {
                cout << q.top() << '\n';
                q.pop();
            }
        }
    }
}