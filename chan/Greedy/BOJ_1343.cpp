#include <iostream>
#include <vector>
#include <string>
using namespace std;

string fillBoard(string board, vector<string> polyominos){
    string result;
    int cnt = 0;
    for(int i = 0; i <= board.length(); i++){
        if(board[i] == '.' || i == board.length()){
            while(cnt != 0){
                if(cnt >= 4){
                    result.append(polyominos[0]);
                    cnt -= 4;
                }else if(cnt >= 2){
                    result.append(polyominos[1]);
                    cnt -= 2;
                }else{
                    return "-1";
                }
            }
            if(board[i] == '.')
                result.append(".");
        }else
            cnt++;
    }
    return result;
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    cin.sync_with_stdio(false);

    vector<string> polyominos = {"AAAA", "BB"};
    string board;
    cin >> board;
    
    cout << fillBoard(board, polyominos);
}