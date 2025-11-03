#include <iostream>
#include <vector>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;

vector<int> tmp;
vector<int> A;
long result = 0;

void merge(int S, int E){
    if(E - S < 1)
        return;
    int M = S + (E - S) / 2;
    merge(S, M);
    merge(M + 1, E);
    for(int i = S; i <= E; i++)
        tmp[i] = A[i];
    int k = S;
    int idx1 = S;
    int idx2 = M + 1;
    while(idx1 <= M && idx2 <= E){
        if(tmp[idx1] > tmp[idx2]){
            A[k] = tmp[idx2];
            result = result + idx2 - k;
            k++;
            idx2++;
        }else{
            A[k] = tmp[idx1];
            k++;
            idx1++;
        }
    }
    while(idx1 <= M){
        A[k] = tmp[idx1];
        k++;
        idx1++;
    }
    while(idx2 <= E){
        A[k] = tmp[idx2];
        k++;
        idx2++;
    }
}

int main(){
    FASTIO;
    int N;
    cin >> N;
    A.resize(N + 1);
    tmp.resize(N + 1);
    for(int i = 1; i <= N; i++)
        cin >> A[i];
    merge(1, N);
    cout << result;
    return 0;
}