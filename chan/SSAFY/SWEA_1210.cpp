#include <iostream>
#include <vector>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;

int main(){
    FASTIO;
    for(int t = 0; t < 10; t++){
        vector<vector<int>> maze(100, vector<int>(100));
        int n, x, y;
        cin >> n;
        for(int i = 0; i < 100; i++){
            for(int j = 0; j < 100; j++){
                cin >> maze[i][j];
                if(maze[i][j] == 2){
                    x = i; 
                    y = j;
                }
            }
        }
        while(x > 0){
            if(y > 0 && maze[x][y - 1] == 1)
                while(y > 0 && maze[x][y - 1] == 1)
                    y--;
            else if(y < 99 && maze[x][y + 1] == 1)
                while(y < 99 && maze[x][y + 1] == 1)
                    y++;
            x--;
        }
        cout << '#' << n << ' ' << y << '\n';
    }
}