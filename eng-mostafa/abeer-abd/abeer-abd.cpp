#include <bits/stdc++.h>
using namespace std;

// Task 1
string removeStars(string s) {
    Stack<char> st;
    for (char c : s) {
        c != '*' ? st.push(c) : st.pop();
    }
    string ret = "";
    while (!st.empty()) ret = st.peek() + ret, st.pop();

    return ret;
}

template<typename T>
struct Node {
    T val;
    Node* nxt;
    Node(T x):val(x),nxt(nullptr){}
};

template<typename T>
class Stack {
    Node<T>* top;
    int sz;
public:
    Stack():top(nullptr),sz(0){}

    void push(T x) {
        Node<T>* newNode = new Node(x);
        newNode->nxt = top;
        top = newNode;
        ++sz;
    }

    void pop() {
        if (top != nullptr) {
            Node<T>* del_ptr = top;
            top = top->nxt;
            delete del_ptr;
            --sz;
        }
    }

    bool empty() { return !sz; }

    T peek() { return top->val; }

    // Task 2
    void copy(Stack<T> st) {
        while (!empty()) pop();
        Stack<T> temp;
        while (!st.empty()) temp.push(st.peek()), st.pop();
        while (!temp.empty()) push(temp.peek()), temp.pop();
    }

    // Task 3
    int get_size() { return sz; }
};

int main()
{
    return 0;
}