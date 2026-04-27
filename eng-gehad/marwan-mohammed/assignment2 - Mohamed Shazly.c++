#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct NodeChar { char data; NodeChar* next; };
struct NodeInt { int data; NodeInt* next; };

NodeChar* topChar = nullptr;
NodeInt* topInt = nullptr;

void pushChar(char val) { NodeChar* n = new NodeChar; n->data = val; n->next = topChar; topChar = n; }
char popChar() { if(!topChar) return 0; char v = topChar->data; NodeChar* t = topChar; topChar = topChar->next; delete t; return v; }
char peekChar() { return topChar ? topChar->data : 0; }
bool isEmptyChar() { return topChar == nullptr; }

void pushInt(int val) { NodeInt* n = new NodeInt; n->data = val; n->next = topInt; topInt = n; }
int popInt() { if(!topInt) return 0; int v = topInt->data; NodeInt* t = topInt; topInt = topInt->next; delete t; return v; }

bool isOperand(char c) { return (c >= '0' && c <= '9'); }
bool isOperator(char c) { return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^'); }
int precedence(char op) {
    if(op == '^') return 3;
    if(op == '*' || op == '/') return 2;
    if(op == '+' || op == '-') return 1;
    return 0;
}

string infixToPostfix(string s) {
    string res = "";
    for(char c : s) {
        if(isOperand(c)) res += c;
        else if(c == '(') pushChar(c);
        else if(c == ')') {
            while(!isEmptyChar() && peekChar() != '(') res += popChar();
            if(!isEmptyChar()) popChar();
        } else {
            while(!isEmptyChar() && precedence(peekChar()) >= precedence(c)) res += popChar();
            pushChar(c);
        }
    }
    while(!isEmptyChar()) res += popChar();
    return res;
}

string infixToPrefix(string infix) {
    reverse(infix.begin(), infix.end());
    for(char &c : infix) {
        if(c == '(') c = ')';
        else if(c == ')') c = '(';
    }
    string postfix = infixToPostfix(infix);
    reverse(postfix.begin(), postfix.end());
    return postfix;
}

int applyOp(char op, int a, int b) {
    if(op == '+') return a + b;
    if(op == '-') return a - b;
    if(op == '*') return a * b;
    if(op == '/') return a / b;
    return 0;
}

int evaluatePrefix(string prefix) {
    for(int i = prefix.size() - 1; i >= 0; i--) {
        if(isOperand(prefix[i])) pushInt(prefix[i] - '0');
        else {
            int a = popInt();
            int b = popInt();
            pushInt(applyOp(prefix[i], a, b));
        }
    }
    return popInt();
}

int main() {
    string infix = "(2+3)*4";
    string prefix = infixToPrefix(infix);
    int result = evaluatePrefix(prefix);
    cout << "Infix: " << infix << endl;
    cout << "Prefix: " << prefix << endl;
    cout << "Value: " << result << endl;
    return 0;
}