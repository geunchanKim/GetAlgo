#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    cin.sync_with_stdio(false);

    priority_queue<int> Q;
    int cnt = 0;
    int total = 0;
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        int price;
        cin >> price;
        Q.push(price);
    }

    while(!Q.empty()){
        cnt++;
        if(cnt == 3){
            cnt = 0;
            Q.pop();
        }else{
            total += Q.top();
            Q.pop();
        }
    }

    cout << total;
}