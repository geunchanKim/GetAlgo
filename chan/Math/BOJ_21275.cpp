#include <iostream>
#include <map>
#include <set>
#include <string>
using namespace std;
map<char, int> table;

int calMax(string S) {
    int result = 0;
    for(int i = 0; i < S.size(); i++) {
        int cmp = table[S[i]];
        result = max(result, cmp);
    }
    return result;
}

long long find_X(int num, string S) {
    long long result = 0;
    long long power = 1;  

    for (int i = S.length() - 1; i >= 0; --i) {
        result += table[S[i]] * power; 
        power *= num; 
    }

    return result;
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    cin.sync_with_stdio(false);

    //자료
    table['0'] = 0; table['1'] = 1; table['2'] = 2; table['3'] = 3; table['4'] = 4; table['5'] = 5; table['6'] = 6; table['7'] = 7; table['8'] = 8; table['9'] = 9;
    table['a'] = 10; table['b'] = 11; table['c'] = 12; table['d'] = 13; table['e'] = 14; table['f'] = 15; table['g'] = 16; table['h'] = 17; table['i'] = 18; table['j'] = 19;
    table['k'] = 20; table['l'] = 21; table['m'] = 22; table['n'] = 23; table['o'] = 24; table['p'] = 25; table['q'] = 26; table['r'] = 27; table['s'] = 28; table['t'] = 29;
    table['u'] = 30; table['v'] = 31; table['w'] = 32; table['x'] = 33; table['y'] = 34; table['z'] = 35;
    set< pair < int, int > > ans; 

    //입력 : X를 A진법, X를 B진법
    string A, B;
    cin >> A >> B;
    int max_a = calMax(A);
    int max_b = calMax(B);
    if(A[0] == 'z')
        max_a = 36;
    if(B[0] == 'z')
        max_b = 36;

    for(int i = max_a; i <= 36; i++){
        for(int j = max_b; j <= 36; j++){
            if(i == j)
                continue;
            
            if(find_X(i, A) >= 0 && find_X(i, A) == find_X(j, B))
                ans.insert(make_pair(i, j));     
        }
    }

    //출력 : X를 십진법으로 표현한 수와 A와 B를 공백으로 출현
    //2개 이상 Multiple 아니면 Impossible
    if(!ans.empty()){
        if(ans.size() == 1){
            for(const auto &elem : ans)
                cout << find_X(elem.first, A) << ' ' << elem.first << ' ' << elem.second;
        }else
            cout << "Multiple";
    }else
        cout << "Impossible";
    
    return 0;
}