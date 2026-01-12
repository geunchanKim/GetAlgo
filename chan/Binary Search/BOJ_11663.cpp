#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;

int lowerBound(const vector<int>& v, int target){
    int left = 0, right = v.size() - 1;
    int res = v.size();
    while(left <= right){
        int mid = (left + right) / 2;
        if(v[mid] >= target){
            res = mid;
            right = mid - 1;
        }else{
            left = mid + 1;
        }
    }
    return res;
}

int upperBound(const vector<int>& v, int target){
    int left = 0, right = v.size() - 1;
    int res = v.size();
    while(left <= right){
        int mid = (left + right) / 2;
        if(v[mid] > target){
            res = mid;
            right = mid - 1;
        }else{
            left = mid + 1;
        }
    }
    return res;
}

int main(){
    FASTIO;
    int N, M;
    cin >> N >> M;
    vector<int> line(N);
    for(int i = 0; i < N; i++)
        cin >> line[i];
    sort(line.begin(), line.end());
    while(M--){
        int start, end;
        cin >> start >> end;
        int l = lowerBound(line, start);
        int r = upperBound(line, end);
        cout << r - l << '\n';
    }
    return 0;
}
