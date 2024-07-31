#include <iostream>
#include <deque>
#include <unordered_map>

using namespace std;

int main() {
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    
    int N;
    deque<int> DQ;
    cin >> N;

    unordered_map<string, int> commandMap;
    commandMap["push_front"] = 1;
    commandMap["push_back"] = 2;
    commandMap["pop_front"] = 3;
    commandMap["pop_back"] = 4;
    commandMap["size"] = 5;
    commandMap["empty"] = 6;
    commandMap["front"] = 7;
    commandMap["back"] = 8;

    for (int i = 0; i < N; i++) {
        string command;
        cin >> command;
        switch (commandMap[command]) {
            case 1: { // push_front
                int X;
                cin >> X;
                DQ.push_front(X);
                break;
            }
            case 2: { // push_back
                int X;
                cin >> X;
                DQ.push_back(X);
                break;
            }
            case 3: // pop_front
                if (!DQ.empty()) {
                    cout << DQ.front() << "\n";
                    DQ.pop_front();
                } else {
                    cout << -1 << "\n"; //디큐가 비어있는 경우 -1 출력
                }
                break;
            case 4: // pop_back
                if (!DQ.empty()) {
                    cout << DQ.back() << "\n";
                    DQ.pop_back();
                } else {
                    cout << -1 << "\n"; // 디큐가 비어있는 경우 -1 출력
                }
                break;
            case 5: // size
                cout << DQ.size() << "\n";
                break;
            case 6: // empty
                cout << (DQ.empty() ? 1 : 0) << "\n";
                break;
            case 7: // front
                if (!DQ.empty()) {
                    cout << DQ.front() << "\n";
                } else {
                    cout << -1 << "\n"; // 디큐가 비어있는 경우 -1 출력
                }
                break;
            case 8: //back
                if(!DQ.empty()){
                    cout << DQ.back() << "\n";
                }else{
                    cout << -1 << "\n"; // 디큐가 비어있는 경우 -1 출력
                }
                break;
            default:
                break;
        }
    }
}