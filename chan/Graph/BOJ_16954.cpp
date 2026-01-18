#include <iostream>
#include <queue>
#include <vector>
#include <string>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;
int dx[] = {0, 0, 0, 1, -1, 1, -1, 1, -1};
int dy[] = {0, 1, -1, 0, 0, 1, -1, -1, 1};
vector<string> maze(8);

int BFS(){
    queue<pair<int, int>> Q;
    Q.push({7, 0}); 

    while(!Q.empty()){
        int size = Q.size();
        vector<vector<bool>> visited(8, vector<bool>(8, false));

        for(int i = 0; i < size; i++){
            auto [r, c] = Q.front();
            Q.pop();
            if(maze[r][c] == '#')
                continue;
            if(r == 0 && c == 7) 
                return 1;
            for (int d = 0; d < 9; d++) {
                int nr = r + dx[d];
                int nc = c + dy[d];
                if (nr < 0 || nc < 0 || nr >= 8 || nc >= 8)
                    continue;
                if (maze[nr][nc] == '.' && !visited[nr][nc]) {
                    visited[nr][nc] = true;
                    Q.push({nr, nc});
                }
            }
        }

        for (int i = 7; i >= 0; i--) {
            for (int j = 0; j < 8; j++) {
                if (i == 0) maze[i][j] = '.';
                else maze[i][j] = maze[i - 1][j];
            }
        }
    }
    return 0;
}

int main(){
    FASTIO;
    for(int i = 0; i < 8; i++) 
        cin >> maze[i];
    cout << BFS();
    return 0;
}