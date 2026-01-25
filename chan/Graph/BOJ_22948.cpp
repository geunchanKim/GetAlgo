#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;
struct Info{
    int x, id;
    bool isLeft;
};
// x좌표 기준으로 정렬
bool compare(const Info& a, const Info& b){
    return a.x < b.x;
}
int N, A, B;
int parent[200005];
vector<int> tree[200005];
int main(){
    FASTIO;
    cin >> N;
    vector<Info> events;
    for(int i = 0; i < N; i++){
        int k, x, r;
        cin >> k >> x >> r;
        events.push_back({x - r, k, true});
        events.push_back({x + r, k, false});
    }
    cin >> A >> B;
    sort(events.begin(), events.end(), compare);
    // 1. 스윕 라인으로 트리 구축 (O(N log N))
    stack<int> s;
    s.push(0); // 0번은 외부 공간 (Root)
    for(auto& e : events){
        if(e.isLeft){
            parent[e.id] = s.top();
            tree[s.top()].push_back(e.id);
            s.push(e.id);
        }else
            s.pop();
    }
    // 2. A에서 루트(0)까지의 경로 추출
    vector<int> pathA;
    int curr = A;
    while(curr != -1){
        pathA.push_back(curr);
        if (curr == 0) break;
        curr = parent[curr];
    }
    // 3. B에서 루트(0)까지의 경로 추출
    vector<int> pathB;
    curr = B;
    while(curr != -1){
        pathB.push_back(curr);
        if (curr == 0) break;
        curr = parent[curr];
    }
    // 4. 공통 조상(LCA) 찾기 위해 뒤에서부터 비교
    int i = pathA.size() - 1;
    int j = pathB.size() - 1;
    while(i >= 0 && j >= 0 && pathA[i] == pathB[j]){
        i--;
        j--;
    }
    // 5. 경로 합치기 (A -> LCA -> B)
    vector<int> result;
    // A에서 공통 조상 직전까지
    for(int k = 0; k <= i + 1; k++)
        result.push_back(pathA[k]);
    // 공통 조상 이후부터 B까지 (역순으로 저장되어 있으므로 앞에서부터)
    for(int k = j; k >= 0; k--)
        result.push_back(pathB[k]);
    // 출력
    cout << result.size() << "\n";
    for(int node : result)
        cout << node << " ";
    return 0;
}