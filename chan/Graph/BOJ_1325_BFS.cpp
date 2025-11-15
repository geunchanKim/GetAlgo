#include <iostream>
#include <queue>
#include <vector>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;
vector<vector<int>> G;
vector<int> visited;
vector<pair<int, int>> result;

int cnt = 0;
int maxcnt = 0;

void BFS(int node){
    queue<int> Q;
    Q.push(node);
    visited[node] = true;
    cnt++;
    while(!Q.empty()){
        int tmp = Q.front();
        Q.pop();
        for(int i : G[tmp]){
            if(!visited[i]){
                Q.push(i);
                visited[i] = true;
                cnt++;
            }
        }
    }
    if(maxcnt < cnt)
        maxcnt = cnt;
    result.push_back(make_pair(node, cnt));
}

int main(){
    FASTIO;
    int N, M;
    cin >> N >> M;
    G.resize(N + 1);
    visited.resize(N + 1, false);
    for(int i = 0; i < M; i++){
        int s, e;
        cin >> s >> e;
        G[e].push_back(s);
    }
    for(int i = 1; i <= N; i++){
        if(G[i].size() != 0){
            BFS(i);
            fill(visited.begin(), visited.end(), false);
            cnt = 0;
        }
    }
    for(auto &p : result)
        if(p.second == maxcnt)
            cout << p.first << ' ';
    return 0;
}
