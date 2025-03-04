#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
    //변수 선언 및 입력
    string str;
    cin >> str;
    stack<char> S; 
    int tmp = 1; //ans에 더하기 전 중간값을 계산하기 위한 변수
    int ans = 0;

    //계산
    for(int i = 0; i < str.length(); i++){
        if(str[i] == '('){
            tmp *= 2;
            S.push(str[i]);
        }
        if(str[i] == '['){
            tmp *= 3;
            S.push(str[i]);
        }
        if(str[i] == ')'){
            if(S.empty() || S.top() != '('){ //올바르지 못한 괄호
                ans = 0;
                break;
            }else if(str[i-1] == '('){ //괄호값이 '()'이므로 더해주고 tmp 나누기
                ans += tmp;
                tmp /= 2;
                S.pop();
            }else{ //괄호값이 '()'아니므로 tmp만 나누기
                tmp /= 2;
                S.pop();
            }
        }
        if(str[i] == ']'){ 
            if(S.empty() || S.top() != '['){ 
                ans = 0;
                break;
            }else if(str[i-1] == '['){
                ans += tmp;
                tmp /= 3;
                S.pop();
            }else{
                tmp /= 3;
                S.pop();
            }
        }
    }
    if(!S.empty())
        ans = 0;
    cout << ans;
}