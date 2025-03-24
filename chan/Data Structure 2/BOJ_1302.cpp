#include <iostream>
#include <map>
#define FIRST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;

int main(){
    FIRST;
    
    map<string, int> bookList;
    multimap<int, string> reverseBookList;
    int max = 0;
    int N;
    cin >> N;
    
    for(int i = 0; i < N; i++){
        string tmp;
        cin >> tmp;
        bookList[tmp]++;
    }

    for (const auto& book : bookList) {
        auto it = reverseBookList.find(book.second);
        if(it == reverseBookList.end())
            reverseBookList.insert({book.second, book.first});
    }
    
    cout << prev(reverseBookList.end())->second;
    return 0;
}