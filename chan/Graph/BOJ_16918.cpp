#include <iostream>
#include <vector>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;

int R, C, N;
vector<vector<char>> A;   
vector<vector<char>> B;   
vector<vector<char>> Cmap; 

void explode(const vector<vector<char>>& src, vector<vector<char>>& dest){
    dest.assign(R, vector<char>(C, 'O'));

    int dx[] = {1,0,-1,0};
    int dy[] = {0,1,0,-1};

    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            if(src[i][j] == 'O'){
                dest[i][j] = '.';
                for(int d = 0; d < 4; d++){
                    int nx = i + dx[d];
                    int ny = j + dy[d];
                    if(nx >= 0 && ny >= 0 && nx < R && ny < C)
                        dest[nx][ny] = '.';
                }
            }
        }
    }
}

int main(){
    FASTIO;
    cin >> R >> C >> N;
    A.assign(R, vector<char>(C));
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> A[i][j];
        }
    }
    if(N == 1){
        for(int i = 0; i < R; i++){
            for(int j = 0; j < C; j++) 
                cout << A[i][j];
            cout << '\n';
        }
        return 0;
    }
    if(N % 2 == 0){
        for(int i = 0; i < R; i++){
            for(int j = 0; j < C; j++) 
                cout << 'O';
            cout << '\n';
        }
        return 0;
    }
    explode(A, B);    
    explode(B, Cmap);  
    if(N % 4 == 3){
        for(int i = 0; i < R; i++){
            for(int j = 0; j < C; j++) 
                cout << B[i][j];
            cout << '\n';
        }
    } else {
        for(int i = 0; i < R; i++){
            for(int j = 0; j < C; j++) 
                cout << Cmap[i][j];
            cout << '\n';
        }
    }

    return 0;
}
