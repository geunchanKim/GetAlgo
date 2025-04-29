#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;

struct Class {
    int start;
    int end;
};

bool cmp(Class a, Class b) {
    if (a.start == b.start)
        return a.end < b.end;
    return a.start < b.start;
}

int main() {
    FASTIO;
    int N;
    cin >> N;
    vector<Class> classes(N);
    for (int i = 0; i < N; i++)
        cin >> classes[i].start >> classes[i].end;
    sort(classes.begin(), classes.end(), cmp);
    priority_queue<int, vector<int>, greater<int>> pq; // 끝나는 시간 기준 오름차순
    
    pq.push(classes[0].end);

    for (int i = 1; i < N; i++) {
        if(pq.top() <= classes[i].start) 
            pq.pop(); // 끝나는 시간이 빠른 강의실 사용
        pq.push(classes[i].end); // 새 끝나는 시간 등록
    }

    cout << pq.size(); // 필요한 강의실 수
    return 0;
}
