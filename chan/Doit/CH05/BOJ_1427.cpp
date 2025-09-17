#include <iostream>
#include <string>
using namespace std;
#define FASTIO cin.tie(NULL); ios::sync_with_stdio(false);

int main(){
    FASTIO;
    string num;
    cin >> num;
    for(int i = 0; i < num.length(); i++){
        int max = num[i] - 0;
        int max_idx = i;
        for(int j = i; j < num.length(); j++){
            if(max < num[j]){
                max = num[j] - 0;
                max_idx = j;
            }
        }
        char tmp = num[i];
        num[i] = max;  
        num[max_idx] = tmp;   
    }
    cout << num;
    return 0;
}