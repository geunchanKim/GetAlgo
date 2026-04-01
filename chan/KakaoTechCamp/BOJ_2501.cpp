#include <iostream>
#define FASTIO cin.tie(NULL); cout.tie(NULL), ios::sync_with_stdio(false);
using namespace std;

int main(){
    FASTIO;
    int N, K, cnt = 0;
    cin >> N >> K;
    for(int i = 1; i <= N; i++){
        if(N % i == 0)
            cnt++;
        
        if(K == cnt){
            cout << i;
            return 0;
        }
    }
    cout << 0;
    return 0;
}