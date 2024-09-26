#include <iostream>
using namespace std;

// GCD(최대공약수)를 구하는 함수
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

// LCM(최소공배수)를 구하는 함수
unsigned long long lcm(int a, int b) {
    return (unsigned long long)a * (b / gcd(a, b));  // 곱셈 전에 나눗셈을 먼저 수행하여 오버플로우 방지
}

int main() {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        cout << lcm(a, b) << "\n";
    }

    return 0;
}
