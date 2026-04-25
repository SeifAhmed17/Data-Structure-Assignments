#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct Node {
    T val; Node* nxt;
    Node(T x):val(x),nxt(nullptr){}
};

template<typename T>
class Stack {
public:
    Node<T>* top; int sz;
    Stack():top(nullptr),sz(0){}
    void push(T x) {
        Node<T>* newNode = new Node<T>(x);
        newNode->nxt = top, top = newNode;
        ++sz;
    }
    void pop() {
        if (top != nullptr) {
            Node<T>* del_ptr = top;
            top = top->nxt, --sz;
            delete del_ptr;
        }
    }
    bool empty() { return !sz; }
    T peek() { return top->val; }
    int get_size() { return sz; }
    void copy(Stack<T> st) {
        while (!empty()) pop();
        Stack<T> temp;
        while (!st.empty()) temp.push(st.peek()), st.pop();
        while (!temp.empty()) push(temp.peek()), temp.pop();
    }
};

template<typename T>
class Queue
{
public:
    int sz; Node<T>* front, *back;
    Queue() { front = back = nullptr, sz = 0; }
    void push(T x) {
        Node<T>* newNode = new Node<T>(x);
        if (!sz) front = back = newNode;
        else back->nxt = newNode, back = newNode;
        ++sz;
    }
    T pop() {
        T ret = front->val;
        Node<T> *del = front;
        front = front->nxt;
        delete del;
        if (!--sz) front = back = nullptr;
        return ret;
    }
    bool is_palindrome() {
        Stack<T> st;
        Node<T>* cur = front;
        for (int i=0; i < sz; i++, cur = cur->nxt) {
            if ((sz&1) && i == sz/2) continue;
            if (i < sz/2) st.push(cur->val);
            else {
                if (cur->val != st.peek()) return false;
                st.pop();
            }
        }
        return st.empty();
    }
    void rotate_by_k_positions(int k) {
        if (!sz) return;
        k %= sz;
        while (k--) push(pop());
    }
};

template<typename T>
class LinkedList {
public:
    Node<T> *head, *tail;
    int sz;
    LinkedList():sz(0), head(nullptr), tail(nullptr) {}
    void insert(T x) {
        Node<T> *newNode = new Node<T>(x);
        if (!sz) head = tail = newNode;
        else tail->nxt = newNode, tail = newNode;
        ++sz;
    }
    T get_nth(int n) {
        Node<T> *cur = head;
        for (int i=1; cur!=nullptr;i++, cur=cur->nxt) if (i==n) return cur->val;
        return -1;
    }
};

template<typename T>
Node<T>* merge_two_linked_lists(Node<T> *h1, Node<T> *h2) {
    LinkedList<T> l;
    while (h1!=nullptr || h2!=nullptr)
        h2 == nullptr || (h1!=nullptr&&h1->val <= h2->val) ? l.insert(h1->val), h1=h1->nxt : l.insert(h2->val), h2=h2->nxt;
    return l.head;
}

template<typename T>
LinkedList<T> reverse_linked_list(LinkedList<T> l) {
    LinkedList<T> ret;
    function<void(Node<T>*)> go = [&](Node<T>* cur) {
        if (!cur) return;
        go(cur->nxt);
        ret.insert(cur->val);
    };
    go(l.head);
    return ret;
}

template<typename T>
LinkedList<T> remove_number_at_position_x(LinkedList<T> l, int x) {
    if (l.head==nullptr || x < 0 || x >= l.sz) return l;
    if (!x) {
        Node<T> *del = l.head;
        l.head = l.head->nxt;
        delete del;
        if (!l.head) l.tail = nullptr;
    } else {
        Node<T> *cur = l.head;
        while (--x) cur=cur->nxt;
        Node<T> *del = cur->nxt;
        cur->nxt = cur->nxt->nxt;
        if (del == l.tail) l.tail = cur;
        delete del;
    }
    --l.sz;
    return l;
}

int reverse_a_number_using_stack(int x) {
    Stack<int> st;
    while (x) st.push(x%10), x /= 10;
    int r = 1, ret = 0;
    while (!st.empty()) ret += r*st.peek(), st.pop(), r*=10;
    return ret;
}

bool valid_parentheses(const string& s) {
    auto inv = [&](char c) {
        if (c == ']') return '[';
        return c == ')' ? '(' : '{';
    };
    Stack<char> st;
    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') st.push(c);
        else {
            if (st.empty() || st.peek() != inv(c)) return false;
            st.pop();
        }
    }
    return st.empty();
}

string remove_stars(const string& s) {
    Stack<char> st;
    for (char c : s) c != '*' ? st.push(c) : st.pop();
    string ret = "";
    while (!st.empty()) ret = st.peek() + ret, st.pop();
    return ret;
}

LinkedList<int> remove_duplicates(LinkedList<int> l) {
    int p = -2e9;
    LinkedList<int> ret;
    for (Node<int> *cur = l.head; cur != nullptr; cur = cur->nxt)
        if (cur->val != p) p = cur->val, ret.insert(p);
    return ret;
}

int main() {
    return 0;
}
