#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;
int K, W, H;
int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};
int hx[] = {1, 1, 2, 2, -1, -1, -2, -2};
int hy[] = {2, -2, 1, -1, 2, -2, 1, -1};
vector<vector<int>> board;
vector<vector<vector<bool>>> visited;
vector<vector<vector<int>>> dist;

int BFS(int sx, int sy, int sk){
    queue<tuple<int, int, int, int>> Q;
    Q.push({sx, sy, sk, 0});
    while(!Q.empty()){
        auto [tx, ty, tk, dist] = Q.front();
        if (tx == H - 1 && ty == W - 1)
            return dist;
        Q.pop();
        visited[tx][ty][tk] = true;
        for(int i = 0; i < 4; i++){
            int x = tx + dx[i];
            int y = ty + dy[i];
            if(x < 0 || y < 0 || x >= H || y >= W)
                continue;
            if(board[x][y] == 1 || visited[x][y][tk])
                continue;
            visited[x][y][tk] = true;
            Q.push({x, y, tk, dist + 1});
        }
        if(tk < K){
            for(int i = 0; i < 8; i++){
                int x = tx + hx[i];
                int y = ty + hy[i];
                if(x < 0 || y < 0 || x >= H || y >= W)
                    continue;
                if(board[x][y] == 1 || visited[x][y][tk + 1])
                    continue;
                visited[x][y][tk + 1] = true;
                Q.push({x, y, tk + 1, dist + 1});
            }
        }
    }
    return -1;
}

int main(){
    FASTIO;
    cin >> K;
    cin >> W >> H;
    board.assign(H, vector<int>(W));
    visited.assign(H, vector<vector<bool>>(W, vector<bool>(K + 1, false)));
    dist.assign(H, vector<vector<int>>(W, vector<int>(K + 1, -1)));
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++)
            cin >> board[i][j];
    }
    cout << BFS(0, 0, 0);
    return 0;
}