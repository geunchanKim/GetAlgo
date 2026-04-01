#include <iostream>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;

int main(){
    FASTIO;
    int N, max = -1000000, min = 1000000, num;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> num;
        if(max < num)
            max = num;
        if(min > num)
            min = num;
    }
    cout << min << ' ' << max;
    return 0;
}