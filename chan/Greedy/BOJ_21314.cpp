#include <iostream>
#include <string>
using namespace std;

string findMax(string S) {
    string result;
    int mCount = 0;  // 연속된 M의 개수를 셀 변수
    for (int i = 0; i < S.length(); i++) {
        if (S[i] == 'M') {
            mCount++;  // M의 개수를 셈
        } else {
            if (mCount > 0) {
                result += '5';  // K는 5로 시작
                for (int j = 0; j < mCount; j++) {
                    result += '0';  // 연속된 M만큼 0을 붙임
                }
                mCount = 0;
            } else {
                result += '5';  // M이 없을 경우 그냥 5를 붙임
            }
        }
    }
    if (mCount > 0) {  // 남아있는 M 처리
        for (int j = 0; j < mCount; j++) {
            result += '1';  // 연속된 M만큼 1을 붙임
        }
    }
    return result;
}

string findMin(string S) {
    string result;
    int mCount = 0;  // 연속된 M의 개수를 셀 변수
    for (int i = 0; i < S.length(); i++) {
        if (S[i] == 'M') {
            mCount++;  // M의 개수를 셈
        } else {
            if (mCount > 0) {
                result += '1';  // 최소값은 M에서 1로 시작
                for (int j = 0; j < mCount - 1; j++) {
                    result += '0';  // M이 2개 이상이면 0을 붙임
                }
                result += '5';  // K는 5로 처리
                mCount = 0;
            } else {
                result += '5';  // M이 없을 경우 그냥 5를 붙임
            }
        }
    }
    if (mCount > 0) {  // 남아있는 M 처리
        result += '1';  // 연속된 M이 남으면 1로 처리
        for (int j = 0; j < mCount - 1; j++) {
            result += '0';  // M이 2개 이상이면 0을 붙임
        }
    }
    return result;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    cin.sync_with_stdio(false);

    string S;
    cin >> S;

    string max = findMax(S);
    string min = findMin(S);

    cout << max << "\n" << min << "\n";
    return 0;
}
