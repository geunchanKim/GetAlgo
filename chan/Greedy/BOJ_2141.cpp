#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;

int main(){
    FASTIO;
    int N;
    long long sum = 0, cur = 0;
    cin >> N;
    vector< pair < long long, long long > > map;
    for(int i = 0; i < N; i++){
        long long town, population;
        cin >> town >> population;
        map.push_back(make_pair(town, population));
        sum += population; // long long
    }
    sort(map.begin(), map.end());
    for(int i = 0; i < N; i++){
        cur += map[i].second;
        if(cur >= (sum + 1) / 2){  // 짝수/홀수 상관없이 OK
            cout << map[i].first;
            break;
        }
    }
    return 0;
}