#include <iostream>
#include <stack>
#include <vector>
using namespace std;
vector<int> nseq;
vector<char> ans;

bool check(int n){
    stack<int> test;
    int i = 1;
    for(int idx = 0; idx < n;){ //수열의 idx를 다 확인해보기 위함
        if(!test.empty()){ //비어있을 경우
            if(test.top() == nseq[idx]){ //같다면 pop 및 idx 증가
                test.pop();
                ans.push_back('-');
                idx++;  
            }else if(test.top() > nseq[idx]){ //test의 top이 nseq[idx] 즉 타겟보다 크면 이미 불가능함
                return false;
            }
            else{ //같지도 top이 크지도 않다면 push 및 i 증가
                test.push(i);
                ans.push_back('+');
                i++;
            }
        }else{ //비어있지 아니하면 push 및 i 증가
            test.push(i);
            ans.push_back('+');
            i++;
        }
    } 
    return true;
}

int main(){
    int n;
    cin >> n;
    nseq.resize(n);
    for(int i = 0; i < n; i++)
        cin >> nseq[i];
    bool flag = check(n);
    if(flag){
        for(int i = 0; i < ans.size(); i++)
            cout << ans[i] << "\n";
    }else{
        cout << "NO";
    }
}