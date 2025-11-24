#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;
vector<vector<int>> map;
vector<vector<bool>> visited;
vector<int> result;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1}; 
int total = 0;
int N;

void BFS(int sx, int sy){
    if(visited[sx][sy])
        return;
    int cnt = 1;
    queue<pair<int, int>> Q;
    total++;
    visited[sx][sy] = true;
    Q.push(make_pair(sx, sy));
    while(!Q.empty()){
        int tx = Q.front().first;
        int ty = Q.front().second;
        Q.pop();
        for(int i = 0; i < 4; i++){
            int x = tx + dx[i];
            int y = ty + dy[i];
            if(x >= 0 && y >= 0 && x < N && y < N){
                if(!visited[x][y] && map[x][y] == 1){
                    Q.push(make_pair(x, y));
                    visited[x][y] = true;
                    cnt++;
                }
            }
        }
    }
    result.push_back(cnt);
}

int main(){
    FASTIO;
    vector<pair<int, int>> spot;
    string tmp;
    cin >> N;
    map.resize(N);
    visited.resize(N);
    for(int i = 0; i < N; i++){
        cin >> tmp;
        visited[i].resize(N, false);
        for(int j = 0; j < N; j++){
            map[i].push_back(tmp[j] - '0');
            if(tmp[j] - '0' == 1)
                spot.push_back(make_pair(i, j));
        }
    }
    for(auto i : spot)
        BFS(i.first, i.second);
    sort(result.begin(), result.end());
    cout << total << '\n';
    for(int i : result)
        cout << i << '\n';
    return 0;
}