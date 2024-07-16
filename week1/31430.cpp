#include <iostream>
#include <cmath>
using namespace std;

int strToInt(string str){
    int result = 0;
    int len = str.length();
    for(int i = 0; i < str.length(); i++){
        result += (str[i] - '0') * (pow(10, len-1));
        len--;
    }
    return result;
}

int main(){
    string A, B, C, AB;
    int a, b, c, ab;

    cin >> A;
    cin >> B;
    cin >> C;
    AB = A + B;

    a = strToInt(A);
    b = strToInt(B);
    c = strToInt(C);
    ab = strToInt(AB);

    cout << a+b-c << "\n"; 
    cout << ab-c << "\n";
}