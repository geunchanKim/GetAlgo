#include <iostream>
#include <queue>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;
vector<vector<int>> G;
vector<bool> visited;
vector<int> result;

void BFS(int com){
    queue<int> Q;
    Q.push(com);
    visited[com] = true;
    while(!Q.empty()){
        int tmp = Q.front();
        Q.pop();
        for(int i : G[tmp]){
            if(!visited[i]){
                result.push_back(i);
                Q.push(i);
                visited[i] = true;
            }
        }
    }
}

int main(){
    FASTIO;
    int N, E;
    cin >> N;
    G.resize(N + 1);
    visited.resize(N + 1, false);
    cin >> E;
    for(int i = 0; i < E; i++){
        int s, e;
        cin >> s >> e;
        G[s].push_back(e);
        G[e].push_back(s);
    }
    BFS(1);
    cout << result.size();
    return 0;
}