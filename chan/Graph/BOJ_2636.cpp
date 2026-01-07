#include <iostream>
#include <queue>
#include <vector>
#include <set>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;
int N, M, pre, cnt = 0;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
vector<vector<int>> pan;
set<pair<int, int>> ones;
set<pair<int, int>> zeros;

void bfs(int sx, int sy){
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    queue<pair<int, int>> Q;
    zeros.clear();
    Q.push({sx, sy});
    while(!Q.empty()){
        auto [tx, ty] = Q.front();
        visited[tx][ty] = true;
        Q.pop();
        for(int i = 0; i < 4; i++){
            int x = tx + dx[i];
            int y = ty + dy[i];
            if(x < 0 || y < 0 || x >= N || y >= M)
                continue;
            if(visited[x][y])
                continue;
            if(pan[x][y] == 1){
                zeros.insert({x, y});
                ones.erase({x, y});
            }
            if(pan[x][y] == 0)
                Q.push({x, y});
            visited[x][y] = true;
        }
    }

}

int main(){
    FASTIO;
    cin >> N >> M;
    pan.resize(N, vector<int>(M));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> pan[i][j];
            if(pan[i][j] == 1)
                ones.insert({i, j});
        }
    }
    pre = ones.size();
    while(ones.size() != 0){
        pre = ones.size();
        bfs(0, 0);
        for(auto P : zeros)
            pan[P.first][P.second] = 0;
        cnt++;
    }
    cout << cnt << '\n' << pre;
    return 0;
}