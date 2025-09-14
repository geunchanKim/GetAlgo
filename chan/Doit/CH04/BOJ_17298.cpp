#include <iostream>
#include <stack>
#include <vector>
#define FASTIO cin.tie(NULL); ios::sync_with_stdio(false);
using namespace std;

int main(){
    FASTIO;
    stack<pair<int, int>> S;
    int N, tmp, tmp_idx;
    cin >> N;
    vector<int> NGE(N, -1);
    for(int i = 0; i < N; i++){
        cin >> tmp;
  
        while (!S.empty() && S.top().first < tmp) {
            NGE[S.top().second] = tmp;
            S.pop();
        }

        S.push({tmp, i});
    }

    for(int i = 0; i < N; i++)
        cout << NGE[i] << ' ';
    
    return 0;
}