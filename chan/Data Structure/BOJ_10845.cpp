#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

int main() {
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    
    int N;
    queue<int> Q;
    cin >> N;

    unordered_map<string, int> commandMap;
    commandMap["push"] = 1;
    commandMap["pop"] = 2;
    commandMap["size"] = 3;
    commandMap["empty"] = 4;
    commandMap["front"] = 5;
    commandMap["back"] = 6;

    for (int i = 0; i < N; i++) {
        string command;
        cin >> command;
        switch (commandMap[command]) {
            case 1: { // push
                int X;
                cin >> X;
                Q.push(X);
                break;
            }
            case 2: // pop
                if (!Q.empty()) {
                    cout << Q.front() << "\n";
                    Q.pop();
                } else {
                    cout << -1 << "\n"; // 큐가 비어있는 경우 -1 출력
                }
                break;
            case 3: // size
                cout << Q.size() << "\n";
                break;
            case 4: // empty
                cout << (Q.empty() ? 1 : 0) << "\n";
                break;
            case 5: // front
                if (!Q.empty()) {
                    cout << Q.front() << "\n";
                } else {
                    cout << -1 << "\n"; // 큐가 비어있는 경우 -1 출력
                }
                break;
            case 6: //back
                if(!Q.empty()){
                    cout << Q.back() << "\n";
                }else{
                    cout << -1 << "\n"; // 큐가 비어있는 경우 -1 출력
                }
                break;
            default:
                break;
        }
    }
}