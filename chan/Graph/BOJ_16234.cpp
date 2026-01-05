#include <iostream>
#include <queue>
#include <vector>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int N, L, R, ans = 0;
vector<vector<int>> A;
vector<vector<int>> visited;
vector<pair<int, int>> ally;

bool BFS(int x, int y){
    queue<pair<int, int>> Q;
    Q.push(make_pair(x, y));
    visited[x][y] = 1;
    ally.push_back(make_pair(x, y));
    while(!Q.empty()){
        int tx = Q.front().first;
        int ty = Q.front().second;
        Q.pop();
        for(int i = 0; i < 4; i++){
            int nx = tx + dx[i];
            int ny = ty + dy[i];
            if(nx < 0 || nx >= N || ny < 0 || ny >= N)
                continue;
            if(visited[nx][ny])
                continue;
            int diff = abs(A[nx][ny] - A[tx][ty]);
            if(L <= diff && diff <= R){
                Q.push(make_pair(nx, ny));
                visited[nx][ny] = 1;
                ally.push_back(make_pair(nx, ny));
            }
        }
    }
    return ally.size() > 1;
}

int main(){
    FASTIO;
    cin >> N >> L >> R;
    A.resize(N, vector<int>(N));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++)
            cin >> A[i][j];
    }
    while(true){
        visited.assign(N, vector<int>(N, 0));
        bool flag = false;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(!visited[i][j]){
                    ally.clear();
                    if(BFS(i, j)){
                        flag = true;
                        int sum = 0;
                        for(auto &p : ally)
                            sum += A[p.first][p.second];
                        int avg = sum / ally.size();
                        for(auto &p : ally)
                            A[p.first][p.second] = avg;
                    }
                }
            }
        }
        if(!flag)
            break;
        ans++;
    }
    cout << ans << '\n';
    return 0;
}