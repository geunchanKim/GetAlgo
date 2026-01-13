#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;

long long count(long long length, long long k, vector<long long> line){
    long long cnt = 0;
    for(int i = 0; i < k; i++)
        cnt += line[i] / length;
    return cnt;
}

int main(){
    FASTIO;
    long long K, N, start = 1, end, mid, ans;
    cin >> K >> N;
    vector<long long> line(K);
    for(int i = 0; i < K; i++)
        cin >> line[i];
    sort(line.begin(), line.end());
    end = line[K - 1];
    while(start <= end){
        mid = (start + end) / 2;
        if(count(mid, K, line) >= N){
            ans = mid;
            start = mid + 1;
        }else
            end = mid - 1;
    }
    cout << ans;
    return 0;
}