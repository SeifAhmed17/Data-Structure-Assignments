#include <iostream>
using namespace std;

class Stack {
    int arr[100];
    int top;

public:
    Stack() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    void push(int x) {
        arr[++top] = x;
    }

    int pop() {
        return arr[top--];
    }

    int peek() {
        return arr[top];
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    cout << s.pop();
    return 0;
}