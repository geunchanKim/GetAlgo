#include <iostream>
#include <stack>
#include <set>
#include <vector>
using namespace std;

bool except[201];
string str;
vector< pair < int, int > > par;
set< string > ans;

void dfs(int index, int delete_cnt){
    if(delete_cnt >= 1){
        string temp = "";
        for(int i=0; i<str.length(); i++)
            if(!except[i]) temp+=str[i];
        ans.insert(temp);
    }
    for(int i=index; i<par.size(); i++){
        except[par[i].first] = 1;
        except[par[i].second] = 1;
        dfs(i+1, delete_cnt+1);
        except[par[i].first] = 0;
        except[par[i].second] = 0;
    }
}

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    stack<int> S;
    cin >> str;
    for(int i = 0; i < str.length(); i++){
        if(str[i] == '(')
            S.push(i);
        else if(str[i] == ')'){
            par.push_back(make_pair(S.top(), i));
            S.pop();
        }else
            continue;
    }
    dfs(0, 0);
    for(auto it=ans.begin(); it!=ans.end(); it++)
        cout << *it << '\n';
}