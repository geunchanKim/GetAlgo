#include <iostream>
#include <queue>
using namespace std;

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    
    //Data 
    int N, result;
    cin >> N;
    int **list = new int*[N];

    //Input with dynamic memory allocation
    for(int i = 0; i < N; i++){
        list[i] =  new int[N];
       for(int j = 0; j < N; j++)
            cin >> list[i][j];
    }

    //Find nth top
    for(int i = 0; i < N; i++){
        //Find nth row max and idx
        int idx = 0;
        int max = list[N-1][0];
        result = max;
        for(int j = 1; j < N; j++){
            if(max < list[N-1][j]){
                max = list[N-1][j];
                idx = j;
                if(i == N-1)
                    result = max;
            }
        }
   
        //Move idxth col
        for(int j = N-1; j > 0; j--)
            list[j][idx] = list[j-1][idx];
        
    }
    
    cout << result;

    //Free malloc
    for(int i = 0; i < N; i++)
        delete[] list[i];
    
    delete[] list;
}