#include <iostream>
#include <map>
#define FIRST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;

int main(){
    FIRST;
    map<int, int> A;
    map<int, int> B;
    map<int, int> C;
    int a, b;
    cin >> a >> b;
    for(int i = 0; i < a; i++){
        int tmp;
        cin >> tmp;
        A[tmp] = 1;
    }
    for(int i = 0; i < b; i++){
        int tmp;
        cin >> tmp;
        B[tmp] = 1;
        C[tmp] = 1;
    }
    for(auto it : C){
        auto flag = A.find(it.first);
        if(flag != A.end()){
            A.erase(it.first);
            B.erase(it.first);
        }
    }
    cout << A.size() + B.size();
    return 0;
}