#include <iostream>
using namespace std;

int solve(int H, int W, int N){
    int nth, floor;
    if(N % H){
        nth = N / H + 1;
        floor = N % H;
    }else{
        nth = N / H;
        floor = H;
    }
    int ans = floor * 100 + nth;
    return ans; 
}

int main(){
    int T, H, W, N;
    cin >> T;
    for(int i = 0; i < T; i++){
        cin >> H >> W >> N;
        int ans  = solve(H, W, N);
        cout << ans << "\n";
    }
}