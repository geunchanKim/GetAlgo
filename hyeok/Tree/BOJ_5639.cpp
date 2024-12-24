#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
void pre_to_post (int st, int end)
{
    if(st >= end)
        return;
    if(st == end - 1)
    {
        cout << v[st] << '\n';
        return;
    }

    int idx = st + 1;
    while(idx < end)
    {
        if(v[st] < v[idx]) break;
        idx++;
    }
    pre_to_post(st + 1, idx);
    pre_to_post(idx, end);
    cout << v[st] << '\n';
    return;
}

int main()
{   
    int n;
    while(cin >> n)
        v.push_back(n);
    pre_to_post(0, v.size());
    return 0;
}