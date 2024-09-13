#include <iostream>
using namespace std;

int main(){
    int N;
    string num;
    int total = 0;
    cin >> N;
    cin >> num;
    for(int i = 0; i < N; i++){
        total += num[i] - '0';
    }
    cout << total;
}