#include <iostream>
#include <vector>
using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    cin.sync_with_stdio(false);

    int N, K, result;
    int idx = 0;
    cin >> N >> K;
    vector<bool> flag(N + 1, false);

    for (int i = 2; i <= N; i++){
        for (int j = i; j <= N; j += i){
            if (!flag[j]){
                idx++;
                flag[j] = true;
                if (idx == K){
                    cout << j << "\n";
                    break;
                }
            }
        }
        if (idx == K)
            break;
    }
}