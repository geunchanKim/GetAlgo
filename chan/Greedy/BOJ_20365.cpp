#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    cin.sync_with_stdio(false);

    int cnt = 0;
    int N;
    cin >> N;

    vector<char> str1;
    string str2;
    cin >> str2;
    if(str2[0] == 'R')
        str1.resize(N, 'R');
    else
        str1.resize(N, 'B');
    cnt++;
    
    for(int i = 1; i < N; i++){
        if(str1[i] != str2[i]){
            str1[i] = str2[i];
            if(str1[i] != str1[i-1])
                cnt++;
        }
    }

    cout << cnt;
    return 0;
}