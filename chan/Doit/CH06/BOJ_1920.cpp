#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;

int main(){
    FASTIO;
    int N, M;
    cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i++)
        cin >> A[i];
    sort(A.begin(), A.end());
    cin >> M;
    for(int i = 0; i < M; i++){
        int tmp;
        bool flag = false;
        cin >> tmp;
        int start = 0;
        int end = A.size() - 1;
        while(start <= end){
            int midi = (start + end) / 2;
            if(A[midi] == tmp){
                flag = true;
                cout << 1 << '\n';
                break;
            }else if(A[midi] < tmp)
                start = midi + 1;
            else if(A[midi] > tmp)
                end = midi - 1;
        }
        if(!flag)
            cout << 0 << '\n';
    }
}