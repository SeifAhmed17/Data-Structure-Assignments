#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

class Stack
{
private:
    Node* top;

public:
    Stack()
    {
        top = NULL;
    }

    void push(int val)
    {
        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = top;
        top = newNode;
    }

    int pop()
    {
        if (top == NULL)
            return -1;

        int val = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return val;
    }

    int peek()
    {
        if (top == NULL)
            return -1;
        return top->data;
    }

    bool isEmpty()
    {
        return top == NULL;
    }
};

int precedence(char op)
{
    if (op == '^')
    {
        return 3;
    }
    else if (op == '*' || op == '/')
    {
        return 2;
    }
    else if (op == '+' || op == '-')
    {
        return 1;
    }
    return 0;
}

bool isOperand(char c)
{
    return isdigit(c);
}

string infixToPostfix(string s)
{
    Stack st;
    string result = "";

    for (char c : s)
    {

        if (isOperand(c))
        {
            result += c;
        }

        else if (c == '(')
        {
            st.push(c);
        }

        else if (c == ')')
        {
            while (!st.isEmpty() && st.peek() != '(') {
                result += (char)st.pop();
            }
            st.pop();
        }

        else
        {
            while (!st.isEmpty() && precedence(st.peek()) >= precedence(c)) {
                result += (char)st.pop();
            }
            st.push(c);
        }
    }

    while (!st.isEmpty()) {
        result += (char)st.pop();
    }

    return result;
}

string infixToPrefix(string s)
{
    reverse(s.begin(), s.end());

    for (char& c : s)
    {
        if (c == '(') c = ')';
        else if (c == ')') c = '(';
    }

    string postfix = infixToPostfix(s);
    reverse(postfix.begin(), postfix.end());

    return postfix;
}

int applyOp(char op, int a, int b)
{
    if (op == '+')
    {
        return a + b;
    }
    if (op == '-')
    {
        return a - b;
    }
    if (op == '*')
    {
        return a * b;
    }
    if (op == '/')
    {
        return a / b;
    }
    return 0;
}

int evaluatePrefix(string prefix)
{
    Stack st;

    for (int i = prefix.size() - 1; i >= 0; i--)
    {

        if (isdigit(prefix[i]))
        {
            st.push(prefix[i] - '0');
        }

        else
        {
            int a = st.pop();
            int b = st.pop();
            st.push(applyOp(prefix[i], a, b));
        }
    }

    return st.pop();
}

int main()
{
    string infix;

    cout << "Enter Infix: ";
    cin >> infix;

    string prefix = infixToPrefix(infix);
    int value = evaluatePrefix(prefix);

    cout << "Infix: " << infix << endl;
    cout << "Prefix: " << prefix << endl;
    cout << "Value: " << value << endl;

    return 0;
}