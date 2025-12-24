#include <iostream>
#include <set>
#include <queue>
#include <vector>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;
int graph[101];
bool visited[101];   
bool done[101];      
set<int> answer;

void DFS(int x){
    visited[x] = true;
    int next = graph[x];
    if(!visited[next]){
        if (!done[next])
            DFS(next);
    }else {
        int cur = next;
        answer.insert(cur);
        while (cur != x) {
            cur = graph[cur];
            answer.insert(cur);
        }
    }

    visited[x] = false;
    done[x] = true;
}

int main(){
    FASTIO;
    int N;
    cin >> N;
    for(int i = 1; i <= N; i++)
        cin >> graph[i];

    for(int i = 1; i <= N; i++)
        if (!done[i])
            DFS(i);
    
    cout << answer.size() << '\n';
    for(int i : answer)
        cout << i << '\n';

    return 0;
}