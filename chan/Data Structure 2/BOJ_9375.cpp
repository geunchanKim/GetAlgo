#include <iostream>
#include <map>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int solve() {
    int N;
    cin >> N;

    if (N == 0) return 0; // 입력 예외 처리

    map<string, int> cloth;
    
    // 옷 개수 입력
    for (int i = 0; i < N; i++) {
        string item, category;
        cin >> item >> category;
        cloth[category]++; // 카테고리별 개수 증가
    }

    // 조합의 개수 계산
    int result = 1;
    for (auto it : cloth) {
        result *= (it.second + 1); // 각 카테고리에서 "입지 않는 경우(+1)" 포함
    }

    return result - 1; // 아무것도 안 입는 경우 제외
}

int main() {
    FASTIO;
    
    int T;
    cin >> T;
    
    while (T--) {
        cout << solve() << '\n';
    }

    return 0;
}