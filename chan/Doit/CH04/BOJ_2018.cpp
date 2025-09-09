#include <iostream>
#include <vector>
#define FASTIO cin.tie(NULL); ios::sync_with_stdio(false);
using namespace std;

int main(){
    FASTIO;
    int N;
    int start_idx = 1, end_idx = 1, sum = 1, cnt = 1;
    cin >> N;
    while(end_idx != N){
        if(sum == N){
            cnt++;
            end_idx++;
            sum = sum + end_idx;
        }else if(sum > N){
            sum = sum - start_idx;
            start_idx++;
        }else if(sum < N){
            end_idx++;
            sum = sum + end_idx;
        }
    }
    cout << cnt << '\n';
    return 0;
}