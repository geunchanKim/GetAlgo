#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;
typedef long long ll;
ll N, M;
vector<ll> list;

bool check(ll T){
    ll people = 0;
    for (int i = 0; i < N; i++) {
        people += T / list[i];
        if(people >= M) 
            return true;
    }
    return false;
}

int main(){
    FASTIO;
    cin >> N >> M;
    list.resize(N);
    ll min_val = 1000000000LL;
    for (int i = 0; i < N; i++) {
        cin >> list[i];
        if (list[i] < min_val) 
            min_val = list[i];
    }
    ll start = 1, end = min_val * M, ans = end;
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
