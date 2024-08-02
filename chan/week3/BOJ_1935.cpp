#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    int N;
    double x, y;
    string expression;
    cin >> N;
    cin >> expression;
    stack<double> S;
    vector<double> V(N);
    for(int i = 0; i < N; i++)
        cin >> V[i];
    for(int i = 0; i < expression.length(); i++){
        switch(expression[i]){
            case '+':
                x = S.top();
                S.pop();
                y = S.top();
                S.pop();
                S.push(y+x);
                break;
            case '-': 
                x = S.top();
                S.pop();
                y = S.top();
                S.pop();
                S.push(y-x);
                break;
            case '*':
                x = S.top();
                S.pop();
                y = S.top();
                S.pop();
                S.push(y*x);
                break;
            case '/':
                x = S.top();
                S.pop();
                y = S.top();
                S.pop();
                S.push(y/x);
                break;
            default:
                int idx = expression[i] - 65;
                S.push(V[idx]);
                break;
        }
    }
    cout << fixed;
    cout.precision(2);
    cout << S.top();
}