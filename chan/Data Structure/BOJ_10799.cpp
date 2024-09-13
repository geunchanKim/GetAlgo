#include <iostream>
#include <stack>
using namespace std;

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    int cnt = 0;
    stack<char> S;
    string parenthesis;
    cin >> parenthesis;
    for(int i = 0; i < parenthesis.length(); i++){
        if(parenthesis[i] == '('){
            S.push(parenthesis[i]);
            if(parenthesis[i+1] == ')'){
                S.pop();
                if(!S.empty())
                    cnt += S.size();
                //cout << i << ' ' << parenthesis[i] << ' ' << cnt << ' ' << S.size() << endl;
            }  
        }else if(parenthesis[i] == ')'){
            if(parenthesis[i+1] == ')'){
                cnt++;
                S.pop();
                //cout << i << ' ' << parenthesis[i] << ' ' << cnt << ' ' << S.size() << endl;
            }
        }
    }
    cout << cnt;
}
