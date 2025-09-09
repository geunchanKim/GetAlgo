#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO cin.tie(NULL); ios::sync_with_stdio(false);
using namespace std;

int main(){
    FASTIO;
    int N, M;
    cin >> N >> M;
    int i = 0, j = N - 1, cnt = 0;
    vector<int> numbers(N);
    for(int k = 0; k < N; k++)
        cin >> numbers[k];
    sort(numbers.begin(), numbers.end());
    while(i < j){
        int tmp = numbers[i] + numbers[j];
        if(tmp == M){
            cnt++;
            i++;
            j--;
        }else if(tmp < M)
            i++;
        else if(tmp > M)
            j--;
    }
    cout << cnt << '\n';
    return 0;
}