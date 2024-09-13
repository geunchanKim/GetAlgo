#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

bool is_digit(string input){
    return atoi(input.c_str()) != 0 || input.compare("0") == 0;
}

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    
    unordered_map<string, int> strPokedex;
    unordered_map<int, string> numPokedex;
    int N, M;
    cin >> N >> M;

    for(int i = 1; i <= N; i++){
        string name;
        cin >> name;
        strPokedex[name] = i;
        numPokedex[i] = name;
    }

    for(int i = 0; i < M; i++){
        string input;
        cin >> input;
        if(!is_digit(input))
            cout << strPokedex[input] << "\n";
        else
            cout << numPokedex[atoi(input.c_str())] << "\n";
    }
}