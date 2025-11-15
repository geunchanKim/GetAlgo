#include <iostream>
#include <vector>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;
vector<vector<int>> G;
vector<bool> visited;
int cnt = -1;

void DFS(int node){
    if(visited[node])
        return;
    visited[node] = true;
    cnt++;
    for(int i : G[node]){
        if(!visited[i])
            DFS(i);
    }
}
int main(){
    FASTIO;
    int N, M;
    cin >> N;
    G.resize(N + 1);
    visited.resize(N + 1, false);
    cin >> M;
    for(int i = 0; i < M; i++){
        int s, e;
        cin >> s >> e;
        G[s].push_back(e);
        G[e].push_back(s);
    }
    DFS(1);
    cout << cnt;
    return 0;
}