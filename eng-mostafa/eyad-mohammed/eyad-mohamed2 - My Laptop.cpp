#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

class Stack {
private:
    Node* topNode;

public:
    Stack() { topNode = nullptr; }

    void push(int val) {
        Node* newNode = new Node;
        newNode->data = val;
        newNode->next = topNode;
        topNode = newNode;
    }

    int pop() {
        if (isEmpty()) return -1;
        Node* temp = topNode;
        int val = temp->data;
        topNode = temp->next;
        delete temp;
        return val;
    }

    int peek() {
        if (isEmpty()) return -1;
        return topNode->data;
    }

    bool isEmpty() {
        return topNode == nullptr;
    }
};

int getLength(char str[]) {
    int len = 0;
    while (str[len] != '\0') len++;
    return len;
}

void reverseStr(char str[]) {
    int n = getLength(str);
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

bool isOperand(char c) {
    return (c >= '0' && c <= '9');
}

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

void infixToPostfix(char infix[], char postfix[]) {
    Stack s;
    int k = 0;
    for (int i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];
        if (isOperand(c)) {
            postfix[k++] = c;
        } else if (c == '(') {
            s.push(c);
        } else if (c == ')') {
            while (!s.isEmpty() && s.peek() != '(') {
                postfix[k++] = (char)s.pop();
            }
            s.pop();
        } else if (isOperator(c)) {
            while (!s.isEmpty() && precedence(s.peek()) >= precedence(c)) {
                postfix[k++] = (char)s.pop();
            }
            s.push(c);
        }
    }
    while (!s.isEmpty()) {
        postfix[k++] = (char)s.pop();
    }
    postfix[k] = '\0';
}

void convertToPrefix(char infix[], char prefix[]) {
    reverseStr(infix);
    for (int i = 0; infix[i] != '\0'; i++) {
        if (infix[i] == '(') infix[i] = ')';
        else if (infix[i] == ')') infix[i] = '(';
    }
    
    char tempPostfix[100];
    infixToPostfix(infix, tempPostfix);
    
    int len = getLength(tempPostfix);
    for (int i = 0; i <= len; i++) {
        prefix[i] = tempPostfix[i];
    }
    reverseStr(prefix);
}

int applyOp(char op, int a, int b) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    if (op == '/') return a / b;
    return 0;
}

int evaluatePrefix(char prefix[]) {
    Stack s;
    int len = getLength(prefix);
    for (int i = len - 1; i >= 0; i--) {
        if (isOperand(prefix[i])) {
            s.push(prefix[i] - '0');
        } else if (isOperator(prefix[i])) {
            int a = s.pop();
            int b = s.pop();
            s.push(applyOp(prefix[i], a, b));
        }
    }
    return s.pop();
}

int main() {
    char infix[100] = "(2+3)*4";
    char prefix[100];

    cout << "Infix: " << infix << endl;
    convertToPrefix(infix, prefix);
    cout << "Prefix: " << prefix << endl;
    cout << "Value: " << evaluatePrefix(prefix) << endl;

    return 0;
}