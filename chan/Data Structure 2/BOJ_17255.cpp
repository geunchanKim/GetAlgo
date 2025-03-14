#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

string N;
unordered_set<string> S;
int SSize;

void dfs(int l, int r, string tmp, int length){
    if(tmp.size() >= SSize){
        if(N == tmp.substr(tmp.size() - N.size()))
            S.insert(tmp);
        return;
    }

    if (l - 1 >= 0) 
        dfs(l - 1, r, tmp + N.substr(l - 1, length), length + 1);        
    if (r + 1 < N.size()) 
        dfs(l, r + 1, tmp + N.substr(l, length), length + 1); 
}

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin >> N;
    SSize = N.size() * (N.size() + 1)/2;
    for(int i = 0; i < N.size(); i++){
        string tmp = "";
        tmp += N[i];
        dfs(i, i, tmp, 2);
    }

    cout << S.size();
    return 0;
}