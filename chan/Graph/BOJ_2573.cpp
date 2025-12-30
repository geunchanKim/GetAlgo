#include <iostream>
#include <vector>
#include <queue>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;

int N, M;
vector<vector<int>> NP;
vector<vector<int>> meltCnt;
vector<pair<int, int>> loc;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

bool check(){
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    queue<pair<int, int>> Q;

    int sx = loc[0].first;
    int sy = loc[0].second;
    Q.push({sx, sy});
    visited[sx][sy] = true;

    int cnt = 1;

    while(!Q.empty()){
        auto [tx, ty] = Q.front(); Q.pop();
        for(int i = 0; i < 4; i++){
            int x = tx + dx[i];
            int y = ty + dy[i];
            if(x >= 0 && y >= 0 && x < N && y < M){
                if(!visited[x][y] && NP[x][y] > 0){
                    visited[x][y] = true;
                    Q.push({x, y});
                    cnt++;
                }
            }
        }
    }
    return cnt == loc.size();
}

void melt(int tx, int ty){
    int cnt = 0;
    for(int i = 0; i < 4; i++){
        int x = tx + dx[i];
        int y = ty + dy[i];
        if(x >= 0 && y >= 0 && x < N && y < M){
            if(NP[x][y] == 0)
                cnt++;
        }
    }
    meltCnt[tx][ty] = cnt;
}

int main(){
    FASTIO;
    cin >> N >> M;
    NP.resize(N, vector<int>(M));

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> NP[i][j];
            if(NP[i][j] > 0)
                loc.push_back({i, j});
        }
    }

    int result = 0;

    while(true){
        if(loc.empty()){
            cout << 0;
            return 0;
        }

        if(!check()){
            cout << result;
            return 0;
        }

        result++;

        meltCnt.assign(N, vector<int>(M, 0));
        for(auto &p : loc)
            melt(p.first, p.second);

        for(auto &p : loc){
            int x = p.first, y = p.second;
            NP[x][y] = max(0, NP[x][y] - meltCnt[x][y]);
        }

        vector<pair<int,int>> newLoc;
        for(auto &p : loc){
            if(NP[p.first][p.second] > 0)
                newLoc.push_back(p);
        }
        loc = newLoc;
    }
}