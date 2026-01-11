#include <iostream>
#include <queue>
#include <vector>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;
int R, C, cnt = 0;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
pair<int, int> Jstart;
vector<pair<int, int>> Fstart;
vector<vector<char>> maze;
vector<vector<bool>> visited;

bool BFS(){
    queue<pair<int, int>> JQ;
    queue<pair<int, int>> FQ;
    JQ.push(Jstart);
    visited[Jstart.first][Jstart.second] = true;
    for(auto &p : Fstart)
        FQ.push(p);
    while(!JQ.empty()){
        int fsz = FQ.size();
        while(fsz--){
            auto [x, y] = FQ.front(); FQ.pop();
            for(int d = 0; d < 4; d++){
                int nx = x + dx[d];
                int ny = y + dy[d];
                if(nx < 0 || ny < 0 || nx >= R || ny >= C) 
                    continue;
                if(maze[nx][ny] == '.' || maze[nx][ny] == 'J'){
                    maze[nx][ny] = 'F';
                    FQ.push({nx, ny});
                }
            }
        }
        int jsz = JQ.size();
        while(jsz--){
            auto [x, y] = JQ.front(); 
            JQ.pop();
            for(int d = 0; d < 4; d++){
                int nx = x + dx[d];
                int ny = y + dy[d];
                if(nx < 0 || ny < 0 || nx >= R || ny >= C){
                    cnt++;
                    return true;
                }
                if(maze[nx][ny] == '.' && !visited[nx][ny]){
                    visited[nx][ny] = true;
                    JQ.push({nx, ny});
                }
            }
        }
        cnt++;
    }
    return false;
}

int main(){
    FASTIO;
    cin >> R >> C;
    maze.resize(R, vector<char>(C));
    visited.resize(R, vector<bool>(C, false));
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> maze[i][j];
            if(maze[i][j] == 'J')
                Jstart = {i, j};
            if(maze[i][j] == 'F')
                Fstart.push_back({i, j});
        }
    }
    if(BFS())
        cout << cnt;
    else
        cout << "IMPOSSIBLE";
    return 0;
}