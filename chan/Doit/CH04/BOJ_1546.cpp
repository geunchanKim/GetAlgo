#include <iostream>
#define FASTIO cin.tie(NULL); ios::sync_with_stdio(false);
using namespace std;

int main(){
    FASTIO;
    int N;
    double max = 0, sum = 0;
    cin >> N;
    vector<double> grades(N);
    for(int i = 0; i < N; i++){
        cin >> grades[i];
        if(max < grades[i])
            max = grades[i];
        sum += grades[i];
    }
    cout << sum / max / N * 100;
    return 0;
}