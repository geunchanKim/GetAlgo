#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
vector<vector<int>> G;
vector<bool> visited;
vector<bool> visited2;

void DFS(int node){
    cout << node << ' ';
    visited[node] = true;
    for(int i : G[node]){
        if(!visited[i])
            DFS(i);
    }
}

void BFS(int node){
    queue<int> Q;
    Q.push(node);
    while(!Q.empty()){
        int tmp = Q.front();
        Q.pop();
        if(!visited2[tmp])
            cout << tmp << ' ';
        visited2[tmp] = true;
        for(int i : G[tmp]){
            if(!visited2[i])
                Q.push(i);
        }
    }
}

int main(){
    FASTIO;
    int N, M, V;
    cin >> N >> M >> V;
    G.resize(N + 1);
    visited.resize(N + 1, false);
    visited2.resize(N + 1, false);
    for(int i = 0; i < M; i++){
        int s, e;
        cin >> s >> e;
        G[s].push_back(e);
        G[e].push_back(s);
    }
    for(int i = 1; i <= N; i++)
        sort(G[i].begin(), G[i].end());
    DFS(V);
    cout << '\n';
    BFS(V);
    return 0;
}