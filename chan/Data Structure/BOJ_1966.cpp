#include <iostream>
#include <queue>
using namespace std;

void when_print(queue< pair <int, int> > Q, priority_queue<int> PQ, int N, int M){
    int cnt = 0;
    while(true){
        //비어 있는지 체크
        if(!Q.empty()){
            // front의 우선순위가 높으면 -> 우선순위 큐와 큐의 top을 비교하면 좋을듯!
            if(Q.front().second == PQ.top()){
                cnt++; //횟수 증가
                if(Q.front().first == M) //원하는 인덱스를 찾았으니 break
                    break;
                //우선순위가 가장 높은 것들을 찾았으니 Q와 PQ 둘 다 pop
                Q.pop(); 
                PQ.pop();
            }else{ // 아니면 front를 뒤로 보냄
                Q.push(Q.front());
                Q.pop();
            }
        }
    }
    cout << cnt << '\n'; 
}

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    int T;
    cin >> T;
    for(int i = 0; i < T; i++){
        int N, M;
        cin >> N >> M;
        queue< pair <int, int> > Q;
        priority_queue<int> PQ;
        for(int j = 0; j < N; j++){
            int num;
            cin >> num;
            Q.push(pair<int, int>(j, num));
            PQ.push(num);
        }
        when_print(Q, PQ, N, M);
    }
}