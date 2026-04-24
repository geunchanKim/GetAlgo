#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;

bool compare(int x, int y){
    return x > y;
}

int main(){
    FASTIO;
    int N, K, idx = 0, cnt = 0;
    cin >> N >> K;
    vector<int> A(N);
    for(int i = 0; i < N; i++)
        cin >> A[i];
    sort(A.begin(), A.end(), compare);
    while(K > 0){
        if(K >= A[idx]){
            cnt += (K / A[idx]);
            K = K % A[idx];
        }
        idx++;
    }
    cout << cnt;
}