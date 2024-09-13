#include <iostream>
#include <vector>
using namespace std;

int main(){
    long long int result;
    int A, B, C;
    vector<int> list(10, 0);
    cin >> A >> B >> C;
    result = A * B * C;
    while(result){
        int idx = result % 10;
        list[idx]++;
        result /= 10;
    }
    for(int i = 0; i < 10; i++)
        cout << list[i] << "\n";
}