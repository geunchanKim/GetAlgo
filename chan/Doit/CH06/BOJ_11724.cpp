#include <iostream>
#include <vector>
using namespace std;
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
vector<vector<int>> A;
vector<bool> visited;

void DFS(int N){
    if(visited[N])
        return;
    visited[N] = true;
    for(int i : A[N]){
        if(visited[i] == false)
            DFS(i);
    }
}

int main(){
    FASTIO;
    int N, M, cnt = 0;
    cin >> N >> M;
    A.resize(N + 1);
    visited.resize(N + 1, false);
    for(int i = 0; i < M; i++){
        int s, e;
        cin >> s >> e;
        A[s].push_back(e);
        A[e].push_back(s);
    }
    for(int i = 1; i < N + 1; i++){
        if(!visited[i]){
            cnt++;
            DFS(i);
        }
    }
    cout << cnt;
    return 0;
}   