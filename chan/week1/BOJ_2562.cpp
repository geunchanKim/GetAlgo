#include <iostream>
using namespace std;

int main(){
    int ary[10];
    int nth, max;
    max = 0;
    for (int i = 1; i <= 9; i++){
        cin >> ary[i];
        if (max < ary[i]){
            max = ary[i];
            nth = i;
        }
    }
    cout << max << "\n" << nth;
}