#include <iostream>
#include <vector>
#include <unordered_map>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;

vector<int> inorder, postorder;
unordered_map<int, int> in_idx; // 값 -> inorder 인덱스 매핑

void solve(int in_start, int in_end, int post_start, int post_end) {
    if (in_start > in_end || post_start > post_end) return;

    int root = postorder[post_end]; // 후위 순회의 마지막이 루트
    cout << root << ' ';

    int root_index = in_idx[root]; // 중위 순회에서 루트 위치
    int left_size = root_index - in_start; // 왼쪽 서브트리 크기

    // 왼쪽 서브트리
    solve(in_start, root_index - 1, post_start, post_start + left_size - 1);
    // 오른쪽 서브트리
    solve(root_index + 1, in_end, post_start + left_size, post_end - 1);
}

int main() {
    FASTIO;
    int n;
    cin >> n;
    inorder.resize(n);
    postorder.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> inorder[i];
        in_idx[inorder[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        cin >> postorder[i];
    }

    solve(0, n - 1, 0, n - 1);
    return 0;
}