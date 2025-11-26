#include <iostream>
#include <stack>
using namespace std;

bool isMatching(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

bool isBalanced(string exp) {
    stack<char> st;

    for (char ch : exp) {
        if (ch == '(' || ch == '{' || ch == '[')
            st.push(ch);
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (st.empty() || !isMatching(st.top(), ch))
                return false;
            st.pop();
        }
    }

    return st.empty();
}

int main() {
    string exp;
    cout << "Enter expression: ";
    cin >> exp;

    if (isBalanced(exp))
        cout << "Balanced Expression\n";
    else
        cout << "Unbalanced Expression\n";
}
