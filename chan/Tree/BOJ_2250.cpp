#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;

int root = 1, col_idx = 1, depth_max_idx = 0;
vector<int> tree[10002];
vector<int> depth[10002];
int node_col[10002];

void inorder(int cur, int d){
    if (cur == -1)
        return;
    inorder(tree[cur][0], d + 1);

    node_col[cur] = col_idx++;
    depth[d].push_back(cur);
    depth_max_idx = max(depth_max_idx, d);

    inorder(tree[cur][1], d + 1);
}

int main(){
    FASTIO;

    //입력
    int N;
    cin >> N;
    vector<bool> isRoot(N + 1, true);
    for (int i = 1; i <= N; i++){
        int cur, l, r;
        cin >> cur >> l >> r;
        tree[cur].push_back(l);
        tree[cur].push_back(r);

        if (l != -1)
            isRoot[l] = false;
        if (r != -1)
            isRoot[r] = false;
    }

    //root 노드 찾기
    for (int i = 1; i <= N; i++){
        if (isRoot[i]){
            root = i;
            break;
        }
    }

    //중위 순회 (왼 root 오)
    inorder(root, 1);

    //가장 넓은 레벨과 그 레벨의 너비를 출력
    int ans = 0, level = 0;
    for (int i = 1; i <= depth_max_idx; i++){
        int min_col = N, max_col = 0;
        for (auto x : depth[i]){
            min_col = min(min_col, node_col[x]);
            max_col = max(max_col, node_col[x]);
        }
        if (ans < max_col - min_col + 1){
            ans = max_col - min_col + 1;
            level = i;
        }
    }
    cout << level << ' ' << ans;
    return 0;
}