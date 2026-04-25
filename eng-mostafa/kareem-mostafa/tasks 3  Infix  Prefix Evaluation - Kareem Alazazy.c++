#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int v) { data = v; next = NULL; }
};

struct Stack {
    Node* top = NULL;

    void push(int v) {
        Node* n = new Node(v);
        n->next = top;
        top = n;
    }

    int pop() {
        int v = top->data;
        Node* t = top;
        top = top->next;
        delete t;
        return v;
    }

    int peek() {
        return top->data;
    }

    bool isEmpty() {
        return top == NULL;
    }
};

bool isOperand(char c) {
    return isdigit(c);
}

bool isOperator(char c) {
    return c=='+'||c=='-'||c=='*'||c=='/'||c=='^';
}

int precedence(char op) {
    if (op=='^') return 3;
    if (op=='*'||op=='/') return 2;
    if (op=='+'||op=='-') return 1;
    return 0;
}

string infixToPostfix(string s) {
    Stack st;
    string res = "";

    for (char c : s) {
        if (isOperand(c))
            res += c;
        else if (c == '(')
            st.push(c);
        else if (c == ')') {
            while (!st.isEmpty() && st.peek() != '(')
                res += char(st.pop());
            st.pop();
        } else {
            while (!st.isEmpty() && precedence(st.peek()) >= precedence(c))
                res += char(st.pop());
            st.push(c);
        }
    }

    while (!st.isEmpty())
        res += char(st.pop());

    return res;
}

string infixToPrefix(string s) {
    reverse(s.begin(), s.end());

    for (char &c : s) {
        if (c == '(') c = ')';
        else if (c == ')') c = '(';
    }

    string postfix = infixToPostfix(s);
    reverse(postfix.begin(), postfix.end());
    return postfix;
}

int applyOp(char op, int a, int b) {
    if (op=='+') return a+b;
    if (op=='-') return a-b;
    if (op=='*') return a*b;
    if (op=='/') return a/b;
    if (op=='^') return pow(a,b);
    return 0;
}

int evaluatePrefix(string s) {
    Stack st;

    for (int i = s.size()-1; i >= 0; i--) {
        if (isdigit(s[i]))
            st.push(s[i]-'0');
        else {
            int a = st.pop();
            int b = st.pop();
            st.push(applyOp(s[i], a, b));
        }
    }
    return st.pop();
}

int main() {
    string infix;
    cin >> infix;

    string prefix = infixToPrefix(infix);
    int val = evaluatePrefix(prefix);

    cout << "Infix: " << infix << endl;
    cout << "Prefix: " << prefix << endl;
    cout << "Value: " << val << endl;
}