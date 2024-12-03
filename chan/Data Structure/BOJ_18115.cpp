#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    
    int N;
    vector<int> ary;
    deque<int> DQ;

    cin >> N;
    ary.resize(N+1);

    for(int i = N; i > 0; i--)
        cin >> ary[i];
    
    for(int i = 1; i <= N; i++){
        if(ary[i] == 1){
            DQ.push_front(i);
        }else if(ary[i] == 2){
            int tmp_front = DQ.front();
            DQ.pop_front();
            DQ.push_front(i);
            DQ.push_front(tmp_front);
        }else if(ary[i] == 3){
            DQ.push_back(i);
        }
    }
    
    while(!DQ.empty()){
        int tmp = DQ.front();
        DQ.pop_front();
        cout << tmp << " ";
    }
}