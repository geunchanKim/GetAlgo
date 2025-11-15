#include <iostream>
#include <queue>
#include <vector>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;
vector<vector<int>> T;
vector<int> visited;
vector<int> result;

void DFS(int node){
    if(visited[node])
        return;
    visited[node] = true;
    for(int i : T[node]){
        if(!visited[i]){
            result[i] = node;
            DFS(i);
        }
    }
}

int main(){
    FASTIO;
    int N;
    cin >> N;
    T.resize(N + 1);
    visited.resize(N + 1, false);
    result.resize(N + 1, 1);
    for(int i = 0; i < N - 1; i++){
        int S, E;
        cin >> S >> E;
        T[S].push_back(E);
        T[E].push_back(S);
    }
    DFS(1);
    for(int i = 2; i <= N; i++)
        cout << result[i] << '\n';
    return 0;
}