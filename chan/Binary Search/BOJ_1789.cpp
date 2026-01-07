#include <iostream>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;

long long total(long long n){
    return (n * (n + 1)) / 2;
}

int main(){
    FASTIO;
    long long S, start, mid, end, ans = 0;
    cin >> S;
    start = 0;
    end = S;
    while(start <= end){
        mid = (start + end) / 2;
        if(total(mid) <= S){
            ans = mid;    
            start = mid + 1;    
        }else
            end = mid - 1;
    }
    cout << ans;
    return 0;
}