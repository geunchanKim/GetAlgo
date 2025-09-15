#include <iostream>
#include <queue>
#define FASTIO cin.tie(NULL); ios::sync_with_stdio(false);
using namespace std;

int main(){
    FASTIO;
    int N;
    cin >> N;
    queue<int> Q;
    for(int i = 1; i <= N; i++)
        Q.push(i);
    int i = 0;
    while(Q.size() != 1){
        if(i % 2 == 0)
            Q.pop();
        else{
            Q.push(Q.front());
            Q.pop();
        }
        i++;
    }
    cout << Q.back();
    return 0;
}