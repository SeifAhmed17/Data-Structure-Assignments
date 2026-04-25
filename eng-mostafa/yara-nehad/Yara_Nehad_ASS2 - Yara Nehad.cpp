#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

template <class t>
class Node {
public:
    t data;
    Node* next;
};

template <class t>
class Stack 
{
public:
    Node<t>* top;

    Stack() 
    {
        top = NULL;
    }
    bool isEmpty() 
    {
        return (top == NULL);
    }

    void push(t newitem) 
    {
        Node<t>* newnode = new Node<t>();
        newnode->data = newitem;
        newnode->next = top;
        top = newnode;
    }

    void pop() 
    {
        if (!isEmpty()) {
            Node<t>* temp = top;
            top = top->next;
            delete temp;
        }
    }

    t getTop()
    {
        return top->data;
    }
};

int precedence(char c) 
{
    if (c == '*' || c == '/') return 2;
    else if (c == '+' || c == '-') return 1;
    else return -1;
}

string infixToPrefix(string s) 
{
    reverse(s.begin(), s.end());

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(')
            s[i] = ')';
        else if (s[i] == ')') 
            s[i] = '(';
    }

    Stack<char> st;
    string result = "";

    for (int i = 0; i < s.length(); i++) {
        char c = s[i];

        if (isalnum(c)) 
        {
            result += c;
        }

        else if (c == '(') 
        {
            st.push(c);
        }

        else if (c == ')') 
        {
            while (!st.isEmpty() && st.getTop() != '(') {
                result += st.getTop();
                st.pop();
            }
            st.pop();
        }

        else 
        {
            while (!st.isEmpty() && precedence(st.getTop()) >= precedence(c)) {
                result += st.getTop();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.isEmpty()) 
    {
        result += st.getTop();
        st.pop();
    }

    reverse(result.begin(), result.end());
    return result;
}

int evaluatePrefix(string exp) {

    stack<int> st;

    for (int i = exp.length() - 1; i >= 0; i--) {

        char c = exp[i];

        if (isdigit(c)) {
            st.push(c - '0');
        }
        else {
            int a = st.top(); st.pop();
            int b = st.top(); st.pop();

            switch (c) {
                case '+': st.push(a + b); break;
                case '-': st.push(a - b); break;
                case '*': st.push(a * b); break;
                case '/': st.push(a / b); break;
            }
        }
    }

    return st.top();
}
int main() 
{
    string infix;
    cout << "Enter Infix: ";
    cin >> infix;

    string prefix = infixToPrefix(infix);

    cout << "Prefix: " << prefix << endl;

    cout << "Value: " << evaluatePrefix(prefix) << endl;

    return 0;
}