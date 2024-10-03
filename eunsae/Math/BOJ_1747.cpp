#include <iostream>
#include <cmath>

int isPrime(int n);
int isPalindrome(int n);


int main(){
    int n;
    std::cin >> n;

    while(1){
        if(isPalindrome(n) && isPrime(n)){
            std::cout << n << std::endl;
            break;
        }
        n++;
    }
}

int isPrime(int n){ 
    if(n==1){
        return 0;
    }

    if(n==2 || n==3){
        return 1;
    }

    if(n % 2 == 0 || n % 3 == 0){
        return 0;
    }

    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return 0;
        }
    }
    
    return 1;
}

int isPalindrome(int n){ //펠린드롬인지 확인
    int originN = n;
    int reversedN = 0;
    while(originN != 0){
        reversedN = reversedN * 10 + (originN % 10);
        originN /= 10;
    }
    if(n == reversedN){
        return 1;
    }

    return 0;
}