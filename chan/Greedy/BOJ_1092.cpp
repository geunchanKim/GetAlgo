#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;

int main(){
    //변수 선언 및 입력
    FASTIO;
    int N, M;
    cin >> N;
    vector<int> cranes(N);
    for (int i = 0; i < N; i++)
        cin >> cranes[i];
    cin >> M;
    vector<int> boxes(M);
    for (int i = 0; i < M; i++)
        cin >> boxes[i];
    sort(cranes.begin(), cranes.end(), greater<int>());
    sort(boxes.begin(), boxes.end(), greater<int>());

    //불가능한 경우
    if (cranes[0] < boxes[0]) {
        cout << -1;
        return 0;
    }

    //가능한 경우
    int cnt = 0;
    while (!boxes.empty()) {
        int idx = 0;
        for (int i = 0; i < boxes.size();){
            if (idx == cranes.size()) 
                break;
            if (cranes[idx] >= boxes[i]){
                boxes.erase(boxes.begin() + i);
                idx++;
            }else
                i++;
        }
        cnt++;
    }
    cout << cnt;
    return 0;
}