#include <iostream>
#include <queue>
using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    cin.sync_with_stdio(false);

    priority_queue<int> rope;    
    priority_queue<int> newRope;
    int N;
    cin >> N;
    
    for(int i = 0; i < N; i++){
        int weight;
        cin >> weight;
        rope.push(weight);
    }

    for(int i = 1; i <= N; i++){
        int newWeight = rope.top() * i;
        rope.pop();
        newRope.push(newWeight);
    }
    cout << newRope.top();

    return 0;
}