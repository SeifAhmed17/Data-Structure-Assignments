#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Node {
public:
    char data;
    Node* next;
    Node(char val) {
        data = val;
        next = NULL;
    }
};

class Stack {
    Node* top = NULL;
    int sz = 0;

public:
    bool isEmpty() { return top == NULL; }

    void push(char item) {
        Node* newNode = new Node(item);
        newNode->next = top;
        top = newNode;
        sz++;
    }

    void pop() {
        if (isEmpty()) return;
        Node* temp = top;
        top = top->next;
        delete temp;
        sz--;
    }

    char peek() {
        if (!isEmpty()) return top->data;
        return '\0';
    }

    // Task 3
    int getSize() {
        return sz;
    }
};

// Task 1
string removeStars(string s) {
    Stack st;
    for (char c : s) {
        if (c == '*') {
            st.pop();
        } else {
            st.push(c);
        }
    }

    string result = "";
    while (!st.isEmpty()) {
        result += st.peek();
        st.pop();
    }
    reverse(result.begin(), result.end());
    return result;
}

// Task 2
Stack* copyStack(Stack* original) {
    Stack temp;
    Stack* newStack = new Stack();

    while (!original->isEmpty()) {
        temp.push(original->peek());
        original->pop();
    }

    while (!temp.isEmpty()) {
        newStack->push(temp.peek());
        original->push(temp.peek());
        temp.pop();
    }

    return newStack;
}

int main() {
    string s = "leet**cod*e";
    cout << "Task 1: " << removeStars(s) << endl;
    Stack* myStack = new Stack();
    myStack->push('A');
    myStack->push('B');
    myStack->push('C');
    cout << "Task 3: " << myStack->getSize() << endl;
    Stack* copied = copyStack(myStack);
    cout << "Task 2 (Top of copy): " << copied->peek() << endl;
    return 0;
}