#include <iostream>
#include <map>
#include <set>
using namespace std;

map<int, pair<int, int>> mainMap;  // P별 (L, G)
map<int, set<pair<int, int>>> groupMap; // G별 (L, P)
set<pair<int, int>> allSet; // 전체 (L, P)

void insert(int P, int L, int G) {
    mainMap[P] = make_pair(L, G);
    groupMap[G].insert({L, P});
    allSet.insert({L, P});
}

void removeByP(int P) {
    auto it = mainMap[P];
    int L = it.first;
    int G = it.second;
    groupMap[G].erase({L, P}); // groupMap에서도 삭제
    allSet.erase({L, P}); //allSets에서도 삭제
}

void findProblem(int x, int L) {
    if (allSet.empty()) {
        cout << "-1\n";
        return;
    }

    if (x == 1) {  // L 이상 중 가장 쉬운 문제
        auto it = allSet.lower_bound({L, 0});
        if (it == allSet.end()) {
            cout << "-1\n";
        } else {
            cout << it->second << "\n";
        }
    } 
    else if (x == -1) {  // L 미만 중 가장 어려운 문제
        auto it = allSet.lower_bound({L, 0});
        if (it == allSet.begin()) {
            cout << "-1\n";
        } else {
            --it;
            cout << it->second << "\n";
        }
    }
}

int main() {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int P, L, G;
        cin >> P >> L >> G;
        insert(P, L, G);
    }    

    int M;  
    cin >> M;
    for(int i = 0; i < M; i++){
        string cmd;
        cin >> cmd;
        if(cmd == "add"){
            int P, L, G;
            cin >> P >> L >> G;
            insert(P, L, G);
        }else if(cmd == "solved"){
            int P;
            cin >> P;
            removeByP(P);
        }else if(cmd == "recommend"){
            int G, x;
            cin >> G >> x;
            if(x == 1)
                cout << prev(groupMap[G].end())->second << "\n";
            else if(x == -1)
                cout << groupMap[G].begin()->second << "\n";
        }else if(cmd == "recommend2"){
            int x;
            cin >> x;
            if(x == 1)
                cout << prev(allSet.end())->second << "\n";
            else if(x == -1)
            cout << allSet.begin()->second << "\n";
        }else if(cmd == "recommend3"){
            int x, L;
            cin >> x >> L;
            findProblem(x, L);
        }
    }

    return 0;
}
