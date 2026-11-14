#include <iostream>
#include <vector>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;
int main(){
    FASTIO;
    int tc;
    cin >> tc;
    for(int i = 0; i < tc; i++){
        int N, max = 0;
        cin >> N;
        vector<int> ary(N);
        for(int j = 0; j < N; j++)
            cin >> ary[j];
    
        long long cnt = 0;  
        for(int j = N - 1; j >= 0; j--){
            if(ary[j] > max)
                max = ary[j];
            else
                cnt += max - ary[j];
        }
        cout << "#" << i + 1 << ' ' << cnt << '\n';
    }
}