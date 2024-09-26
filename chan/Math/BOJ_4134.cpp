#include <iostream>
using namespace std;

bool isPrime(long long n){    
    if(n <= 1)
        return false;
    
    if(n == 2 || n == 3)
        return true;

    if(n % 2 == 0 || n % 3 == 0)
        return false;

    for(long long j = 5; j*j <= n; j++){
        if(n % j == 0 || n % (j+2) == 0)
            return false;
    }
    return true;
}

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int Tcase;
    cin >> Tcase;
    for(int i = 0; i < Tcase; i++){
        long long n;
        cin >> n;
        while(!isPrime(n))
            n++;
        
        cout << n << "\n";
    }
}