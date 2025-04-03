#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;

int main(){
    FASTIO;

    //DATA TYPES
    queue<int> Q;
    int N, del, root;
    int cnt = 0;
    cin >> N;
    vector<vector<int>> tree(N);

    //MAKE TREE
    for(int i = 0; i < N; i++){
        int parent;
        cin >> parent;
        if(parent == -1)
            root = i;
        else
            tree[parent].push_back(i);
    }

    //DELETE 
    cin >> del;
    Q.push(del);
    while(!Q.empty()){
        int tmp = Q.front();
        Q.pop();
        for(auto i : tree[tmp])  
            Q.push(i);
        tree[tmp].push_back(-1);
    }
    for(int i = 0; i < N; i++)
        tree[i].erase(remove(tree[i].begin(), tree[i].end(), del), tree[i].end());

    //COUNT LEAF NODE
    for(int i = 0; i < N; i++){
        if(tree[i].size() == 0)
            cnt++;
    }

    cout << cnt;
    return 0;
}