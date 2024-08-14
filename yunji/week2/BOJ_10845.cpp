#include <iostream>
#include <vector>
using namespace std;

vector<int> queue;

void push();
void pop();
void empty();
void front();
void back();

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
            cout << queue.size() << endl;
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

void push() {
    int numToPush;
    cin >> numToPush;
    queue.push_back(numToPush);
}

void pop() {
    if (queue.empty()) {
        cout << -1 << endl;
    }
    else {
        cout << queue[0] << endl;
        queue.erase(queue.begin());
    }
}

void empty() {
    if (queue.empty()) {
        cout << 1 << endl;
    }
    else {
        cout << 0 << endl;
    }
}

void front() {
    if (queue.empty()) {
        cout << -1 << endl;
    }
    else {
        cout << queue.front() << endl;
    }
}

void back() {
    if (queue.empty()) {
        cout << -1 << endl;
    }
    else {
        cout << queue.back() << endl;
    }
}