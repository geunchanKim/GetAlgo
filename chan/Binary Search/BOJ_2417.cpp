#include <iostream>
#include <cmath>

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

using namespace std;

typedef unsigned long long ull;

int main(){
    FASTIO;
    long long n;
    cin >> n;
    if(n <= 0){
        cout << 0 << '\n';
        return 0;
    }
    ull left = 0, right = 3037000500ULL, ans = 0;
    while(left <= right){
        ull mid = (left + right) / 2;
        if(mid * mid >= (ull)n){
            ans = mid;
            right = mid - 1;
        }else
            left = mid + 1;
    }
    cout << ans << '\n';
    return 0;
}