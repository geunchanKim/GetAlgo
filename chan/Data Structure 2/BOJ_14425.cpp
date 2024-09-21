#include <iostream>
#include <unordered_map>
using namespace std;

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    
    unordered_map<string, bool> list;
    int cnt = 0;
    int N, M;
    cin >> N >> M;

    for(int i = 0; i < N; i++){
        string S;
        cin >> S;
        list[S] = true;
    }

    for(int i = 0; i < M; i++){
        string S;
        cin >> S;
        if(list[S])
            cnt++;
    }

    cout << cnt;
}