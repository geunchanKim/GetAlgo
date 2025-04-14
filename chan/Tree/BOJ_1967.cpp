#include <iostream>
#include <vector>
#include <queue>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;

int main(){
    FASTIO;
    int maxBranch = 0;
    int n;
    cin >> n;
    vector< vector < pair<int, int> > > tree(n + 1);

    for(int i = 0; i < n - 1; i++){
        int a, b, c;
        cin >> a >> b >> c;
        tree[a].push_back(make_pair(b, c));
        tree[b].push_back(make_pair(a, c));
    }
    
    for(int i = 1; i <= n; i++){
        vector<int> visited(n + 1, 0);
        vector<int> result(n + 1, 0);
        queue<int> Q;
        Q.push(i);
        visited[i] = 1;
        while(!Q.empty()){
            int node = Q.front();
            Q.pop();
            //cout << node << " : " << node << '\n';
            for(auto [next, dist] : tree[node]){
                if(!visited[next]){
                    visited[next] = 1;
                    result[next] = result[node] + dist;
                    Q.push(next);
                    //cout << next << ' ' << dist << ' ' << result[next] << ' ' << result[node] << '\n';
                }
            }
        }

        for(int i = 1; i <= n; i++){
            if(result[i] > maxBranch)
                maxBranch = result[i];
        }
    }

    cout << maxBranch;
    return 0;
}