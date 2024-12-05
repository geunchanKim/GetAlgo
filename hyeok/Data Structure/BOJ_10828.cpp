#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> st;
    int n;
    string command;

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> command;

        if(command == "push")
        {
            int num;
            cin >> num;
            st.push(num);
        }
        if(command == "pop")
        {
            if(st.size() == 0)
            cout << -1 << endl;
            else{
            cout << st.top() << endl;
            st.pop();}
        }
        if(command == "size")
        {
            cout << st.size() << endl;
        }
        if(command == "empty")
        {
            cout << st.empty() << endl;
        }
        if(command == "top")
        {
            if(st.size() == 0)
            cout << -1 << endl;
            else
            cout << st.top() << endl;
        }
    }
}