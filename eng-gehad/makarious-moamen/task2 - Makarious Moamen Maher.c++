#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

bool isOperand(char c) {
    return isdigit(c);
}

bool isOperator(char c) {
    return c=='+' || c=='-' || c=='*' || c=='/' || c=='^';
}

int precedence(char op) {
    if (op=='^') return 3;
    if (op=='*' || op=='/') return 2;
    if (op=='+' || op=='-') return 1;
    return 0;
}

string infixToPrefix(string infix) {
    reverse(infix.begin(), infix.end());

    for (char &c : infix) {
        if (c == '(') c = ')';
        else if (c == ')') c = '(';
    }

    stack<char> st;
    string postfix = "";

    for (char c : infix) {
        if (isdigit(c))
            postfix += c;
        else if (c == '(')
            st.push(c);
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            st.pop();
        }
        else {
            while (!st.empty() && precedence(st.top()) >= precedence(c)) {
                postfix += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }

    reverse(postfix.begin(), postfix.end());
    return postfix;
}

int applyOp(char op, int a, int b) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    if (op == '/') return a / b;
    return 0;
}

int evaluatePrefix(string prefix) {
    stack<int> st;

    for (int i = prefix.size()-1; i >= 0; i--) {
        if (isdigit(prefix[i]))
            st.push(prefix[i] - '0');
        else {
            int a = st.top(); st.pop();
            int b = st.top(); st.pop();
            st.push(applyOp(prefix[i], a, b));
        }
    }
    return st.top();
}

int main() {
    string infix;
    cout << "Enter infix: ";
    cin >> infix;

    string prefix = infixToPrefix(infix);
    int result = evaluatePrefix(prefix);

    cout << "Prefix: " << prefix << endl;
    cout << "Value: " << result << endl;

    return 0;
}