#include <iostream>
#include <vector>
using namespace std;

vector<int> stack;

void push();
void pop();
void empty();
void top();

int main() {
    int n;
    string cmd;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> cmd;

        if (!cmd.compare("push")) {
            push();
        }
        else if (!cmd.compare("pop")) {
            pop();
        }
        else if (!cmd.compare("size")) {
            cout << stack.size() << endl;
        }
        else if (!cmd.compare("empty")) {
            empty();
        }
        else if (!cmd.compare("top")) {
            top();
        }
    }

    return 0;
}

void push() {
    int numToPush;
    cin >> numToPush;
    stack.push_back(numToPush);
}

void pop() {
    if (stack.empty()) {
        cout << -1 << endl;
    }
    else {
        cout << stack.back() << endl;
        stack.pop_back();
    }
}

void empty() {
    if (stack.empty()) {
        cout << 1 << endl;
    }
    else {
        cout << 0 << endl;
    }
}

void top() {
    if (stack.empty()) {
        cout << -1 << endl;
    }
    else {
        cout << stack.back() << endl;
    }
}