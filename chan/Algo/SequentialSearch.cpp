#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    vector<int> S(N);
    for(int i = 0; i < N; i++)
        cin >> S[i];
    for(int i = 0; i < M; i++){
        int x;
        int flag = 0;
        cin >> x;
        for(int loc = 0; loc < N; loc++)
            if(S[loc] == x){
                cout << x << " is in " << loc+1 << ".\n";
                flag = 1;
            }else if(!flag && loc == N-1)
                cout << x << " is not in " << "S.\n";
    }
}   