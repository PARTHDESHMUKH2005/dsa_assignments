#include <iostream>
#include <stack>
using namespace std;

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;

    stack<char> st;

    for (char c : s)
        st.push(c);

    cout << "Reversed string: ";
    while (!st.empty()) {
        cout << st.top();
        st.pop();
    }
}
