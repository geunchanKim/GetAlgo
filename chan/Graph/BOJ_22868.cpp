#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;
int N, M, cnt = 0;
vector<vector<int>> path;
vector<int> parent;
vector<bool> blocked;

void BFS1(int s, int e){
    queue<pair<int, int>> Q;
    vector<bool> visited(N + 1, false);
    Q.push({s, 0});
    visited[s] = true;
    parent[s] = -1;
    while(!Q.empty()){
        auto [cur, c] = Q.front(); 
        Q.pop();
        if(cur == e) {
            cnt += c;
            break;
        }
        for(int next : path[cur]){
            if(!visited[next]){
                visited[next] = true;
                parent[next] = cur;
                Q.push({next, c + 1});
            }
        }
    }
}

void BFS2(int s, int e){
    queue<pair<int,int>> Q;
    vector<bool> visited(N + 1, false);
    Q.push({s, 0});
    visited[s] = true;
    while(!Q.empty()){
        auto [cur, c] = Q.front(); 
        Q.pop();
        if(cur == e){
            cnt += c;
            break;
        }
        for(int next : path[cur]){
            if(!visited[next] && !blocked[next]){
                visited[next] = true;
                Q.push({next, c + 1});
            }
        }
    }
}

int main(){
    FASTIO;
    int S, E;
    cin >> N >> M;
    path.resize(N + 1);
    parent.assign(N + 1, -1);
    blocked.assign(N + 1, false);
    for(int i = 0; i < M; i++){
        int x, y;
        cin >> x >> y;
        path[x].push_back(y); 
        path[y].push_back(x);
    }
    for(int i = 1; i <= N; i++)
        sort(path[i].begin(), path[i].end());
    cin >> S >> E;
    BFS1(S, E);
    int cur = parent[E];
    while(cur != -1  && cur != S){
        blocked[cur] = true;
        cur = parent[cur];
    }
    BFS2(E, S);
    cout << cnt;
    return 0;
}