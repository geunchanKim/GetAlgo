#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;
typedef long long ll;

struct Circle {
    ll x, y, r;
};

vector<Circle> circles;
vector<int> parent;
vector<vector<int>> tree;
int N, answer = 0;

int DFS(int u) {
    int max1 = 0, max2 = 0;

    for (int v : tree[u]) {
        int h = DFS(v) + 1; 
        if (h > max1) {
            max2 = max1;
            max1 = h;
        } else if (h > max2) {
            max2 = h;
        }
    }
    answer = max(answer, max1 + max2);
    return max1;
}

bool contains(int a, int b) {
    if (circles[a].r <= circles[b].r) return false; // 포함하는 원이 더 커야 함
    ll dx = circles[a].x - circles[b].x;
    ll dy = circles[a].y - circles[b].y;
    ll dist2 = dx * dx + dy * dy;
    ll rdiff = circles[a].r - circles[b].r;
    return dist2 < rdiff * rdiff;
}

int main() {
    FASTIO;
    cin >> N;
    circles.resize(N + 1);
    for (int i = 1; i <= N; i++)
        cin >> circles[i].x >> circles[i].y >> circles[i].r;
    parent.assign(N + 1, 0); 
    for (int i = 1; i <= N; i++) {
        ll minR = 2000000000LL; 
        int p = 0;
        for (int j = 1; j <= N; j++) {
            if(i == j) continue;
            if(contains(j, i) && circles[j].r < minR){
                minR = circles[j].r;
                p = j;
            }
        }
        parent[i] = p;
    }
    tree.assign(N + 1, vector<int>());
    for(int i = 1; i <= N; i++)
        tree[parent[i]].push_back(i);
    DFS(0);
    cout << answer;
    return 0;
}