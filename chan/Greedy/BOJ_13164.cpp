#include <iostream>
#include <queue>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;

int main(){
    FASTIO;
    int N, K, prev, sum = 0;
    priority_queue<int> Q;
    cin >> N >> K;
    cin >> prev;
    for(int i = 0; i < N - 1; i++){
        int tmp;
        cin >> tmp;
        Q.push(tmp - prev);
        prev = tmp;
    }
    for(int i = 0; i < K - 1; i++)
        Q.pop();
    while(!Q.empty()){
        sum += Q.top();
        Q.pop();
    }
    cout << sum;
    return 0;
}