#include <iostream>
#include <vector>
using namespace std;

int main() {
    int testNum;
    cin >> testNum;

    for (int i = 0; i < testNum; i++) {
        int n, m;
        cin >> n >> m;
        vector<int> queue;
        for (int i = 0; i < n; i++) {
            int priority;
            cin >> priority;
            queue.push_back(priority);
        }

        
    }

    return 0;
}