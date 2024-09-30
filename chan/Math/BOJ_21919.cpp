#include <iostream>
#include <map>
using namespace std;

bool isPrime(long long n){    
    if(n <= 1)
        return false;
    
    if(n == 2 || n == 3)
        return true;

    if(n % 2 == 0 || n % 3 == 0)
        return false;

    for(long long i = 5; i*i <= n; i++){
        if(n % i == 0)
            return false;
    }
    return true;
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    cin.sync_with_stdio(false);

    //Declaring Data & Input
    bool flag = false;
    int N;
    long long result = 1;
    cin >> N;
    map <long long, bool> visited;

    for(int i = 0; i < N; i++){
        long long num;
        cin >> num;
        if(isPrime(num) && !visited[num]){
            flag = true;
            visited[num] = true;
            result = result * num;
        }
    }

    if(!flag)
        cout << -1 << "\n";
    else 
        cout << result << "\n";

    return 0;
}