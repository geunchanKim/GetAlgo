#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO cin.tie(NULL); ios::sync_with_stdio(false);
using namespace std;

int main(){
    FASTIO;
    int N;
    long long cnt = 0;
    cin >> N;
    vector<long long> A(N);
    for(int i = 0; i < N; i++)
        cin >> A[i];
    sort(A.begin(), A.end());
    
    for(int i = 0; i < N; i++){
        int start = 0;
        int end = N - 1;
        while(start < end){
            long long tmp = A[start] + A[end];
            if(tmp == A[i]){
                if(start != i && end != i){
                    cnt++;
                    break;
                }else if(start == i)
                    start++;
                else if(end == i)
                    end--;
            }else if(tmp < A[i])
                start++;
            else if(tmp > A[i])
                end--;
        }
    }

    cout << cnt << '\n';
    return 0;
}