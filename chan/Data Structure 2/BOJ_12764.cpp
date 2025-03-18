#include <iostream>
#include <string>
#include <cmath>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#define FIRST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 100005
using namespace std;

int N;
pair<int, int> User[MAX];
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
set<int> Seat; 
int answer;
int Computer[MAX];

int Arrange(){
    int ans = 0;
    for(int i = 0; i < N; i++){
        while (!pq.empty()) {
			if (pq.top().first <= User[i].first) {
				Seat.insert(pq.top().second); 
				pq.pop();
			}
			else break;
		};
		if (Seat.empty()) { 
			pq.push(make_pair(User[i].second, ans));
			Computer[ans++]++;
		}
		else {
			pq.push(make_pair(User[i].second, *Seat.begin()));
			Computer[*Seat.begin()]++;
			Seat.erase(Seat.begin());
		}
    }
    return ans;
}

bool comp(pair<int, int> A, pair<int, int> B){
    return A.first < B.first;
}

int main(){
    FIRST;
    cin >> N;
    for(int i = 0; i < N; i++){
        int P, Q;
        cin >> P >> Q;
        User[i] = make_pair(P, Q);
    }

    sort(User, User + N, comp);

    answer = Arrange();
    cout << answer << '\n';
    for(int i = 0; i < answer; i++)
        cout << Computer[i] << ' ';
    
    return 0;
}