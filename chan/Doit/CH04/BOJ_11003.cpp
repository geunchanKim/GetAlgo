#include <iostream>
#include <deque>
#define FASTIO cin.tie(NULL); ios::sync_with_stdio(false);
using namespace std;

int main(){
    FASTIO;
    deque<pair<int, int>> dq;
    int N, L;
    cin >> N >> L;
    for(int i = 0; i < N; i++){
        int tmp;
        cin >> tmp;
        //입력 받은 수 보다 큰 값을 덱에서 제거
        while(dq.size() && dq.back().first > tmp)
            dq.pop_back();
        dq.push_back(pair<int, int>(tmp, i));
        //범위에 벗어나 값을 덱에서 제거
        if(dq.front().second <= i - L)
            dq.pop_front();
        cout << dq.front().first << ' ';
    }
    return 0;
}