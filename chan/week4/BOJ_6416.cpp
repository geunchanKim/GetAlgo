#include <iostream>
#include <set>
#include <map>
#include <queue>
using namespace std;

int bfs(map<int,vector<int>> &treeMap){
    map <int,int> checkMap; //방문했는지 체크 위한 자료구조

    //root node를 찾는 과정
    for(auto t : treeMap)
        for(auto el : t.second) //t.second를 checkMap에 다 방문했다고 등록
            checkMap[el] = 1;

    int root = 0;
    for(auto t : treeMap)
        if(!checkMap[t.first]) //간선 중에 t.first가 checkMap에 등록 안되어 있는 경우가 root임
            root = t.first; 
    
    checkMap.clear(); //bfs를 위해 reset
    checkMap[root] = 1; //먼저 root는 방문했음
    //bfs에서는 queue를 사용
    queue <int> q;
    q.push(root); //queue에 root를 넣고 시작

    while(!q.empty()){
        //queue부터 연결된 곳들을 찾아서 다 방문 표시 및 queue에 등록
        int x = q.front();
        q.pop();
        for(int i = 0; i < treeMap[x].size(); i++){
            int nx = treeMap[x][i];
            if(checkMap[nx] == 1) return 0; //이미 방문했더라면 순환 불가능
            checkMap[nx] = 1;
            q.push(nx);
        }
    }
    
    //각 노드들이 방문되었는지 방문안되었더라면 잘못된 트리임
    for(auto t : treeMap){
        for(auto el : t.second){
            if(!checkMap[el] || !checkMap[t.first]) return 0;
        }
    }
    return 1;
}

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    int k = 1;
    while(true){
        int E = 0;
        set<int> V; //set은 중복을 허용 X 
        map<int, vector<int>> treeMap; //V의 최대 수를 모르기 때문에 간선으로만 사이클이 있는지 없는지 확인하기 위해 map 사용
        int u, v;
        while(true){
            cin >> u >> v;
            if(u < 0 && v < 0)
                return 0;
            if(u == 0 && v == 0)
                break;
            E++;
            V.insert(u);
            V.insert(v);
            treeMap[u].push_back(v);
        }
        if(u && v && E != V.size() - 1){
            printf("Case %d is not a tree.\n", k++);
        }else{
            if(bfs(treeMap))
                printf("Case %d is a tree.\n", k++);
            else
                printf("Case %d is not a tree.\n", k++);
        }
    }
}