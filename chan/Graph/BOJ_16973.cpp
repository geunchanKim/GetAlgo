#include <iostream>
#include <queue>
#include <vector>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;

int N, M, H, W, SX, SY, FX, FY;
vector<vector<int>> graph;
vector<vector<bool>> visited;
vector<vector<int>> psum;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int wallCount(int x, int y) {
    int x2 = x + H - 1;
    int y2 = y + W - 1;
    return psum[x2][y2] - psum[x - 1][y2] - psum[x2][y - 1] + psum[x - 1][y - 1];
}

bool canMove(int x, int y) {
    if (x < 1 || y < 1 || x + H - 1 > N || y + W - 1 > M)
        return false;
    return wallCount(x, y) == 0;
}

int solve() {
    queue<pair<int,int>> Q;

    if(!canMove(SX, SY)) return -1;

    Q.push({SX, SY});
    visited[SX][SY] = true;

    int dist = 0;

    while(!Q.empty()){
        int qs = Q.size();
        while(qs--){
            auto [x, y] = Q.front(); Q.pop();

            if(x == FX && y == FY)
                return dist;

            for(int d = 0; d < 4; d++){
                int nx = x + dx[d];
                int ny = y + dy[d];

                if(!visited[nx][ny] && canMove(nx, ny)){
                    visited[nx][ny] = true;
                    Q.push({nx, ny});
                }
            }
        }
        dist++;
    }
    return -1;
}

int main() {
    FASTIO;
    cin >> N >> M;
    graph.resize(N + 1, vector<int>(M + 1));
    visited.resize(N + 1, vector<bool>(M + 1, false));
    psum.resize(N + 1, vector<int>(M + 1, 0));
    
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= M; j++)
            cin >> graph[i][j];

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++)
            psum[i][j] = graph[i][j] + psum[i - 1][j] + psum[i][j - 1] - psum[i - 1][j - 1];
    }
    cin >> H >> W >> SX >> SY >> FX >> FY;

    cout << solve();
    return 0;
}
