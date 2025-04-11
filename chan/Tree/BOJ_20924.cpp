#include <iostream>
#include <vector>
#include <queue>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;

int main(){
    FASTIO;
    int flag = 1;
    int N, R, G = 0;
    cin >> N >> R;

    vector<vector<pair<int, int>>> tree(N + 1);
    vector<int> result(N + 1, 0);
    vector<int> visited(N + 1, 0);
    queue<int> Q;

    for(int i = 0; i < N - 1; i++){
        int a, b, d;
        cin >> a >> b >> d;
        tree[a].push_back({b, d});
        tree[b].push_back({a, d}); // 트리니까 양방향 간선
    }

    Q.push(R);
    visited[R] = 1;

    while(!Q.empty()){
        int node = Q.front();
        Q.pop();
        for(auto [next, dist] : tree[node]){
            if(!visited[next]){
                visited[next] = 1;
                result[next] = result[node] + dist;
                Q.push(next);
            }
        }

        // 기둥 끝 찾기: 자식이 하나 이상이면 아직 기둥
        if(Q.size() != 1 && flag){
            G = node;
            flag = 0;
        }
    }

    // 가장 먼 리프까지 거리 구하기
    int maxBranch = 0;
    for(int i = 1; i <= N; i++){
        if(result[i] > result[G])
            maxBranch = max(maxBranch, result[i] - result[G]);
    }

    cout << result[G] << ' ' << maxBranch << '\n';
    return 0;
}
