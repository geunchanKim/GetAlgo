#include <iostream>
#include <string>
#include <vector>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;

int main(){
    FASTIO;
    int N, M;
    vector<pair<string, int>> S;
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        string s;
        long long n;
        cin >> s >> n;
        S.push_back({s, n});
    }
    for(int i = 0; i < M; i++){
        long long n;
        int start = 0, end = N - 1, mid, ans;
        cin >> n;
        while(start <= end){
            mid = (start + end) / 2;
            if(n <= S[mid].second){
                ans = mid;
                end = mid - 1;
            }else
                start = mid + 1;
        }
        cout << S[ans].first << '\n';
    }
    return 0;
}