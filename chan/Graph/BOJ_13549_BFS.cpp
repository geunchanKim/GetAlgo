#include <iostream>
#include <vector>
#include <queue>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;
const int MAX = 100000;
int N, K;
vector<int> visited(MAX + 1, -1);

void BFS(int num){
    queue<int> Q;
    Q.push(num);
    visited[num] = 0;
    while (!Q.empty()) {
        int cur = Q.front(); Q.pop();
        if (cur == K) break;
        int next;
        next = cur * 2;
        if (next <= MAX && visited[next] == -1) {
            visited[next] = visited[cur];
            Q.push(next);
        }
        next = cur - 1;
        if (next >= 0 && visited[next] == -1) {
            visited[next] = visited[cur] + 1;
            Q.push(next);
        }
        next = cur + 1;
        if (next <= MAX && visited[next] == -1) {
            visited[next] = visited[cur] + 1;
            Q.push(next);
        }
    }
    return;
}

int main(){
    FASTIO;
    cin >> N >> K;
    BFS(N);
    cout << visited[K];
    return 0;
}