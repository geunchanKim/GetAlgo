#include <iostream>
#include <vector>
#define FASTIO cin.tie(NULL); ios::sync_with_stdio(false);
using namespace std;

int main(){
    FASTIO;
    int N, M;
    cin >> N >> M;
    vector<int> sum(N+1, 0);
    for(int i = 1; i <= N; i++){
        int num;
        cin >> num;
        sum[i] = sum[i - 1] + num;
    }
    for(int k = 0; k < M; k++){
        int i, j;
        cin >> i >> j;
        cout << sum[j] - sum[i - 1] << '\n';
    }
    return 0;
}