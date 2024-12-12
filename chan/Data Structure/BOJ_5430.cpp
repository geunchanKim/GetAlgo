#include <iostream>
#include <list>
#include <string>
#include <sstream>
using namespace std;

int main() {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        bool flag = true;
        bool reverse = false; // 리스트가 뒤집힌 상태를 나타내는 플래그
        string cmd;
        cin >> cmd;
        int n;
        cin >> n;
        string input;
        cin >> input;

        // 입력 문자열 처리
        input = input.substr(1, input.size() - 2);
        stringstream ss(input);
        string number;
        list<int> L;
        while (getline(ss, number, ',')) {
            if (!number.empty()) {
                L.push_back(stoi(number));
            }
        }

        // 명령어 처리
        for (char c : cmd) {
            if (c == 'R') {
                reverse = !reverse; // 뒤집기 상태 변경
            } else if (c == 'D') {
                if (L.empty()) {
                    cout << "error\n";
                    flag = false;
                    break;
                }
                if (reverse) {
                    L.pop_back(); // 뒤집힌 상태에서는 뒤에서 삭제
                } else {
                    L.pop_front(); // 기본 상태에서는 앞에서 삭제
                }
            }
        }

        // 출력
        if (flag) {
            cout << "[";
            if (reverse) {
                for (auto it = L.rbegin(); it != L.rend(); ++it) {
                    if (it != L.rbegin()) cout << ",";
                    cout << *it;
                }
            } else {
                for (auto it = L.begin(); it != L.end(); ++it) {
                    if (it != L.begin()) cout << ",";
                    cout << *it;
                }
            }
            cout << "]\n";
        }
    }
    return 0;
}
