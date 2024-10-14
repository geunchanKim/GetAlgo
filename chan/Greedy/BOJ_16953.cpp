#include <iostream>
using namespace std;
long B;
int result = -1;

void solve(long A, int cnt){
    // A가 B와 같으면 변환 성공
    if(A == B){
        result = cnt;  // 변환 횟수 저장
        return;
    } 
    // A가 B를 초과하면 더 이상 변환 불가능
    else if(A > B)
        return;
    
    // A * 10 + 1 변환
    solve(A * 10 + 1, cnt + 1);
    
    // A * 2 변환
    solve(A * 2, cnt + 1);
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    cin.sync_with_stdio(false);

    long A;
    cin >> A >> B;

    solve(A, 1);

    cout << result;
    return 0;
}