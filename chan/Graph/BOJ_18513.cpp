#include <iostream>
#include <unordered_set>
#include <queue>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;
queue<pair<int, int>> Q;
unordered_set<int> visited;
long long result = 0;
int idx[] = {-1, 1};

void BFS(int K){
    int house_cnt = 0;
    while(house_cnt < K){
        int spring = Q.front().first;
        int house = Q.front().second;
        Q.pop();
        for(int i = 0; i < 2; i++){
            int house_idx = house + idx[i];
            if(house_cnt < K && visited.find(house_idx) == visited.end()){
                Q.push({spring, house_idx});
                visited.insert(house_idx);
                result += abs(spring - house_idx);
                house_cnt++;
            }
        }
    }
}

int main(){
    FASTIO;
    int N, K;
    cin >> N >> K;
    for(int i = 0; i < N; i++){
        int spring;
        cin >> spring;
        Q.push({spring, spring});
        visited.insert(spring);
    }
    BFS(K);
    cout << result;
    return 0;
}
