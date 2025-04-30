#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;

int main(){
    FASTIO;
    int ans = 0;
    int N;
    cin >> N;
    vector<int> honey(N + 1);
    vector<int> sum(N + 1);
    for(int i = 1; i <= N; i++){
        cin >> honey[i];
        sum[i] = sum[i - 1] + honey[i];
    }

    //벌 - 꿀 - 벌
    for(int i = 2; i < N; i++){
        int tmp = (sum[i] - sum[1]) + (sum[N - 1] - sum[i - 1]);
        ans = max(ans, tmp);
    }

    //벌 - 벌 - 꿀
    for(int i = 2; i < N; i++){
        int tmp = (sum[N] - sum[1] - honey[i]) + (sum[N] - sum[i]);
        ans = max(ans, tmp);
    }

    //꿀 - 벌 - 벌
    for(int i = 2; i < N; i++){
        int tmp = (sum[N - 1] - honey[i]) + sum[i - 1];
        ans = max(ans, tmp);
    }

    cout << ans;
    return 0;
}