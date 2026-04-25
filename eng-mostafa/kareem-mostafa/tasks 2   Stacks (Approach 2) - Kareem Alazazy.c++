#include <bits/stdc++.h>
using namespace std;

struct Stack {
    vector<int> v;
    void push(int x) { v.push_back(x); }
    int pop() { int x = v.back(); v.pop_back(); return x; }
    bool isEmpty() { return v.empty(); }
};

struct Queue {
    Stack s1, s2;
    int added_elements = 0;

    void enqueue(int value) {
        s1.push(value);
        added_elements++;
    }

    int dequeue() {
        if (s2.isEmpty()) {
            while (!s1.isEmpty())
                s2.push(s1.pop());
        }
        added_elements--;
        return s2.pop();
    }
};