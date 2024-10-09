#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    cin.sync_with_stdio(false);

    deque<long> DQ;
    long min = 0;
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        long num;
        cin >> num;
        DQ.push_back(num);
    }

    sort(DQ.begin(), DQ.end(), greater<long>());

    if(N % 2 == 0){
        while(!DQ.empty()){
            long tmp = DQ.front() + DQ.back();
            DQ.pop_front();
            DQ.pop_back();
            if(min < tmp)
                min = tmp;
        }
    }else{
        min = DQ.front();
        DQ.pop_front();
        while(!DQ.empty()){
            long tmp = DQ.front() + DQ.back();
            DQ.pop_front();
            DQ.pop_back();
            if(min < tmp)
                min = tmp;
        }
    }

    cout << min;
}