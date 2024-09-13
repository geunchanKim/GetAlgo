#include <iostream>
#include <vector>
using namespace std;

void insertTree(int depth, int start, int end, vector<vector<int> >& level, vector<int>& list) {
    if (start >= end)
        return;
    
    int mid = (start + end) / 2;  // 중간 인덱스 계산
    level[depth].push_back(list[mid]);  // 현재 깊이에 중간 값을 추가

    // 재귀적으로 왼쪽과 오른쪽 서브트리 처리
    insertTree(depth + 1, start, mid, level, list);
    insertTree(depth + 1, mid + 1, end, level, list);
}

int main() {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    // 각 층을 담기 위한 자료구조
    int k;
    cin >> k;
    vector<vector<int> > level_order(k);

    // 노드의 개수 + 입력 
    int nodes = (1 << k) - 1;  // 2^k - 1
    vector<int> list(nodes);
    
    for (int i = 0; i < nodes; i++) 
        cin >> list[i];
    
    // 트리를 구성하는 함수 호출
    insertTree(0, 0, nodes, level_order, list);

    // 결과 출력
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < level_order[i].size(); j++)
            cout << level_order[i][j] << " ";
        cout << "\n";
    }
}
