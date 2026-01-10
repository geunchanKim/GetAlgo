#include <iostream>
#include <queue>
#include <vector>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;
int w, h, cnt = 0;
int dx_even[] = {-1, 1, 0, 0, -1, 1};
int dy_even[] = {0, 0 , 1, -1, -1, -1};
int dx_odd[] = {-1, 1, 0, 0, -1, 1};
int dy_odd[] = {0, 0 , 1, -1, 1, 1};
vector<vector<int>> house;
vector<vector<bool>> visited;

void BFS(int sx, int sy){
    queue<pair<int, int>> Q;
    Q.push({sx, sy});
    while(!Q.empty()){
        auto [tx, ty] = Q.front();
        visited[tx][ty] = true;
        Q.pop();
        for(int i = 0; i < 6; i++){
            int x, y;
            if(tx % 2 == 0){
                x = tx + dx_even[i];
                y = ty + dy_even[i];
            }else{
                x = tx + dx_odd[i];
                y = ty + dy_odd[i];
            }
            if(x < 0 || y < 0 || x >= h + 2 || y >= w + 2)
                continue;
            if(visited[x][y])
                continue;
            if(house[x][y] == 1){
                cnt++;
                continue;
            }
            Q.push({x, y});
            visited[x][y] = true;
        }
    }
}

int main(){
    FASTIO;
    cin >> w >> h;
    house.resize(h + 2, vector<int>(w + 2, 0));
    visited.resize(h + 2, vector<bool>(w + 2, false));
    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= w; j++)
            cin >> house[i][j];
    }
    BFS(0, 0);
    cout << cnt;
    return 0;
}