#include <iostream>
#include <vector>
#define FASTIO cin.tie(NULL); ios::sync_with_stdio(false);
using namespace std;

int main(){
    FASTIO;
    int N, M;
    long result = 0;
    cin >> N >> M;
    vector<long> S(N + 1, 0);
    vector<long> C(M, 0);
    for(int i = 1; i <= N; i++){
        int tmp;
        cin >> tmp;
        S[i] = S[i - 1] + tmp;
        if(S[i] % M == 0)
            result++;
        C[S[i] % M]++;
    }
    for(int i = 0; i < M; i++)
        if(C[i] > 1)
            result = result + (C[i] * (C[i] - 1) / 2);
    cout << result << '\n';
    return 0;
}