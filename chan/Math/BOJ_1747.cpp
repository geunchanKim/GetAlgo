#include <iostream>
#include <deque>
using namespace std;

bool isPrime(int N){
    if(N == 1)
        return false;

    if(N == 2 || N == 3)
        return true;
    
    if(N % 2 == 0 || N % 3 == 0)
        return false;

    for(int i = 5; i*i <= N; i++){
        if(N % i == 0)
            return false;
    }

    return true;
}

bool isPalindrome(deque<int> DQ){
    while(DQ.size() > 1){  // size()가 1 이상인 경우에만 front와 back을 비교
        if(DQ.front() != DQ.back()){
            return false;
        }
        DQ.pop_front();
        DQ.pop_back();
    }
    return true;
}

deque<int> numberToDeque(int N) {
    deque<int> DQ;
    while(N != 0) {
        DQ.push_front(N % 10);
        N /= 10;
    }
    return DQ;
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    cin.sync_with_stdio(false);

    int N;
    cin >> N;

    while(true){
        deque<int> DQ = numberToDeque(N);  // N에 대해 DQ를 초기화
        if(isPrime(N) && isPalindrome(DQ)){
            cout << N << endl;  // N을 출력하고 종료
            break;
        }
        N++;
    }

    return 0;
}
