#include <iostream>
#include <queue>
#include <iomanip>
using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    cin.sync_with_stdio(false);

    priority_queue<double> PQ;
    double result = 0;
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        double amount;
        cin >> amount;
        PQ.push(amount);
    }

    result += PQ.top();
    PQ.pop();
    while(!PQ.empty()){
        result += (PQ.top() / 2);
        PQ.pop();
    }
    
    cout << fixed << setprecision(5);
    cout << result;

    return 0;
}