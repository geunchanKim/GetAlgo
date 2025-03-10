#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void binsearch(int n, vector<int> s, int x, int& loc){
    int low, high, mid;
    low = 0;
    high = n-1;
    while(low <= high && loc == -1){
        mid = (low+high)/2;
        if(x == s[mid])
            loc = mid;
        else if(x < s[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
}

int main(){
    int N, M;
    cin >> N >> M;
    vector<int> S(N);
    for(int i = 0; i < N; i++)
        cin >> S[i];
    sort(S.begin(), S.end());
    for(int i = 0; i < M; i++){
        int X;
        int location = -1;
        cin >> X;
        binsearch(N, S, X, location);
        if(location == -1)
            cout << X << " is not in S.\n";
        else
            cout << X << " is in " << location+1 << ".\n";
    }
}