#include <iostream>
#include <vector>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;

int main(){
    FASTIO;
    int tc;
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    cin >> tc;
    for(int i = 0; i < tc; i++){
        int N, x = 0, y = 0, d = 0;
        cin >> N;
        vector<vector<int>> ary(N, vector<int>(N));
        vector<vector<bool>> visited(N, vector<bool>(N, false));
        cout << '#' << i + 1 << '\n';
        for(int j = 1; j <= N * N; j++){
            ary[x][y] = j;
            visited[x][y] = true;
            int nx = x + dx[d];
            int ny = y + dy[d];
            if(nx < 0 || ny < 0 || nx >= N || ny >= N || visited[nx][ny])
                d = (d + 1) % 4;
            x = x + dx[d];
            y = y + dy[d];
        }
        for(int j = 0; j < N; j++){
            for(int k = 0; k < N; k++)
                cout << ary[j][k] << ' ';
            cout << '\n';
        }
    }

}