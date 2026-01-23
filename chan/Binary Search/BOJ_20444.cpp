#include <iostream>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;
typedef long long ll;

int main(){
    FASTIO;
    ll n, k;
    cin >> n >> k;
    ll start = 0, end = n / 2, mid;
    bool flag = false;
    while(start <= end){
        mid = (start + end) / 2;
        ll cnt = (mid + 1) * (n - mid + 1);
        if(cnt == k){
            flag = true;
            break;
        }else if(cnt > k)
            end = mid - 1;
        else
            start = mid + 1;
    }
    if(flag)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}