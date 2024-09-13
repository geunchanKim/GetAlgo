#include <iostream>
#include <stack>
using namespace std;

void check(stack<char> S, int N){
    stack<char> S2;
    for(int i = 0; i < N/2; i++){
        if(!S.empty()){
            if(S.top() == ')'){
                S.pop();
                while(!S.empty() && S.top() != '('){
                    S2.push(S.top());
                    S.pop();
                }
                if(!S.empty())
                    S.pop();
                while(!S2.empty()){
                    S.push(S2.top());
                    S2.pop();
                }
            }else{
                cout << "NO\n";
                return;
            }
        }
    }
    if(S.empty())
        cout << "YES\n";
    else 
        cout << "NO\n";
    return;
}

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    int T;
    cin >> T;
    for(int i = 0; i < T; i++){
        string parenthesis;
        cin >> parenthesis;
        stack<char> S;
        for(int j = 0; j < parenthesis.length(); j++)
            S.push(parenthesis[j]);    
        check(S, parenthesis.length());
    }
}