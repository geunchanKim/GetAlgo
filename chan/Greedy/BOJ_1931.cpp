#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    cin.sync_with_stdio(false);

    vector< pair < int, int > > Meeting;
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        int a, b;
        cin >> a >> b;
        Meeting.push_back(make_pair(b, a)); // 끝나는 시간(b), 시작 시간(a)을 넣음
    }

    // 회의를 끝나는 시간을 기준으로 오름차순 정렬
    sort(Meeting.begin(), Meeting.end());

    int count = 0;
    int lastEndTime = 0;

    for(const auto &time : Meeting){
        int start = time.second;
        int end = time.first;

        // 현재 회의가 이전 회의의 끝난 시간 이후에 시작되면 선택
        if(start >= lastEndTime){
            count++;
            lastEndTime = end;
        }
    }

    cout << count << endl;

    return 0;
}