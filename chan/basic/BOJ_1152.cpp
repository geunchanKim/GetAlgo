#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(){
    int cnt = 0;
    string sentence;
    char separator = ' ';
    getline(cin, sentence);
    istringstream iss(sentence);
    string str_buf;
    while (getline(iss, str_buf, separator)) {
        if(str_buf.compare(" "))
            cnt++;
    }
    if(sentence[0] == ' ')
        cnt--;
    cout << cnt;
    return 0;
}
