#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
template<typename t>
struct Node
{
    char data;
    Node* next;
};

template<typename t>
class Stack
{
    Node<t>* top;

public:
    Stack() { top = NULL; }

    void push(t x)
    {
        Node<t>* n = new Node<t>();
        n->data = x;
        n->next = top;
        top = n;
    }

    void pop()
    {
        if (top != NULL)
        {
            Node<t>* r = top;
            top = top->next;
            delete r;
        }
    }

     t Top() {
        if (top != NULL) {
            return top->data;
        }
    }

    bool empty() { return top == NULL; }
};

bool IsOperand(char c)
{
    return isalnum(c);
}

bool IsOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '$');
}

int Priority(char op)
{
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '$') return 3;
    return 0;
}

bool RightAssoc(char op)
{
    return op == '$';
}

string InfixToPostfix(string s)
{
    Stack<char> st;
    string postfix = "";

    for (int i = 0; i < s.size(); i++)
    {
        char c = s[i];

        if (c == ' ') continue;

        if (IsOperand(c))
            postfix += c;

        else if (c == '(')
            st.push(c);

        else if (c == ')')
        {
            while (!st.empty() && st.Top() != '(')
            {
                postfix += st.Top();
                st.pop();
            }
            st.pop();
        }

        else if (IsOperator(c))
        {
            while (!st.empty() && st.Top() != '(' &&
                (Priority(st.Top()) > Priority(c) ||
                    (Priority(st.Top()) == Priority(c) && !RightAssoc(c))))
            {
                postfix += st.Top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty())
    {
        postfix += st.Top();
        st.pop();
    }

    return postfix;
}
string InfixToPrefix(string s)
{
    reverse(s.begin(), s.end());

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(') s[i] = ')';
        else if (s[i] == ')') s[i] = '(';
    }

    string post = InfixToPostfix(s);
    reverse(post.begin(), post.end());

    return post;
}
int app(char op, int a, int b)
{
    if (op == '+') return b + a;
    if (op == '-') return b - a;
    if (op == '*') return b * a;
    if (op == '/') return b / a;
}
int value(string s)
{
    Stack<int> st;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        char c = s[i];
        if (isdigit(c)) {
            st.push(c - '0');
        }
        else {
            int a = st.Top();
            st.pop();
            int b= st.Top();
            st.pop();
            int result = app(c,a,b);
            st.push(result);
        }
    }
    return st.Top();




}

int main()
{
    string exp;
    cout << "Enter Infix: ";
    cin >> exp;

    cout << "Prefix: " << InfixToPrefix(exp) << endl;
    cout << "result:" << value(exp);
}