#include <iostream>
#include <vector>
using namespace std;

int minCoins(int amount, vector<int>& coins){
    if(amount < 2)
        return -1;

    int cnt = 0;
    if(amount < 5){
        cnt += amount / coins[1];
        amount %= coins[1];
        if(amount)
            return -1;
        return cnt;
    }

    int left = amount % coins[0];
    int flag = left % coins[1];
    if(!flag){
        for(int coin : coins){
            cnt += amount / coin;
            amount %= coin;
        }
    }else{
        int time = amount / coins[0] - 1;
        cnt += time;
        amount = amount - (coins[0] * time);
        cnt += amount / coins[1];
        amount %= coins[1];
        if(amount)
            return -1;
    }
    return cnt;
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    cin.sync_with_stdio(false);

    vector<int> coins = {5, 2};
    int amount;
    cin >> amount;

    int result = minCoins(amount, coins);
    cout << result;
}