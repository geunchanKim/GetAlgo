#include <iostream>
#include <string>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;

int main() {
    FASTIO;
    int N, K;
    string s;
    cin >> N >> K >> s;

    string stk;
    stk.reserve(N);

    for (char c : s) {
        while (!stk.empty() && K > 0 && stk.back() < c) {
            stk.pop_back();
            --K;
        }
        stk.push_back(c);
    }

    // 아직 덜 지웠다면 뒤에서 제거
    if (K > 0) stk.erase(stk.end() - K, stk.end());

    cout << stk;
    return 0;
}
