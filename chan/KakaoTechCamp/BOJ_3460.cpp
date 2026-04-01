#include <iostream>
#define FASTIO cin.tie(NULL); cout.tie(NULL), ios::sync_with_stdio(false);
using namespace std;

int main(){
    FASTIO;
    int T, n, cnt;
    cin >> T;
    for(int i = 0; i < T; i++){
        cnt = 0;
        cin >> n;
        while(n){
            if(n % 2 == 1)
                cout << cnt << ' ';
            n = n / 2;
            cnt++;
        }
        cout << '\n';
    }
    return 0;
}