#include <iostream>
#include <queue>
#include <functional>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;

int main(){
    FASTIO;
    int N, sum = 0;
    cin >> N;
    priority_queue< int, vector<int>, greater<int> > Q;
    for(int i = 0; i < N; i++){
        int tmp;
        cin >> tmp;
        Q.push(tmp);
    }
    if(N == 1){
        cout << 0;
        return 0;
    }
    while(!Q.empty()){
        int a = Q.top(), b;
        Q.pop();
        if(!Q.empty()){
            b = Q.top();
            Q.pop();
            sum += (a + b);
            if(!Q.empty())
                Q.push(a + b);
        }else
            sum += a; 
    }
    cout << sum;
    return 0;
}