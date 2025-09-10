#include <iostream>
#include <vector>
#define FASTIO cin.tie(NULL); ios::sync_with_stdio(false);
using namespace std;

int main(){
    FASTIO;
    int S, P, cnt = 0;
    string DNA;
    bool flag = true;
    int myArr[4] = { 0 };
    int checkArr[4];
    cin >> S >> P;
    int start = 0, end = P;
    cin >> DNA;
    for(int i = 0; i < 4; i++)
        cin >> checkArr[i];

    for(int i = start; i < end; i++){
        switch (DNA[i]){
            case 'A':
                myArr[0]++;
                break;
            case 'C':
                myArr[1]++;
                break;
            case 'G':
                myArr[2]++;
                break;
            case 'T':
                myArr[3]++;
                break;
            default:
                break;
        }
    }

    while(end <= S){
        for(int i = 0; i < 4; i++)
            if(myArr[i] < checkArr[i])
                flag = false;
        
        if(flag)
            cnt++;
        flag = true;

        switch (DNA[start]){
            case 'A':
                myArr[0]--;
                break;
            case 'C':
                myArr[1]--;
                break;
            case 'G':
                myArr[2]--;
                break;
            case 'T':
                myArr[3]--;
                break;
            default:
                break;
        }
        switch (DNA[end]){
            case 'A':
                myArr[0]++;
                break;
            case 'C':
                myArr[1]++;
                break;
            case 'G':
                myArr[2]++;
                break;
            case 'T':
                myArr[3]++;
                break;
            default:
                break;
        }
        start++;
        end++;
    }
    cout << cnt << '\n';
    return 0;
}