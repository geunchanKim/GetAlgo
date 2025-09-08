#include <iostream>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

int main(){
    FASTIO;
    int N, sum = 0;
    string Numbers;
    cin >> N;
    cin >> Numbers;
    for(int i = 0; i < N; i++){
        sum += Numbers[i] - '0';
    }
    cout << sum;
    return 0;
}