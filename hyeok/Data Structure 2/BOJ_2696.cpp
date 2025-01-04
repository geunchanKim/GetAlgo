#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void middle_value()
{
    int num, middle;
    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;
    vector<int> ans;

    cin >> num;
    cin >> middle;
    ans.push_back(middle);
    for(int i = 2; i <= num; i++)
    {
        int a;
        cin >> a;
        if(a < middle)
            maxheap.push(a);
        else
            minheap.push(a);
        if(i % 2 == 0) continue;
        else if(maxheap.size() < minheap.size())
        {
            maxheap.push(middle);
            middle = minheap.top();
            minheap.pop();
            ans.push_back(middle);
        }
        else if(minheap.size() < maxheap.size())
        {
            minheap.push(middle);
            middle = maxheap.top();
            maxheap.pop();
            ans.push_back(middle);
        }
        else
            ans.push_back(middle);
    }

    cout << num/2 + 1 << '\n';
    for(int i = 0; i < ans.size(); i++)
    {
        if(i % 10 == 0 && i != 0)
            cout << '\n';
        cout << ans[i] << ' ';
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        middle_value();
        cout << '\n';
    }
    return 0;
}