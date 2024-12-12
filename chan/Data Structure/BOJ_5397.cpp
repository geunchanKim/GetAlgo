#include <iostream>
#include <list>
#include <string>
using namespace std;

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        list<char> ans;
        list<char>::iterator cursor = ans.begin();
        string S;
        cin >> S;
        for(int j = 0; j < S.length(); j++){
            if(S[j] == '-'){
                if(cursor != ans.begin())
                    cursor = ans.erase(--cursor);
            }else if(S[j] == '<'){
                if(cursor != ans.begin())
                    cursor--;
            }else if(S[j] == '>'){
                if(cursor != ans.end())
                    cursor++;
            }else{
                cursor = ans.insert(cursor, S[j]);
                cursor++;
            }
        }
        for(auto A : ans) cout << A;
        cout << '\n';
    }
}