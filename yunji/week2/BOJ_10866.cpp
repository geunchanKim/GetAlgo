#include <iostream>
#include <vector>
using namespace std;

vector<int> deque;

void pushFront();
void pushBack();
void popFront();
void popBack();
void empty();
void front();
void back();

int main() {
    int n;
    string cmd;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> cmd;
        if (!cmd.compare("push_front")) {
            pushFront();
        }
        else if (!cmd.compare("push_back")) {
            pushBack();
        }
        else if (!cmd.compare("pop_front")) {
            popFront();
        }
        else if (!cmd.compare("pop_back")) {
            popBack();
        }
        else if (!cmd.compare("size")) {
            cout << deque.size() << endl;
        }
        else if (!cmd.compare("empty")) {
            empty();
        }
        else if (!cmd.compare("front")) {
            front();
        }
        else if (!cmd.compare("back")) {
            back();
        }
    }

    return 0;
}

void pushFront() {
    int numToPush;
    cin >> numToPush;
    deque.insert(deque.begin(), numToPush);
}

void pushBack() {
    int numToPush;
    cin >> numToPush;
    deque.insert(deque.end(), numToPush);
}

void popFront() {
    if (deque.empty()) {
        cout << -1 << endl;
    }
    else {
        cout << deque.front() << endl;
        deque.erase(deque.begin());
    }
}

void popBack() {
    if (deque.empty()) {
        cout << -1 << endl;
    }
    else {
        cout << deque.back() << endl;
        deque.pop_back();
    }
}

void empty() {
    if (deque.empty()) {
        cout << 1 << endl;
    }
    else {
        cout << 0 << endl;
    }
}

void front() {
    if (deque.empty()) {
        cout << -1 << endl;
    }
    else {
        cout << deque.front() << endl;
    }
}

void back() {
    if (deque.empty()) {
        cout << -1 << endl;
    }
    else {
        cout << deque.back() << endl;
    }
}