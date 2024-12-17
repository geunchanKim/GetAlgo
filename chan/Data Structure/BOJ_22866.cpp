#include <iostream>
#include <stack>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    //INPUT
    int N;
    cin >> N;
    vector<int> height(N+1, 0);
    for(int i = 1; i <= N; i++)
        cin >> height[i];
    
    vector<int> visibleCount(N + 1, 0);
    vector<int> closestBuilding(N + 1, -1);
    stack<int> S;

    //FROM LEFT TO RIGHT
    for(int i = 1; i <= N; i++){
        while(!S.empty() && height[S.top()] <= height[i])
            S.pop();
        if(!S.empty()){
            visibleCount[i] += S.size();
            if (closestBuilding[i] == -1 || abs(i - S.top()) < abs(i - closestBuilding[i])) {
                closestBuilding[i] = S.top();
            }
        }
        S.push(i);
    }

    // CLEAR THE STACK
    while (!S.empty()) {
        S.pop();
    }

    //FROM RIGHT TO LEFT
    for(int i = N; i >= 1; i--){
        while(!S.empty() && height[S.top()] <= height[i])
            S.pop();
        if(!S.empty()){
            visibleCount[i] += S.size();
            if(closestBuilding[i] == -1 || abs(i - S.top()) < abs(i - closestBuilding[i])){
                closestBuilding[i] = S.top();
            }
        }
        S.push(i);
    }

    for (int i = 1; i <= N; i++) {
        cout << visibleCount[i];
        if(visibleCount[i] > 0){
            cout << " " << closestBuilding[i];
        }
        cout << "\n";
    }
}