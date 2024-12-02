#include <iostream>
#include <stack>
using namespace std;

int main(){
    int N;
    int cnt = 0;
    cin >> N;
    
    for(int i = 0; i < N; i++){
        stack<char> S;
        string str;
        cin >> str;
        if(str.length() % 2 == 0){
            for(int i = 0; i < str.length(); i++){
                if(!S.empty()){
                    if(S.top() == str[i]){
                        S.pop();
                    }else{
                        S.push(str[i]);
                    }
                }else{
                    S.push(str[i]);
                }
            }

            if(S.empty())
                cnt++;
        }
    }
    
    cout << cnt;
}