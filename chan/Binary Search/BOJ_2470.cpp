#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;
typedef long long ll;

int main(){
    FASTIO;
    ll N, left = 0, sum;
    cin >> N;
    ll right = N - 1;
    vector<ll> ary(N);
    vector<ll> best(2);
    for(ll i = 0; i < N; i++)
        cin >> ary[i];
    sort(ary.begin(), ary.end());
    best[0] = ary[left];
    best[1] = ary[right];
    while(left < right){
        sum = ary[left] + ary[right];
        if(abs(sum) < abs(best[0] + best[1])){
            best[0] = ary[left];
            best[1] = ary[right];
        }
        if(sum == 0)
            break;
        else if(sum < 0)
            left++;
        else
            right--;
    }
    cout << best[0] << ' ' << best[1] << '\n';
    return 0;
}   