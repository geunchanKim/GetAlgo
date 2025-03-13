#include <iostream>
#include <queue>
using namespace std;

void solve(int M){
    priority_queue<long long int> MAX;
    priority_queue< long long int, vector < long long int >, greater < long long int > > MIN;
    vector<long long int> ans;
    ans.push_back(0);
    for(int i = 1; i <= M; i++){
        int N;
        cin >> N;
        if(i % 2 == 1){
            MAX.push(N);
            if(!MIN.empty() && MAX.top() > MIN.top()){
                MIN.push(MAX.top());
                MAX.pop();
                MAX.push(MIN.top());
                MIN.pop();
            }
            ans.push_back(MAX.top());
        }else
            MIN.push(N);    
    }

    cout << ans.size() - 1 << '\n';
    for(int i = 1; i < ans.size(); i++){
        if(i % 10 == 0)
            cout << ans[i] << '\n';
        else
            cout << ans[i] << ' ';
    }
}

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    int T;
    cin >> T;
    for(int i = 0; i < T; i++){
        int M;
        cin >> M;
        solve(M);
    }
    return 0;
}