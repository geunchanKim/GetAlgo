#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;

int main(){
    FASTIO;
    int N, Q;
    cin >> N >> Q;
    vector<bool> occupied(N + 1, false);
    
    while (Q--) {
        int land;
        cin >> land;
        int first_blocked = 0;
        int current = land;
        
        while (current > 1) {
            if (occupied[current]) first_blocked = current;
            current /= 2; // Move to parent node
        }
        
        cout << first_blocked << '\n';
        if (first_blocked == 0) occupied[land] = true;
    }
    
    return 0;
}