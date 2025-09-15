#include <iostream>
#include <queue>
using namespace std;
#define FASTIO cin.tie(NULL); ios::sync_with_stdio(false);

struct cmp {
    bool operator()(int a, int b){
        if(abs(a) == abs(b))
            return a > b;
        return abs(a) > abs(b);
    }
};

int main(){
    FASTIO;
    int N;
    cin >> N;
    priority_queue<int, vector<int>, cmp> PQ;
    for(int i = 0; i < N; i++){
        int tmp;
        cin >> tmp;
        if(tmp == 0){
            if(!PQ.empty()){
                cout << PQ.top() << '\n';
                PQ.pop();
            }else
                cout << '0' << '\n';
        }else
                PQ.push(tmp);
    }
    return 0;
}