#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define FASTIO cin.tie(NULL); ios::sync_with_stdio(false);

int main(){
    FASTIO;
    int N;
    cin >> N;
    vector<pair<int, int>> ary;
    for(int i = 0; i < N; i++){
        int tmp;
        cin >> tmp;
        ary.push_back({tmp, i});
    }
    sort(ary.begin(), ary.end());
    int max = 0;
    for(int i = 0; i < N; i++){
        if(max < ary[i].second - i)
            max = ary[i].second - i;
    }
    cout << max + 1;
    return 0;
}