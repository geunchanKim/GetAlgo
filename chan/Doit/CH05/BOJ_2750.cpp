#include <iostream>
#include <vector>
#define FASTIO cin.tie(NULL); ios::sync_with_stdio(false);
using namespace std;

int main(){
    FASTIO;
    int N; 
    cin >> N;
    vector<int> ary(N);
    for(int i = 0; i < N; i++)
        cin >> ary[i];
    for(int i = 0; i < N - 1; i++){
        for(int j = 0; j < N - 1 - i; j++){
            if(ary[j] > ary[j + 1]){
                int tmp = ary[j];
                ary[j] = ary[j + 1];
                ary[j + 1] = tmp;
            }
        }
    }
    for(int i = 0; i < N; i++)
        cout << ary[i] << '\n';
    return 0;
}