#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

void find_total_gcd(vector<int> list){
    long total = 0;
    for(int i = 0; i < list.size(); i++){
        for(int j = i+1; j < list.size(); j++)
            total += gcd(list[i], list[j]);
    }
    cout << total << "\n";
}

int main(){
    cin.tie(NULL); cout.tie(NULL);
    cin.sync_with_stdio(false);

    int t, n;
    vector<int> list;
    cin >> t;

    for(int i = 0; i < t; i++){
        cin >> n;
        list.resize(n, 0);
        for(int j = 0; j < n; j++)
            cin >> list[j];
        
        find_total_gcd(list);
    }
}