#include <iostream>
using namespace std;

int cnt = 0;

unsigned long long fib(unsigned long long n){
    cnt++;
    if(n <= 1)
        return n;
    else
        return fib(n - 1) + fib(n - 2);
}

int main(){
    unsigned long long N;
    cin >> N;
    cout << fib(N) << "\n";
    cout << cnt;
}