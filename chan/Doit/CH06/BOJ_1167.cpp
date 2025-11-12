#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;
vector<vector<pair<int,int>>> T;  // (다음 노드, 가중치)
vector<bool> visited;
vector<int> D;

void BFS(int node){
    queue<int> Q;
    Q.push(node);
    visited[node] = true;
    while(!Q.empty()){
        int tmp = Q.front();
        Q.pop();
        for(pair<int, int> i : T[tmp]){
            if(!visited[i.first]){
                visited[i.first] = true;
                Q.push(i.first);
                D[i.first] = D[tmp] + i.second;
            }
        }
    }
}

int main(){
    FASTIO;
    int V, max = 1;
    cin >> V;
    visited.resize(V + 1, false);
    D.resize(V + 1, 0);
    T.resize(V + 1);
    for(int i = 0; i < V; i++){
        int from;
        cin >> from;
        while(true){
            int to, w;
            cin >> to;
            if (to == -1) break;
            cin >> w;
            T[from].push_back({to, w});
            T[to].push_back({from, w});
        }
    }
    BFS(1);
    for(int i = 2; i <= V; i++)
        if(D[max] < D[i])
            max = i;
    fill(D.begin(), D.end(), 0);
    fill(visited.begin(), visited.end(), false);
    BFS(max);
    sort(D.begin(), D.end());
    cout << D[V];
    return 0;
}