#include <iostream>
using namespace std;
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int N;

bool isPrime(int num){
    for(int i = 2; i <= num / 2; i++){
        if(num % i == 0)
            return false;
    }
    return true;
}

void DFS(int num, int n){
    if(N == n){
        if(isPrime(num))
            cout << num << '\n';
        return;
    }
    for(int i = 1; i < 10; i++){
        if(i % 2 == 0)
            continue;
        if(isPrime(num * 10 + i))
            DFS(num * 10 + i, n + 1);
    }
}

int main(){
    FASTIO;
    cin >> N;
    DFS(2, 1);
    DFS(3, 1);
    DFS(5, 1);
    DFS(7, 1);
    return 0;
}