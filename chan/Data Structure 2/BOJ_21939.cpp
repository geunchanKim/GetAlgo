#include <iostream>
#include <set>
#include <unordered_map>
using namespace std;

// 난이도(L) 기준 정렬, 난이도가 같다면 문제 번호(P) 기준 정렬
struct Compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
        if (a.second == b.second)
            return a.first > b.first;  // 난이도가 같다면 문제 번호(P)가 큰 순서대로 정렬
        return a.second > b.second;  // 난이도 기준 내림차순 정렬
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    set<pair<int, int>, Compare> S;  // (P, L) 저장
    unordered_map<int, int> problem_map;  // P -> L 매핑

    cin >> N;
    for (int i = 0; i < N; i++) {
        int P, L;
        cin >> P >> L;
        S.insert({P, L});
        problem_map[P] = L;
    }

    cin >> M;
    for (int i = 0; i < M; i++) {
        string cmd;
        cin >> cmd;

        if (cmd == "recommend") {
            int x;
            cin >> x;
            if (x == 1) {
                // 가장 높은 난이도의 문제 출력
                cout << S.begin()->first << "\n";
            } else if (x == -1) {
                // 가장 낮은 난이도의 문제 출력
                cout << prev(S.end())->first << "\n";
            }
        } 
        else if (cmd == "add") {
            int P, L;
            cin >> P >> L;
            S.insert({P, L});
            problem_map[P] = L;  // 문제 추가
        } 
        else if (cmd == "solved") {
            int P;
            cin >> P;
            if (problem_map.find(P) != problem_map.end()) {
                int L = problem_map[P];  // 문제 P의 난이도 L 가져오기
                S.erase({P, L});  // set에서 삭제
                problem_map.erase(P);  // map에서도 삭제
            }
        }
    }

    return 0;
}
