#include <iostream>
#include <string>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* top = nullptr;

void push(int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = top;
    top = newNode;
}

int pop() {
    Node* temp = top;
    int val = top->data;
    top = top->next;
    delete temp;
    return val;
}

int peek() {
    return top->data;
}

bool isEmpty() {
    return top == nullptr;
}

bool isOperand(char c) {
    return c >= '0' && c <= '9';
}

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int precedence(char op) {
    if (op == '*' || op == '/')
     return 2;
    if (op == '+' || op == '-')
     return 1;
    return 0;
}

string infixToPostfix(string exp) {
    string result = "";

    for (int i = 0; i < exp.size(); i++) {
        char c = exp[i];

        if (isOperand(c)) {
            result += c;
        }
        else if (c == '(') {
            push(c);
        }
        else if (c == ')') {
            while (!isEmpty() && peek() != '(') {
                result += (char)pop();
            }
            pop();
        }
        else if (isOperator(c)) {
            while (!isEmpty() && precedence(peek()) >= precedence(c)) {
                result += (char)pop();
            }
            push(c);
        }
    }

    while (!isEmpty()) {
        result += (char)pop();
    }

    return result;
}

string infixToPrefix(string exp) {
    string rev = "";
    for (int i = exp.size() - 1; i >= 0; i--) {
        rev += exp[i];
    }

    for (int i = 0; i < rev.size(); i++) {
        if      (rev[i] == '(') rev[i] = ')';
        else if (rev[i] == ')') rev[i] = '(';
    }

    string postfix = infixToPostfix(rev);

    string prefix = "";
    for (int i = postfix.size() - 1; i >= 0; i--) {
        prefix += postfix[i];
    }

    return prefix;
}

int applyOp(char op, int a, int b) {
    if (op == '+')
     return a + b;
    if (op == '-')
     return a - b;
    if (op == '*')
     return a * b;
    if (op == '/')
     return a / b;
    return 0;
}

int evaluatePrefix(string prefix) {
    for (int i = prefix.size() - 1; i >= 0; i--) {
        char c = prefix[i];

        if (isOperand(c)) {
            push(c - '0');
        } else {
            int a = pop();
            int b = pop();
            push(applyOp(c, a, b));
        }
    }

    return pop();
}

int main() {
    string infix;

    cout << "Enter infix: ";
    cin  >> infix;

    string prefix = infixToPrefix(infix);
    int    result = evaluatePrefix(prefix);

    cout << "Infix:  " << infix  << endl;
    cout << "Prefix: " << prefix << endl;
    cout << "Value:  " << result << endl;

    return 0;
}