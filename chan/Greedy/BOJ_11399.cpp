#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    cin.sync_with_stdio(false);

    priority_queue< int, vector< int >, greater < int > > pq;
    int N;
    int tmp = 0;
    int total = 0;
    cin >> N;
    for(int i = 0; i < N; i++){
        int time;
        cin >> time;
        pq.push(time);
    }

    while(!pq.empty()){
        tmp = pq.top() + tmp;
        total += tmp;
        pq.pop();
    }
    
    cout << total;
    return 0;
}