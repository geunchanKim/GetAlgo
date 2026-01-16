#include <iostream>
#include <algorithm>
#include <vector>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
typedef long long ll;
using namespace std;

ll count(ll x, ll n, vector<ll> l){
    ll result = 0;
    for(int i = 0; i < n; i++){
        if(l[i] - x < 0)
            result += l[i];
        else
            result += x;
    }
    return result;
}

int main(){
    FASTIO;
    ll N, MAX, start = 1, end, ans;
    cin >> N;
    vector<ll> list(N);
    for(int i = 0; i < N; i++)
        cin >> list[i];
    cin >> MAX;
    sort(list.begin(), list.end());
    end = list[N - 1];
    while(start <= end){
        ll mid = (start + end) / 2;
        if(count(mid, N, list) <= MAX){
            ans = mid;
            start = mid + 1;
        }else
            end = mid - 1;
    }
    cout << ans;
    return 0;
}