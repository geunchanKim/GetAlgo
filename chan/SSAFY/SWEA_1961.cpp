#include <iostream>
#include <vector>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;

vector<vector<int>> rotate(const vector<vector<int>>& a);
int N;
int main(){
    FASTIO;
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; t++){
        cin >> N;
        vector<vector<int>> ary(N, vector<int>(N));
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                cin >> ary[i][j];
        auto ary90 = rotate(ary);
        auto ary180 = rotate(ary90);
        auto ary270 = rotate(ary180);
        cout << '#' << t << '\n';
        for (int i = 0; i < N; i++) {   
            for (int j = 0; j < N; j++) cout << ary90[i][j];
            cout << ' ';
            for (int j = 0; j < N; j++) cout << ary180[i][j];
            cout << ' ';
            for (int j = 0; j < N; j++) cout << ary270[i][j];
            cout << '\n';
        }
    }
}

vector<vector<int>> rotate(const vector<vector<int>>& a){
    vector<vector<int>> ary(N, vector<int>(N));
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            ary[i][j] = a[N-1-j][i];
    return ary;
}