#include <iostream>
#include <queue>
using namespace std;

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    int N, K;
    cin >> N >> K;
    queue<int> Q;
    for(int i = 1; i <= N; i++)
        Q.push(i);
    cout << '<';
    while(!Q.empty()){
        for(int i = 0; i < K-1; i++){
            Q.push(Q.front());
            Q.pop();
        }
        if(Q.size() != 1)
            cout << Q.front() << ", ";
        else
            cout << Q.front();
        Q.pop();
    }
    cout << '>';
}