#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

int main() {
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    
    int N;
    stack<int> S;
    cin >> N;

    unordered_map<string, int> commandMap;
    commandMap["push"] = 1;
    commandMap["pop"] = 2;
    commandMap["size"] = 3;
    commandMap["empty"] = 4;
    commandMap["top"] = 5;

    for (int i = 0; i < N; i++) {
        string command;
        cin >> command;

        switch (commandMap[command]) {
            case 1: { // push
                int X;
                cin >> X;
                S.push(X);
                break;
            }
            case 2: // pop
                if (!S.empty()) {
                    cout << S.top() << "\n";
                    S.pop();
                } else {
                    cout << -1 << "\n"; // 스택이 비어있는 경우 -1 출력
                }
                break;
            case 3: // size
                cout << S.size() << "\n";
                break;
            case 4: // empty
                cout << (S.empty() ? 1 : 0) << "\n";
                break;
            case 5: // top
                if (!S.empty()) {
                    cout << S.top() << "\n";
                } else {
                    cout << -1 << "\n"; // 스택이 비어있는 경우 -1 출력
                }
                break;
            default:
                break;
        }
    }
}
