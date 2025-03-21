#include <iostream>
#include <map>
#define FIRST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;

int N;
map<string, int> runners;

int main(){
    FIRST;
    cin >> N;
    for(int i = 0; i < N; i++){
        string runner;
        cin >> runner;
        if(runners[runner])
            runners[runner]++;
        else
            runners[runner] = 1;
    }
    for(int i = 0; i < N - 1; i++){
        string runner;
        cin >> runner;
        runners[runner]--;
        if(runners[runner] == 0)
            runners.erase(runner);
    }
    for (const auto& runner : runners) {
        cout << runner.first;
    }
    return 0;
}