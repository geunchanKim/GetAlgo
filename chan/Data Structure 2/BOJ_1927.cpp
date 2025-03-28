#include <iostream>
#include <queue>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;

int main(){
    FASTIO;
    priority_queue< long long int, vector < long long int >, greater< long long int > > PQ;
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        long long int tmp;
        cin >> tmp;
        if(tmp == 0){
            if(!PQ.empty()){
                cout << PQ.top() << '\n';
                PQ.pop();
            }else
                cout << 0 << '\n';
        }else
            PQ.push(tmp);
    }
    return 0;
}