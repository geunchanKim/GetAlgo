#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int cnt = 0;
void exchange(int N, vector<int>& S){
    for(int i = 0; i < N; i++){
        for(int j = i + 1; j < N; j++){
            if(S[i] > S[j]){
                swap(S[i], S[j]);
                cnt++;
            }
        }
    }
}

int main(){
    int N;
    cin >> N;
    vector<int> S(N);
    for(int i = 0; i < N; i++)
        cin >> S[i];
    exchange(N, S);
    for (int i = 0; i < N; i++)
        cout << S[i] << (i == N - 1 ? '\n' : ' ');
    cout << cnt;
}