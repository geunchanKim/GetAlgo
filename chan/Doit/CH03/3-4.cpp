#include <iostream>
using namespace std;

int main(){
    long long answer = 1;
    for(int i = 1; i <= 50; i++){
        answer = answer * i;
    }
    cout << answer % 10007;

    answer = 1;
    for(int i = 1; i <= 50; i++){
        answer = (answer * i) % 10007;
    }
    cout << answer;
}