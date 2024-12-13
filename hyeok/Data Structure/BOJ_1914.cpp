#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void hanoi (int n, int from, int tmp, int to)
{
    if(n == 1)
    {
        cout << from << ' ' << to << '\n';
        return;
    }
    else
    {
        hanoi (n - 1, from, to, tmp);
        cout << from << ' ' << to << '\n';
        hanoi (n - 1, tmp, from, to);
    }
}

int main()
{
    ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

    int num;
    cin >> num;

    string a = to_string(pow(2, num));
    int x = a.find('.');
    a = a.substr(0, x);
    a[a.length() - 1] -= 1;
    cout << a << '\n';

    if(num <= 20) {
        hanoi(num, 1, 2, 3);
    }

    return 0;
}