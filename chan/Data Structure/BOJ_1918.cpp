#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    string expression;
    stack<char> op;
    cin >> expression;
    for(int i = 0; i < expression.length(); i++){
        // 피연산자이면 출력 배열에 넣기
        if(expression[i] >= 65 && expression[i] <= 90)
            cout << expression[i];
        // 연산자이면
        if(expression[i] >= 40 && expression[i] <= 47){
            if(expression[i] == '(') // ( 일 경우 - 스택에 넣기
                op.push(expression[i]);
            else if(expression[i] == ')'){ // ) 일 경우 - ( 까지 출력
                while(!op.empty() && op.top() != '('){
                    cout << op.top();
                    op.pop();
                }
                op.pop();
            }
            else if(expression[i] == '*' || expression[i] == '/'){ // * / 일 경우 - 우선순위가 스택의 탑보다 높으면 출력 (*, /만 우선순위 높음)
                while(!op.empty() && (op.top() == '*' || op.top() == '/')){
                    cout << op.top();
                    op.pop();
                }
                op.push(expression[i]); //현재 연산자 넣기
            }
            else if(expression[i] == '+' || expression[i] == '-'){ // + - 일 경우 - 우선순위가 스택의 탑보다 높으면 출력 ( ( 제외 다 출력)
                while(!op.empty() && op.top() != '('){
                    cout << op.top();
                    op.pop();
                }
                op.push(expression[i]); //현재 연산자 넣기
            }
        }
    }
    while(!op.empty()){
        cout << op.top();
        op.pop();
    }
}