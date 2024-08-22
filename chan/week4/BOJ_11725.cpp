#include <iostream>
#include <map>
#include <queue>
#include <vector>
#define MAX 100001
using namespace std;

void bfs(vector<vector<int> > &tree, int N){
    vector<int> parent(N, 0);
    vector<int> visited(N, 0);
    queue<int> q;
    int root = 1;
    q.push(root);
    visited[1] = 1;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int i = 0; i < tree[x].size(); i++){
            int nx = tree[x][i];
            if(visited[nx])
                continue;
            parent[nx] = x;
            visited[nx] = 1;
            q.push(nx);
        }
    }
    for(int i = 2; i < parent.size(); i++)
        cout << parent[i] << "\n";
}

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    int N;
    cin >> N;
    vector<vector<int> > tree(N+1);
    for(int i = 0; i < N - 1; i++){
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    bfs(tree, N + 1);
}