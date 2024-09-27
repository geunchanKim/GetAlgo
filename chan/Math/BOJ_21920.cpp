#include <iostream>
#include <vector>
#include <iomanip> 
using namespace std;

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

int main(){
    cin.tie(NULL); cout.tie(NULL);
    cin.sync_with_stdio(false);

    int N, X;
    double result = 0;
    double cnt = 0;
    vector<int> A;
    
    //Input
    cin >> N;
    A.resize(N);
    for(int i = 0; i < N; i++)
        cin >> A[i];
    
    cin >> X;
    
    //Check whether A[i] is disjoint or not
    for(int i = 0; i < N; i++){
        if(gcd(X, A[i]) == 1){
            result += A[i];
            cnt++;
        }
    }

    cout << fixed << setprecision(7) << result / cnt << "\n";
    return 0;
}