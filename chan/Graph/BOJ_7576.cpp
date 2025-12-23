#include <iostream>
#include <queue>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;
vector<vector<int>> storage;
int dist = 1;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

bool check(int N, int M){
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            if(storage[i][j] == 0)
                return false;
        }
    }
    return true;
}

int main(){
    FASTIO;
    int N, M;
    cin >> N >> M;
    storage.resize(M, vector<int>(N));
    queue<pair<int, int>> Q;
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            cin >> storage[i][j];
            if(storage[i][j] == 1)
                Q.push({i, j});
        }
    }
    while(!Q.empty()){
        auto [x, y] = Q.front();
        Q.pop();
        for(int i = 0; i < 4; i++){
            int tx = x + dx[i];
            int ty = y + dy[i];
            if(tx < 0 || ty < 0 || tx >= M || ty >= N)
                continue;
            if(storage[tx][ty] != 0)
                continue;
            storage[tx][ty] = storage[x][y] + 1;
            if(dist < storage[tx][ty])
                dist = storage[tx][ty];
            Q.push({tx, ty});
        }
    }
    bool flag = check(N, M);
    if(flag)
        cout << dist - 1;
    else
        cout << -1;
    return 0;
}