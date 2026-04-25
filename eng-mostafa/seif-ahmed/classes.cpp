#include <bits/stdc++.h>
using namespace std;

class Stack {
public:
    int top; int N = 1e5+17;
    int *arr;
    Stack():top(-1) { arr = new int[N]; }
    void push(int x) { if (top < N-1) arr[++top] = x; }
    int pop() { if (top >= 0) return arr[top--]; }
    bool empty() { return top == -1; }
    int peek() { return arr[top]; }
};
    
class Queue {
public:
    Stack s1, s2;
    Queue(){}
    void move() { while (!s1.empty()) s2.push(s1.pop()); }
    void enqueue(int x) { s1.push(x); }
    void dequeue() {
        if (s2.empty()) move();
        if (!s2.empty()) s2.pop();
    }
};

int main() {
    return 0;
}