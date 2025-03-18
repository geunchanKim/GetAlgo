#include <iostream>
#include <queue>
#define FIRST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;

int N; 
priority_queue<long long int> MAX;
priority_queue< long long int, vector < long long int >, greater < long long int > > MIN;

void solve(int N){
    for(int i = 0; i < N; i++){
        int tmp;
        cin >> tmp;
        if(i % 2 == 0){
            MAX.push(tmp);
            if(!MIN.empty() && MAX.top() > MIN.top()){
                MIN.push(MAX.top());
                MAX.pop();
                MAX.push(MIN.top());
                MIN.pop();
            }
        }else{
            MIN.push(tmp);
            if(!MIN.empty() && MAX.top() > MIN.top()){
                MIN.push(MAX.top());
                MAX.pop();
                MAX.push(MIN.top());
                MIN.pop();
            } 
        }
        cout << MAX.top() << '\n';
    }
} 

int main(){
    FIRST;
    cin >> N;
    solve(N);
    return 0;
}