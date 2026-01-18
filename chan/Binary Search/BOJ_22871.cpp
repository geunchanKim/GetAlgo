#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;
typedef long long ll;
ll N;
vector<ll> list;

bool check(ll K) {
    vector<bool> reachable(N + 1, false);
    reachable[1] = true;
    for (int i = 1; i <= N; i++) {
        if(!reachable[i]) continue;
        for(int j = i + 1; j <= N; j++){
            ll cost = (ll)(j - i) * (1 + llabs(list[i] - list[j]));
            if(cost <= K)
                reachable[j] = true; 
        }
        if(reachable[N]) 
            return true;
    }
    return reachable[N];
}

int main() {
    FASTIO;
    cin >> N;
    list.resize(N + 1);
    for(int i = 1; i <= N; i++)
        cin >> list[i];
    ll start = 0; 
    ll end = 1000000LL * 5000LL; 
    ll ans = end;
    while(start <= end){
        ll mid = (start + end) / 2;
        if(check(mid)){
            ans = mid;
            end = mid - 1;
        }else
            start = mid + 1;
    }
    cout << ans;
    return 0;
}