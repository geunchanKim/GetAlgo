#include <iostream>
#include <queue>
#include <vector>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;
vector<vector<int>> T;
vector<int> visited;
vector<int> result;

void BFS(int node){
    queue<int> Q;
    Q.push(node);
    visited[node] = true;
    while(!Q.empty()){
        int tmp = Q.front();
        Q.pop();
        for(int i : T[tmp]){
            if(!visited[i]){
                result[i] = tmp;
                Q.push(i);
                visited[i] = true;
            }
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
    BFS(1);
    for(int i = 2; i <= N; i++)
        cout << result[i] << '\n';
    return 0;
}