#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

class DualPriorityQueue {
private:
    priority_queue<int> maxHeap;  // 최대 힙
    priority_queue< int, vector< int >, greater< int > > minHeap;  // 최소 힙
    unordered_map<int, int> count;  // 각 값의 삽입/삭제 상태를 추적

    // 힙의 상단에 있는 유효하지 않은 값을 제거하는 함수
    void syncHeaps() {
        // 최대 힙 동기화
        while (!maxHeap.empty() && count[maxHeap.top()] == 0) {
            maxHeap.pop();
        }
        // 최소 힙 동기화
        while (!minHeap.empty() && count[minHeap.top()] == 0) {
            minHeap.pop();
        }
    }

public:
    // 값을 삽입하는 함수
    void insert(int value) {
        maxHeap.push(value);
        minHeap.push(value);
        count[value]++;
    }

    // 최댓값을 삭제하는 함수
    void deleteMax() {
        syncHeaps();
        if (!maxHeap.empty()) {
            int maxValue = maxHeap.top();
            count[maxValue]--;
            maxHeap.pop();
        }
    }

    // 최솟값을 삭제하는 함수
    void deleteMin() {
        syncHeaps();
        if (!minHeap.empty()) {
            int minValue = minHeap.top();
            count[minValue]--;
            minHeap.pop();
        }
    }

    // 최댓값을 반환하는 함수
    int getMax() {
        syncHeaps();
        return maxHeap.top();
    }

    // 최솟값을 반환하는 함수
    int getMin() {
        syncHeaps();
        return minHeap.top();
    }

    // 큐가 비어 있는지 확인하는 함수
    bool isEmpty() {
        syncHeaps();
        return maxHeap.empty() || minHeap.empty();
    }
};

int main() {
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    int T;
    cin >> T;
    for(int i = 0; i < T; i++){
        DualPriorityQueue dpq;
        int k;
        cin >> k;
        for(int j = 0; j < k; j++){ 
            char op;
            cin >> op;
            if(op == 'I'){
                int num;
                cin >> num;
                dpq.insert(num);
            }else if(op == 'D'){
                int flag;
                cin >> flag;
                if(flag == 1)
                    dpq.deleteMax();
                else if(flag == -1)
                    dpq.deleteMin();
            }
        }
        if(!dpq.isEmpty())
            cout << dpq.getMax() << " " << dpq.getMin() << "\n";
        else
            cout << "EMPTY" << "\n";
    }
}