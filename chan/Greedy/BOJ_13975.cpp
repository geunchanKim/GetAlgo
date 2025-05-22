#include <iostream>
#include <queue>
#include <functional>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;

void solve(){
    long long K, sum = 0;
    cin >> K;
    priority_queue< long long, vector<long long>, greater<long long> > Q;
    for(long long i = 0; i < K; i++){
        long long tmp;
        cin >> tmp;
        Q.push(tmp);
    }

    while (Q.size() > 1) {
        long long first = Q.top(); Q.pop();
        long long second = Q.top(); Q.pop();
        long long merged = first + second;
        sum += merged;
        Q.push(merged);
    }

    cout << sum << '\n';
    return;
}

int main(){
    FASTIO;
    int T;
    cin >> T;
    for(int i = 0; i < T; i++)
        solve();
    return 0;
}