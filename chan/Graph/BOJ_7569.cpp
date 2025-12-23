#include <iostream>
#include <queue>
#include <tuple>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;
vector<vector<vector<int>>> storage;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};
int dz[] = {1, -1};

bool check(int z, int y, int x){
    for(int i = 0; i < z; i++){
        for(int j = 0; j < y; j++){
            for(int k = 0; k < x; k++){
                if(storage[i][j][k] == 0)
                    return false;
            }
        }
    }
    return true;
}

int main(){
    FASTIO;
    int M, N, H, dist = 1;
    cin >> M >> N >> H;
    storage.resize(
        H, vector<vector<int>>(
            N, vector<int>(M)
        )
    );
    queue<tuple<int, int, int>> Q;

    for(int i = 0; i < H; i++){
        for(int j = 0; j < N; j++){
            for(int k = 0; k < M; k++){
                cin >> storage[i][j][k];
                if(storage[i][j][k] == 1)
                    Q.push({i, j, k});
            }
        }
    }

    while(!Q.empty()){
        auto [z, y, x] = Q.front();
        Q.pop();
        for(int i = 0; i < 2; i++){
            int nz = z + dz[i];
            if(nz < 0 || nz >= H) continue;

            if(storage[nz][y][x] == 0){
                storage[nz][y][x] = storage[z][y][x] + 1;
                dist = max(dist, storage[nz][y][x]);
                Q.push({nz, y, x});
            }
        }

        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(nx < 0 || ny < 0 || nx >= M || ny >= N) continue;

            if(storage[z][ny][nx] == 0){
                storage[z][ny][nx] = storage[z][y][x] + 1;
                dist = max(dist, storage[z][ny][nx]);
                Q.push({z, ny, nx});
            }
        }
    }

    bool flag = check(H, N, M);
    if(flag){
        cout << dist - 1;
    }else
        cout << -1;
    return 0;
}