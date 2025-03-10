#include <iostream>
#include <vector>
using namespace std;

int sum(int N, vector<int>& S){
    int result = 0;
    for(int i = 0; i < N; i++)
        result += S[i];
    return result;
}

int main(){
    int N;
    cin >> N;
    vector<int> S(N);
    for(int i = 0; i < N; i++)
        cin >> S[i];
    cout << sum(N, S);
}