#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;

int main(){
    FASTIO;
    int tc;
    cin >> tc;
    for(int t = 0; t < tc; t++){
        int N, mid, sum = 0;
        cin >> N;
        mid = N / 2;
        vector<vector<int>> arr(N, vector<int>(N));
        for(int i = 0; i < N; i++){
            string s;
            cin >> s;
            for(int j = 0; j < N; j++)
                arr[i][j] = s[j] - '0';
        }
        for(int i = 0; i < N; i++){
            int k = abs(i - mid);
            for(int j = k; j <= N - 1 - k; j++)
                sum += arr[i][j];
        }
        cout << '#' << t + 1 << ' ' << sum << '\n';
    }
}