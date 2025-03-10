#include <iostream>
using namespace std;
typedef vector< vector < int > > matrix_t;

void matrixmult(int N, matrix_t A, matrix_t B, matrix_t& C){
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++){
            C[i][j] = 0;
            for(int k = 0; k < N; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
}

int main(){
    int N;
    cin >> N;
    matrix_t A(N, vector<int>(N));
    matrix_t B(N, vector<int>(N));
    matrix_t C(N, vector<int>(N));
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cin >> A[i][j];
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cin >> B[i][j];
    matrixmult(N, A,  B, C);
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cout << C[i][j] << (j == N - 1 ? '\n' : ' ');
}