#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int*ary = new int[n];

    for(int i = 1; i <= n; i++)
    {
        int k = n - i;
        cin >> ary[k];
    }

    deque<int> dq;

    int card = 1;
    for(int i = 0; i < n; i++)
    {
        if(ary[i] == 1)
        {
            dq.push_front(card);
        }
        else if(ary[i] == 2)
        {
            if(dq.empty())
            {
                dq.push_front(card);
            }
            else {
            int tmp;
            tmp = dq.front();
            dq.pop_front();
            dq.push_front(card);
            dq.push_front(tmp);
            }
        }
        else if(ary[i] == 3)
        {
            dq.push_back(card);
        }

        card++;
    }

    for(int i = 0; i < dq.size(); i++)
    {
        cout << dq[i];
        if(i < dq.size() -1)
        {
            cout << " ";
        }
    }
    cout << endl;

    delete[] ary;
}