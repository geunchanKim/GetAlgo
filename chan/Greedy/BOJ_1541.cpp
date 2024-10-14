#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    cin.sync_with_stdio(false);

    int result = 0;
    string input;
    cin >> input;
    int idx = input.length();
    for(int i = 0; i < input.length(); i++){
        if(input[i] == '-'){
            idx = i;
            break;
        }
    }

    for(int i = idx + 1; i < input.length(); i++){
        if(input[i] == '+')
            input[i] = '-';
    }

    if(input[0] != '-')
        input = '+' + input;

    int num = 0;
    int temp = 1;
    for (int i=input.size()-1; i>=0; i--){
        if (input[i] == '+') {
            result += num;
            temp = 1;
            num = 0;
        }else if (input[i] == '-') {
            result -= num;
            temp = 1;
            num = 0;
        }else{
            num += (input[i] - '0') * temp;
            temp *= 10;
        }
    }
 
    cout << result;
 
    return 0;
}