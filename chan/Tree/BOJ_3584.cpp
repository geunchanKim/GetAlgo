#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;

int main(){
    FASTIO;
    int T;
    cin >> T;
    for(int i = 0; i < T; i++){
        int N, A, B, tmp;
        cin >> N;
        vector< vector < int > > tree(N + 1);
        vector<int> aPath;
        vector<int> bPath;
        for(int i = 0; i < N - 1; i++){
            int a, b;
            cin >> a >> b;
            tree[b].push_back(a);
        }
        cin >> A >> B;
        tmp = A;
        aPath.push_back(A);
        while(tree[tmp].size() != 0){
            aPath.push_back(tree[tmp][0]);
            tmp = tree[tmp][0];
        }
        tmp = B;
        bPath.push_back(B);
        while(tree[tmp].size() != 0){
            bPath.push_back(tree[tmp][0]);
            tmp = tree[tmp][0];
        }
        for(auto a : aPath){
            auto it = find(bPath.begin(), bPath.end(), a);
            if (it != bPath.end()) {
                cout << a << "\n";
                break;
            } 
        }
    }
    return 0;
}