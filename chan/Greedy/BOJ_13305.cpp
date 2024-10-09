#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    cin.sync_with_stdio(false);

    long totalPrice = 0;
    int N;
    cin >> N;
    
    vector<long> roadDistance(N - 1);
    vector<int> price(N);

    // 거리 입력
    for (int i = 0; i < N - 1; i++) {
        cin >> roadDistance[i];
    }

    // 주유소 가격 입력
    for (int i = 0; i < N; i++) {
        cin >> price[i];
    }

    // 그리디 알고리즘을 이용해 최저가 주유소에서 최대한 멀리 이동
    long minPrice = price[0];  // 첫 번째 주유소의 가격
    for (int i = 0; i < N - 1; i++) {
        // 현재까지의 최소 가격으로 거리만큼 연료 충전
        if (price[i] < minPrice) {
            minPrice = price[i];  // 더 저렴한 주유소 발견 시 업데이트
        }
        totalPrice += minPrice * roadDistance[i];
    }

    cout << totalPrice << "\n";

    return 0;
}
