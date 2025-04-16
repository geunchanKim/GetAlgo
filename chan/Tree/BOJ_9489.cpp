#include <iostream>
#include <vector>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;

int main(){
    FASTIO;
    int n, k;
    while(cin >> n >> k){
        //종료 조건
        if(n == 0 && k == 0)
            break;
        
        int idx = -1, prev = 0, cousin = 0, data;
        int parent[1000001];
        vector<int> node;
        for(int i = 0; i < n; i++){
            cin >> data;
            node.push_back(data);
            if(i == 0){
                prev = data;
                parent[data] = -1;
            }else{
                if(prev + 1 == data){
                    parent[data] = node[idx];
                    prev = data;
                }else{
                    prev = data;
                    idx++;
                    parent[data] = node[idx];
                }
            }
        }

        if(k == node[0]){
            cousin = 0;
        }else{
            for (int i = 0; i < node.size(); i++){
                if (parent[parent[node[i]]] == parent[parent[k]] && parent[node[i]] != parent[k])
                    cousin++;
            }
        }
        cout << cousin << '\n';
    }
    return 0;
}