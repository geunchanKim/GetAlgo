#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;

int main(){
    FASTIO;
    queue<int> Q;
    int N;
    int leaf = 0;
    double W;
    cin >> N >> W;
    vector< vector < int > > tree(N + 1);
    vector<int> visited(N + 1, 0);
    
    for(int i = 0; i < N - 1; i++){
        int U, V;
        cin >> U >> V;
        tree[U].push_back(V);
        tree[V].push_back(U);
    }

    Q.push(1);
    visited[1] = 1;

    while(!Q.empty()){
        int tmp = Q.front();
        Q.pop();
        bool isLeaf = true;
        for(auto i : tree[tmp]){
            if(!visited[i]){
                visited[i] = 1;
                Q.push(i);
                isLeaf = false;
            }
        }
        if(isLeaf) leaf++;
    }

    cout << fixed << setprecision(10) << W / (double)leaf;
    return 0;
}
