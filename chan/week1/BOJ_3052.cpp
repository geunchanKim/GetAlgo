#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> list(10);
    vector<int> check(42, 0);
    int cnt = 0;
    for(int i = 0; i < 10; i++){
        cin >> list[i];
        int idx = list[i] % 42;
        if(!check[idx]){
            cnt++;
            check[idx] = 1;
        }
    }
    cout << cnt;
}