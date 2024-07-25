#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;
int cnt = 0;
deque<int> DQ;

int where(int num){
    int idx;
    deque<int>::iterator it = find(DQ.begin(), DQ.end(), num);
     if (it != DQ.end()) 
        idx = distance(DQ.begin(), it);
    return idx;
}
void lmove(int num){
    if(!DQ.empty()){
        while(DQ.front() != num){
            DQ.push_back(DQ.front());
            DQ.pop_front();
            cnt++;
        }
        DQ.pop_front();
    }
}

void rmove(int num){
    if(!DQ.empty()){
        while(DQ.front() != num){
            DQ.push_front(DQ.back());
            DQ.pop_back();
            cnt++;
        }
        DQ.pop_front();
    }
}

void findNum(int num){
    if(!DQ.empty()){
        int size = DQ.size()%2 ? DQ.size()/2 + 1 : DQ.size()/2;
        if(DQ.front() == num){
            DQ.pop_front();
            return;
        }else if(size > where(num)){
            lmove(num);
            return;
        }else{
            rmove(num);
            return;
        }
    }
}

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, M;
    cin >> N >> M;
    for(int i = 1; i <= N; i++)
        DQ.push_back(i);
    for(int i = 0; i < M; i++){
        int idx;
        cin >> idx;
        findNum(idx);
    }
    cout << cnt;
}