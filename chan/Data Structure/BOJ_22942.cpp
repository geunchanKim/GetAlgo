#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <set>
using namespace std;

struct Point{
    int id;
    int x;
    int isOpen;
};

bool cmp(Point a, Point b) {
    return a.x < b.x;
};

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    stack<int> S;
    vector<Point> V;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++){
        int X, R;
        cin >> X >> R;
        V.push_back({i, X-R, 1});
        V.push_back({i, X+R, 0});
    }
    sort(V.begin(), V.end(), cmp);

    for(auto p : V){
        if(p.isOpen)
            S.push(p.id);
        else{
            if(S.top() != p.id){
                cout << "NO";
                return 0;
            }else
                S.pop();
        }
    }
    cout << "YES";
    return 0;
}