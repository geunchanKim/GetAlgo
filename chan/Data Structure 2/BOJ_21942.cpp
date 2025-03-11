#include <iostream>
#include <string>
#include <unordered_map>
#include <map>
using namespace std;

int monthDays[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int MonthToDay(int month){
	if (month == 1)
        return 0;
	int days = 0;
	for (int i = 0; i < month - 1; i++)
		days += monthDays[i];
	return days;
}

struct pair_hash {
    size_t operator()(const pair<string, string>& p) const {
        return hash<string>()(p.first) ^ hash<string>()(p.second);
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    unordered_map< pair < string, string >, unsigned long long int, pair_hash> Info;
    map<string, unsigned long long int> Report;
    unsigned long long int LimitTime = 0;
    int N, F;
    string L;
    cin >> N >> L >> F;
    LimitTime += stoi(L.substr(0, 3)) * 1440;
    LimitTime += stoi(L.substr(4, 2)) * 60;
    LimitTime += stoi(L.substr(7, 2));

    for(int i = 0; i < N; i++){
        string Date, Time, P, M;
        cin >> Date >> Time >> P >> M;
        unsigned long long int curTime = 0;
        curTime += MonthToDay(stoi(Date.substr(5, 2))) * 1440;
		curTime += stoi(Date.substr(8, 2)) * 1440;				
		curTime += stoi(Time.substr(0, 2)) * 60;				
		curTime += stoi(Time.substr(3, 2));						
        if(i == 0)
            Info[{P, M}] = curTime;
        else{
            auto it = Info.find({P, M});
            if(it != Info.end()) {
                if(curTime - it->second > LimitTime)
                    Report[it->first.second] += (curTime - it->second - LimitTime) * F;  
                Info.erase(it);  
            }else
                Info[{P, M}] = curTime;
        }
    }

    if (Report.empty()) 
        cout << -1;
	else{
		for (auto user : Report)
			cout << user.first << ' ' << user.second << '\n';
	}
}