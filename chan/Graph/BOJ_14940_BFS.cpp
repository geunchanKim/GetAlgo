#include <iostream>
#include <vector>
#include <queue>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;
vector<vector<int>> map;
vector<vector<int>> result;
vector<vector<bool>> visited;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int n, m;

void BFS(int x, int y){
    queue<pair<int, int>> Q;
    Q.push(make_pair(x, y));
    result[x][y] = 0;
    while(!Q.empty()){
        x = Q.front().first;
        y = Q.front().second;
        Q.pop();
        visited[x][y] = true;
        for(int i = 0; i < 4; i++){
            int tx = x + dx[i];
            int ty = y + dy[i];
            if(tx >= 0 && ty >= 0 && tx < n && ty < m){
                if(map[tx][ty] == 1 && !visited[tx][ty]){
                    visited[tx][ty] = true;
                    result[tx][ty] = result[x][y] + 1;
                    Q.push(make_pair(tx, ty));
                }
            }
        }
    }
}

int main(){
    FASTIO;
    int sx, sy;
    cin >> n >> m;
    map.resize(n);
    result.resize(n);
    visited.resize(n);
    for(int i = 0; i < n; i++){
        visited[i].resize(m, false);
        result[i].resize(m, 0);
        for(int j = 0; j < m; j++){
            int tmp;
            cin >> tmp;
            if(tmp == 2){
                sx = i;
                sy = j;
            }
            map[i].push_back(tmp);
        }
    }
    BFS(sx, sy);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(map[i][j] == 0)        // 벽
                cout << 0 << " ";
            else if(!visited[i][j])   // 길이지만 못 감
                cout << -1 << " ";
            else
                cout << result[i][j] << " ";
        }
        cout << '\n';
    }
}