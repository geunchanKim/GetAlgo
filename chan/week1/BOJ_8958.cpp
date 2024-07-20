#include <iostream>
using namespace std;

int check_score(string quiz){
    int bonus = 0;
    int score = 0;
    for(int i = 0; i < quiz.length(); i++){
        if(quiz[i] == 'O'){
            bonus++;
            score = score + bonus;
        }else{
            bonus = 0;
        }
    }
    return score;
}

int main(){
    int T;
    cin >> T;
    for(int i = 0; i < T; i++){
        string quiz;
        cin >> quiz;
        int score = check_score(quiz);
        cout << score << "\n";
    }
}