#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
typedef long long ll;
using namespace std;

ll count(ll x, ll n, vector<ll> list){
    ll cnt = 0;
    for(int i = 0; i < n; i++){
        if(list[i] - x > 0)
            cnt += (list[i] - x);
    }
    return cnt;
}

int main(){
    FASTIO;
    ll N, M, start = 0, end, mid, ans;
    cin >> N >> M;
    vector<ll> list(N);
    for(int i = 0; i < N; i++)
        cin >> list[i];
    sort(list.begin(), list.end());
    end = list[N - 1];
    while(start <= end){
        mid = (start + end) / 2;
        if(count(mid, N, list) >= M){
            ans = mid;
            start = mid + 1;
        }else
            end = mid - 1;
    }
    cout << ans;
    return 0;
}
