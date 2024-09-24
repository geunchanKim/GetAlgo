#include <iostream>
#include <map>
#include <string>
#include <iomanip>
using namespace std;

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    map<string, int> dic;
    string plant;
    int total = 0;
    while(getline(cin, plant)){
        total++;
        if(!dic[plant])
            dic[plant] = 1;
        else
            dic[plant]++;
        plant.clear();
    }
    for(const auto& [key, value] : dic){
        double result = double(value) / double(total) * 100.0;
        cout << fixed << setprecision(4);
        cout << key << " " << result << "\n";
    }
}