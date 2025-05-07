#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <functional>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;

int main(){
    FASTIO;
    int N;
    cin >> N;
    vector<pair<int, int>> Meetings(N);

    for(int i = 0; i < N; i++){
        cin >> Meetings[i].first >> Meetings[i].second;
    }

    // 시작 시간 기준 정렬
    sort(Meetings.begin(), Meetings.end());

    // 종료 시간 오름차순 -> 빨리 끝나는 회의실 먼저 확인
    priority_queue<int, vector<int>, greater<int>> endTimes;

    for(auto [start, end] : Meetings){
        // 가장 빨리 끝나는 회의실이 이 회의의 시작 전에 끝났다면 재사용 가능
        if(!endTimes.empty() && endTimes.top() <= start){
            endTimes.pop(); // 재사용
        }
        endTimes.push(end); // 회의실 배정 또는 새 회의실
    }

    cout << endTimes.size(); // 필요한 회의실 수
    return 0;
}