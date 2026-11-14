#include <iostream>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;

int main(){
    FASTIO;
    for(int i = 0; i < 10; i++){
        int tc, max = 0, sum_rc = 0, sum_rc_reverse = 0, colSum[100] = {0};
        vector<vector<int>> ary(100, vector<int>(100));
        cin >> tc;
        for(int j = 0; j < 100; j++){
            int sum_row = 0;
            for(int k = 0; k < 100; k++){
                cin >> ary[j][k];
                if(j == k)
                    sum_rc += ary[j][k];
                if(j + k == 99)
                    sum_rc_reverse += ary[j][k];
                sum_row += ary[j][k];
                colSum[k] += ary[j][k];
            }
            if(max < sum_row)
                max = sum_row;
            if(max < sum_rc)
                max = sum_rc;
            if(max < sum_rc_reverse)
                max = sum_rc_reverse;
        }
        for(auto tmp : colSum){
            if(max < tmp)
                max = tmp;
        }
        cout << '#' << tc << ' ' << max << '\n';
    }
}