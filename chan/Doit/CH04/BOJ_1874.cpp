#include <iostream>
#include <stack>
#include <vector>
#define FASTIO cin.tie(NULL); ios::sync_with_stdio(false);
using namespace std;

int main(){
    FASTIO;
    stack<int> S;
    int n, idx = 1;
    cin >> n;
    vector<int> seq(n + 1);
    vector<char> cSeq;
    for(int i = 1; i <= n; i++)
        cin >> seq[i];

    for(int i = 1; idx <= n; i++){
        if(S.empty()){
            S.push(i);
            cSeq.push_back('+');
        }else if(S.top() == seq[idx]){
            S.pop();
            cSeq.push_back('-');
            i--;
            idx++;
        }else if(S.top() < seq[idx]){
            S.push(i);
            cSeq.push_back('+');
        }else{
            cout << "NO";
            return 0;
        }
    }

    while(!S.empty()){
        S.pop();
        cSeq.push_back('-');
    }

    for(int i = 0; i < cSeq.size(); i++)
        cout << cSeq[i] << '\n';

    return 0;
}