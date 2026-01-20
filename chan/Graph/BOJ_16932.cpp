#include <iostream>
#include <queue>
#include <vector>
#include <set>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;
int N, M, idx = 1, MAX = 0;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
vector<vector<int>> group;
vector<int> groupSize;
vector<vector<bool>> visited;
set<pair<int, int>> ones;
set<pair<int, int>> zeros;

void BFS(int sx, int sy){
    if(visited[sx][sy])
        return;
    queue<pair<int, int>> Q;
    int cnt = 0;
    Q.push({sx, sy});
    visited[sx][sy] = true;
    while(!Q.empty()){
        auto [tx, ty] = Q.front();
        Q.pop();
        group[tx][ty] = idx;
        cnt++;
        for(int i = 0; i < 4; i++){
            int x = tx + dx[i];
            int y = ty + dy[i];
            if(x < 0 || y < 0 || x >= N || y >= M)
                continue;
            if(visited[x][y] || group[x][y] == 0)
                continue;
            Q.push({x, y});
            visited[x][y] = true; 
        }
    }
    groupSize.push_back(cnt);
    idx++;
}

int count(int sx, int sy){
    set<int> groupIdx;
    int sum = 1;
    for(int i = 0; i < 4; i++){
        int x = sx + dx[i];
        int y = sy + dy[i];
        if(x < 0 || y < 0 || x >= N || y >= M)
            continue;
        groupIdx.insert(group[x][y]);
    }
    for(auto p : groupIdx)
        sum += groupSize[p];
    return sum;
}

int main(){
    FASTIO;
    cin >> N >> M;
    group.resize(N, vector<int>(M));
    visited.assign(N, vector<bool>(M, false));
    groupSize.push_back(0);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> group[i][j];
            if(group[i][j] == 1)
                ones.insert({i, j});
            if(group[i][j] == 0)
                zeros.insert({i, j});
        }
    }
    for(auto p : ones)
        BFS(p.first, p.second);
    for(auto p : zeros){
        int tmp = count(p.first, p.second);
        if(MAX < tmp)
            MAX = tmp;
    }
    cout << MAX;
    return 0;
}