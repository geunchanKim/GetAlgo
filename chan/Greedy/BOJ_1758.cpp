#include <iostream>
#include <queue>
using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    cin.sync_with_stdio(false);

    priority_queue<int> line;
    int N;
    long long result = 0;
    int idx = 1;
    cin >> N;
    for(int i = 0; i < N; i++){
        long long num;
        cin >> num;
        line.push(num);
    }

    while(!line.empty()){
        long long tip = line.top() - (idx++ - 1);
        if(tip > 0)
            result += tip;
        line.pop();
    }

    cout << result;
    return 0;
}