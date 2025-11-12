#include <iostream>
#include <vector>
#include <queue>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int maze[101][101];
bool visited[101][101] = { false };
int N, M;

void BFS(int i, int j){
    queue<pair<int, int>> Q;
    Q.push(make_pair(i, j));

    while(!Q.empty()){
        i = Q.front().first;
        j = Q.front().second;
        Q.pop();
        visited[i][j] = true;
        for(int k = 0; k < 4; k++){
            int x = i + dx[k];
            int y = j + dy[k];
            if(x >= 0 && y >= 0 && x < N && y < M){
                if(maze[x][y] != 0 && !visited[x][y]){
                    visited[x][y] = true;
                    maze[x][y] = maze[i][j] + 1;
                    Q.push(make_pair(x, y));
                }
            }
        }
    }
}

int main(){
    FASTIO;
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        string s;
        cin >> s;
        for(int j = 0; j < M; j++)
            maze[i][j] = s[j] - '0';
    }
    BFS(0, 0);
    cout << maze[N - 1][M - 1];
    return 0;
}
