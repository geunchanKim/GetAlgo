#include <iostream>
using namespace std;
int ary[46];

int Fib(int n, int* p)
{
    if(n == 0)
        return ary[n] = 0;
    else if(n == 1)
        return ary[n] = 1;
    if(ary[n] > 0) return ary[n];
    return ary[n] = (Fib(n - 1, ary) + Fib(n - 2, ary));
}

int main()
{
    ios:: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int num;
    cin >> num;

    cout << Fib(num, ary) << '\n';
}