#include <iostream>
#include <vector>
using namespace std;

int minCoin(int amount, vector<int> coins){
    int cnt = 0;
    for(auto coin : coins){
        if(coin <= amount){
            cnt += amount / coin;
            amount %= coin;
        }
    }
    return cnt;
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    cin.sync_with_stdio(false);

    int N, K;
    cin >> N >> K;
    vector<int> coins;
    for(int i = 0; i < N; i++){
        int coin;
        cin >> coin;
        coins.insert(coins.begin(), coin);
    }

    cout << minCoin(K, coins);;
    return 0;
}