#include <iostream>
#include <vector>
#include <queue>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;
int T, n, team;
vector<int> list;
vector<bool> visited;
vector<bool> finished;

void dfs(int x) {
    visited[x] = true;
    int next = list[x];
    if (!visited[next])
        dfs(next);
    else if (!finished[next]){
        int cnt = 1;
        int cur = next;
        while (cur != x){
            cur = list[cur];
            cnt++;
        }
        team += cnt;
    }
    finished[x] = true;
}

int main(){
    FASTIO;
    cin >> T;
    for(int i = 0; i < T; i++){
        cin >> n;
        list.assign(n + 1, 0);
        visited.assign(n + 1, false);
        finished.assign(n + 1, false);
        team = 0;
        for(int j = 1; j <= n; j++)
            cin >> list[j];
        for(int j = 1; j <= n; j++)
            dfs(j);
        cout << n - team << '\n';
    }
    return 0;
}