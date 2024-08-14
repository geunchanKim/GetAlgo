#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, k, cnt = 1;
    cin >> n >> k;

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        q.push(i);
    }

    cout << "<";
    while (1) {
        int num = q.front();
        q.pop();
        if (cnt % k == 0) {
            cout << num;
            if (cnt < n) {
                    cout << ", ";
            }
            else {
                break;
            }
        }
        else {
            q.push(num);
        }
        cnt++;
    }
    cout << ">" << endl;

    return 0;
}