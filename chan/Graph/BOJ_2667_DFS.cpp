#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;

vector<vector<int>> mapArr;
vector<vector<bool>> visited;
vector<int> result;
int N;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

int DFS(int x, int y){
    visited[x][y] = true;
    int cnt = 1;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && ny >= 0 && nx < N && ny < N){
            if(!visited[nx][ny] && mapArr[nx][ny] == 1){
                cnt += DFS(nx, ny);
            }
        }
    }
    return cnt;
}

int main(){
    FASTIO;
    cin >> N;
    mapArr.resize(N);
    visited.resize(N);
    for(int i = 0; i < N; i++){
        visited[i].resize(N, false);
        string line;
        cin >> line;
        for(int j = 0; j < N; j++)
            mapArr[i].push_back(line[j] - '0');
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(mapArr[i][j] == 1 && !visited[i][j]){
                int cnt = DFS(i, j);
                result.push_back(cnt);
            }
        }
    }
    sort(result.begin(), result.end());
    cout << result.size() << "\n";
    for(int x : result){
        cout << x << "\n";
    }
    return 0;
}