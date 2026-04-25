//                                                  بِسۡمِ ٱللَّهِ ٱلرَّحۡمَٰنِ ٱلرَّحِيمِ
// El_Mooo ==> 1 (^_^)
#include <algorithm>
#include <iostream>
using namespace std;
#define elmoo ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"
#define all(x) (x).begin(), (x).end()
/*============================================================================*/
template<class T>
class Stack {
    struct Node {
        T value;
        Node *prev;
        Node(T x) : prev(nullptr), value(x) {}
    };
    Node *top ;
    int cnt ;

public:

    Stack() : top(nullptr), cnt(0) {}

    int size() {
        return cnt;
    }

    bool is_empty() {
        return cnt == 0;
    }

    void push(T x) {
        Node *new_node = new Node(x);
        if (top == nullptr) top = new_node;
        else {
            new_node->prev = top;
            top = new_node;
        }
        cnt++;
    }

    void pop() {
        if (top == nullptr) return;
        Node *del = top;
        top = top->prev;
        delete del;
        cnt--;
    }

    void get_top(T &x , bool &ch) {
        if (is_empty()) {
            ch = false;
            return void (cout << "Stack is Empty!\n");
        }
        ch = true;
        x = top->value;
    }

    T peek() {
        return top->value;
    }

    void print() {
        Node *cur = top;
        cout << "The stack elements : [ ";
        while (cur != nullptr) {
            cout << cur->value;
            cur = cur->prev;
            if (cur != nullptr) cout << " , ";
        }
        cout << " ]" << endl;
    }

    void clear() {
        while (!is_empty()) pop();
    }

    ~Stack() {
        clear();
    }
};
class PreFix {
public:
bool IsOperand(char c) {
    return (c >= '0' && c <= '9');
}
bool IsOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

string InfixToPrefix(string infix) {
    Stack<char> st;
    string prefix = "";

    reverse(all(infix));

    for (int i = 0; i < infix.length(); i++) {
        if (infix[i] == '(') infix[i] = ')';
        else if (infix[i] == ')') infix[i] = '(';
    }

    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];
        if (IsOperand(c)) prefix += c;
        else if (c == '(') st.push(c);
        else if (c == ')') {
            while (!st.is_empty() && st.peek() != '(') {
                prefix += st.peek();
                st.pop();
            }
            st.pop();
        }
        else if (IsOperator(c)) {
            while (!st.is_empty() && precedence(st.peek()) > precedence(c)) {
                prefix += st.peek();
                st.pop();
            }
            while (!st.is_empty() && precedence(st.peek()) == precedence(c) && c == '^') {
                prefix += st.peek();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.is_empty()) {
        prefix += st.peek();
        st.pop();
    }
    reverse(all(prefix));
    return prefix;
}

int evaluatePrefix(string prefix) {
    Stack<int> st;

    for (int i = prefix.length() - 1; i >= 0; i--) {
        char c = prefix[i];

        if (IsOperand(c)) {
            st.push(c - '0');
        }
        else if (IsOperator(c)) {
            int op1 = st.peek();
            st.pop();
            int op2 = st.peek();
            st.pop();
            if (c == '+') st.push(op1 + op2);
            else if (c == '-') st.push(op1 - op2);
            else if (c == '*') st.push(op1 * op2);
            else if (c == '/') st.push(op1 / op2);

        }
    }
    int ans = st.peek();
    st.pop();
    return ans;
}

};
template <class T>
class QueueUsingStacks {
private:
    Stack<T> s1;
    Stack<T> s2;
    int added_elements;

public:
    QueueUsingStacks() : added_elements(0) {}

    void enqueue(T value) {
        s1.push(value);
        added_elements++;
    }

    T dequeue() {
        if (s1.is_empty() && s2.is_empty()) {
            cout << "Queue is Empty!" << endl;
            return T();
        }

        if (s2.is_empty()) {
            while (!s1.is_empty()) {
                s2.push(s1.peek());
                s1.pop();
            }
        }

        T value = s2.peek();
        s2.pop();
        added_elements--;

        return value;
    }

    bool is_empty() {
        return added_elements == 0;
    }
};

// 2+3*5
// 5*3+2
// pre -> 5 3 * 2
// st -> +
void elmooo() {
    string InfixExpression; cin >> InfixExpression;

    cout << "Original Infix: " << InfixExpression << endl;

    PreFix operations;

    string prefix = operations.InfixToPrefix(InfixExpression);
    cout << "Converted Prefix: " << prefix << endl;

    int result = operations.evaluatePrefix(prefix);
    cout << "Evaluated Result: " << result << endl;

}

int main() {
    // elmoo;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // int t; cin >> t; while (t--);
        elmooo();
    return 0;
}