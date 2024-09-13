#include <iostream>
#include <deque>
#include <cmath>
using namespace std;

void print_balloon(deque< pair <int, int> > DQ){
    while(!DQ.empty()){
        cout << DQ.front().first << ' ';
        int paperNum = DQ.front().second;
        DQ.pop_front();
        if(paperNum > 0){
            for(int i = 0; i < paperNum - 1; i++){
                DQ.push_back(DQ.front());
                DQ.pop_front();
            }    
        }else{
            for(int i = 0; i < abs(paperNum); i++){
                DQ.push_front(DQ.back());
                DQ.pop_back();
            }
        }  
    }
}

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    int N;
    cin >> N;
    deque< pair <int, int> > DQ;
    for(int i = 1; i <= N; i++){
        int paperNum;
        cin >> paperNum;
        DQ.push_back(pair<int, int>(i, paperNum));
    }
    print_balloon(DQ);
}