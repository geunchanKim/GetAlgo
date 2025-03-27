#include <iostream>
#include <map>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;

int main(){
    map<string, int> check;
    int startTime = 0;
    int endTime = 0;
    int quitTime = 0;
    int cnt = 0;
    string S, E, Q, time, name;
    cin >> S >> E >> Q;
    startTime += stoi(S.substr(0, 2)) * 60;
    startTime += stoi(S.substr(3, 2));
    endTime += stoi(E.substr(0, 2)) * 60;
    endTime += stoi(E.substr(3, 2));
    quitTime += stoi(Q.substr(0, 2)) * 60;
    quitTime += stoi(Q.substr(3, 2));
    while(cin >> time >> name){
        int realTime = 0;
        realTime += stoi(time.substr(0, 2)) * 60;
        realTime += stoi(time.substr(3, 2));
        if(!check[name]){
            if(realTime <= startTime)
                check[name] = 1;
        }else{
            if(endTime <= realTime && realTime <= quitTime && check[name] == 1){
                check[name] = 0;
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}