#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;
int N, M, T;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};
vector<vector<int>> maze;
vector<vector<vector<bool>>> visited;

int BFS(){
    queue<tuple<int,int,int,int>> Q; // x, y, time, sword
    Q.push({0, 0, 0, 0});
    visited[0][0][0] = true;
    while(!Q.empty()){
        auto [x, y, time, sword] = Q.front();
        Q.pop();
        if(time > T) continue;
        // 도착
        if(x == N-1 && y == M-1){
            return time;
        }
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nsword = sword;
            if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            // 검 줍기
            if(maze[nx][ny] == 2) nsword = 1;
            // 벽이면 검이 있어야 통과 가능
            if(maze[nx][ny] == 1 && nsword == 0) continue;
            if(!visited[nx][ny][nsword]){
                visited[nx][ny][nsword] = true;
                Q.push({nx, ny, time + 1, nsword});
            }
        }
    }
    return 1e9; // 도달 못함
}

int main(){
    FASTIO;
    cin >> N >> M >> T;
    maze.resize(N, vector<int>(M));
    visited.resize(N, vector<vector<bool>>(M, vector<bool>(2, false)));
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            cin >> maze[i][j];
    int result = BFS();
    if(result > T) cout << "Fail";
    else cout << result;
    return 0;
}