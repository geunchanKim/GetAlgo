#include <iostream>
#include <queue>
#include <vector>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;
int N, M, MAX = 0;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
vector<vector<int>> lab;
vector<pair<int, int>> zeros;
vector<pair<int, int>> twos;

void bfs(){
    int cnt = 0;
    vector<vector<int>> copy_lab(N, vector<int>(M));
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    copy(lab.begin(), lab.end(), copy_lab.begin());
    queue<pair<int, int>> Q;
    for (auto &p : twos) {
        Q.push(p);
        visited[p.first][p.second] = true;
    }
    while(!Q.empty()){
        auto [tx, ty] = Q.front();
        Q.pop();
        for(int j = 0; j < 4; j++){
            int TX = tx + dx[j];
            int TY = ty + dy[j];
            if(TX < 0 || TX >= N || TY < 0 || TY >= M)
                continue;
            if(visited[TX][TY])
                continue;
            if(copy_lab[TX][TY] == 1)
                continue;
            copy_lab[TX][TY] = 2;
            Q.push({TX, TY});
            visited[TX][TY] = true;
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(copy_lab[i][j] == 0)
                cnt++;
        }
    }
    if(cnt > MAX)
        MAX = cnt;
}

void dfs(int start, int cnt){
    if(cnt == 3){
        bfs(); 
        return;
    }
    for(int i = start; i < zeros.size(); i++){
        auto [x, y] = zeros[i];
        lab[x][y] = 1;
        dfs(i + 1, cnt + 1);
        lab[x][y] = 0;
    }
}

int main(){
    FASTIO;
    cin >> N >> M;
    lab.resize(N, vector<int>(M));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> lab[i][j];
            if(lab[i][j] == 0)
                zeros.push_back(make_pair(i, j));
            else if(lab[i][j] == 2)
                twos.push_back(make_pair(i, j));
        }
    }
    dfs(0, 0);
    cout << MAX;
    return 0;
}