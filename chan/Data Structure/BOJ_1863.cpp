#include <iostream>
#include <stack>
using namespace std;

int main() {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int ans = 0;
    int N;
    cin >> N;

    stack<int> S;

    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;

        while (!S.empty() && S.top() > y) {  // 현재 높이가 더 낮으면 스택에서 제거
            S.pop();
            ans++;
        }

        if (!S.empty() && S.top() == y) {
            continue; // 현재 높이가 이전 높이와 같으면 아무것도 하지 않음
        }

        if (y > 0) {  // 새로운 높이를 추가
            S.push(y);
        }
    }

    while (!S.empty()) {  // 남아 있는 높이 처리
        S.pop();
        ans++;
    }

    cout << ans << "\n";
    return 0;
}
