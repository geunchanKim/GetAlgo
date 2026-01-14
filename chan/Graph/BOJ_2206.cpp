#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;

int N, M;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
vector<vector<int>> MAP;
vector<vector<vector<bool>>> visited;

int BFS(){
    queue<tuple<int,int,int,int>> Q;
    Q.push({0,0,0,1});
    visited[0][0][0] = true;
    while(!Q.empty()){
        auto [x, y, z, cnt] = Q.front();
        Q.pop();
        if(x == N - 1 && y == M - 1)
            return cnt;
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= N || ny >= M)
                continue;
            int nz = z;
            if(MAP[nx][ny] == 1){
                if(z == 1) continue;
                nz = 1;
            }
            if(visited[nx][ny][nz]) continue;
            visited[nx][ny][nz] = true;
            Q.push({nx, ny, nz, cnt + 1});
        }
    }
    return -1;
}

int main(){
    FASTIO;
    cin >> N >> M;
    MAP.assign(N, vector<int>(M));
    visited.assign(N, vector<vector<bool>>(M, vector<bool>(2, false)));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            char c;
            cin >> c;
            MAP[i][j] = c - '0';
        }
    }
    cout << BFS();
    return 0;
}
