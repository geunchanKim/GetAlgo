#include <iostream>
#include <vector>
using namespace std;
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
int N, M;
int arr[9];
bool visited[9];

void DFS(int cnt){
    if(cnt == M){
        for(int i = 0; i < M; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    for(int i = 1; i <= N; i++){
        if(!visited[i]){
            visited[i] = true;
            arr[cnt] = i;
            DFS(cnt + 1);
            visited[i] = false;
        }
    }
}

int main(){
    FASTIO;
    cin >> N >> M;
    DFS(0);
    return 0;
}