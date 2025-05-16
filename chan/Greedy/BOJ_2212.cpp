#include <iostream>
#include <queue>
#include <algorithm>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;

int main(){
    FASTIO;
    int N, K, sum = 0;
    cin >> N;
    cin >> K;
    priority_queue<int> Q;
    vector<int> nPoint;
    for(int i = 0; i < N; i++){
        int point;
        cin >> point;
        nPoint.push_back(point);
    }
    
    if(N <= K){
        cout << 0;
        return 0;
    }

    sort(nPoint.begin(), nPoint.end());

    int tmp = nPoint[0];
    for(int i = 1; i < N; i++){
        int dist = nPoint[i] - tmp;
        Q.push(dist);
        tmp = nPoint[i];
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