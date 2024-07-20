#include <iostream>
using namespace std;

int main(){
    int ary[10];
    int idx = 1;
    bool a_flag = true, d_flag = true;
    for(int i = 1; i < 9; i++){
        cin >> ary[i];
        if(ary[i] != i)
            a_flag = false; 
    }

    for(int i = 8; i > 0; i--){
        if(ary[idx++] != i)
            d_flag = false;
    }
    
    if(a_flag)
        cout << "ascending";
    else if(d_flag)
        cout << "descending";
    else    
        cout << "mixed";
}