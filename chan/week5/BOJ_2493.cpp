// 시간초과 나온 내 코드...
// #include <stack>
// #include <vector>
// using namespace std;
// stack<pair<int, int> > S;
// void find_ans(vector<int>& ans){
//     vector<pair<int, int> > store;
//     while(!S.empty()){
//         store.push_back(S.top());
//         S.pop();
//         if(!S.empty()){
//             for(auto i : store){
//                 //cout << "not empty " << i.second << " " << S.top().second << endl;
//                 if(!ans[i.first] && i.second < S.top().second){
//                     ans[i.first] = S.top().first;
//                     //cout << ans[i.first] << endl;   
//                 }
//             }
//         }
//     }
//     return;
// }
// int main(){
//     cin.tie(NULL);
//     cin.sync_with_stdio(false);
//     int N;
//     cin >> N;
//     vector<int> ans (N+1, 0);
//     for(int i = 1; i <= N; i++){
//         int j;
//         cin >> j;
//         S.push(make_pair(i, j));
//     }
//     find_ans(ans);
//     for(int i = 1; i <= N; i++)
//         cout << ans[i] << " ";
// }

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;
    cin >> N;
    vector<int> ans(N + 1, 0);
    stack<pair<int, int>> S;  // <탑의 인덱스, 탑의 높이>

    for(int i = 1; i <= N; i++){
        int height;
        cin >> height;

        // 스택에서 현재 탑보다 낮은 탑들을 제거
        while(!S.empty() && S.top().second < height) {
            S.pop();
        }

        // 스택이 비어있지 않다면, 현재 탑의 왼쪽에 있는 첫 번째 큰 탑을 찾는다.
        if(!S.empty()) {
            ans[i] = S.top().first;
        }

        // 현재 탑을 스택에 추가
        S.push({i, height});
    }

    for(int i = 1; i <= N; i++) {
        cout << ans[i] << " ";
    }
}
