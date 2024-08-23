#include <iostream>
#include <vector>
#define MAX 100001
using namespace std;

string isCutVertex(int k, vector<int> tree[MAX]){ //끝점일 때만 단절점이 아니다
    if(tree[k].size() >= 2)
        return "yes";
    else
        return "no";
}

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    int N, q;
    cin >> N;
    vector<int> tree[MAX];
    for(int i = 0; i < N - 1; i++){
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    cin >> q;
    for(int i = 0; i < q; i++){
        int t, k;
        cin >> t >> k;
        if(t == 1){ //단절점인지 확인
            cout << isCutVertex(k, tree) << "\n";
        }else if(t == 2){ //tree안에 모든 간선은 bridge임...
            cout << "yes" << "\n";
        }
    }
}