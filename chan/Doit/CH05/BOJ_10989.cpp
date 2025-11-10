#include <iostream>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;

int main(){
    FASTIO;
    long long N;
    long long ary[10001] = {0};
    cin >> N;
    for(int i = 0; i < N; i++){
        int idx;
        cin >> idx;
        ary[idx]++;
    }
    for(int i = 1; i < 10001; i++){ 
        for(int j = 0; j < ary[i]; j++)
            cout << i << '\n';
    }
    return 0;
}