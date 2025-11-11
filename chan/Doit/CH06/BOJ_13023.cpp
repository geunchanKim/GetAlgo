#include <iostream>
#include <vector>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;
vector<vector<int>> G;
vector<bool> visited; 
bool flag = false;

void DFS(int node, int level){
    if(level == 4){
        flag = true;
        return;
    }
    if(visited[node])
        return;
    visited[node] = true;
    for(int i : G[node]){
        if(!visited[i])
            DFS(i, level + 1);
    }
    visited[node] = false;
}

int main(){
    FASTIO;
    int N, M;
    cin >> N >> M;
    G.resize(N);
    visited.resize(N, false);
    for(int i = 0; i < M; i++){
        int s, e;
        cin >> s >> e;
        G[s].push_back(e);
        G[e].push_back(s);
    }
    for(int i = 0; i < N; i++){
        DFS(i, 0);
        if(flag)
            break;
    }
    if(flag)
        cout << 1;
    else
        cout << 0;
    return 0;
}