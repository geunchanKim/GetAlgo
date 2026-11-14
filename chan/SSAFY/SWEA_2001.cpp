#include <iostream>
#include <vector>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;

int main(){
    FASTIO;
    int tc;
    cin >> tc;
    for(int t = 0; t < tc; t++){
        int N, M, max = 0;
        cin >> N >> M;
        vector<vector<int>> ary(N, vector<int>(N));
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                cin >> ary[i][j];
        for(int i = 0; i <= N - M; i++){
            for(int j = 0; j <= N - M; j++){
                int sum = 0;
                for(int k = 0; k < M; k++){
                    for(int l = 0; l < M; l++){
                        sum += ary[i + k][j + l];
                    }
                }
                if(sum > max)
                    max = sum;
            }
        }
        cout << '#' << t + 1 << ' ' << max << '\n';
    }
}