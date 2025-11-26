#include <iostream>
#include <stack>
using namespace std;

int solve(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
    return 0;
}

int evaluatePostfix(string exp) {
    stack<int> st;

    for (char c : exp) {
        if (isdigit(c)) {
            st.push(c - '0');  
        } else {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            st.push(solve(a, b, c));
        }
    }
    return st.top();
}

int main() {
    string exp;
    cout << "Enter postfix expression: ";
    cin >> exp;

    cout << "Result = " << evaluatePostfix(exp);
}
