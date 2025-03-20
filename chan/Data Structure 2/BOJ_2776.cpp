#include <iostream>
#include <map>
#define FIRST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;

int T, N, M;

void solve(){
    map<int, int> note;
    cin >> N;
    for(int i = 0; i < N; i++){
        int num;
        cin >> num;
        note[num] = 1;
    }
    cin >> M;
    for(int i = 0; i < M; i++){
        int num;
        cin >> num;
        if(note.find(num) != note.end())
            cout << "1\n";
        else
            cout << "0\n";
    }
}

int main(){
    FIRST;
    cin >> T;
    for(int i = 0; i < T; i++)
        solve();
}