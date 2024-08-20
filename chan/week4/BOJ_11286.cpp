#include <iostream>
#include <queue>
#include <cstdlib>
using namespace std;

struct cmp {
    bool operator()(int a, int b){
        if(abs(a) == abs(b))
            return a > b;
        return abs(a) > abs(b);
    }
};

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    int N;
    cin >> N;
    priority_queue<int, vector<int>, cmp> pq; //priority_queue<자료형, 구현체, 비교연산자> pq;
    for(int i = 0; i < N; i++){
        int operation;
        cin >> operation;
        if(operation == 0){
            if(pq.empty())
                cout << 0 << "\n";
            else{
                cout << pq.top() << "\n";
                pq.pop();
            }
        }else{
            pq.push(operation);
        }
    }
}