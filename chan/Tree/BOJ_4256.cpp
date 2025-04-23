#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;

vector<int> preorder;
vector<int> inorder;
int n;

void postorder(int start, int end, int pos){
    for(int i = start; i < end; ++i){
        if(inorder[i] == preorder[pos]){
            postorder(start, i, pos + 1);
            postorder(i + 1, end, pos + 1 + i - start);
            cout << preorder[pos] << ' ';
        }
    }
}

int main(){
    FASTIO;
    int T;
    cin >> T;
    for(int i = 0; i < T; i++){
        cin >> n;
        preorder = vector<int>(n);
        inorder = vector<int>(n);
        for(int j = 0; j < n; j++)
            cin >> preorder[j];
        for(int j = 0; j < n; j++)
            cin >> inorder[j];
        postorder(0, n, 0);
        cout << '\n';
    }
    return 0;
}